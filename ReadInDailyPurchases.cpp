#include "Header.h"
purchase *ReadInDailyPurchases(string date, purchase *head)
{
	purchase *dailyPurchase;
	purchase *pointer;
	ifstream iFile;
	Date 	 exDate;
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
		//IN - Reading info into variables from the iFile;
		getline(iFile, expireDate);
		iFile >> memberId;
		iFile.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(iFile, product);
		iFile >> price;
		iFile >> quantity;
		iFile.ignore(numeric_limits<streamsize>::max(), '\n');

		// Creating a date from file (01/01/2015 format)
		month 	= atoi(expireDate.substr(0,2).c_str());
		day  	= atoi(expireDate.substr(3,2).c_str());
		year 	= atoi(expireDate.substr(6,4).c_str());

		exDate.SetDate(month,day,year);


		// struct assignment
		dailyPurchase->purchaseDate = *exDate;
		dailyPurchase->memberId     = memberId;
		dailyPurchase->product	    = product;
		dailyPurchase->price		= price;
		dailyPurchase->quantity	   = quantity;


		// creating a new node for more info
		dailyPurchase->next = head;
		head 	            = dailyPurchase;

		dailyPurchase = new purchase;

	}

	delete dailyPurchase;

	iFile.close();



	return head;
}


