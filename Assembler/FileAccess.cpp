//
//  Implementation of file access class.
//
#include "stdafx.h"
#include "FileAccess.h"

/**/
/*
FileAccess::FileAccess(int argc, char *argv[])

NAME

	FileAccess::FileAccess(int argc, char *argv[]) - Initiates the access to the given file name

SYNOPSIS

	FileAccess::FileAccess(int argc, char *argv[])
	argc		-->			Total number of arguments
	argv		-->			Array of the characters entered by the user

DESCRIPTION
	
	This function is the constructor for FileAccess class that will help to open the file.

RETURNS

	VOID

AUTHOR

	Sujil Maharjan

DATE

	5:28 PM 12/22/2015

*/
/**/
FileAccess::FileAccess(int argc, char *argv[])
{
	// Check that there is exactly one run time parameter.
	if (argc != 2) {
		cerr << "Usage: Assem <FileName>" << endl;
		exit(1);
	}
	// Open the file.  One might question if this is the best place to open the file.
	// One might also question whether we need a file access class.
	m_sfile.open(argv[1], ios::in);
	cout << argv[1];
	// If the open failed, report the error and terminate.
	if (!m_sfile) {
		cerr << "Source file could not be opened, assembler terminated."
			<< endl;
		exit(1);
	}
} /* FileAccess::FileAccess(int argc, char *argv[]) */

/**/
/*
FileAccess::~FileAccess()

NAME

	FileAccess::~FileAccess() - Closes the open file

SYNOPSIS

	FileAccess::~FileAccess()

DESCRIPTION

	This function is the destructor of the File

RETURNS

	VOID

AUTHOR

	Sujil Maharjan

DATE

5:28 PM 12/22/2015

*/
/**/
FileAccess::~FileAccess()
{
	m_sfile.close();
} /* FileAccess::~FileAccess() */

/**/
/*
bool FileAccess::GetNextLine(string &a_buff)

NAME

	FileAccess::GetNextLine(string &a_buff) - Gets the next line from the file

SYNOPSIS

	bool FileAccess::GetNextLine(string &a_buff)
	a_buff		-->			Contains the string of the line. It is returned as reference

DESCRIPTION

	This function reads the next line from the open file if there exists a next line

RETURNS

	Returns true if successfully got the next line, false if next line doesn't exit

AUTHOR

	Sujil Maharjan

DATE

	5:28 PM 12/22/2015

*/
/**/
bool FileAccess::GetNextLine(string &a_buff)
{
	if (m_sfile.eof()) return false;

	getline(m_sfile, a_buff);

	// Return indicating success.
	return true;
} /* bool FileAccess::GetNextLine(string &a_buff) */

/**/
/*
void FileAccess::rewind()

NAME

	FileAccess::rewind() - It rewinds the pointer to beginnning of the file

SYNOPSIS

	void FileAccess::rewind()

DESCRIPTION

	This function rewinds the pointer to the beginning of the file

RETURNS

	VOID

AUTHOR

	Sujil Maharjan

DATE

	5:28 PM 12/22/2015

*/
/**/
void FileAccess::rewind()
{
	// Clean the end of file flag and go back to the beginning of the file.
	m_sfile.clear();
	m_sfile.seekg(0, ios::beg);
} /* void FileAccess::rewind() */

