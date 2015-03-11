#include "Preferred.h"
Preferred::Preferred()
{

}
Preferred::Preferred(string 		 memberName,		//overloaded constructor
					  int    		 memberNumber,
					  string         memberType,
					  Date			 memberExpDate,
					  float			 memberTotSpent,
					  float			 memberRebate)
   :Basic(memberName,memberNumber,memberType, memberExpDate, memberTotSpent)
{

}


	/**********************************************************************
	 * MUTATORS
	 **********************************************************************/

	void Preferred::SetAllValues(string 		 memberName,	//Sets all of the values
							  int    		 memberNumber,	// for the preferred
							  string		 memberType,	// member
							  Date			 memberExpDate,
							  float			 memberTotSpent,
							  float			 memberRebate)
	{

	}

	void Preferred::SetRebate(float memberRebate)
	{

	}

//	virtual void UpdateMember()  //NEED TO ADD

	float Preferred::GetRebate() const
	{

	}
