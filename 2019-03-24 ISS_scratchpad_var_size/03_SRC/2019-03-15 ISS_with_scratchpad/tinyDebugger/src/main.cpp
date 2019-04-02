#include <iostream>
#include <fstream>
#include "sim.h"
#include <cstdlib>
#include <string.h>
#include <stdlib.h>

#define DIS
int decode(char*, int, int);
int select_mode(void);
int enter_command(void);
void clear_register(int *reg);
void info_register(int *reg);
void twos_offset(void);



int main(int argc, char* argv[])
{
		int pc = 0;
		int line;
		char inst[17];
		FILE *fin;
		fin = fopen(argv[1], "r");
		int freq[10] = {0};
		int clks[10] = {4, 4, 4, 4, 4, 8, 8, 4, 16, 16};
		PAD scratch_pad[PAD_SIZE];
		int hit;

		for( int i=0; i<26; i++)
		{
			p[i].flash_fetch = 0.0;
			p[i].scratch_fetch = 0.0;
			p[i].decode = 0.0;
			p[i].execute = 0.0;
		}

		if( argc != 3)
		{
				cout << "lss <input file> <line>\n";
				return -1;
		}

		flash_fetch(fin, scratch_pad, 0);
#ifdef DEBUG1
		for( int j=0; j<PAD_SIZE; j++)
		{
				printf("%d\t%s\n", scratch_pad[j].pc, scratch_pad[j].inst);
		}
#endif
		line = atoi(argv[2]);
		
		int b_num = 0;

		while(pc < line)
		{
				hit = scratch_fetch( scratch_pad, inst, pc); // if hit return 0
				if(hit & 1)
				{
					flash_fetch( fin, scratch_pad, pc);
#ifdef DEBUG1
		for( int j=0; j<PAD_SIZE; j++)
		{
				printf("%d\t%s\n", scratch_pad[j].pc, scratch_pad[j].inst);
		}
#endif
					scratch_fetch( scratch_pad, inst, pc);
				}
				decode_2(inst);
				b_num = run_program(freq, clks);

				if( b_num != 0)
				{
					pc += b_num;
					b_num+=1;
					pc++;
				}
				pc++;
				time++;
		}

		fclose(fin);
		report_profile(freq, clks);
		plot_power_performance(time); 
		return 0;
}

int decode(
				char *bin, // currently-accessed line
				int num,	// number of reading bit	
				int val		// MSB
		  )
{
		int CODE = 0;
		char bit;
		static int loc = 0;

		/*
		   infile >> bit;
		   infile >> bit;
		   infile >> bit;
		   infile >> bit;
		   */
	
		for( int i=0 ; i<num; i++)
		{
				//		infile >> bit;
				bit = bin[loc+i];
				if( bit == '1')
						CODE |= (val >> i); // good
		}
		loc = loc + num;
		if( loc >= 15)
				loc = 0;
#ifdef DEBUG
		cout << "-" << CODE << endl;
#endif
		return CODE;
}

void flash_fetch( FILE *fin, PAD *scratch_pad, int line)
{
		static char state = '0';
		char bit;
		int num = 0;
		fseek(fin, line*18, SEEK_SET);
		
		while(num < PAD_SIZE)
		{
			if(feof(fin))
					break;
	
			fscanf(fin, "%s\n", scratch_pad[num].inst);
			
			scratch_pad[num].pc = line + num;	
			
			for( int i=0; i<16; i++)
			{
					if( scratch_pad[num].inst[i] == '1' && state == '0')
							p[time].flash_fetch += 2.0;
	
					else if( scratch_pad[num].inst[i] == '0' && state == '1')
							p[time].flash_fetch  += 2.0;
	
					else
						p[time].flash_fetch += 0.4;
		
					state = scratch_pad[num].inst[i];
			}
			time++;
			num++;
		}
}

int scratch_fetch( PAD *scratch_pad, char *bin, int pc)
{
		static char state = '0';
		char bit;
		int hit = 0;

		for( hit=0; hit<PAD_SIZE; hit++)
		{
			if( pc == scratch_pad[hit].pc)
					break;
		}
		if( hit == PAD_SIZE)
				return 1;

		for( int i=0; i<16; i++)
		{
				bin[i] = scratch_pad[hit].inst[i];

				if( bin[i] == '1' && state == '0')
						p[time].scratch_fetch += 0.4;

				else if( bin[i] == '0' && state == '1')
						p[time].scratch_fetch += 0.4;

				else
						p[time].scratch_fetch += 0.08;

				state = bin[i];
		}
		return 0;
}

