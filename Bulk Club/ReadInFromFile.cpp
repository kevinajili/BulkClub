#include "Header.h"
BulkClub *ReadInFromFile(BulkClub   *list)
{

	int month;
	int day;
	int year;
	string expireDate;
	Date   *exDate;
	string memberName;
	int    memberId;
	string membershipType;
	Basic *newMember;
	ifstream iFile;

// opens the bank input file
	iFile.open("ReadinMember.txt");

// cycles through the file until it reaches the end
while (!iFile.eof())
{
	getline(iFile, memberName);
	iFile >> memberId;
	iFile.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(iFile, membershipType);
	getline(iFile, expireDate);

	month = atoi(expireDate.substr(0,2).c_str());
	day   = atoi(expireDate.substr(3,2).c_str());
	year  = atoi(expireDate.substr(6,9).c_str());

	exDate    = new Date(month,day,year);
	if(membershipType == "Basic")
	{
	newMember = new Basic(memberName, memberId, membershipType, *exDate, 0.0);
	}
	else
	{
		newMember = new Preferred(memberName, memberId, membershipType, *exDate, 0.0, 0.0);
	}
	list->AddMember(newMember);
}
iFile.close();


return list;
}

