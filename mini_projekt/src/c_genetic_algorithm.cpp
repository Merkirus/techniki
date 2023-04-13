#include "../include/c_genetic_algorithm.h"

CGeneticAlgoritm::CGeneticAlgoritm()
{
    pops_size = BASE_POPS;
    cross_prob = BASE_CROSS_PROB;
    mut_prob = BASE_MUT_PROB;
    vec_pops.reserve(pops_size);
}

CGeneticAlgoritm::CGeneticAlgoritm(int pops_size, double cross_prob, double mut_prob)
{
    this->pops_size = pops_size;
    this->cross_prob = cross_prob;
    this->mut_prob = mut_prob;
    vec_pops.reserve(pops_size);
}

CGeneticAlgoritm::CGeneticAlgoritm(CKnapsackProblem knap)
{
    pops_size = BASE_POPS;
    cross_prob = BASE_CROSS_PROB;
    mut_prob = BASE_MUT_PROB;
    vec_pops.reserve(pops_size);
    this->knap = knap;
}

CIndividual CGeneticAlgoritm::pcBestMatch()
{
    if (pops_size == 0)
        return NULL;

    if (pops_size == 1)
        return vec_pops[0];

    CIndividual max = vec_pops[0];

    for (int it = 1; it < pops_size; ++it)
        if (max.get_fitness() < vec_pops[it].get_fitness())
            max = vec_pops[it];

    return max;
}

void CGeneticAlgoritm::randomStartingPops()
{
    for (int i = 0; i < pops_size; ++i) {
        CIndividual temp(knap.get_vec_size());
        temp.random_genotype();
        vec_pops.push_back(temp);
    }
}

void CGeneticAlgoritm::add_knap(CKnapsackProblem knap)
{
    this->knap = knap;
}

void CGeneticAlgoritm::run()
{
    randomStartingPops();
    for (int i = 0; i < ITERATIONS; ++i) {
        rate_genotypes();
        std::vector<CIndividual> vec_future_pops;
        while (vec_future_pops.size() != pops_size) {
            CIndividual contender1 = vec_pops[Rand_int::guess(0, pops_size-1)];
            CIndividual contender2 = vec_pops[Rand_int::guess(0, pops_size-1)];
            CIndividual parent1 = contender1.get_fitness() > contender2.get_fitness() ? contender1 : contender2;
            contender1 = vec_pops[Rand_int::guess(0, pops_size-1)];
            contender2 = vec_pops[Rand_int::guess(0, pops_size-1)];
            CIndividual parent2 = contender1.get_fitness() > contender2.get_fitness() ? contender1 : contender2;
            if (Rand_int::guess(0, 100) < cross_prob * 100) {
                CIndividual child1(parent1.get_gen_size());
                CIndividual child2(parent2.get_gen_size());
                int pivot = Rand_int::guess(0, pops_size-1);
                child1.crossover(&parent1, &parent2, pivot);
                child2.crossover(&parent2, &parent1, pivot);
                parent1 = child1;
                parent2 = child2;
            }
            parent1.mutate(mut_prob);
            parent2.mutate(mut_prob);
            vec_future_pops.push_back(parent1);
            vec_future_pops.push_back(parent2);
        }
        vec_pops = vec_future_pops;
    }
}

void CGeneticAlgoritm::run_mod()
{
    randomStartingPops();
    for (int i = 0; i < ITERATIONS; ++i) {
        rate_genotypes();
        std::vector<CIndividual> vec_future_pops;
        while (vec_future_pops.size() != pops_size) {
            CIndividual contender1 = vec_pops[Rand_int::guess(0, pops_size-1)];
            CIndividual contender2 = vec_pops[Rand_int::guess(0, pops_size-1)];
            CIndividual parent1 = contender1.get_fitness() > contender2.get_fitness() ? contender1 : contender2;
            contender1 = vec_pops[Rand_int::guess(0, pops_size-1)];
            contender2 = vec_pops[Rand_int::guess(0, pops_size-1)];
            CIndividual parent2 = contender1.get_fitness() > contender2.get_fitness() ? contender1 : contender2;
            if (Rand_int::guess(0, 100) < cross_prob * 100) {
                CIndividual child1(parent1.get_gen_size());
                CIndividual child2(parent2.get_gen_size());
                int pivot = Rand_int::guess(0, pops_size-1);
                child1.crossover(&parent1, &parent2, pivot);
                child2.crossover(&parent2, &parent1, pivot);
                parent1 = child1;
                parent2 = child2;
            }
            CIndividual mask1 = vec_pops[Rand_int::guess(0, pops_size-1)];
            CIndividual mask2 = vec_pops[Rand_int::guess(0, pops_size-1)];
            parent1.mutate_mod(mut_prob, &mask1);
            parent2.mutate_mod(mut_prob, &mask2);
            vec_future_pops.push_back(parent1);
            vec_future_pops.push_back(parent2);
        }
        vec_pops = vec_future_pops;
    }
}

void CGeneticAlgoritm::rate_genotypes()
{
    for (int i = 0; i < pops_size; ++i) {
        (vec_pops[i]).set_fitness(&knap);
    }
}
