#include "Header.h"
string FromDailyPurchaseToMember(Basic *memberPtr )
{
	ostringstream output;
	purchase 	  *ptr;
	Date	 	  purchaseDate;
	string 	 	  product;
	float 	 	  dailyPurchaseTot;

	output << endl;
	output << left;
	output << "Now displaying purchases for: \n";
	output << "Name:       "
		   << memberPtr-> GetName() << endl
		   << "Member ID:  " << memberPtr->GetId();
	output << endl << endl;
	output << setw (20) << "Purchase Date";
	output << setw (40) << "Product";
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
	output << setw(32) << ' ';

	output << setfill('-');
	output << setw(5) << '-';
	output << setfill(' ');
	output << setw(5) << ' ';

	output << setfill('-');
	output << setw(9) << '-';
	output << setfill(' ');
	output << setw(1) << ' ';
	output << endl;


	output << memberPtr->outputPurchaseDisplay();
	output << endl;
	output << left;
	output << setw(35) << "Total amount spent with tax: ";
	output << right;
	output << fixed    << setprecision(2) << memberPtr->GetTotalPurchase();
	output << endl << endl;
	return output.str();
}
