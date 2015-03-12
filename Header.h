#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <fstream>
#include <string.h>
#include <limits>
#include <stdlib.h>
#include "BulkClub.h"
#include "Preferred.h"
enum MenuOptions
{
	EXIT,		// User chooses to exit the program
	ADD,		// User chooses to initialize values for an member
	REMOVE, 	// User chooses to change the age of the member
	FIND,		// User chooses to change the value of the member
	LIST_SIZE,
	CHANGE_STATUS,
	FIRST_MEMBER,
	CHANGE_MMEBEREXDATE,
	OUTPUT,
	OUTPUT_PURCHASES_BYCUSTOMER,
	CLEAR		// User chooses to display attributes to the screen
};

int ValidateInput(const string   INT_PROMPT,   // IN & CALC - Integer prompt 1
		          const int      MIN_NUM,	  // IN & CALC - Minimum integer
		          const int      MAX_NUM);	  // IN & CALC - Maximum integer

char ValidateInput(const string CHAR_PROMPT,  // IN & CALC - Character prompt
		      	   const char   FIRST_CHAR,   // IN & CALC - Valid character
		           const char   SECOND_CHAR);  // IN & CALC - Valid character

purchase *ReadInDailyPurchases(string date, purchase *head);

BulkClub *ReadInFromFile(BulkClub   *list);
string FromDailyPurchaseToMember(purchase *Day, Basic *memberPtr );
void PurchaseInfoToMember(purchase *Day, BulkClub *list);
#endif /* HEADER_H_ */
