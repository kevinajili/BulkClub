#include "Header.h"
string SearchForExpirationDate (int month,BulkClub *list)
{
	Basic *member;
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
	output << endl;
	member = list->FirstMember();
	while(member != NULL)
	{
		if(member->GetDate().GetMonth() == month)
		{

			output << setw(NAME_COL)         << member->GetName();
			output << setw(MEM_ID_COL)       << member->GetId();
			output << setw(MEM_TYPE_COL)     << member->GetMemberType();
			output << setw(MEM_EXP_DATE_COL) << member->GetDate().DisplayDate();
		}
		member = member->GetNext();
	}
	return output.str();
}
