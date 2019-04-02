#include <iostream>
#include <fstream>
#include <cstdlib>

#include "CCode.h"
#include "CDecode.h"
#include "CExecute.h"
#include "CRegister.h"

using namespace std;

int main( int argc, char *argv[])
{
	if(argc != 3)
	{
		cout << "tpu <input file><line>\n";
		return -1;
	}
	CFlash1KWord code_memory(argv[1], atoi(argv[2]));

	for( int i=0; i<atoi(argv[2]); i++)
	{
		cout << code_memory.code_at(i) << endl;
	}

	CT1DecodeDirectFetch decode(code_memory);
    C16RegisterFile regs;
    CT1ExecuteTinyUnit execute( decode, regs);

	for( int i=0; i<atoi(argv[2]); i++)
	{
        decode.do_fetch_from(i);
		decode.do_decode();
        decode.show_instruction();

        execute.do_execute();
	}
    cout << "After executing instruction ... " << endl;
    regs.show_regs();
}

