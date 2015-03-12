#include "date.h"
/************************************************************************
    CONSTRUCTORS & DESTRUCTOR
 ************************************************************************/

Date::Date()
{
    dateMonth = 0;
    dateDay   = 0;
    dateYear  = 0;

}

Date::Date(int month,
           int day,
           int year)
{
    SetDate(month, day, year);
}

Date::~Date() { }


/************************************************************************
     MUTATORS
    -------------------------------------------------------------------
     SetDate
 ************************************************************************/

// Sets the date given a month day and year
//    Checks to see if the dat is valid prior to setting the date
void Date::SetDate(int month,
                   int day,
                   int year)
{
    dateMonth = month;
    dateDay   = day;
    dateYear  = year;
}

/******************************************************
     ACCESSORS
    ------------------------------------------------
     GetDate
     GetYear
     GetMonth
     GetDay
     DisplayDate
 ******************************************************/
void Date::GetDate(int &month,
                   int &day,
                   int &year) const
{
      month = dateMonth;
      day   = dateDay;
      year  = dateYear;
}

int  Date::GetYear() const
{
    return dateYear;
}

int  Date::GetMonth() const
{
    return dateMonth;
}

int  Date::GetDay() const
{
    return dateDay;
}

string Date::DisplayDate() const
{
	ostringstream output;
    // Check if Day or Month are < 10 and add a leading 0 if necessary
    if (dateMonth < 10)
    {
        output << '0';
    }
    output << dateMonth << '/';
    if (dateDay < 10)
    {
        output << '0';
    }
    output << dateDay   << '/'
           << dateYear;

    return output.str();
}
void Date::AutoSetDate()
{
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int currentYear;
	int currentMonth;
	int currentDay;
	int lastDayInMonth;
	tm *currentTime;     // Used to find the current time

	// Find the current year based on the currentTime
	time_t now  = time(0);
	currentTime  = localtime(&now);
	currentYear  = 1900 + currentTime->tm_year;
	currentMonth = 1 + currentTime->tm_mon;
	currentDay   = currentTime->tm_mday;

	currentYear++;
	// Set the Date (if it is valid)
	dateMonth = currentMonth;
	dateDay   = currentDay;
	dateYear  = currentYear;

}



