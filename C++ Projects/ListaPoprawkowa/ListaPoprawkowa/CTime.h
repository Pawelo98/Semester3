#pragma once
#include <string>
#define DAYS_IN_A_YEAR 365
#define WRONG_DATE "Date you passed is wrong, set it to default = 01.01.01"
#define LEAP4 4
#define LEAP100 100
#define LEAP400 400
#define NUMBER_OF_MONTHS 12
#define SEPARATING_LINE "-----------------------------------------------------------------------------"
#define THIRTEEN 13
#define ELEVEN 11
#define CURR_YEAR 2019
#define THREE_SIX_SIX 366
#define HOURS_TO_DIVIDE 1032
#define HOURS_TO_CONSTRUCTOR 7081.43

using namespace std;

class CTime
{
public:
	CTime() { d_days = 1.0; };
	CTime(double dDays);
	CTime(int iDay, int iMonth, int iYear);

	double dGetDays() { return d_days; };
	string sDateToString();

	CTime operator-(double dDays);
	CTime operator+(double dDays);
	double operator-(const CTime &cOtherDate);
	bool operator>=(const CTime &cOtherDate);
	bool operator<=(const CTime &cOtherDate);
	bool operator==(const CTime &cOtherDate);
	bool operator>(const CTime &cOtherDate);
	bool operator<(const CTime &cOtherDate);
protected:
	double d_days;
	const int DAYS_IN_MONTHS[NUMBER_OF_MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
};