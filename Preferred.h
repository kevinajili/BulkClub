
#ifndef PREFERRED_H_
#define PREFERRED_H_

#include "Basic.h"

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
	 **********************************************************************/
	float GetRebate() const;				   //Returns the value for rebate


private:

	float rebate;
};


#endif /* PREFERRED_H_ */
