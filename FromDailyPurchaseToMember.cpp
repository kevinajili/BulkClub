#include "Header.h"
void FromDailyPurchaseToMember(purchase *Day, BulkClub *MyBulkClubList)
{
	purchase *dailyPurchase;
	purchase *head;
	BulkClub *ptr1;
	Basic 	 *member;
	purchase *ptr;
	Date	 purchaseDate;
	string 	 product;

	ptr  = Day;
	ptr1 = new BulkClub;
	ptr1 = MyBulkClubList;

	while(ptr != NULL)
	{

		dailyPurchase = new purchase;
		dailyPurchase->purchaseDate = ptr->purchaseDate;
		dailyPurchase->memberId		= ptr->memberId;
		dailyPurchase->price		= ptr->price;
		dailyPurchase->product		= ptr->product;
		dailyPurchase->quantity		= ptr->quantity;

		member = ptr1->FindMember(dailyPurchase->memberId);


		if(member->GetMemberExpireDate() != dailyPurchase->purchaseDate.DisplayDate())
		{
			member->AddPurchaseToList(dailyPurchase);
			// creating a new node for more info
				dailyPurchase->next = head;
				head 	            = dailyPurchase;
				delete dailyPurchase;
				dailyPurchase = new purchase;
		}

		// creating a new node for more info
		ptr = ptr->next;

	}
	member->SetPurchaseHistory(ptr);

}
