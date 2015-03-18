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
	SEARCH_FOR_EXP_DATE,
	FIND,		// User chooses to change the value of the member
	LIST_SIZE,
	CHANGE_STATUS,
	CHANGE_MMEBEREXDATE,
	OUTPUT,
	OUTPUT_PURCHASES_BYCUSTOMER,
	SEARCH_BY_ITEM_SOLD,
	SEARCH_BY_DATE,
	CLEAR		// User chooses to display attributes to the screen
};

int ValidateInput(const string   INT_PROMPT,   // IN & CALC - Integer prompt 1
		          const int      MIN_NUM,	  // IN & CALC - Minimum integer
		          const int      MAX_NUM);	  // IN & CALC - Maximum integer

char ValidateInput(const string CHAR_PROMPT,  // IN & CALC - Character prompt
		      	   const char   FIRST_CHAR,   // IN & CALC - Valid character
		           const char   SECOND_CHAR);  // IN & CALC - Valid character

void     ReadInDailyPurchases(string date, BulkClub *list);
BulkClub *ReadInFromFile(BulkClub   *list);
string   FromDailyPurchaseToMember(Basic *memberPtr );
string 	 ItemsSortedByName(BulkClub *list);
string   SearchForExpirationDate (int month,BulkClub *list);
string SearchByItemSold(string searchItem, BulkClub *list);
string SearchByDailySales(BulkClub *list, Date searchDate);
#endif /* HEADER_H_ */
