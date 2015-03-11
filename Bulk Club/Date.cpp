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




