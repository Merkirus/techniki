#pragma once

#include "c_individual.h"
#include "c_knapsack_problem.h"
#include "my_random.h"
#include <vector>

#define BASE_POPS 4
#define BASE_CROSS_PROB 0.6
#define BASE_MUT_PROB 0.1
#define ITERATIONS 1000

class CGeneticAlgoritm
{
public:
    CGeneticAlgoritm();
    CGeneticAlgoritm(int pops_size, double cross_prob, double mut_prob);
    CGeneticAlgoritm(CKnapsackProblem knap);
    CIndividual pcBestMatch();
    void randomStartingPops();
    void add_knap(CKnapsackProblem knap);
    void rate_genotypes();
    void run();
    void run_mod();
private:
    CKnapsackProblem knap;
    std::vector<CIndividual> vec_pops;
    int pops_size;
    double cross_prob;
    double mut_prob;
};
