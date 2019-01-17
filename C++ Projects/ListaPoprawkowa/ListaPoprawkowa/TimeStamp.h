#pragma once
#include "pch.h"
#include "CTime.h"
#define WRONG_DATE_STAMP "Date you passed is wrong, set it to default = 01.01.01 00:00"
#define MINS_IN_HOUR 60
#define DAYS_IN_MIN 0.00069444444
#define HOURS_IN_DAY 24
#define DAYS_IN_HOUR 0.04166666667
#define EMPTY "  "
#define DWUKROPEK ":"

class TimeStamp : CTime
{
public:
	TimeStamp();
	TimeStamp(double dDays);
	TimeStamp(int iMinutes, int iHours, int iDays, int iMonths, int iYears);

	double dGetDays() { return d_days; };
	string sDateToString();
	string sFormat(string sToFormat);

	TimeStamp operator-(double dDays);
	TimeStamp operator+(double dDays);
	double operator-(const TimeStamp &other);
	bool operator>=(const TimeStamp &cOtherDate);
	bool operator<=(const TimeStamp &cOtherDate);
	bool operator==(const TimeStamp &cOtherDate);
	bool operator>(const TimeStamp &cOtherDate);
	bool operator<(const TimeStamp &cOtherDate);
};