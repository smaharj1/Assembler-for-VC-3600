//
// Class to manage error reporting. Note: all members are static so we can access them anywhere.
// What other choices do we have to accomplish the same thing?
//
#ifndef _ERRORS_H
#define _ERRORS_H

#include <string>
#include <vector>

using namespace std;

class Errors {

public:

	// Initializes error reports.
	static void InitErrorReporting();

	// Records an error message.
	static void RecordError(const string &a_emsg);

	// Displays the collected error message.
	static void DisplayErrors();

	static bool isEmpty();

private:

	static vector<string> m_ErrorMsgs;
};
#endif
