#include "Header.h"
void PurchaseInfoToMember(purchase *Day, BulkClub *list)
{
	ostringstream output;
	purchase      *ptr;
	int			  itemCounter;
	Date	      purchaseDate;
	string 	      product;
	Basic	      *memberPtr;
	float         dailyPurchaseTot;
	int 		  dayVar;
	itemCounter      = 0;
	dailyPurchaseTot = 0;
	memberPtr		 = list->FirstMember();
	while(memberPtr != NULL)
	{
		ptr = Day;
		while(ptr != NULL)
		{

			if (memberPtr -> GetId() == ptr->memberId)
			{
				// Else if the year of expiration is the same as the year of purchase
					if(memberPtr->GetDate().GetYear() == ptr->purchaseDate.GetYear())
					{
						if(memberPtr->GetDate().GetMonth() == ptr->purchaseDate.GetMonth())
							{
								if(memberPtr->GetDate().GetDay() >= ptr->purchaseDate.GetDay())
								{

									if (itemCounter < 200 )
									{
									dailyPurchaseTot += 	(ptr->price * ptr->quantity)
													 + ((ptr->price * ptr->quantity) * .0875);

									itemCounter += ptr->quantity;
									}

								}
								else
								{
				 					cout << "Failed to meet member requirements\n";
								}
							}
						else
						{
				     		dailyPurchaseTot += 	(ptr->price * ptr->quantity)
											 + ((ptr->price * ptr->quantity) * .0875);

						}

					}

				// IF the year is greater than the year of purchase
				if(memberPtr->GetDate().GetYear() > ptr->purchaseDate.GetYear())
				{
					dailyPurchaseTot += 	(ptr->price * ptr->quantity)
									  + ((ptr->price * ptr->quantity) * .0875);
				}

			}
			dayVar = ptr->purchaseDate.GetDay();
			ptr = ptr->next;
			if(dayVar !=)

		}

		memberPtr->SetTotalSpent(dailyPurchaseTot);
		memberPtr = memberPtr->GetNext();
		dailyPurchaseTot = 0;
		itemCounter 	 = 0;
	}

}

