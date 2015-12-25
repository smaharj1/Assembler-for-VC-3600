#include "stdafx.h"
#include "Errors.h"

vector<string> Errors::m_ErrorMsgs;

/**/
/*
void Errors::InitErrorReporting()

NAME

	Errors::InitErrorReporting() - Initializes error reporting

SYNOPSIS

	void Errors::InitErrorReporting()

DESCRIPTION

	This function initialises error reporting

RETURNS

	VOID

AUTHOR

	Sujil Maharjan

DATE

	5:28 PM 12/22/2015

*/
/**/
void Errors::InitErrorReporting() {
	m_ErrorMsgs.erase(m_ErrorMsgs.begin(), m_ErrorMsgs.end());
}/* void Errors::InitErrorReporting() */

/**/
/*
void Errors::RecordError(const string &a_emsg)

NAME

	Errors::RecordError(const string &a_emsg) - Records the error as string

SYNOPSIS

	void Errors::RecordError(const string &a_emsg)
	a_emsg		-->			Contains the error message as string

DESCRIPTION

	This function records the given error passed through string and stores it in the error vector.

RETURNS

	VOID

AUTHOR

	Sujil Maharjan

DATE

	5:28 PM 12/22/2015

*/
/**/
void Errors::RecordError(const string &a_emsg) {
	m_ErrorMsgs.push_back(a_emsg);
}/* void Errors::RecordError(const string &a_emsg)*/

/**/
/*
void Errors::DisplayErrors()

NAME

	void Errors::DisplayErrors() - Constructor of the assembler that takes in the file name as its arguments

SYNOPSIS

	void Errors::DisplayErrors()

DESCRIPTION

	This function prints out all of the errors that existed after translating the code

RETURNS

	VOID

AUTHOR

	Sujil Maharjan

DATE

	5:28 PM 12/22/2015

*/
/**/
void Errors::DisplayErrors() {
	for (int i = 0; i < m_ErrorMsgs.size(); ++i) {
		cout << m_ErrorMsgs[i] << endl;
	}
}/* void Errors::DisplayErrors()*/

/**/
/*
bool Errors::isEmpty()

NAME

	Errors::isEmpty() - Checks if there are any errors

SYNOPSIS

	bool Errors::isEmpty()

DESCRIPTION

	This function checks if there are any errors during the translation by checking the vector holding error messages

RETURNS

	Retursn true if the error message vector is empty, false otherwise.

AUTHOR

	Sujil Maharjan

DATE

	5:28 PM 12/22/2015

*/
/**/
bool Errors::isEmpty() {
	return m_ErrorMsgs.empty();
} /* bool Errors::isEmpty()*/