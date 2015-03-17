#include "Header.h"
string SearchByItemSold(string searchItem, BulkClub *list)
{
	Basic    	  *member;
	purchase 	  *purchase;
	ostringstream output;
	float		  totQuantity;
	float		  totSale;


	member      = list->FirstMember();
	totQuantity = 0;
	while(member != NULL)
	{
		purchase = member->GetPurchaseHead();
		while(purchase != NULL)
		{
			if(searchItem == purchase->product)
			{
				totQuantity += purchase->quantity;
				totSale		= purchase->price;
			}
			purchase = purchase->next;
		}
		member = member->GetNext();
	}
	output << left;
	output << "For the item " << searchItem << endl << endl;
	output << setw(10)  << "Price";
	output << setw(20)  << "Total Quantity";
	output << setw(10)  << "Total Sold";
	output << endl;
	output << setfill('-');
	output << setw(5) << '-';
	output << setfill(' ');
	output << setw(5) << ' ';

	output << setfill('-');
	output << setw(14) << '-';
	output << setfill(' ');
	output << setw(6) << ' ';

	output << setfill('-');
	output << setw(9) << '-';
	output << setfill(' ');
	output << setw(1) << ' ';
	output << endl;

	output << setw(10)  << totSale;
	output << setw(20)  << totQuantity;
	output << setw(10)  << totQuantity*totSale;

    return output.str();
}

