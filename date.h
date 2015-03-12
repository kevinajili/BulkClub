/*
 * date.h
 *
 *  Created on: Mar 5, 2015
 *      Author: Austin
 */

#ifndef DATE_H_
#define DATE_H_

#include <ctime>
#include <iostream>
#include <sstream>
using namespace std;

class Date
{
public:

    /*****************************************************
         CONSTRUCTORS & DESTRUCTOR
     *****************************************************/
    Date();
    Date(int month,
         int day,
         int year);

    ~Date();

    /*****************************************************
         MUTATORS
     *****************************************************/
    void SetDate(int month,
                 int day,
                 int year);
    void AutoSetDate();
    /******************************************************
        ACCESSORS
     ******************************************************/
    void GetDate(int &month,
                 int &day,
                 int &year) const;
    int  GetYear()  const;
    int  GetMonth() const;
    int  GetDay()   const;

    // Displays in MM/DD/YYYY format
    string DisplayDate() const;


private:
    int dateMonth;
    int dateDay;
    int dateYear;
};



#endif /* DATE_H_ */
