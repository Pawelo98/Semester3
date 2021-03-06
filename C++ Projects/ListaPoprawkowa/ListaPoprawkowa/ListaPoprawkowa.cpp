#include "pch.h"
#include <iostream>
#include "CTime.h"
#include "TimeStamp.h"

using namespace std;

int main()
{
	CTime *time1 = new CTime(THIRTEEN, 1, CURR_YEAR);
	CTime *time2 = new CTime(TWO_NINE, TWO, FOUR);

	cout << time1->dGetDays() << endl;
	cout << time1->sDateToString() << endl;

	cout << time2->dGetDays() << endl;
	cout << time2->sDateToString() << endl;

	CTime *time3 = new CTime(*time1 + time2->dGetDays());

	cout << time3->dGetDays() << endl;
	cout << time3->sDateToString() << endl;

	cout << *time1 - *time2 << endl;
	cout << (*time1 > *time2) << endl;
	cout << (*time1 >= *time2) << endl;
	cout << (*time1 <= *time2) << endl;
	cout << (*time1 < *time2) << endl;
	cout << (*time1 == *time2) << endl << endl;

	delete time1, time2, time3;

	cout << SEPARATING_LINE << endl << endl;

	TimeStamp *stamp1 = new TimeStamp(ELEVEN, THIRTEEN, THIRTEEN, 1, THIRTEEN);
	TimeStamp *stamp2 = new TimeStamp(HOURS_TO_CONSTRUCTOR);

	TimeStamp *stamp3 = new TimeStamp(*stamp1 - HOURS_TO_DIVIDE);

	cout << stamp1->dGetDays() << endl;
	cout << stamp1->sDateToString() << endl;

	cout << stamp2->dGetDays() << endl;
	cout << stamp2->sDateToString() << endl;

	cout << stamp3->dGetDays() << endl;
	cout << stamp3->sDateToString() << endl;

	cout << (*stamp2 - *stamp1) << endl;
	cout << (*stamp3 > *stamp2) << endl;
	cout << (*stamp3 >= *stamp2) << endl;
	cout << (*stamp3 <= *stamp2) << endl;
	cout << (*stamp3 < *stamp2) << endl;
	cout << (*stamp3 == *stamp2) << endl << endl;

	cout << stamp1->sFormat("Ala MM yyyy") << endl;

	delete stamp1, stamp2, stamp3;

	return 0;

} // int main()
