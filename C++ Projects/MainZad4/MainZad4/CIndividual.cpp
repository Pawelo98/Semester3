#include "pch.h"
#include "CIndividual.h"

using namespace std;

CIndividual::CIndividual()
{
	random_device rd;
	mt19937 generator(rd());
	gen = generator;
} // CIndividual::CIndividual()

vector<int> CIndividual::vGetGenotype()
{
	return v_genotype;
} // vector<int> CIndividual::vGetGenotype()

void CIndividual::vSetGenotype(vector<int> vGenotype)
{
	v_genotype = vGenotype;
} // void CIndividual::vSetGenotype(vector<int> vGenotype)

double CIndividual::dFitness(CKnapsackProblem *cKnapsackProblem)
{
	if ((*cKnapsackProblem).dSolutionWeight(this->vGetGenotype()) > (*cKnapsackProblem).dGetSize()) return 0;
	else return (*cKnapsackProblem).dSolutionResult(this->vGetGenotype());
} // double CIndividual::dFitness(CKnapsackProblem *cKnapsackProblem)

void CIndividual::vMutate(double d_mutation_chance)
{
	for (int i = 0; i < v_genotype.size(); i++)
	{
		uniform_real_distribution<> distribution(0, 1);
		if (d_mutation_chance > distribution(gen))
		{
			if (v_genotype.at(i) == 1) v_genotype.at(i) = 0;
			else v_genotype.at(i) = 1;
		} // if (d_mutation_chance > distribution(gen))
	} // for (int i = 0; i < v_genotype.size(); i++)
} // void CIndividual::vMutate(double d_mutation_chance)

vector<CIndividual> CIndividual::crossGenotypes(CIndividual *cIndividual)
{
	uniform_int_distribution<> distribution(1, v_genotype.size() - 1);
	int iCutPlace = distribution(gen);

	vector<CIndividual> vChilds;
	vector <int> vChild1;
	vector <int> vChild2;

	for (int i = 0; i < iCutPlace; i++)
	{
		vChild1.push_back(v_genotype.at(i));
		vChild2.push_back((*cIndividual).v_genotype.at(i));
	} // for (int i = 0; i < iCutPlace; i++)

	for (int j = iCutPlace; j < v_genotype.size(); j++)
	{
		vChild2.push_back(v_genotype.at(j));
		vChild1.push_back((*cIndividual).v_genotype.at(j));
	} // for (int j = iCutPlace; j < v_genotype.size(); j++)
	this->vSetGenotype(vChild1);
	(*cIndividual).vSetGenotype(vChild2);

	vChilds.push_back(*this);
	vChilds.push_back(*cIndividual);
	return vChilds;
} // vector<CIndividual> CIndividual::crossGenotypes(CIndividual *cIndividual)