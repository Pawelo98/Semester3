#include "pch.h"
#include <iostream>
#include "CGeneticAlgorithm.h"
#include "CIndividual.h"
#include "CKnapsackProblem.h"

using namespace std;

int main()
{
	CKnapsackProblem* ckp = new CKnapsackProblem(4.3);
	CGeneticAlgorithm* cga = new CGeneticAlgorithm(20, 0.1, 0.6, 5000);

	vector<double> vItemsValue{ 1.3, 2.2, 1.4, 2.2, 0.8, 1.7 };
	vector<double> vItemsWeight{ 0.7, 1.1, 1.3, 2.1, 1.1, 2.4 };
	vector<double>* vKnapsackValues = new vector<double>(vItemsValue);
	vector<double>* vKnapsackWeights = new vector<double>(vItemsWeight);
	
	ckp->vSetItemsValue(vKnapsackValues);
	ckp->vSetItemsWeight(vKnapsackWeights);
	cga->vRun(ckp);

	CIndividual cBestIndividual = cga->cFindBestIndividual(ckp);

	cout << "The best individual genotype: ";
	for (int i = 0; i < cBestIndividual.vGetGenotype().size(); i++)
	{
		cout << cBestIndividual.vGetGenotype().at(i);
	} // for (int i = 0; i < cBestIndividual.vGetGenotype().size(); i++)
	cout << " of fitness = " << cBestIndividual.dFitness(ckp) << " and weight = " << ckp->dSolutionWeight(cBestIndividual.vGetGenotype()) << endl;
	delete ckp;
	delete cga;
	return 0;
} // int main()
