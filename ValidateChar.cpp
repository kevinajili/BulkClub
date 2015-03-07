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
 *
 * FUNCTION ValidateInput
 *_________________________________________________________________________
 * This function receives the prompt for a character entry, the width of
 *   the prompt, and the two valid characters that the user may enter.
 *   Then this program saves the upper-case version of the entry and checks
 *   it against the two valid characters that were received.  It displays
 *   an error message if the character entry was invalid and re-prompts the
 *   user to enter a character. Then this function sends a valid character
 *   back to the calling function.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *   CHAR_PROMPT	: The string indicating the type of character
 *   				  acceptable has to be previously defined
 *   PROMPT_WIDTH	: The prompt width has to be previously defined
 *   FIRST_CHAR		: First of two acceptable character inputs has to be
 *   				  previously defined
 *   MAX_NUM		: Second of two acceptable character inputs has to be
 *   				  previously defined
 * ________________________________________________________________________
 * POST-CONDITIONS
 *   This function returns a validated character input by value back to the
 *   calling function.
 *************************************************************************/

char ValidateInput(const string CHAR_PROMPT,  // IN & CALC - Character prompt
		      	   const char   FIRST_CHAR,   // IN & CALC - Valid character
		           const char   SECOND_CHAR)  // IN & CALC - Valid character
{
	ostringstream output;		 // CALC 		    - Temporary string
								 //					  stream for formatting
								 //					  prior to output
	string        getCharString; // OUT  		    - Formatted string to
								 //					  be output to screen
	char		  charInput;	 // IN, CALC, & OUT - Integer input
	bool 		  valid;		 // CALC			- True if input is a
								 //					  valid character

	// INITIALIZATION
	valid = false;

	/**********************************************************************
	 * INPUT & PROCESSING - DO-WHILE Loop - Gets character input and loops
	 * if upper-case input is not FIRST_CHAR or SECOND_CHAR.
	 *********************************************************************/
	do
	{
		// PROCESSING & OUTPUT - Formats screen prompt in temporary stream
		cout << CHAR_PROMPT;

		// INPUT - Gets character input and clears input buffer
		cin.get(charInput);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// INPUT - Converts character input to upper-case
		charInput = toupper(charInput);

		/******************************************************************
		 * INPUT, PROCESSING, & OUTPUT - IF-THEN-ELSE - If upper-case input
		 * is not either FIRST_CHAR or SECOND_CHAR, prompts user to enter a
		 * valid character.  If input is valid, sets valid to true, which
		 * allows the program to exit the DO-WHILE loop.
		 *****************************************************************/
		if(charInput != FIRST_CHAR && charInput != SECOND_CHAR)
		{
			cout << "\n**** " << charInput << " is an invalid entry ****\n"
				 << "**** Please input " << FIRST_CHAR
				 << " or " 				   << SECOND_CHAR
				 << "   ****\n\n";

			valid = false;
		} // END if(charInput != FIRST_CHAR && charInput != SECOND_CHAR)
		else
		{
			valid = true;
		} // END else

	}while(!valid);

	// OUTPUT - Returns validated character input to calling function
	return charInput;
}
