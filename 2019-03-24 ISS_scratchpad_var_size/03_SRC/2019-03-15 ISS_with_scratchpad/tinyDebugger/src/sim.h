
#ifndef SIM
#define SIM


using namespace std;

#include <iostream>
#define LINE_NUM 1000
#define PAD_SIZE 20

enum {SUBS, MOVS, ADDS, CMP, ADD, STR, LDR, SUB, BGT, B}; 

typedef struct {
	int OPCODE;
	int opcode[3];
	int offset;
	int OP1;
	int OP2;
}instruction;

typedef struct{
		float flash_fetch;
		float scratch_fetch;
		float decode;
		float execute;
}power;

typedef struct{
		int pc;
		char inst[17];
}PAD;

int time = 0; // var for ploting time axis
static const unsigned int prog_size = 1024;
static const unsigned int mem_size = 256;
static const unsigned int regs = 16;

// memory
instruction program;
power p[LINE_NUM];

int memory[mem_size] = {0};

// function decleration
int decode(ifstream&, int, int);
int run_program(int*, int*);
void on_chip_debug( void);
void report_profile(int[], int[]);
void flash_fetch( FILE*, PAD*, int);
int scratch_fetch( PAD*, char*, int);
void decode_2(char *inst);
void plot_power_performance(int cnt);
#endif
