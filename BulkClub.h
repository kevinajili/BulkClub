#ifndef BULKCLUB_H_
#define BULKCLUB_H_

#include "Basic.h"
#include <string>
using namespace std;

class BulkClub
{
	public:
	BulkClub();		// constructor
		~BulkClub();	// destructor

		/******************
		 ***  MUTATORS  ***
		 ******************/
		void   AddMember(Basic *newMember);	// adds an animal to list
		bool   RemoveMember(string searchKey);	// removes animal from list
		bool   ClearList();						// clears entire list

		/*******************
		 ***  ACCESSORS  ***
		 *******************/
		Basic *FindMember(int number) const;
		Basic *FindMember(string searchKey) const;	// search for animal
		int    TotalMembers() const;		// returns count
		string OutputList() const;		// outputs entire list - table format
		Basic *FirstMember()const;	// outputs head of list

	private:
		Basic *head;			// pointer to head of list
		int    memberCount;		// counts number of items in list
};




#endif /* BULKCLUB_H_ */
