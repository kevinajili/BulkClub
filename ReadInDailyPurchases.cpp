#include "Header.h"
void ReadInDailyPurchases(string date, BulkClub *list)
{
	// Used to manage the information
	purchase *dailyPurchase;
	ifstream iFile;
	Basic	 *member;

	//triggers for comparison statements
	bool 	 validTotal;


	// Reading in other information from the text file
	string 	 product;
	int 	 memberId;
	float    price;
	int 	 quantity;

	// Used for inputing date information
	Date 	 *exDate;
	string   expireDate;
	int 	 month;
	int 	 day;
	int      year;

	// Initialization
	iFile.open(date.c_str());
	dailyPurchase = new purchase;

	//CALC -  Reads through the input File
	while(iFile)
	{
		//Sets member to the top of the list
		member        = list->FirstMember();

		//IN - Reading info into variables from the iFile;
		getline(iFile, expireDate);
		iFile >> memberId;
		iFile.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(iFile, product);
		iFile >> price;
		iFile >> quantity;
		iFile.ignore(numeric_limits<streamsize>::max(), '\n');

		// Creating a date
		month 	= atoi(expireDate.substr(0,2).c_str());
		day  	= atoi(expireDate.substr(3,2).c_str());
		year 	= atoi(expireDate.substr(6,4).c_str());
		exDate  = new Date(month,day,year);

		// struct assignment
		dailyPurchase->purchaseDate = *exDate;
		dailyPurchase->memberId     = memberId;
		dailyPurchase->product	    = product;
		dailyPurchase->price		= price;
		dailyPurchase->quantity	    = quantity;

		// sets the trigger information
		validTotal  = (dailyPurchase->price * dailyPurchase->quantity) <= 200;

	// Goes through the member list
	while(member!= NULL)
		{
			// Only adds to the purchase list if the purchase meets the
			//	requirements
			if(member->GetDate().CompareDate(*exDate)      && validTotal &&
			   member->GetId() == dailyPurchase->memberId)
			{
					// adds the member to the list
					member->AddPurchaseToList(dailyPurchase);
			}
				// Switches the member to the next member
				member = member->GetNext();
		}
			//creates a new instance of a purchase
		dailyPurchase = new purchase;
	}
	iFile.close();
}


