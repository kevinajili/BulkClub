#include "BulkClub.h"

// Constructor - creates an list
BulkClub::BulkClub()
{
	head = NULL;
	memberCount = 0;
}

// Destructor - destroys the list
BulkClub::~BulkClub()
{
	ClearList();
}

// INPUT - adds instance of member to list
void BulkClub::AddMember(Basic *newMember)
{

	if(head != NULL)
	{
	newMember->SetNext(head);
	head->SetPrev(newMember);
	newMember->SetPrev(NULL);
	head = newMember;
	memberCount++;
	}
	else
	{
		newMember->SetNext(head);
		head = newMember;
		memberCount++;
	}
}

// INPUT - removes instance of member from list
bool BulkClub::RemoveMember(string searchKey)
{
	Basic *pointer;
	Basic *pointer2;
	Basic *pointer3;
	bool  removed;
	pointer = head;
	// WHILE - not end of list & not removed
	while(pointer != NULL && !removed)
	{
		// IF - name is found
		if(pointer->GetNext()->GetName() == searchKey)
		{
			pointer2 = pointer->GetNext();
			pointer3 = pointer2->GetNext();
			pointer->SetNext(pointer3);
			delete pointer2;
			pointer->SetNext(pointer3);
			pointer3->SetPrev(pointer);
			removed = true;
			memberCount--;
		}
		else if(pointer->GetName() == searchKey)
		{
			head = pointer->GetNext();
			head->SetPrev(NULL);
			delete pointer;
			removed = true;
		}
		// ELSE - not found
		else
		{
			removed = false;
		}

		pointer = pointer->GetNext();
		pointer = NULL;
	}

	return removed;
}

// OUTPUT - outputs head of list
Basic *BulkClub::FirstMember()const
{
	Basic *pointer;
	pointer = head;
	return pointer;
}

// CALC - deletes entire list
bool BulkClub::ClearList()
{
	Basic *pointer;
	pointer = head;
	bool emptyList;
	if(head == NULL)
	{
		emptyList = true;
	}
	else
	{
		//WHILE - exits when the list is empty
		while(head != NULL)
		{
			emptyList = false;
			pointer = head;
			head = pointer->GetNext();
			delete pointer;
			memberCount--;
		}
	}

	return emptyList;
}

// OUTPUT - searches list for specific name
Basic *BulkClub::FindMember(string searchKey) const
{
	Basic *pointer;
	bool found;
	found = false;
	pointer = head;
	while(pointer != NULL && !found)
	{
		if(pointer->GetName() == searchKey)
		{
			found = true;
		}
		else
		{
			pointer = pointer->GetNext();
		}
	}
	return pointer;
}


// OUTPUT - searches list for specific name
Basic *BulkClub::FindMember(int id) const
{
	Basic *pointer;
	bool found;
	found = false;
	pointer = head;

	while(pointer != NULL && !found)
	{

		if(pointer->GetId() == id)
		{
			found = true;
		}
		else
		{
			pointer = pointer->GetNext();
		}
	}
	return pointer;
}

// OUTPUT - returns count
int BulkClub::TotalMembers() const
{
	return memberCount;
}
string OutputListHeader()
{
	ostringstream output;
	const int 	  NAME_COL         = 25;
	const int     MEM_ID_COL       = 10;
	const int     MEM_TYPE_COL 	   = 20;
	const int  	  MEM_EXP_DATE_COL = 30;
	const int 	  TOT_SPENT_COL    = 15;
	const int 	  REBTATE_AMT_COL  = 15;
	output << left;
	output << setw(NAME_COL)         << "Name";
	output << setw(MEM_ID_COL)       << "ID";
	output << setw(MEM_TYPE_COL) 	 << "Membership Type";
	output << setw(MEM_EXP_DATE_COL) << "Membership Expiration Date";
	output << setw(TOT_SPENT_COL)	 << "Total Spent";
	output << setw(REBTATE_AMT_COL)  << "Rebate Amount";
	output << endl;

	output << setfill('-');
	output << setw(4) << '-';
	output << setfill(' ');
	output << setw(21) << ' ';

	output << setfill('-');
	output << setw(2) << '-';
	output << setfill(' ');
	output << setw(8) << ' ';

	output << setfill('-');
	output << setw(16) << '-';
	output << setfill(' ');
	output << setw(4) << ' ';

	output << setfill('-');
	output << setw(26) << '-';
	output << setfill(' ');
	output << setw(4) << ' ';

	output << setfill('-');
	output << setw(11) << '-';
	output << setfill(' ');
	output << setw(4) << ' ';

	output << setfill('-');
	output << setw(13) << '-';
	output << setfill(' ');
	output << setw(2) << ' ';
	output << endl;
	return output.str();
}
// OUTPUT - outputs entire list in table format
string BulkClub::OutputList() const
{


 	ostringstream output;
	Basic *pointer;
	output << OutputListHeader();
	pointer = head;
	while(pointer != NULL)
	{
		output << pointer->OutputListing() << endl;
		pointer = pointer -> GetNext();
	}

	return output.str();
}
