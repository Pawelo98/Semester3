#include "pch.h"
#include "CKnapsackProblem.h"

CKnapsackProblem::CKnapsackProblem(double dSize)
{
	d_size = dSize;
	if (dSize <= 0)
	{
		cout << KNAPSACK_ERROR << KNAPSACK_DEFAULT << endl;
		d_size = KNAPSACK_DEFAULT;
	} // if (dSize <= 0)
} // CKnapsackProblem::CKnapsackProblem(double dSize)

double CKnapsackProblem::dGetSize()
{
	return d_size;
} // double CKnapsackProblem::dGetSize()

vector<double> CKnapsackProblem::vGetItemsWeight()
{
	return *v_items_weight;
} // vector<double> CKnapsackProblem::vGetItemsWeight()

vector<double> CKnapsackProblem::vGetItemsValue()
{
	return *v_items_value;
} // vector<double> CKnapsackProblem::vGetItemsValue()

double CKnapsackProblem::dSolutionResult(vector<int> vGenotype)
{
	double dValue = 0;
	for (int i = 0; i < vGenotype.size(); i++)
	{
		if (vGenotype.at(i) == 1)
		{
			dValue += v_items_value->at(i);
		} // if (vGenotype.at(i) == 1)
	} // for (int i = 0; i < vGenotype.size(); i++)
	return dValue;
} // double CKnapsackProblem::dSolutionResult(vector<int> vGenotype)

double CKnapsackProblem::dSolutionWeight(vector<int> vGenotype)
{
	double dValue = 0;
	for (int i = 0; i < vGenotype.size(); i++)
	{
		if (vGenotype.at(i) == 1)
		{
			dValue += v_items_weight->at(i);
		} // if (vGenotype.at(i) == 1)
	} // for (int i = 0; i < vGenotype.size(); i++)
	return dValue;
} // double CKnapsackProblem::dSolutionWeight(vector<int> vGenotype)

void CKnapsackProblem::vSetSize(double dSize)
{
	if(dSize>0) d_size = dSize;
} // void CKnapsackProblem::vSetSize(double dSize)

void CKnapsackProblem::vSetItemsValue(vector<double> *vItemsValue)
{
	v_items_value = vItemsValue;
} // void CKnapsackProblem::vSetItemsValue(vector<double> *vItemsValue)

void CKnapsackProblem::vSetItemsWeight(vector<double> *vItemsWeight)
{
	v_items_weight = vItemsWeight;
} // void CKnapsackProblem::vSetItemsWeight(vector<double> *vItemsWeight)

