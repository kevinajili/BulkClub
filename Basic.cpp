#include "Basic.h"

/******************************************************************************
 * CLASS Basic
 *   This object stores the name, id, and member type of a Basic member.
 *   These values are obtained from the main program.
 *******************************************************************************/

// Constructor - creates an basic instance
Basic::Basic()
{
	name  = "";
	id    = 0;
	next  = NULL;
	memberType = "";
	purchasesTotal = 0;
	membershipCost = 55.00;
	purchaseHistory = NULL;
	xDate.AutoSetDate();
	purchaseNoTax = 0;
}

// Non - default constructor - creates a basic instance
//overloaded constructor
Basic::Basic(string 		 memberName,
			 int    		 memberNumber,
			 string          membershipType,
			 Date			 memberExpDate,
			 float			 memberTotSpent)
{
	name 		   = memberName;
	id             = memberNumber;
	next           = NULL;
	memberType     = membershipType;
	membershipCost = 55.00;
	xDate          = memberExpDate;
	purchasesTotal = memberTotSpent;
	purchaseHistory =NULL;

}

// Destructor - destroys a basic object
Basic::~Basic() {}



/************************************************************************
     MUTATORS
 -------------------------------------------------------------------------
 SetAllValues
 ChangeExpireDate
 SetDailyQuantity
 AddPurchaseToList
 SetNext
 SetMemberType
 MembershipCost
 SetPurchaseHistory
 SetTotalSpent
 SetNameAndId
 ************************************************************************/


// INPUT - sets the initial value of the Basic member
void Basic::SetAllValues(string memberName,
		   	   	   	   	 int    memberId)
{
	name 	   = memberName;
	id   	   = memberId;
	memberType = "Basic";
}

//INPUT - Adds a purchase to purchase history
void Basic::AddPurchaseToList(purchase *dailyPurchase)
{

	if(purchaseHistory == NULL)
			{
	   	     	quantityPerDay       =   0;
	   	     	maxDailyPurchase	 =   0;
	   	        purchaseNoTax		 =   0;
	   	        purchasesTotal		 =   0;
				dailyPurchase->next  = purchaseHistory;
				purchaseHistory      = dailyPurchase;
				purchaseNoTax        = dailyPurchase->price * dailyPurchase->quantity;
				purchasesTotal		 = (purchaseNoTax + (purchaseNoTax * .0875));
				quantityPerDay      +=  dailyPurchase->quantity;
				maxDailyPurchase	+= purchasesTotal;

			}
	 		// creating a new node for more info
   else if(dailyPurchase->purchaseDate.DisplayDate() != purchaseHistory->purchaseDate.DisplayDate())
		{
	   	   	   	   	quantityPerDay       =   0;
	   	   	   	   	maxDailyPurchase	 =   0;
					dailyPurchase->next  = purchaseHistory;
					purchaseHistory      = dailyPurchase;
					purchaseNoTax        = dailyPurchase->price * dailyPurchase->quantity;
					purchasesTotal		+= (purchaseNoTax + (purchaseNoTax * .0875));
					quantityPerDay      +=  dailyPurchase->quantity;
					maxDailyPurchase	+= purchasesTotal;
		}

			else
		{
				if(quantityPerDay <= 200 && maxDailyPurchase <= 200)
				{
					dailyPurchase->next  = purchaseHistory;
					purchaseHistory      = dailyPurchase;
					purchaseNoTax        = dailyPurchase->price * dailyPurchase->quantity;
					purchasesTotal		+= (purchaseNoTax + (purchaseNoTax * .0875));
					quantityPerDay      +=  dailyPurchase->quantity;
					maxDailyPurchase	+= purchasesTotal;
				}
		}
}
// INPUT - sets the animal type
void Basic::SetMemberType(string member)
{
	memberType = member;
}

//INPUT - sets membership cost
void Basic::MembershipCost(string cost)
{
		membershipCost = atof(cost.c_str());
}

//INPUT - sets total spent
void Basic::SetTotalSpent(float totalSpent)
{
	purchasesTotal = totalSpent;
}
// INPUT - sets the next pointer
void Basic::SetNext(Basic *nextNode)
{
	next = nextNode;
}

//INPUT - sets purchase history
void Basic::SetPurchaseHistory(purchase *myPurchaseHistory)
{
	purchaseHistory = myPurchaseHistory;
}

//INPUT - sets name and id
void Basic::SetNameAndId(string &memberName,
						   int	  &memberId) const
{
	memberName = name;
	memberId  = id;
}

//INPUT - changes the expiration date of a membership
void Basic::ChangeExpireDate()
{
	xDate.AutoSetDate();
}

//INPUT - sets the daily amount
void  Basic::SetDailyQuantity(int amount)
{
	quantityPerDay = amount;
}
/******************************************************
     ACCESSORS
    ------------------------------------------------
    *GetNext()
  	 GetDate()
  	 MembershipAnnualCost
  	 GetTotalPurchase()
  	 GetTotalPurchaseNoTax()
  	 GetId()
  	 *GetPurchaseHead()
  	 Display()
  	 GetMemberType()
  	 StringConvert(int integer)
  	 Ellipsis
  	 TableDisplay
  	 outputPurchaseDisplay()
  	 OutputListing()
  	 GetName()
  	 GetMemberExpireDate()
 ******************************************************/
