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

// INPUT - adds instance of animal to list
void BulkClub::AddMember(Basic *newMember)
{
	newMember->SetNext(head);
	head = newMember;
	newMember = NULL;
	memberCount++;

}

// INPUT - removes instance of animal from list
bool BulkClub::RemoveMember(string searchKey)
{
	Basic *pointer;
	bool  removed;
	pointer = head;
	// WHILE - not end of list & not removed
	while(pointer != NULL && !removed)
	{
		// IF - name is found
		if(pointer->GetName() == searchKey)
		{
			head = pointer->GetNext();
			delete pointer;
			removed = true;
			memberCount--;
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
Basic *BulkClub::FindMember(int number) const
{
	Basic *pointer;
	bool found;
	found = false;
	pointer = head;
	while(pointer != NULL && !found)
	{
		if(pointer->GetId() == number)
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

// OUTPUT - outputs entire list in table format
string BulkClub::OutputList() const
{
	const int NAME_WIDTH   = 10;
	const int ID_WIDTH    = 3;
	const int Member_TYPE_WIDTH  = 6;

 	ostringstream output;
	Basic *pointer;

	pointer = head;

	if(memberCount == 1)
	{
		output << pointer->Display();
	}
	else
	{
		// OUTPUT - Prints heading titles to the screen
		output << left;
		output << setw(Member_TYPE_WIDTH)  << "Member Type" << ' ';
		output << setw(NAME_WIDTH)         << "NAME"   << ' ';
		output << setw(ID_WIDTH)          << "ID"    << ' ';
		output << endl;
		// OUTPUT - Prints divider between heading and data to the screen
		output << setfill('-');
		output << setw(Member_TYPE_WIDTH)  << '-' << ' ';
		output << setw(NAME_WIDTH)   	   << '-' << ' ';
		output << setw(ID_WIDTH)    	   << '-' << ' ';

		output << setfill(' ');
		output << endl;
		output << right;

		while(pointer != NULL)
		{
			output << pointer->TableDisplay(Member_TYPE_WIDTH,
											NAME_WIDTH,
											ID_WIDTH);

			output << endl;
			pointer = pointer->GetNext();
		}
	}

	return output.str();
}