void decode_2(char *inst)
{
		program.opcode[0] = decode(inst, 3, 4);
		p[time].decode += 0.1;
		switch( program.opcode[0])
		{
				case 0:
						program.opcode[1] = decode(inst, 4, 8);
						p[time].decode += 0.1;

						if( program.opcode[1] == 15) // SUBS
						{
								program.offset = decode(inst, 3, 4);
								program.OP1 = decode(inst, 3, 4);
								program.OP2 = decode(inst, 3, 4);
								program.OPCODE = 0;
								p[time].decode += 0.3;
//								printf("SUBS\n");
								break;
						}
						else
						{
								cout << "Not defined Operation!" << endl;
								break;
						}
						break;

				case 1:
						program.opcode[1] = decode(inst, 2, 2);
						p[time].decode += 0.1;
						
						switch( program.opcode[1])
						{
								case 0: // MOVS
										program.OP1 = decode(inst, 3, 4);
										program.offset = decode(inst, 8, 128);
										program.OPCODE = 1;
										p[time].decode += 0.2;
//										printf("MOVS\n");
										break;

								case 2: // ADDS
										program.OP1 = decode(inst, 3, 4);
										program.offset = decode(inst, 8, 128);
										program.OPCODE = 2;
										p[time].decode += 0.2;
//										printf("ADDS\n");
										break;

								default:
										cout << "Not defined Operation!" << endl;
										break;
						}
						break;

				case 2:
						program.opcode[1] = decode(inst, 3, 4);
						p[time].decode += 0.1;
						switch( program.opcode[1])
						{
								case 0: // CMP
										program.opcode[2] = decode(inst, 4, 8);
										p[time].decode += 0.1;

										switch( program.opcode[2])
										{
												case 10:
														program.OP1 = decode(inst, 3, 4);
														program.OP2 = decode(inst, 3, 4);
														program.OPCODE = 3;
														p[time].decode += 0.2;
//														printf("CMPS\n");
														break;

												default:
														cout << "Not defined Operation!" << endl;
														break;
										}
										break;
								case 1: // ADD
										program.opcode[2] = decode(inst, 2, 2);
										program.offset = decode(inst, 1, 1);
										program.OP1 = decode(inst, 4, 8);
										program.OP2 = decode(inst, 3, 4);
										program.OP2 += (program.offset << 3);
										p[time].decode += 0.4;
										program.OPCODE = 4;
//										printf("ADD\n");
										break;

								default:
										cout << "Not defined Operation!" << endl;
										break;
						}
						break;

				case 3:
						program.opcode[1] = decode(inst, 2, 2);
						p[time].decode += 0.1;

						switch( program.opcode[1])
						{
								case 0: // STR
										program.offset = decode(inst, 5, 16);
										program.OP1 = decode(inst, 3, 4);
										program.OP2 = decode(inst, 3, 4);
										p[time].decode += 0.3;
										program.OPCODE = 5;
//										printf("STR\n");
										break;
								case 1: // LDR
										program.offset = decode(inst, 5, 16);
										program.OP1 = decode(inst, 3, 4);
										program.OP2 = decode(inst, 3, 4);
										p[time].decode += 0.3;
										program.OPCODE = 6;
//										printf("LDR\n");
										break;

								default:
										cout << "Not defined Operation!" << endl;
										break;
						}
						break;

				case 5:
						program.opcode[1] = decode(inst, 6, 32);
						p[time].decode += 0.1;

						switch( program.opcode[1])
						{
								case 33: // SUB
										program.offset = decode(inst, 7, 64);
										p[time].decode += 0.1;
										program.OPCODE = 7;
//										printf("SUB\n");
										break;

								default:
										cout << "Not defined Operation!" << endl;
										break;
						}
						break;

				case 6:
						program.opcode[1] = decode(inst, 5, 16);
						p[time].decode += 0.1;

						switch( program.opcode[1])
						{
								case 28: // BGT
										program.offset = decode(inst, 8, 128);
										p[time].decode += 0.1;
										program.OPCODE = 8;
//										printf("BGT\n");
										break;

								default:
										cout << "Not defined Operation!" << endl;
										break;
						}
						break;

				case 7:
						program.opcode[1] = decode(inst, 2, 2);
						p[time].decode += 0.1;

						switch(program.opcode[1])
						{
								case 0: // B
										program.offset = decode(inst, 11, 1024);
										p[time].decode += 0.1;
										program.OPCODE = 9;
//										printf("B\n");
										break;

								default: 
										cout << "Not defined Operation!" << endl;
										break;
						}
						break;

				default:
						break;
		}

}

