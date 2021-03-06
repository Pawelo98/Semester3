#include "pch.h"
#include <iostream>
#include "CGeneticAlgorithm.h"
#include "CIndividual.h"
#include "CKnapsackProblem.h"

using namespace std;

int main()
{
	CKnapsackProblem* ckp = new CKnapsackProblem(KNAPSACK_SIZE);
	CGeneticAlgorithm* cga = new CGeneticAlgorithm(POP_SIZE, MUT_PROB, CROSS_PROB, ITERS_NUMBER);

	vector<double>* vKnapsackValues = new vector<double>(VALUES_VECTOR);
	vector<double>* vKnapsackWeights = new vector<double>(WEIGHTS_VECTOR);
	
	ckp->vSetItemsValue(vKnapsackValues);
	ckp->vSetItemsWeight(vKnapsackWeights);
	cga->vRun(ckp);

	CIndividual cBestIndividual = cga->cFindBestIndividual(ckp);

	cout << THE_BEST_GENOTYPE;
	for (int i = 0; i < cBestIndividual.vGetGenotype().size(); i++)
	{
		cout << cBestIndividual.vGetGenotype().at(i);
	} // for (int i = 0; i < cBestIndividual.vGetGenotype().size(); i++)
	cout << FITNESS_STRING << cBestIndividual.dFitness(ckp) << WEIGHT_STRING << ckp->dSolutionWeight(cBestIndividual.vGetGenotype()) << endl;
	delete ckp;
	delete cga;
	return 0;
} // int main()
