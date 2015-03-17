
#ifndef PREFERRED_H_
#define PREFERRED_H_

#include "Basic.h"

/**************************************************************************
 * CLASS Preferred
 * This object is a derived class of basic, it stores the same information,
 * but preferred members get a 6% rebate near the end of each year.
 *************************************************************************/
class Preferred: public Basic
{
public:
	/**********************************************************************
	 * CONSTRUCTORS & DESTRUCTOR
	 **********************************************************************/
	Preferred();
	Preferred(string 		 memberName,		//overloaded constructor
		      int    		 memberNumber,
		      string         memberType,
			  Date			 memberExpDate,
			  float			 memberTotSpent,
			  float			 memberRebate);
	~Preferred();

	/**********************************************************************
	 * MUTATORS
	 * -------------------------------------------------------------------
	 * SetAllValues
	 * SetRebate
	 **********************************************************************/

	void SetAllValues(string 		 memberName,	//Sets all of the values
					  int    		 memberNumber,	// for the preferred
					  string         memberType,	// member
					  Date			 memberExpDate,
					  float			 memberTotSpent,
					  float			 memberRebate);

	void  SetRebate(float memberRebate);		   //Sets the value for rebate


	/**********************************************************************
	 * ACCESSORS
	 * -------------------------------------------------------------------
	 * GetRebate
	 **********************************************************************/
	float GetRebate() const;				   //Returns the value for rebate


private:

	float rebate;			//rebate for end of the year
};


#endif /* PREFERRED_H_ */
