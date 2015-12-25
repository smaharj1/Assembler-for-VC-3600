#include "stdafx.h"
#include "Instruction.h"
#include <string>


/**/
/*
Instruction::Instruction()

NAME

	Instruction::Instruction() - Initiates the instruction class constructor

SYNOPSIS

	Instruction::Instruction()

DESCRIPTION

	This function is the constructor for Instruction class

RETURNS

	VOID

AUTHOR

	Sujil Maharjan

DATE

	5:28 PM 12/22/2015

*/
/**/
Instruction::Instruction() {
	MACHINE_OPCODE = { "add", "sub", "mult", "div", "load", "store", "read", "write", "b", "bm", "bz", "bp", "halt" };
	ASSEMBLY_OPCODE = { "org", "dc", "ds", "end" };
	m_IsNumericOperand = true;
	
} /* Instruction::Instruction() */

/**/
/*
Instruction::InstructionType Instruction::ParseInstruction(string &a_buff)

NAME

	Instruction::ParseInstruction(string &a_buff) - It parsees the given string and stores the values of it locally in different variables

SYNOPSIS

	Instruction::InstructionType Instruction::ParseInstruction(string &a_buff)
	a_buff		-->			The string that contains one line of statement

DESCRIPTION

	This function parses the given string and separates the opcode, operand and label

RETURNS

	Returns the instruction type of the given string (if it is assembler or machine instruction)

AUTHOR

	Sujil Maharjan

DATE

	5:28 PM 12/22/2015

*/
/**/
Instruction::InstructionType Instruction::ParseInstruction(string &a_buff) {
	bool hasComment = false;
	clearValues();

	// first save the given string instruction
	m_instruction = a_buff;

	istringstream input(a_buff);
	string ibuff;
	int count = 0;

	input >> ibuff;

	// Handles the empty line
	if (ibuff.empty()) return ST_None;

	// IF there is a comment at the beginning, it means the instruction is just the comment
	if (ibuff.at(0) == ';') return ST_Comment;

	// Start the count and start the loop to fill in the values 
	while(ibuff != ""){

		int findComment = ibuff.find(';');
		// if the first of the string is comment, break the loop since we don't need it anymore
		if ( findComment >= 0) {
			hasComment = true;
			
			if (ibuff.at(0) == ';') break;

			ibuff = ibuff.substr(0, ibuff.find(';'));
		}

		switch(count) {
			case 0:
				m_Label = ibuff;
				break;
			case 1:
				m_OpCode = ibuff;
				break;
			case 2:
				m_Operand = ibuff;
				break;
		}
		
		// Read the next element into ibuff.
		ibuff = "";

		input >> ibuff;
		count++;

		if (hasComment) break;
	}

	// Now correct the places according to the count
	if (count == 2) {
		// only contains two words in the string.
		// So, check if the current OpCode is actually OpCode. If not, it means we don't have any label 
		if (find(MACHINE_OPCODE.begin(), MACHINE_OPCODE.end(), m_OpCode) == MACHINE_OPCODE.end()) {
			if (find(ASSEMBLY_OPCODE.begin(), ASSEMBLY_OPCODE.end(), m_OpCode) == ASSEMBLY_OPCODE.end()) {
				m_Operand = m_OpCode;
				m_OpCode = m_Label;
				m_Label = "";
			}
		}
	}
	else if (count == 1) {
		m_OpCode = m_Label;
		m_Label = "";
	}

	// convert the OpCode to lower case
	for (int i = 0; i < m_OpCode.length(); ++i) {
		m_OpCode[i] = tolower(m_OpCode[i]);
	}

	// Compute the instruction type of the opcode
	if (find(MACHINE_OPCODE.begin(), MACHINE_OPCODE.end(), m_OpCode) != MACHINE_OPCODE.end()) {
		m_type = ST_MachineLanguage;
		m_NumOpCode = distance(MACHINE_OPCODE.begin(), find(MACHINE_OPCODE.begin(), MACHINE_OPCODE.end(), m_OpCode)) + 1;
	}
	else if (m_OpCode == "end") {
		m_type = ST_End;
	}
	else if (find(ASSEMBLY_OPCODE.begin(), ASSEMBLY_OPCODE.end(), m_OpCode) != ASSEMBLY_OPCODE.end()) {
		m_type =  ST_AssemblerInstr;
	}
	else {
		m_type =  ST_ILLEGAL;
	}

	// Try to check if the Operand is a numeric value and store it if it is true.
	try {
		m_OperandValue = stoi(m_Operand);
	}
	catch (invalid_argument&) {
		m_IsNumericOperand = false;
	}
		
	// Compare it with the OpCode and return what type of instruction it is
	return m_type;
} /* Instruction::InstructionType Instruction::ParseInstruction(string &a_buff) */

/**/
/*
int Instruction::LocationNextInstruction(int a_loc)

NAME

	Instruction::LocationNextInstruction(int a_loc) - Computes the location of the next instruction

SYNOPSIS

	int Instruction::LocationNextInstruction(int a_loc)
	a_loc		-->			The current location that helps in determining next location

DESCRIPTION

	This function determines the next location of the instruction based on the current location and the instruction

RETURNS

	Returns the location of the next instruction

AUTHOR

	Sujil Maharjan

DATE

	5:28 PM 12/22/2015

*/
/**/
int Instruction::LocationNextInstruction(int a_loc) {
	if (m_OpCode == "org" || m_OpCode == "ds") return a_loc + m_OperandValue;
	
	return ++a_loc;
} /* int Instruction::LocationNextInstruction(int a_loc) */

/**/
/*
void Instruction::clearValues()

NAME

	Instruction::clearValues() - Clears all of the values of the class variables

SYNOPSIS

	void Instruction::clearValues()

DESCRIPTION

	This function clears the values of all of the class variables and sets it to empty

RETURNS

	VOID

AUTHOR

	Sujil Maharjan

DATE

	5:28 PM 12/22/2015

*/
/**/
void Instruction::clearValues() {
	m_Label = "";
	m_OpCode = "";
	m_Operand = "";
	m_instruction = "";
	m_OperandValue = 999999;
	m_NumOpCode = 0;
	m_IsNumericOperand = true;
} /* void Instruction::clearValues() */