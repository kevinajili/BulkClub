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
 *   This object stores the name, id, and member type of a Basic member.  These
 *   values are obtained from the main program.
 *******************************************************************************/
struct purchase
{
	Date      purchaseDate;
	int       memberId;
	string    product;
	float     price;
	int    	  quantity;
	purchase *next;
	purchase *prev;
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
		void SetPrev(Basic *prevNode);
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
		Basic *GetPrev()				const;
		Date   GetDate() const;
		float  MembershipAnnualCost(Date currentDate);
		float  GetTotalPurchase()const;
		float  GetTotalPurchaseNoTax() const;

		 //TableDisplay() - outputs single row output ready for table
		int    GetId()   const;  						// gets the Member type
		purchase *GetPurchaseHead();
		string   Display() const;	              // displays the member details
		string GetMemberType() const;
		string StringConvert(int integer) const;  // converts int to string
		string Ellipsis(string inputStr,		  // shortens long strings
						int maxLength) const;	  // with "..."
		string TableDisplay(const int MEMBERSHIP_WIDTH,
							 const int NAME_WIDTH,
							 const int ID_WIDTH) const;
							 
		string OutputPurchaseDisplay() const;
		string OutputListing()const;
		string GetName() const;							// gets the Member name
		int    GetId()   const;  						// gets the Member type
		void   GetNameAndId(string &memberName,
							int    &memberId)  const;  // gets Member age
		Date   GetDate() const;
		string GetMemberType() const;
		string StringConvert(int integer) const;   		// converts int to string
		string Ellipsis(string inputStr,		   		// shortens long strings
					    int maxLength) const;	   		// with "..."
		Basic *GetNext() const;							// return pointer to
														// to next Member
		string GetMemberExpireDate();
	private:
		Basic    *next;		 		// pointer to next Member
		Date 	 xDate;		 		// expiration date
		float    membershipCost;	// member ship cost
		float    maxDailyPurchase;
		float    purchasesTotal;
		float    purchaseNoTax;
		int      id;	     	 	// Member age
		int 	 quantityPerDay;
		purchase *purchaseHistory; 	// member purchase history
		string   memberType;  		// the type of Member
		string   name;	     		// Member name
		Basic	 *prev;
};

#endif /* BASIC_H_ */
