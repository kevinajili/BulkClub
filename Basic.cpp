#include "Basic.h"

/**************************************************************************
 * CLASS Basic
 *   This object stores the name, age, and value of an animal.  These
 *   values are obtained from the main program.
 *************************************************************************/

// Constructor - creates an animal instance
Basic::Basic()
{
	name  = "";
	id    = 0;
	next  = NULL;
	memberType = "";
	purchasesTotal = 0;
	membershipCost = 55.00;
}

// Non - default constructor - creates animal instance
Basic::Basic(string memberName,
			 int	  memberId,
			 Date exDate)
{
	name 		   = memberName;
	id             = memberId;
	next           = NULL;
	memberType     = "Basic";
	xDate          = exDate;
	purchasesTotal = 0;
}

// Destructor - destroys an animal object
Basic::~Basic() {}

// INPUT - sets the initial value of the Basic member
void Basic::SetAllValues(string memberName,
		   	   	   	   	 int    memberId)
{
	name 	   = memberName;
	id   	   = memberId;
	memberType = "Basic";
}
void Basic::AddPurchaseToList(purchase *dailyPurchase)
{
			// creating a new node for more info
			dailyPurchase->next  = purchaseHistory;
			purchaseHistory      = dailyPurchase;
			purchasesTotal		+= (dailyPurchase->price * .0875);
			dailyPurchase		 = NULL;

}
// INPUT - sets the animal type
void Basic::SetMemberType(string member)
{
	memberType = member;
}
void Basic::MembershipCost(string cost)
{
		membershipCost = atof(cost.c_str());
}
// INPUT - sets the next pointer
void Basic::SetNext(Basic *nextNode)
{
	next = nextNode;
}

void Basic::SetPurchaseHistory(purchase *myPurchaseHistory)
{
	purchaseHistory = myPurchaseHistory;
}

// OUTPUT - gets the name
string Basic::GetName() const
{
	return name;
}
int Basic::GetId() const
{
	return id;
}
// OUTPUT - gets the breed
string Basic::GetMemberType() const
{
	return memberType;
}

// OUTPUT - gets the name and age
void Basic::GetNameAndId(string &memberName,
						   int	  &memberId) const
{
	memberName = name;
	memberId  = id;
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
float Basic::MembershipAnnualCost(Date currentDate)
{
	if((xDate.GetYear() - currentDate.GetYear()) == 0)
	{
		return membershipCost;
	}
}
string Basic::GetMemberExpireDate()
{
	return xDate.DisplayDate();
}
