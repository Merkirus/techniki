#pragma once

#include <vector>
#include "my_random.h"
#include "c_knapsack_problem.h"

#define BASE_GEN_SIZE 4

class CIndividual
{
public:
    CIndividual();
    CIndividual(int gen_size);
    void crossover(CIndividual *parent1, CIndividual *parent2, int pivot);
    int get_fitness();
    void random_genotype();
    void mutate(int mut_prob);
    void mutate_mod(int mut_prob, CIndividual *mask);
    void set_fitness(CKnapsackProblem *prob);
    int get_gen_size();
    std::vector<bool> get_vec_genotype();
private:
    std::vector<bool> vec_genotype;
    int gen_size;
    int fitness;
};
