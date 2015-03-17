#include "Preferred.h"
/**************************************************************************
 * CLASS Preferred
 * This object is a derived class of basic, it stores the same information,
 * but preferred members get a 6% rebate near the end of each year.
 *************************************************************************/


//Default constructor
Preferred::Preferred()
{
	rebate = .06;
}

//Non-Default/Overloaded constructor
Preferred::Preferred(string 		 memberName,		//overloaded constructor
					  int    		 memberNumber,
					  string         memberType,
					  Date			 memberExpDate,
					  float			 memberTotSpent,
					  float			 memberRebate)
   :Basic(memberName,memberNumber,memberType, memberExpDate, memberTotSpent)
{
	rebate = .06;
}

//Default Destructor
Preferred::~Preferred(){}
	/**********************************************************************
	 * MUTATORS
	 * -------------------------------------------------------------------
	 * SetAllValues
	 * SetRebate
	 **********************************************************************/
//	sets all values to attributes
	void Preferred::SetAllValues(string 		 memberName,	//Sets all of the values
							  int    		 memberNumber,	// for the preferred
							  string		 memberType,	// member
							  Date			 memberExpDate,
							  float			 memberTotSpent,
							  float			 memberRebate)
	{

	}

//	sets the rebate
	void Preferred::SetRebate(float memberRebate)
	{

	}

	/********************************************************************
	     ACCESSORS
	    -----------------------------------------------------------------
	     GetRebate
	 ********************************************************************/
//	virtual void UpdateMember()  //NEED TO ADD

	float Preferred::GetRebate() const
	{
		return rebate;
	}
