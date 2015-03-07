#include "Header.h"
purchase *ReadInDailyPurchases(string date, purchase *head)
{
	purchase dailyPurchase;
	purchase *newNode;
	ifstream iFile;
	Date 	 *exDate;
	string   expireDate;
	string 	 product;
	int 	 memberId;
	int 	 month;
	int 	 day;
	int      year;
	int      price;
	int 	 quantity;

	// Initialization
	iFile.open(date.c_str());
	newNode = NULL;

	//CALC - from file to linked list
	while(!iFile.eof())
	{
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
		year 	= atoi(expireDate.substr(6,9).c_str());
		exDate  = new Date(month,day,year);

		// struct assignment
		dailyPurchase.purchaseDate = exDate;
		dailyPurchase.memberId     = memberId;
		dailyPurchase.product	   = product;
		dailyPurchase.price		   = price;
		dailyPurchase.quantity	   = quantity;

		// creating a new node for more info
		newNode->next = head;
		head 		  = newNode;
	}

	//deallocation of memory
	exDate  = NULL;
	newNode = NULL;
	delete newNode;
	delete exDate;

	return head;
}


