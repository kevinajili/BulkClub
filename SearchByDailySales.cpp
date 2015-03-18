#include "Header.h"

string SearchByDailySales(BulkClub *list, Date searchDate)
{
	Basic    *member;
	purchase *sortedPurchases;
	ostringstream output;
	int 		  basicCount;
	int 		  preferredCount;
	bool		  found;
	basicCount 	   = 0;
	preferredCount = 0;
	found = false;

	output << "Purchases for the date " << searchDate.DisplayDate() << " include:";
	output << endl << endl;
	output << left;
	output << setw(30)  << "Purchaser\'s Name";
	output << setw(40)  << "Product";
	output << setw(10)  << "Price";
	output << setw(10)  << "Quantity";
	output << endl;


	output << setfill('-');
	output << setw(15) << '-';
	output << setfill(' ');
	output << setw(15) << ' ';


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

	member = list->FirstMember();
	while (member!=NULL)
	{
		found = false;
		sortedPurchases = member->GetPurchaseHead();
		while(sortedPurchases != NULL)
		{
			if(sortedPurchases->purchaseDate.DisplayDate() == searchDate.DisplayDate())
			{
				found = true;
				output << setw(30) << member->GetName();
				output << setw(40) << sortedPurchases->product;
				output << setw(10) << sortedPurchases->price;
				output << setw(10) << sortedPurchases->quantity<< endl;
			}
				sortedPurchases = sortedPurchases->next;
		}
		if(found)
		{
			if(member->GetMemberType() == "Basic")
			{
				basicCount++;
			}
			else
			{
				preferredCount++;
			}
		}
		member = member->GetNext();
	}

	output << endl << endl;
	output << "There are a total of " << basicCount
		   << " basic members that shopped that day"<< endl << endl;
	output << "There are a total of " << preferredCount
			   << " preferred members that shopped that day"<< endl << endl;
	return output.str();

}
