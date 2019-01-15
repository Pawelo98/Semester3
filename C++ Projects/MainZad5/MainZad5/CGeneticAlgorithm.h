#pragma once
#include <vector>
#include <random>
#include "CIndividual.h"
#include "CKnapsackProblem.h"
#define POP_SIZE 20
#define MUT_PROB 0.1
#define CROSS_PROB 0.6
#define ITERS_NUMBER 5000
#define POP_DEFAULT 20
#define MUT_DEFAULT 0.1
#define CROSS_DEFAULT 0.6
#define ITERS_DEFAULT 10000
#define MUTATION_ERROR "Wrong mutation probability, set to default = "
#define POPSIZE_ERROR "Wrong popsize, set to default = "
#define CROSS_ERROR "Wrong crossover probability, set to default = "
#define ITERS_ERROR "Wrong iterations number, set to default = "

using namespace std;

class CGeneticAlgorithm
{
public:
	CGeneticAlgorithm(int iPopSize, double dMutProb, double dCrossProb, double dGeneticTime);
	~CGeneticAlgorithm() {};
	void vRun(CKnapsackProblem *cKnapsackProblem);
	CIndividual cFindBestIndividual(CKnapsackProblem *cKnapsackProblem);
private:
	double d_mutation_chance;
	double d_crossover_chance;
	int i_population_size;
	double d_genetic_time;
	mt19937 gen;
	vector<CIndividual> v_population;
	vector<double> v_population_fitnesses;
};