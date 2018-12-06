#pragma once
#include <vector>
#include <iostream>
#define KNAPSACK_SIZE 4.3
#define KNAPSACK_DEFAULT 5.0
#define KNAPSACK_ERROR "Wrong knapsack size, set to default = "
#define VALUES_VECTOR { 1.3, 2.2, 1.4, 2.2, 0.8, 1.7 }
#define WEIGHTS_VECTOR { 0.7, 1.1, 1.3, 2.1, 1.1, 2.4 }
#define THE_BEST_GENOTYPE "The best individual genotype: "
#define FITNESS_STRING " of fitness = "
#define WEIGHT_STRING " and weight = "

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