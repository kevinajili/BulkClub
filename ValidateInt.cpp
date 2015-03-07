/*********************************************************
 * AUTHOR     : DOOMBRINGER & Mike
 * STUDENT ID : 240887      & 289934
 * Lab 14     : Polymorphism - Overriding
 * CLASS      : CS1B
 * SECTION    : TTH 8:00 - 1150AM
 * DUE DATE   : 12/2/14
 **********************************************************/

#include "header.h"

/**************************************************************************
 * FUNCTION ValidateInput
 *_________________________________________________________________________
 * This function receives a prompt and width to get an integer from the
 *   user via the console screen.  This function also receives a minimum
 *   and maximum number allowed, as well as a word describing the type of
 *   integer being requested.  Then this function gets an integer from the
 *   user, checks if it is a number and within the specified lower and
 *   upper bounds.  This process repeats until the input is valid.  Then
 *   this function returns the input to the calling function.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *   INT_PROMPT		: The string indicating the type of integer acceptable
 *   				  has to be previously defined
 *   MIN_NUM		: The minimum acceptable integer input has to be
 *   				  previously defined
 *   MAX_NUM		: The maximum acceptable integer input has to be
 *   				  previously defined
 * ________________________________________________________________________
 * POST-CONDITIONS
 *   This function gets a valid integer from the user via the console.
 *************************************************************************/

int ValidateInput(const string   INT_PROMPT,   // IN & CALC - Integer prompt 1
		          const int      MIN_NUM,	  // IN & CALC - Minimum integer
		          const int      MAX_NUM)	  // IN & CALC - Maximum integer

{
	long long int intInput;     // IN, CALC, & OUT - Integer input
	bool		  invalid;	    // CALC		       - True if invalid input
	ostringstream tempOutput;	// CALC		       - Output string stream
	string  	  errorString1; // CALC & OUT 	   - Error output string 1
	string  	  errorString2; // CALC & OUT 	   - Error output string 2
	int     	  error1StrLen; // CALC		  	   - Length of tempString
	int    	      error2StrLen;	// CALC		  	   - Length of integer
	int			  colWidth;		// CALC		       - Error message width

	// INITIALIZATION
	invalid = true;

	/**********************************************************************
	 * INPUT - DO-WHILE Loop - Displays queue operation command menu and
	 * prompts user for menu selection until an entry between 0 and 6 has
	 * been entered.
	 *********************************************************************/
	do
	{
		// OUTPUT - Displays stack operation command menu on the screen
		cout << INT_PROMPT;

		/******************************************************************
		 * PROCESSING & OUTPUT - IF-THEN-ELSE-IF - First checks if input
		 * is a number.  Then checks if the input is in range.  If both
		 * conditions are valid, sets the loop control variable invalid to
		 * false, which stores the input and allows the program to exit the
		 * DO-WHILE loop.
		 *****************************************************************/
		if(!(cin >> intInput))
		{
			cout << "\n**** Please input a NUMBER between "
				 << MIN_NUM << " and " << MAX_NUM << " ****\n\n";

			// PROCESSING - Clears fail state
			cin.clear();

			// PROCESSING - Sets invalid to true so menu prompt outputs
			invalid = true;
		} // END if(!(cin >> intCommandF))
		else if(intInput < MIN_NUM || intInput > MAX_NUM)
		{

			// PROCESSING - Formats "invalid" message to temporary stream
			tempOutput << "**** The number " << intInput
				       << " is an invalid entry ";

			/**************************************************************
			 * PROCESSING - Assigns formatted prompt for "invalid" message
			 * to string and clears the temporary stream.
			 *************************************************************/
			errorString1 = tempOutput.str();
			tempOutput.str("");

			// PROCESSING - Counts characters in "invalid" error message
			error1StrLen = errorString1.size();

			// PROCESSING - Formats "in-range" message to temporary stream
			tempOutput << "**** Please input a number between " << MIN_NUM
			           << " and " 								<< MAX_NUM
			           << " ";

			/**************************************************************
			 * PROCESSING - Assigns formatted prompt for "in-range" message
			 * to string and clears the temporary stream.
			 *************************************************************/
			errorString2 = tempOutput.str();
			tempOutput.str("");

			// PROCESSING - Counts characters in "in-range" error message
			error2StrLen = errorString2.size();

			/**************************************************************
			 * PROCESSING - IF-THEN-ELSE - Sets the error message widths
			 * for both "invalid" and "in-range" messages to the longer
			 * message.
			 *************************************************************/
			if(error1StrLen > error2StrLen)
			{
				colWidth = error1StrLen;
			}
			else
			{
				colWidth = error2StrLen;
			} // END if(error1StrLen > error2StrLen)

			// OUTPUT - Prints both messages in an aligned format
			cout << left;
			cout << endl << setw(colWidth) << errorString1 << "****\n";
			cout << setw(colWidth) << errorString2 << "****\n\n";
			cout << right;

			// PROCESSING - Sets invalid to true so menu prompt outputs
			invalid = true;
		} // END else if(intInput < MIN_NUM || intInput > MAX_NUM)
		else
		{
			invalid = false;
		} // END else

		// PROCESSING - Clears input buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	while(invalid);

	// OUTPUT - Returns valid integer back to calling function
	return intInput;
}

