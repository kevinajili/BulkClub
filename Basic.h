#ifndef BASIC_H_
#define BASIC_H_
#include "Date.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

/******************************************************************************
 * CLASS Basic
 *   This object stores the name, id, and member type of a Basic member.
 *   These values are obtained from the main program.
 *******************************************************************************/
struct purchase
{
	Date      purchaseDate;
	int       memberId;
	string    product;
	float     price;
	int    	  quantity;
	purchase *next;
};
class Basic
{
	public:
		Basic();									// constructor
		Basic(string 		 memberName,		    //overloaded constructor
			  int    		 memberNumber,
			  string         membershipType,
			  Date			 memberExpDate,
			  float			 memberTotSpent);
		~Basic();								   	// destructor
		/******************
		 ***  MUTATORS  ***
		 ******************/
		void SetAllValues(string memberName,
  	   	   	   	 	 	  int    memberId);
		void ChangeExpireDate();
		void SetDailyQuantity(int amount);
		void AddPurchaseToList(purchase *dailyPurchase);
		void SetNext(Basic *nextNode);			    // sets the next pointer
		void SetMemberType(string memberType); 		// sets the member type
		void MembershipCost(string cost);			// sets the membership cost
		void SetPurchaseHistory(purchase *myPurchaseHistoy);
		void SetTotalSpent(float totalSpent);
		void SetNameAndId(string &memberName,
							int    &memberId)  const;  // gets Member age

		/*******************
		 ***  ACCESSORS  ***
		 *******************/
		Basic *GetNext()               const;		// return pointer to
												    // to next Member
		Date   GetDate() const;
		float  MembershipAnnualCost(Date currentDate);  //
		float  GetTotalPurchase()const;					//gets total purchase
		float  GetTotalPurchaseNoTax() const;			//gets total purchase
														//	before tax
		 //TableDisplay() - outputs single row output ready for table
		int    GetId()   const;  						// gets the Member type
		purchase *GetPurchaseHead();
		string   Display() const;	              // displays the member details
		string GetMemberType() const;			  // gets member type
		string StringConvert(int integer) const;  // converts int to string
		string Ellipsis(string inputStr,		  // shortens long strings
						int maxLength) const;	  // with "..."
		string TableDisplay(const int MEMBERSHIP_WIDTH, // outputs info on member
							 const int NAME_WIDTH,
							 const int ID_WIDTH) const;
		string outputPurchaseDisplay() const;		// outputs daily purchases
		string OutputListing()         const;		// outputs info on member
		string GetName()     		   const;		// gets the Member name
		string GetMemberExpireDate();				// gets expiration date
	private:
		Basic    *next;		 		// pointer to next Member
		Date 	 xDate;		 		// expiration date
		float    membershipCost;	// member ship cost
		float    maxDailyPurchase;  // daily purchase maximum
		float    purchasesTotal;    // total purchases for a day
		float    purchaseNoTax;		// total before tax
		int      id;	     	 	// Member age
		int 	 quantityPerDay;	// quantity of items purchased for a day
		purchase *purchaseHistory; 	// member purchase history
		string   memberType;  		// the type of Member
		string   name;	     		// Member name
};

#endif /* BASIC_H_ */
