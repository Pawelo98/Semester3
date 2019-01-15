#include "pch.h"
#include "CTime.h"
#include <iostream>
#include <string>

using namespace std;

CTime::CTime(int iDay, int iMonth, int iYear)
{
	if (iYear < 0 || iMonth < 0 || iMonth > NUMBER_OF_MONTHS || iDay < 0 || iDay > DAYS_IN_MONTHS[iMonth - 1])
	{
		iYear = 1;
		iMonth = 1;
		iDay = 1;
		cout << WRONG_DATE << endl;
	} // if (iYear < 0 || iMonth < 0 || iMonth > 12 || iDay < 0 || iDay > DAYS_IN_MONTHS[iMonth - 1])
	double days = iDay;
	// days from iDay
	for (int i = 0; i < iMonth - 1; i++)
	{
		days += DAYS_IN_MONTHS[i];
	} // for (int i = 0; i < iMonth - 1; ++i)
	// days from iMonth
	days += (iYear-1)*DAYS_IN_A_YEAR;
	for (int j = 1; j < iYear; j++)
	{
		if ((j % LEAP4 == 0) && (!(j % LEAP100 == 0) || (j % LEAP400 == 0))) days++;
	}
	// days from iYear
	d_days = days;
} // CTime::CTime(int iDay, int iMonth, int iYear)

CTime::CTime(double dDays)
{
	if (dDays <= 0)
	{
		cout << WRONG_DATE << endl;
		d_days = 1;
	} // if (iDays <= 0)
	else d_days = dDays;
} // CTime::CTime(int iDays)

string CTime::sDateToString()
{
	int iDays = d_days;
	int iDay = 0;
	int iMonth = 1;
	int iYear = 1;
	for (int i = 1; iDays > DAYS_IN_A_YEAR; i++)
	{
		if ((i % LEAP4 == 0) && (!(i % LEAP100 == 0) || (i % LEAP400 == 0))) iDays -= (DAYS_IN_A_YEAR+1);
		else iDays -= DAYS_IN_A_YEAR;
		iYear++;
	} // for (int i = 1; iDays >= DAYS_IN_A_YEAR; i++)
	for (int j = 1; iDays > DAYS_IN_MONTHS[j-1]; j++)
	{
		iDays -= DAYS_IN_MONTHS[j - 1];
		iMonth++;
	} // for (int j = 1; iDays >= DAYS_IN_MONTHS[j-1]; j++)
	iDay = iDays;
	return to_string(iDay) + "." + to_string(iMonth) + "." + to_string(iYear);
} // string CTime::sDateToString()

CTime CTime::operator-(double dDays)
{
	return CTime(this->d_days - dDays);
} // CTime CTime::operator-(int iDays) 

CTime CTime::operator+(double dDays)
{
	return CTime(this->d_days + dDays);
} // CTime CTime::operator+(int iDays)

double CTime::operator-(const CTime &cOtherDate)
{
	return this->d_days - cOtherDate.d_days;
} // int CTime::operator-(const CTime &cOtherDate)

bool CTime::operator>=(const CTime &cOtherDate)
{
	return this->d_days >= cOtherDate.d_days;
} // bool CTime::operator>=(const CTime &cOtherDate)

bool CTime::operator>(const CTime &cOtherDate)
{
	return this->d_days > cOtherDate.d_days;
} // bool CTime::operator>(const CTime &cOtherDate)

bool CTime::operator<=(const CTime &cOtherDate)
{
	return this->d_days <= cOtherDate.d_days;
} // bool CTime::operator<=(const CTime &cOtherDate)

bool CTime::operator<(const CTime &cOtherDate)
{
	return this->d_days < cOtherDate.d_days;
} // bool CTime::operator<(const CTime &cOtherDate)

bool CTime::operator==(const CTime &cOtherDate)
{
	return this->d_days == cOtherDate.d_days;
} // bool CTime::operator==(const CTime &cOtherDate)