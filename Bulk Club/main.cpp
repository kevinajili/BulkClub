#include "Header.h"

int main()
{
	BulkClub   *list;			// CALC		  - list of members
	purchase   *dayOne;			// CALC 	  - purchase for day
	Basic      *memberPtr;		// CALC & OUT - accesses members from list
	string      name;			// IN & OUT   - name of members
	int         id;				// IN & OUT   - age of members
	bool        found;			// CALC 	  - determines if remove success
	MenuOptions menuChoice;		// CALC 	  - user menu choice
	char		memberType;		// IN         - used to input
	char 		searchOp;       //

	dayOne   = NULL;
	list 	 = NULL;
    list = new BulkClub;

	list     = ReadInFromFile(list);
	dayOne   = ReadInDailyPurchases("day1.txt", dayOne);
	dayOne   = ReadInDailyPurchases("day2.txt", dayOne);
	dayOne   = ReadInDailyPurchases("day3.txt", dayOne);
	dayOne   = ReadInDailyPurchases("day4.txt", dayOne);
	dayOne   = ReadInDailyPurchases("day5.txt", dayOne);


//	FromDailyPurchaseToMember(dayOne,list);

	const string MENU_PROMPT =
				"1 - Add Member \n"
				"2 - Remove Member\n"
				"3 - Find Member\n"
				"4 - List Size\n"
				"5 - Change status\n"
				"6 - Output List\n"
				"7 - Clear List\n"
				"0 - EXIT\n"
				"Enter selection: ";

	cout << "**************************************\n"
			"* WELCOME TO THE BulkClub MANAGER    *\n"
			"**************************************\n";

	// INPUT - gets & error checks menu input
		menuChoice = MenuOptions(ValidateInput(MENU_PROMPT, 0, 7));
		cout << endl;

		//WHILE - exits when menu selection is EXIT
		while(menuChoice != EXIT)
		{
			//IF - user adds to the list of members
			if(menuChoice == ADD)
			{
				memberType = ValidateInput("Which member would you like to add Basic or Preferred (B/P): ", 'B','P');

				// IF - member is 'B' (Basic)
				if (memberType == 'B')
				{
					cout << "Enter your member\'s name: ";
					getline(cin, name);
					id  = ValidateInput("Enter your member\'s ID number:  ", 0, 99999);

					memberPtr = new Basic;
					memberPtr->SetAllValues(name, id);
					list->AddMember(memberPtr);
					cout << endl;
					cout << memberPtr->Display();

				}
				// ELSE - member is 'P' (Preferred)
				else
				{
					cout << "Enter your member\'s name:       ";
					getline(cin, name);
					id  = ValidateInput("Enter your member\'s ID number:  ", 0, 99999);

				}
			}
			// ELSE IF - the list is NOT empty
					else if(list->TotalMembers() > 0)
					{
						//SWITCH - determines necessary processing based on menu selection
						switch(menuChoice)
						{
							case REMOVE :
								cout << "Who would you like to remove? ";
								cin  >> name;
								found = list->RemoveMember(name);
								if(found)
								{
									cout << name << " is no longer a part of the Bulk Club!\n";
								}
								else
								{
									cout << name << " is not a part of the Bulk Club!\n";
								}
								cout << endl;
								break;

							case FIND :
								searchOp = ValidateInput("Find by Name or Id", 'N','I');
								if(searchOp == 'N')
								{
									cout << "Enter the member\'s name: ";
									getline(cin, name);
									memberPtr = list->FindMember(name);
									if(memberPtr != NULL)
									{
										cout << memberPtr->Display();
										cout << name;
									}
									else
									{
										cout << name << " is not a part of the Bulk Club\n\n";
									}
								}

								else
								{
									cout << "Enter the member\'s id: ";
									cin  >> id;
									memberPtr = list->FindMember(id);
									if(memberPtr != NULL)
									{
										cout << memberPtr->Display();
										cout << name;
									}
									else
									{
										cout << name << " is not a part of the Bulk Club\n\n";
									}
								}
								break;
							case CHANGE_STATUS:
								searchOp = ValidateInput("Find by Name or Id", 'N','I');
								if(searchOp == 'N')
								{
									cout << "Enter the member\'s name: ";
									getline(cin, name);
									memberPtr = list->FindMember(name);
									if(memberPtr != NULL)
									{
										cout << memberPtr->Display();
										cout << name;
									}
									else
									{
										cout << name << " is not a part of the Bulk Club\n\n";
									}
								}

								else
								{
									cout << "Enter the member\'s id: ";
									cin  >> id;
									memberPtr = list->FindMember(id);
									if(memberPtr != NULL)
									{
										cout << memberPtr->Display();
										cout << name;
									}
									else
									{
										cout << name << " is not a part of the Bulk Club\n\n";
									}
								}
														break;
							case CHANGE_MMEBEREXDATE:
								searchOp = ValidateInput("Find by Name or Id", 'N','I');
									if(searchOp == 'N')
									{
										cout << "Enter the member\'s name: ";
										getline(cin, name);
										memberPtr = list->FindMember(name);
										if(memberPtr != NULL)
										{
											cout << memberPtr->Display();
											cout << name;
										}
										else
										{
											cout << name << " is not a part of the Bulk Club\n\n";
										}
									}

									else
									{
										cout << "Enter the member\'s id: ";
										cin  >> id;
										memberPtr = list->FindMember(id);
										if(memberPtr != NULL)
										{
											cout << memberPtr->Display();
											cout << name;
										}
										else
										{
											cout << name << " is not a part of the Bulk Club\n\n";
										}
									}
																			break;
							case OUTPUT :
											cout << list->OutputList();
											cout << endl;
											break;

							case CLEAR :
											cout << "Clearing list!\n";
											list->ClearList();
											cout << "List cleared.\n\n";
											break;

							case LIST_SIZE :
								if (list->TotalMembers() == 1)
								{
									cout << "There is one member"
											" a part of BulkClub\n\n";
								}
								else
								{
									cout << "There are " << list->TotalMembers()
										 << " members a part of the BulkClub\n\n";
								}
								break;
						}
					}
			// INPUT - gets & error checks new menu input
					menuChoice = MenuOptions(ValidateInput(MENU_PROMPT, 0, 7));
					cout << endl;
		}
	return 0;
}


