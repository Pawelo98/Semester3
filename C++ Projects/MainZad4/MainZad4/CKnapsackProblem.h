#pragma once
#include <vector>

using namespace std;

class CKnapsackProblem
{
public:
	CKnapsackProblem(double dSize);
	~CKnapsackProblem() { delete v_items_weight; delete v_items_value; };
	double dGetSize();
	vector<double> vGetItemsWeight();
	vector<double> vGetItemsValue();
	double dSolutionResult(vector<int> vGenotype);
	double dSolutionWeight(vector<int> vGenotype);
	void vSetSize(double dSize);
	void vSetItemsWeight(vector<double> *vItemsWeight);
	void vSetItemsValue(vector<double> *vItemsValue);
private:
	double d_size;
	vector<double> *v_items_weight;
	vector<double> *v_items_value;
};