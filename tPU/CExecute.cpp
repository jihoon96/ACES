#include "CExecute.h"

bool CT1ExecuteTinyUnit::do_execute()
{
	// ex. MOV3 R1, #2
	if( m_decode_unit.get_opcode() == MOV3)
	{
		unsigned int reg_index = m_decode_unit.get_op1();
				 int 	  data = m_decode_unit.get_op2(); 
				 
				 // write into register
				 m_regs.write_on_reg( reg_index, data);
				 return true;
	}
	else
	{
			cout << "Not executable instruction. not yet implemented sorry...!!" << endl;
			return false;
	}
	
	return true;
}

