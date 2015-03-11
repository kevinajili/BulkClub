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
	Date   purchaseDate;
	int    memberId;
	string product;
	float  price;
	int    quantity;
	purchase *next;
};
class Basic
{
	public:
		Basic();									// constructor
		Basic(string 		 memberName,		//overloaded constructor
			  int    		 memberNumber,
			  string         memberType,
			  Date			 memberExpDate,
			  float			 memberTotSpent);
		~Basic();									// destructor
		/******************
		 ***  MUTATORS  ***
		 ******************/
		void SetAllValues(string memberName,
  	   	   	   	 	 	  int    memberId);
		void AddPurchaseToList(purchase *dailyPurchase);
		void SetNext(Basic *nextNode);			    // sets the next pointer
		void SetMemberType(string memberType); 		// sets the member type
		void MembershipCost(string cost);			// sets the membership cost
		void SetPurchaseHistory(purchase *myPurchaseHistoy);
		/*******************
		 ***  ACCESSORS  ***
		 *******************/
		 float MembershipAnnualCost(Date currentDate);
		 string Display() const;	// displays the member details

		 //TableDisplay() - outputs single row output ready for table
		 string TableDisplay(const int MEMBERSHIP_WIDTH,
							 const int NAME_WIDTH,
							 const int ID_WIDTH) const;
		string GetName() const;							// gets the Member name
		int GetId() const; 								// gets the Member type
		void   GetNameAndId(string &memberName,
							 int    &memberId)  const;  // gets Member age
		string GetMemberType() const;
		string StringConvert(int integer) const;   		// converts int to string
		string Ellipsis(string inputStr,		   		// shortens long strings
					    int maxLength) const;	   		// with "..."
		Basic *GetNext() const;							// return pointer to
														// to next Member
		string GetMemberExpireDate();
	private:
		string   name;	     							// Member name
		int      id;	     	 		// Member age
		Basic    *next;		 		// pointer to next Member
		string   memberType;  		// the type of Member
		Date 	 xDate;		 		// expiration date
		float    membershipCost;		// member ship cost
		float    purchasesTotal;
		purchase *purchaseHistory; 	// member purchase history
};

#endif /* BASIC_H_ */
