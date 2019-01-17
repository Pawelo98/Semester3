#include "pch.h"
#include <iostream>
#include <string>
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
	if (iYears <= 0 || iMonths <= 0 || iMonths > NUMBER_OF_MONTHS || iDays <= 0 || (iYears % 4 == 0 && iMonths == 2 && iDays > DAYS_IN_MONTHS[iMonths - 1] + 1) || (!(iYears % 4 == 0 && iMonths == 2) && iDays > DAYS_IN_MONTHS[iMonths - 1]) || iHours<0 || iMinutes<0 || iMinutes>(MINS_IN_HOUR-1) || iHours > (HOURS_IN_DAY-1))
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
	int i;
	for (i = 1; iDays > daysThisYear+1; i++)
	{
		if ((i % LEAP4 == 0) && (!(i % LEAP100 == 0) || (i % LEAP400 == 0))) iDays -= (DAYS_IN_A_YEAR + 1);
		else iDays -= DAYS_IN_A_YEAR;
		iYear++;
		if (((i+1) % LEAP4 == 0) && (!((i+1) % LEAP100 == 0) || ((i+1) % LEAP400 == 0))) daysThisYear = (DAYS_IN_A_YEAR + 1);
		else daysThisYear = DAYS_IN_A_YEAR;
	} // for (int i = 1; iDays >= DAYS_IN_A_YEAR; i++)
	int daysInMonth[12];
	for (int p = 0; p < 12; p++)
	{
		daysInMonth[p] = DAYS_IN_MONTHS[p];
	}
	for (int j = 1; iDays > daysInMonth[j - 1]; j++)
	{
		if ((i % 4) == 0 && j == 2) iDays -= (DAYS_IN_MONTHS[j - 1] + 1);
		else iDays -= DAYS_IN_MONTHS[j - 1];
		iMonth++;
		if ((i % 4) == 0 && (j + 1) == 2) daysInMonth[j] = DAYS_IN_MONTHS[j] + 1;
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
	return to_string(iDay) + "." + to_string(iMonth) + "." + to_string(iYear) + EMPTY + to_string(iHours) + DWUKROPEK + to_string(iMinutes);
} // string TimeStamp::sDateToString()

string TimeStamp::sFormat(string sToFormat)
{
	double iDays = d_days;
	int iDay = -1;
	int iMonth = 1;
	int iYear = 1;
	int iHours = 0;
	int iMinutes = 1;
	int daysThisYear = DAYS_IN_A_YEAR;
	int i;
	for (i = 1; iDays > daysThisYear + 1; i++)
	{
		if ((i % LEAP4 == 0) && (!(i % LEAP100 == 0) || (i % LEAP400 == 0))) iDays -= (DAYS_IN_A_YEAR + 1);
		else iDays -= DAYS_IN_A_YEAR;
		iYear++;
		if (((i + 1) % LEAP4 == 0) && (!((i + 1) % LEAP100 == 0) || ((i + 1) % LEAP400 == 0))) daysThisYear = (DAYS_IN_A_YEAR + 1);
		else daysThisYear = DAYS_IN_A_YEAR;
	} // for (int i = 1; iDays >= DAYS_IN_A_YEAR; i++)
	int daysInMonth[12];
	for (int p = 0; p < 12; p++)
	{
		daysInMonth[p] = DAYS_IN_MONTHS[p];
	}
	for (int j = 1; iDays > daysInMonth[j - 1]; j++)
	{
		if ((i % 4) == 0 && j == 2) iDays -= (DAYS_IN_MONTHS[j - 1] + 1);
		else iDays -= DAYS_IN_MONTHS[j - 1];
		iMonth++;
		if ((i % 4) == 0 && (j + 1) == 2) daysInMonth[j] = DAYS_IN_MONTHS[j] + 1;
	} // for (int j = 1; iDays >= DAYS_IN_MONTHS[j-1]; j++)
	while (iDays >= 1)
	{
		iDay++;
		iDays--;
	} // while(iDays >= 1)
	while (iDays > DAYS_IN_HOUR)
	{
		iDays -= DAYS_IN_HOUR;
		iHours++;
	} // while(iDays > 0.04166666667)
	while (iDays > DAYS_IN_MIN)
	{
		iDays -= DAYS_IN_MIN;
		iMinutes++;
	} // while(iDays > 0.00069444444)
	if (iDay == 0) iDay = 1;
	
	i = 0;
	while(i< sToFormat.length())
	{
		if (sToFormat[i] == 'y' && sToFormat[i+1] == 'y' && sToFormat[i+2] == 'y' && sToFormat[i+3] == 'y')
		{
			if (iYear < 1000)
			{
				if (iYear < 100)
				{
					if (iYear < 10)
					{
						sToFormat.replace(i, 1, to_string(0));
						sToFormat.replace(i+1, 1, to_string(0));
						sToFormat.replace(i+2, 1, to_string(0));
						sToFormat.replace(i+3, 1, to_string(iYear));
					}
					else
					{
						sToFormat.replace(i, 1, to_string(0));
						sToFormat.replace(i+1, 1, to_string(0));
						sToFormat.replace(i + 2, 2, to_string(iYear));
					}
				}
				else
				{
					sToFormat.replace(i, 1, to_string(0));
					sToFormat.replace(i + 1, 3, to_string(iYear));
				}
			}
			else
			{
				sToFormat.replace(i, 4, to_string(iYear));
			}
			i += 4;
		}
		else if (sToFormat[i] == 'M' && sToFormat[i + 1] == 'M')
		{
			if (iMonth < 10)
			{
				sToFormat.replace(i, 1, to_string(0));
				sToFormat.replace(i+1, 1, to_string(iMonth));
			}
			else
			{
				sToFormat.replace(i, 2, to_string(iMonth));
			}
			i += 2;
		}
		else if (sToFormat[i] == 'd' && sToFormat[i + 1] == 'd')
		{
			if (iDay < 10)
			{
				sToFormat.replace(i, 1, to_string(0));
				sToFormat.replace(i + 1, 1, to_string(iDay));
			}
			else
			{
				sToFormat.replace(i, 2, to_string(iDay));
			}
			i += 2;
		}
		else if (sToFormat[i] == 'h' && sToFormat[i + 1] == 'h')
		{
			if (iHours < 10)
			{
				sToFormat.replace(i, 1, to_string(0));
				sToFormat.replace(i + 1, 1, to_string(iHours));
			}
			else
			{
				sToFormat.replace(i, 2, to_string(iHours));
			}
			i += 2;
		}
		else if (sToFormat[i] == 'm' && sToFormat[i + 1] == 'm')
		{
			if (iMinutes < 10)
			{
				sToFormat.replace(i, 1, to_string(0));
				sToFormat.replace(i + 1, 1, to_string(iMinutes));
			}
			else
			{
				sToFormat.replace(i, 2, to_string(iMinutes));
			}
			i += 2;
			i += 2;
		}
		else
		{
			i++;
		}
	} // while(int i=0 < sToFormat.length())
	return sToFormat;
}

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