void twos_complement(void)
{
		if ( program.OP2 & 128)
		{
				program.OP2 = (~(char)program.OP2 + 1) * (-1);
		}
}

void twos_offset8(void)
{
		if (program.offset & 128)
		{
				program.offset = (~(char)program.offset +1) *(-1);
		}
}

void twos_offset11(void)
{
		if (program.offset & 1024)
		{
				program.offset = (~(program.offset) + 1) *(-1);
		}
}
int b_num = -1;

int run_program(int* freq, int* clks)
{
		int err = 0;
		static int reg[regs] = {0};
		int mode = 1; // mode flag
		int s_mode;
		int command; 
		static int Z = 0;
		static int N = 0;
		int b_num = 0;

#ifdef DIS
				on_chip_debug();
#endif

				switch( program.OPCODE )
				{
						case SUBS:	// SUBS Rd, Rs, #Offset3
								//cout << "SUBS Rd, Rs, Rn\n";
								reg[program.OP2] = reg[program.OP1] - program.offset;
								freq[SUBS]++;
								p[time].execute += 4;
								break;

						case MOVS: 	// MOVS Rd, #Offset8
								//cout << "MOVS Rd, #Offset8\n";
								reg[program.OP1] = program.offset;
								freq[MOVS]++;
								p[time].execute += 4;
								break;

						case ADDS:	// ADDS Rd, #offset
								reg[program.OP1] += program.offset; 
								freq[ADDS]++;
								p[time].execute += 4;
								break;

						case CMP:	// CMP Rd, Rs
								if( (reg[program.OP2] - reg[program.OP1]) < 0)
								{
										Z = 0;
										N = 1;
								}
								else if( (reg[program.OP2] - reg[program.OP1]) >0)
								{
										Z = 0;
										N = 0;
								}
								else if( (reg[program.OP2] - reg[program.OP1]) == 0)
								{
										Z = 1;
										N = 0;
								}
								freq[CMP]++;
								p[time].execute += 4;
								break;

						case ADD:	// ADD Rd, Rm
								reg[ program.OP2 ] += reg[ program.OP1];
								freq[ADD]++;
								p[time].execute += 4;
								break;

						case STR:	// STR Rd, [Rb, #imm]
								memory[ reg[program.OP1] + program.offset ] = reg[ program.OP2];
								freq[STR]++;
								p[time].execute += 10;
								break;

						case LDR:	// LDR Rd, [Rb, #imm]
								reg[program.OP2] = memory[ reg[program.OP1] + program.offset ];
								freq[LDR]++;
								p[time].execute += 10;
								break;

						case SUB:	// SUB sp, #offset
								reg[13] -= program.offset;
								freq[SUB]++;
								p[time].execute += 4;
								break;

						case BGT: // BGT lable
								if(Z == 0 && N == 0)
								{
										twos_offset8();
										freq[BGT]++;
										b_num = program.offset;
										break;
								}
								freq[BGT]++;
								p[time].execute += 12;
								break;

						case B:
								twos_offset11();
								freq[B]++;
								p[time].execute += 12;
								b_num = program.offset;
								break;

						default:
								cout << "Error: Unknown instruction founded" << endl;
								return -1;
				}
		return b_num;
}

