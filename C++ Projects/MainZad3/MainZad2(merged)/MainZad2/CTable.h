#pragma once
#include <string>
#define NUMBER_TO_CREATE "Podaj ilosc obiektow do utworzenia: "
#define INDEX_NAME "Podaj indeks obiektu, ktoremu chcesz zmienic nazwe: "
#define OBJECT_NAME "Podaj nazwe obiektu: "
#define WRONG_INDEX "Wpisales zly indeks obiektu! "
#define INDEX_REMOVE "Podaj indeks obiektu, ktory chcesz usunac: "
#define INDEX_COPY "Podaj indeks obiektu, ktorego kopie chcesz zrobic: "
#define INDEX_SHOW "Podaj indeks obiektu, ktory chcesz wyswietlic: "
#define INDEX_CHANGE "Podaj indeks obiektu, ktoremu chcesz zmienic wartosc komorki: "
#define INDEX_COMM "Podaj indeks komorki, ktorej chcesz zmienic wartosc: "
#define GET_VALUE "Podaj wartosc: "
#define INDEX_LENGTH "Podaj indeks obiektu, ktorego dlugosc tablicy chcesz sprawdzic: "
#define GET_LENGTH "Dlugosc tablicy tego obiektu: "
#define OPEN_BEZP "bezp: '<"
#define OPEN_PAR "parametr: '<"
#define CLOSE_CONSTRUCTOR ">' "
#define OPEN_COPY "kopiuje: '<"
#define COPY_ADDITION "_copy"
#define DESTR_REMOVE "usuwam: '<"
#define WRONG_INDEX "Wpisales zly indeks!"
#define OPEN_TO_STRING "<"
#define LENGTH_TO_STRING "> len: "
#define VALUES_TO_STRING " values: <"
#define PRZECINEK ", "
#define EMPTY_STRING ""

using namespace std;

class CTable
{
public:
	CTable();
	CTable(string sTableName, int iTableSize);
	CTable(CTable &pcOther);
	~CTable();

	string sGetName();
	void vSetName(string sNewName);
	int iGetSize();
	void vSetSize(int iNewSize);
	string sGetValues();
	int* piGetPitable();
	bool bCheckIndex(int iIndex);
	//bool bChangeSize(int iNewSize);
	void vTransferTable(CTable &pcFrom, CTable &pcTo);
	bool bChangeValue(int iTablePosition, int iNewValue);
	bool bReadValue(int iTablePosition);
	void vSetTableName(string sNewName);
	string sObjectToString();
	//void vSetTableSize(int iNewLength);
	void vResize(int newSize);

	const int CASUAL_TABLE_SIZE = 10;
	const string CASUAL_TABLE_NAME = "Casual Table";
	const char CHAR_ZERO = '0';

private:
	string s_name;
	int *pi_table;
	int i_size;
};

