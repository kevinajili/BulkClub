#include "Header.h"
string FromDailyPurchaseToMember(purchase *Day, Basic *memberPtr )
{


	ostringstream output;
	purchase *ptr;
	Date	 purchaseDate;
	string 	 product;

	float dailyPurchaseTot;

	dailyPurchaseTot = 0;


	ptr =Day;

	output << endl;
	output << left;
	output << "Now displaying purchases for: \n";
	output << "Name:       "
		   << memberPtr-> GetName() << endl
		   << "Member ID:  " << memberPtr->GetId();
	output << endl << endl;
	output << setw (20) << "Purchase Date";
	output << setw (20) << "Product";
	output << setw(10)  << "Price";
	output << setw(10)  << "Quantity";
	output << endl;

	output << setfill('-');
	output << setw(14) << '-';
	output << setfill(' ');
	output << setw(6) << ' ';

	output << setfill('-');
	output << setw(8) << '-';
	output << setfill(' ');
	output << setw(12) << ' ';

	output << setfill('-');
	output << setw(5) << '-';
	output << setfill(' ');
	output << setw(5) << ' ';

	output << setfill('-');
	output << setw(9) << '-';
	output << setfill(' ');
	output << setw(1) << ' ';
	output << endl;

	while(ptr != NULL)
	{

		if (memberPtr -> GetId() == ptr->memberId)
		{
			output << setw(20) << ptr->purchaseDate.DisplayDate();
			output << setw(20) << ptr->product;
			output << setw(10) <<  ptr->price;
			output << setw(10) <<  ptr->quantity	<< endl;
			dailyPurchaseTot += 	(ptr->price * ptr->quantity)
							      + ((ptr->price * ptr->quantity) * .0875);

		}

		ptr = ptr->next;

	}
	memberPtr->SetTotalSpent(dailyPurchaseTot);
	output << endl;
	return output.str();
}
