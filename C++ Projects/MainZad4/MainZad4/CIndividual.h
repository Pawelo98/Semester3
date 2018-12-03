#pragma once
#include <random>
#include <vector>
#include "CKnapsackProblem.h"

using namespace std;

class CIndividual
{
public:
	CIndividual();
	~CIndividual() {};
	vector<int> vGetGenotype();
	void vSetGenotype(vector<int> vGenotype);
	double dFitness(CKnapsackProblem *cKnapsackProblem);
	void vMutate(double d_mutation_chance);
	vector<CIndividual> crossGenotypes(CIndividual *cIndividual);
private:
	mt19937 gen;
	vector<int> v_genotype;
};