void report_profile(int freq[], int clks[])
{
		int total = 0;
		int total_clks = 0;
        double flash_fetch = 0.0, scratch_fetch = 0.0, decode = 0.0, execute = 0.0;

		const char ISA2[10][5] = {
				"SUBS", "MOVS", "ADDS", "CMP", "ADD", "STR", "LDR", "SUB", "BGT", "B"
		};

		cout << "\n========================================================" << endl;

		for( int j=0; j<10; j++)
		{
				cout << "\n"<< ISA2[j] << " : " << freq[j] << " times\n";
		}

		cout << "\n=========================================================" << endl;

		for( int i=0; i<10; i++)
		{
				total += freq[i];
				total_clks += freq[i]*clks[i];
		}
        for( int i=0; i<time; i++)
        {
           flash_fetch += p[i].flash_fetch;
           scratch_fetch += p[i].scratch_fetch;
           decode += p[i].decode;
           execute += p[i].execute;
        }
		cout << "\nTotal instructions are executed " << total << " times\n";
		cout << "\nTotal program execution time: " << total_clks << " clks\n\n";
		cout << "\nFlash fetch power perfermance : "<< flash_fetch << "mV" << endl;
		cout << "\nScratch fetch power perfermance : "<< scratch_fetch << "mV" << endl;
		cout << "\nDecode power performance : " << decode << "mV"<< endl;
		cout << "\nExecute power perfromance : "<< execute << "mV"<<endl;		
		cout << "\n=========================================================" << endl;
}	
void on_chip_debug(void)
{
		const char ISA[10][5] = {
				"SUBS", "MOVS", "ADDS", "CMP", "ADD", "STR", "LDR", "SUB", "BGT", "B"
		};
		cout << ISA[program.OPCODE];
		//	for (int j=0; j<4; j++)
		//	{
		//		cout << ISA[program[pc].OPCODE][j];
		//	}

		switch( program.OPCODE)
		{
				case SUBS:
						cout << " R" << program.OP2 << ", " << "R" << program.OP1 << ", #" << program.offset <<  endl;
						break;

				case MOVS:
						cout << " R" <<  program.OP1 << ", #" << program.offset << endl;
						break;

				case ADDS:
						cout << " R" <<  program.OP1 << ", #" << (program.offset) << endl;
						break;
				case CMP:
						cout << " R" << program.OP2 << ", R" << program.OP1 << endl;
						break;
				case ADD:
						cout << " R" <<  program.OP2 << ", R" << (program.OP1 >> 4) << endl;
						break;
				case STR:
						cout << " R" <<  program.OP2 << ", [R" << program.OP1 << ", #" << program.offset*4 << "]" << endl;
						break;
				case LDR:
						cout << " R" <<  program.OP2 << ", [R" << program.OP1 << ", #" << program.offset*4 << "]" << endl;
						break;
				case SUB:
						cout << " sp, #" << program.offset << endl;
						break;

				case BGT:
						twos_offset11();
						cout << " #" << (program.offset) << endl;
						twos_offset11();
						break;

				case B:
						cout << " #" << program.offset << endl;
						break;

				default:
						cout << " Unrecognized instruction ..." << endl;
						break;
		}
}

int select_mode(void)
{
		char command[10];
		char *tmp1, *tmp2;

		cout << "(HRD) ";
		scanf("%s", command);

		if( strcmp(command, "run") == 0)
				return 1;

		else if( strcmp(command, "quit") == 0)
				return 2;

}

int enter_command(void)	
{
		char command[10];
		char command2[10];
		char yes_no[10];
		int temp;

		scanf("%s", command);

		if( strcmp(command, "si") == 0)
				return 1;

		else if( strcmp(command, "c") == 0)
				return 2;

		else if( command[0] == 'b')
		{
				temp = b_num;
				scanf("%d", &b_num);

				if(temp != -1)
				{
						cout << "Do you want to change BP from " << temp << " to " << b_num <<" (y/n)" << endl;
						scanf("%s", yes_no);

						if( strcmp(yes_no, "n") == 0)
								b_num = temp;
				}
				return 3;
		}
		else if( strcmp(command, "info") == 0 )
		{
				scanf("%s", command2);
				if( strcmp(command2, "register") == 0)
						return 4;
		}
}


void info_register(int *reg)
{
		for( int i=0; i< 16; i++)
				cout << "R" << i << ": " << reg[i] << endl;
}

void clear_register(int *reg)
{
		for( int i=0; i<16; i++)
				reg[i] = 0;
}

void plot_power_performance(int cnt)
{
	FILE *fout1;

	fout1 = fopen("output.txt", "w");

	for( int i=0; i< cnt; i++)
	{
		fprintf(fout1, "%d\t%f\t%f\t%f\t%f\n", i+1, p[i].flash_fetch, p[i].scratch_fetch, p[i].decode, p[i].execute);
	}
	fclose(fout1);
}
