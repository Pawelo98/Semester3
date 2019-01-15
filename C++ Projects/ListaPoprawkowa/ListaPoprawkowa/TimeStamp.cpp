#include "pch.h"
#include <iostream>
#include "TimeStamp.h"

using namespace std;

TimeStamp::TimeStamp()
{
	d_days = 1;
} // TimeStamp::TimeStamp()

TimeStamp::TimeStamp(double dDays)
{
	if (dDays <= 0)
	{
		cout << WRONG_DATE_STAMP << endl;
		d_days = 1;
	} // if (dDays <= 0)
	else d_days = dDays;
} // TimeStamp::TimeStamp(double dDays)

TimeStamp::TimeStamp(int iMinutes, int iHours, int iDays, int iMonths, int iYears)
{
	if (iYears <= 0 || iMonths <= 0 || iMonths > NUMBER_OF_MONTHS || iDays <= 0 || iDays > DAYS_IN_MONTHS[iMonths - 1] || iHours<0 || iMinutes<0 || iMinutes>(MINS_IN_HOUR-1) || iHours > (HOURS_IN_DAY-1))
	{
		iYears = 1;
		iMonths = 1;
		iDays = 0;
		iHours = 0;
		iMinutes = 0;
		cout << WRONG_DATE_STAMP << endl;
	} // if (iYears <= 0 || iMonths <= 0 || iMonths > NUMBER_OF_MONTHS || iDays <= 0 || iDays > DAYS_IN_MONTHS[iMonths - 1] || iHours<0 || iMinutes<0 || iMinutes>(MINS_IN_HOUR-1) || iHours > (HOURS_IN_DAY-1))

	double days = iDays+1;
	// days from iDay
	for (int i = 0; i < iMonths - 1; i++)
	{
		days += DAYS_IN_MONTHS[i];
	} // for (int i = 0; i < iMonth - 1; ++i)
	// days from iMonth
	days += (iYears - 1)*DAYS_IN_A_YEAR;
	for (int j = 1; j < iYears; j++)
	{
		if ((j % LEAP4 == 0) && (!(j % LEAP100 == 0) || (j % LEAP400 == 0))) days++;
	} // for (int j = 1; j < iYears; j++)
	// days from iYear
	for (int g = 0; g < iHours; g++)
	{
		days += DAYS_IN_HOUR;
	} // for (int g = 0; g < iHours; g++)
	// days from hours
	for (int h = 0; h < iMinutes; h++)
	{
		days += DAYS_IN_MIN;
	} // for (int h = 0; h < iMinutes; h++)
	// days from minutes
	d_days = days;
} // TimeStamp::TimeStamp(int iMinutes, int iHours, int iDays, int iMonths, int iYears)

string TimeStamp::sDateToString()
{
	double iDays = d_days;
	int iDay = -1;
	int iMonth = 1;
	int iYear = 1;
	int iHours = 0;
	int iMinutes = 1;
	int daysThisYear = DAYS_IN_A_YEAR;
	for (int i = 1; iDays > daysThisYear+1; i++)
	{
		if ((i % LEAP4 == 0) && (!(i % LEAP100 == 0) || (i % LEAP400 == 0))) iDays -= (DAYS_IN_A_YEAR + 1);
		else iDays -= DAYS_IN_A_YEAR;
		iYear++;
		if (((i+1) % LEAP4 == 0) && (!((i+1) % LEAP100 == 0) || ((i+1) % LEAP400 == 0))) daysThisYear = (DAYS_IN_A_YEAR + 1);
		else daysThisYear = DAYS_IN_A_YEAR;
	} // for (int i = 1; iDays >= DAYS_IN_A_YEAR; i++)
	for (int j = 1; iDays > DAYS_IN_MONTHS[j - 1]; j++)
	{
		iDays -= DAYS_IN_MONTHS[j - 1];
		iMonth++;
	} // for (int j = 1; iDays >= DAYS_IN_MONTHS[j-1]; j++)
	while(iDays >= 1)
	{
		iDay++;
		iDays--;
	} // while(iDays >= 1)
	while(iDays > DAYS_IN_HOUR)
	{
		iDays -= DAYS_IN_HOUR;
		iHours++;
	} // while(iDays > 0.04166666667)
	while(iDays > DAYS_IN_MIN)
	{
		iDays -= DAYS_IN_MIN;
		iMinutes++;
	} // while(iDays > 0.00069444444)
	if (iDay == 0) iDay = 1;
	return to_string(iDay) + "." + to_string(iMonth) + "." + to_string(iYear) + "  " + to_string(iHours) + ":" + to_string(iMinutes);
} // string TimeStamp::sDateToString()

TimeStamp TimeStamp::operator-(double dHours)
{
	return TimeStamp(this->dGetDays()- (dHours*DAYS_IN_HOUR));
} // CTime TimeStamp::operator-(double dDays)

double TimeStamp::operator-(const TimeStamp &cOtherDate)
{
	return ((this->d_days - cOtherDate.d_days) * MINS_IN_HOUR * HOURS_IN_DAY);
} // double TimeStamp::operator-(const CTime &cOtherDate)

TimeStamp TimeStamp::operator+(double dHours)
{
	return TimeStamp(this->dGetDays() + (dHours*DAYS_IN_HOUR));
} // CTime TimeStamp::operator+(double dDays)

bool TimeStamp::operator>=(const TimeStamp &cOtherDate)
{
	return this->d_days >= cOtherDate.d_days;
} // bool CTime::operator>=(const CTime &cOtherDate)

bool TimeStamp::operator>(const TimeStamp &cOtherDate)
{
	return this->d_days > cOtherDate.d_days;
} // bool CTime::operator>(const CTime &cOtherDate)

bool TimeStamp::operator<=(const TimeStamp &cOtherDate)
{
	return this->d_days <= cOtherDate.d_days;
} // bool CTime::operator<=(const CTime &cOtherDate)

bool TimeStamp::operator<(const TimeStamp &cOtherDate)
{
	return this->d_days < cOtherDate.d_days;
} // bool CTime::operator<(const CTime &cOtherDate)

bool TimeStamp::operator==(const TimeStamp &cOtherDate)
{
	return this->d_days == cOtherDate.d_days;
} // bool CTime::operator==(const CTime &cOtherDate)