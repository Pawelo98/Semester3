#pragma once
#include <vector>
#include <random>
#include "CIndividual.h"
#include "CKnapsackProblem.h"

using namespace std;

class CGeneticAlgorithm
{
public:
	CGeneticAlgorithm(int iPopSize, double dMutProb, double dCrossProb, int iIters);
	~CGeneticAlgorithm() {};
	void vRun(CKnapsackProblem *cKnapsackProblem);
	CIndividual cFindBestIndividual(CKnapsackProblem *cKnapsackProblem);
private:
	double d_mutation_chance;
	double d_crossover_chance;
	int i_population_size;
	int i_iteration_number;
	mt19937 gen;
	vector<CIndividual> v_population;
	vector<double> v_population_fitnesses;
};