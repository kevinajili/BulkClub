#include "Header.h"
void PurchaseInfoToMember(purchase *Day, BulkClub *list)
{
	ostringstream output;
	purchase      *ptr;
	Date	      purchaseDate;
	string 	      product;
	Basic	      *memberPtr;
	float         dailyPurchaseTot;

	dailyPurchaseTot = 0;
	memberPtr		 = list->FirstMember();
	while(memberPtr != NULL)
	{
		ptr = Day;
		while(ptr != NULL)
		{
			if(memberPtr->)
			if (memberPtr -> GetId() == ptr->memberId)
			{
				dailyPurchaseTot += 	(ptr->price * ptr->quantity)
									  + ((ptr->price * ptr->quantity) * .0875);
			}

			ptr = ptr->next;
		}
		memberPtr->SetTotalSpent(dailyPurchaseTot);
		memberPtr = memberPtr->GetNext();
	}


	output << endl;

}
