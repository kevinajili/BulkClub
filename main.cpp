#include "Header.h"

int main()
{
	BulkClub   *list;			// CALC		  - list of members
	Basic      *memberPtr;		// CALC & OUT - accesses members from list
	Preferred  *memberPtrP;
	string      name;			// IN & OUT   - name of members
	int         id;				// IN & OUT   - age of members
	int 	    monthSearch;
	int 		month;
	int 		day;
	int			year;
	bool        found;			// CALC 	  - determines if remove success
	MenuOptions menuChoice;		// CALC 	  - user menu choice
	char		memberType;		// IN         - used to input
	char 		searchOp;       //
	Date		newXDate;		//IN & CALC   - used to change member expiration date
	string	    searchItem;		//IN & CALC   - used to search for item sold
	list 	 = NULL;
    list     = new BulkClub;

	 list  = ReadInFromFile(list);
	 ReadInDailyPurchases("day1.txt", list);
	 ReadInDailyPurchases("day2.txt",  list);
	 ReadInDailyPurchases("day3.txt",  list);
	 ReadInDailyPurchases("day4.txt",  list);
	 ReadInDailyPurchases("day5.txt",  list);

	const string MENU_PROMPT =	"Bulk Club Menu\n"
								"1  - Add Member \n"
								"2  - Remove Member\n"
								"3  - Search for member expiration Date\n"
								"4  - Find Member\n"
								"5  - List Size\n"
								"6  - Change status\n"
								"7  - Member expiration date\n"
								"8  - Output List\n"
								"9  - View a customers purchase history\n"
								"10 - Search By Item\n"
								"11 - Search purchase by Date\n"
								"12 - Clear List\n"
								"0  - EXIT\n"
								"Enter selection: ";



	    cout << "**************************************\n"
		      	"* WELCOME TO THE BulkClub MANAGER    *\n"
			    "**************************************\n";

		// INPUT - gets & error checks menu input
		menuChoice = MenuOptions(ValidateInput(MENU_PROMPT, 0, 12));
		cout << endl;

		//WHILE - exits when menu selection is EXIT
		while(menuChoice != EXIT)
		{
			//SWITCH - determines necessary processing based on menu selection
			switch(menuChoice)
			{
			case ADD:
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

							newXDate.AutoSetDate();
							memberPtr = new Preferred(name,id,"Preferred",newXDate,0.0,.06);

							cout << endl;
							cout << memberPtr->Display();
							list->AddMember(memberPtr);
						}
						break;
				case REMOVE :
					cout << "Who would you like to remove? ";
					getline(cin, name);
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
				case SEARCH_FOR_EXP_DATE:
					cout << "Enter in a two digit month to search with: ";
					cin  >> monthSearch;

					cout << SearchForExpirationDate(monthSearch,list);
					cout << endl << endl;
							break;
				case FIND :
					searchOp = ValidateInput("Find by Name or Id:      ", 'N','I');
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
						cout << "Enter the member\'s id:   ";
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
					searchOp = ValidateInput("Find by Name or Id:   ", 'N','I');
						if(searchOp == 'N')
						{
							cout << setw(32) <<"Enter the member\'s name:";
							getline(cin, name);
							memberPtr = list->FindMember(name);
							if(memberPtr != NULL)
							{

								memberPtr->ChangeExpireDate();
								cout << "The member expiration date for "
									 << memberPtr->GetName()   <<    " is now  "
									 << memberPtr->GetDate().DisplayDate();
								cout << endl<< endl<< endl;

							}
							else
							{
								cout << name << " is not a part of the Bulk Club\n\n";
							}
						}

						else
						{
							cout << left;
							cout << setw(32) << "Enter the member\'s id:";
							cin  >> id;
							memberPtr = list->FindMember(id);
							if(memberPtr != NULL)
							{
								memberPtr->ChangeExpireDate();
								cout << "The member expiration date for "
									 << memberPtr->GetName()   <<    " is now  "
									 << memberPtr->GetDate().DisplayDate();
								cout << endl<< endl<< endl;
							}
							else
							{
								cout << id << " is not a part of the Bulk Club\n\n";
							}

						}
								break;
				case OUTPUT :
								cout << "Bulk Club Members:\n";
					            cout << list->OutputList();
								cout << endl;
								break;
				case OUTPUT_PURCHASES_BYCUSTOMER:
							searchOp = ValidateInput("Find by Name or Id:      ", 'N','I');
							if(searchOp == 'N')
							{
								cout << "Enter the member\'s name: ";
								getline(cin, name);
								memberPtr = list->FindMember(name);
								if(memberPtr != NULL)
								{
									cout << FromDailyPurchaseToMember(memberPtr);
								}
								else
								{
									cout << name << " is not a part of the Bulk Club\n\n";
								}
							}

							else
							{
								cout << "Enter the member\'s id:   ";
								cin  >> id;
								memberPtr = list->FindMember(id);
								if(memberPtr != NULL)
								{
									cout << FromDailyPurchaseToMember(memberPtr);
								}
								else
								{
									cout << id << " is not a part of the Bulk Club\n\n";
								}
							}
							break;
				case CLEAR :
								cout << "Clearing list!\n";
								list->ClearList();
								cout << "List cleared.\n\n";
								break;

				case SEARCH_BY_ITEM_SOLD:
								cout << "Search By item sold: ";
								getline(cin, searchItem);
								cout << SearchByItemSold(searchItem, list);
								cout << endl << endl;
								break;
				case SEARCH_BY_DATE:
								cout <<"Enter the month (MM formating): ";
								cin  >> month;
								cout << "Enter the day  (DD formating): ";
								cin  >> day;
								cout << "Enter the year (YYYY formating):  ";
								cin  >> year;
								cout << endl << endl;
								newXDate.SetDate(month, day, year);
								cout << SearchByDailySales(list,newXDate);
								break;
				case EXIT:
							cout << "loop error";
							break;
			}

			// INPUT - gets & error checks new menu input
					menuChoice = MenuOptions(ValidateInput(MENU_PROMPT, 0, 12));
					cout << endl;

		}
	return 0;
}