// OUTPUT - gets the name
string Basic::GetName() const
{
	return name;
}
// OUTPUT - gets the id
int Basic::GetId() const
{
	return id;
}
// OUTPUT - gets the total purchases
float  Basic::GetTotalPurchase()const
{
	return purchasesTotal;
}
// OUTPUT - gets the total purchase before tax
float  Basic::GetTotalPurchaseNoTax() const
{
	return purchaseNoTax;
}
// OUTPUT - gets the member type
string Basic::GetMemberType() const
{
	return memberType;
}


// OUTPUT - gets the next pointer
Basic *Basic::GetNext() const
{
	return next;
}

// OUTPUT - returns name, age & width as a string ready for output
string Basic::TableDisplay(const int MEMBERSHIP_WIDTH,
							const int NAME_WIDTH,
		   	   	   	    	const int ID_WIDTH) const
{
	ostringstream output;	 //CALC - output stream variable

	output << left;
	output << setw(MEMBERSHIP_WIDTH) << memberType << ' ';
	output << setw(NAME_WIDTH)  << ' ' + Ellipsis(name, NAME_WIDTH-1) << ' ';
	output << setw(ID_WIDTH)    << ' ' + StringConvert(id);
	output << right;

	return output.str();
}

// OUTPUT - returns name and Speak() ready for output
string Basic::Display() const
{
	ostringstream output;	 //CALC - output stream variable
	output << "Name: " << name << endl;
	output << "ID:   " << id ;
	output << endl << endl;
	return output.str();
}

// OUTPUT - returns formatted string ready for output
string Basic::StringConvert(int integer) const
{
    ostringstream OUTPUT;   //CALC - output stream variable

    OUTPUT << integer;

    return OUTPUT.str();
}

//OUPUT - gets current date
Date   Basic::GetDate() const
{
	return xDate;
}
// OUTPUT - returns modified string ready for output with "..."
string Basic::Ellipsis(string inputStr,	//CALC - input string
			    		int maxLength) const		//CALC - max length of one line
{
	ostringstream OUTPUT;	//CALC - output stream variable
	int strLength;			//CALC - input string length

	strLength = inputStr.size();
	//IF - input string greater than maximum length, modify accordingly
	if(strLength > maxLength)
	{
		OUTPUT << inputStr.substr(0, maxLength - 3) << "...";
	}
	//ELSE - do not modify it
	else
	{
		OUTPUT << inputStr;
	}

	return OUTPUT.str();
}

//OUTPUT - returns the purchase history for member
purchase *Basic::GetPurchaseHead()
{
	return purchaseHistory;
}

//OUTPUT - returns the new membership cost based on date of membership
float Basic::MembershipAnnualCost(Date currentDate)
{
	if((xDate.GetYear() - currentDate.GetYear()) == 0)
	{
		return membershipCost;
	}
	return membershipCost;
}

//OUTPUT - displays the purchases of a member
string Basic::outputPurchaseDisplay() const
{
	ostringstream output;
	purchase *ptr;
	float 	purchase ;
	float   purchaseNoTax;

	purchaseNoTax = 0;
	ptr = purchaseHistory;
	while(ptr != NULL)
	{
			output << left;
			output << setw(20) << ptr->purchaseDate.DisplayDate();
			output << setw(40) << ptr->product;
			output << setw(10) <<  ptr->price;
			output << setw(10) <<  ptr->quantity	<< endl;

			purchase += 	(ptr->price * ptr->quantity)
							+ ((ptr->price * ptr->quantity) * .0875);
			purchaseNoTax += ptr->price * ptr->quantity;
			ptr = ptr->next;
	}
	output << endl;
	output << left;
	output << setw(35) << "Total amount spent without tax: ";
	output << right;
	output << fixed    << setprecision(2) << purchaseNoTax;


	return output.str();
}

//OUPUT - displays a listing of a member
string Basic::OutputListing() const
{
	ostringstream output;
	const int 	  NAME_COL         = 25;
	const int     MEM_ID_COL       = 10;
	const int     MEM_TYPE_COL 	   = 20;
	const int  	  MEM_EXP_DATE_COL = 30;
	const int 	  TOT_SPENT_COL    = 15;
	const int 	  REBTATE_AMT_COL  = 15;

	output << left;

	output << setw(NAME_COL)         << name;
	output << setw(MEM_ID_COL)       << id;
	output << setw(MEM_TYPE_COL)     << memberType;
	output << setw(MEM_EXP_DATE_COL) << xDate.DisplayDate();
	output << setw(TOT_SPENT_COL)	 << fixed << setprecision(2)
									 << purchasesTotal;


	return output.str();
}

//OUTPUT - gets the member's expiration date
string Basic::GetMemberExpireDate()
{
	    return xDate.DisplayDate();
}
