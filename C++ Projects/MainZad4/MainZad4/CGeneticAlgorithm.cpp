#include "pch.h"
#include "CGeneticAlgorithm.h"
#include <iostream>

using namespace std;

CGeneticAlgorithm::CGeneticAlgorithm(int iPopSize, double dMutProb, double dCrossProb, int iIters)
{
	d_mutation_chance = dMutProb;
	d_crossover_chance = dCrossProb;
	i_population_size = iPopSize;
	i_iteration_number = iIters;
	if (dMutProb < 0 || dMutProb>1)
	{
		cout << MUTATION_ERROR << MUT_DEFAULT << endl;
		d_mutation_chance = MUT_DEFAULT;
	} // if (dMutProb < 0 || dMutProb>1)
	if (dCrossProb < 0 || dCrossProb>1)
	{
		cout << CROSS_ERROR << CROSS_DEFAULT << endl;
		d_crossover_chance = CROSS_DEFAULT;
	} // if (dCrossProb < 0 || dCrossProb>1)
	if (iPopSize <= 0)
	{
		cout << POPSIZE_ERROR << POP_DEFAULT << endl;
		i_population_size = POP_DEFAULT;
	} // if (iPopSize <= 0)
	if (iIters <=0)
	{
		cout << ITERS_ERROR << ITERS_DEFAULT << endl;
		i_iteration_number = ITERS_DEFAULT;
	} // if (iIters <=0)
	random_device rd;
	mt19937 generator(rd());
	gen = generator;
} // CGeneticAlgorithm::CGeneticAlgorithm(int iPopSize, double dMutProb, double dCrossProb, int iIters)

void CGeneticAlgorithm::vRun(CKnapsackProblem *cKnapsackProblem)
{
	uniform_int_distribution<> distribution(0, 1);
	for (int i = 0; i < i_population_size; i++)
	{
		CIndividual cIndividual;
		vector<int> cIndividualGenotype;
		for (int l = 0; l < cKnapsackProblem->vGetItemsValue().size(); l++)
		{
			cIndividualGenotype.push_back(distribution(gen));
		}
		cIndividual.vSetGenotype(cIndividualGenotype);
		v_population.push_back(cIndividual);
	} // for (int i = 0; i < i_population_size; i++)
	// finished generating population
	
	for (int j = 0; j < i_iteration_number; j++)
	{
		for (int g = 0; g < v_population.size(); g++)
		{
			if (j == 0) v_population_fitnesses.push_back(v_population.at(g).dFitness(cKnapsackProblem));
			else if (j==1 && (v_population.size()%2==1) && g==v_population.size()-1) v_population_fitnesses.push_back(v_population.at(g).dFitness(cKnapsackProblem));
			else v_population_fitnesses.at(g) = v_population.at(g).dFitness(cKnapsackProblem);
		} // for (int g = 0; g < v_population.size(); g++)
		// finished fitnessing population
		
		vector<CIndividual> vNewPopulation, vCurrentPopulation;
		int index1, index2;
		CIndividual toCross1, toCross2;
		while (vNewPopulation.size() < v_population.size())
		{
			uniform_int_distribution<> distribution2(0, v_population.size() - 1);
			index1 = distribution2(gen);
			index2 = distribution2(gen);

			if (v_population.at(index1).dFitness(cKnapsackProblem) > v_population.at(index2).dFitness(cKnapsackProblem)) toCross1 = v_population.at(index1);
			else toCross1 = v_population.at(index2);
			index1 = distribution2(gen);
			index2 = distribution2(gen);

			if (v_population.at(index1).dFitness(cKnapsackProblem) > v_population.at(index2).dFitness(cKnapsackProblem)) toCross2 = v_population.at(index1);
			else toCross2 = v_population.at(index2);

			vCurrentPopulation = toCross1.crossGenotypes(&toCross2);
			vNewPopulation.push_back(vCurrentPopulation.at(0));
			vNewPopulation.push_back(vCurrentPopulation.at(1));
			vCurrentPopulation.clear();
		} // while (vNewPopulation.size() < v_population.size())
		v_population = vNewPopulation;
		// finished crossovering population
		
		for (int h = 0; h < v_population.size(); h++)
		{
			v_population.at(h).vMutate(d_mutation_chance);
		} // for (int h = 0; h < v_population.size(); h++)
		// finished mutating population
	} // for (int j = 0; j < i_iteration_number; j++)
	// finished run of genetic algorithm
} // void CGeneticAlgorithm::vRun(CKnapsackProblem *cKnapsackProblem)

CIndividual CGeneticAlgorithm::cFindBestIndividual(CKnapsackProblem *cKnapsackProblem)
{
	int iBestIndividual = 0;
	double dBestFitness = 0;
	for (int i = 0; i < v_population.size(); i++)
	{
		if (v_population.at(i).dFitness(cKnapsackProblem) > dBestFitness)
		{
			dBestFitness = v_population.at(i).dFitness(cKnapsackProblem);
			iBestIndividual = i;
		} // if (v_population.at(i).dFitness(cKnapsackProblem) > dBestFitness)
	} // for (int i = 0; i < v_population.size(); i++)
	return v_population.at(iBestIndividual);
} // CIndividual CGeneticAlgorithm::cFindBestIndividual(CKnapsackProblem *cKnapsackProblem)