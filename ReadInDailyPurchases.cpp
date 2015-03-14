#include "Header.h"
void ReadInDailyPurchases(string date, BulkClub *list)
{
	purchase *dailyPurchase;
	ifstream iFile;
	Basic	 *member;
	bool 	 validQuanity;
	bool 	 validTotal;
	bool	 validPurchase;
	Date 	 *exDate;
	string   expireDate;
	string 	 product;
	int 	 memberId;
	float    price;
	int 	 quantity;
	int 	 month;
	int 	 day;
	int      year;

	// Initialization
	iFile.open(date.c_str());
	dailyPurchase = new purchase;


	//CALC - from file to linked list
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



		validTotal  = (dailyPurchase->price * dailyPurchase->quantity) <= 200;
	while(member!= NULL)
		{


		if(member->GetDate().CompareDate(*exDate) && validTotal && member->GetId() == dailyPurchase->memberId)
		{
				member->AddPurchaseToList(dailyPurchase);

		}
			member = member->GetNext();

		}
		dailyPurchase = new purchase;


	}

	iFile.close();




}


