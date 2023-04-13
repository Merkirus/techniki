#include "../include/c_individual.h"

CIndividual::CIndividual()
{
    vec_genotype.reserve(BASE_GEN_SIZE);
    gen_size = BASE_GEN_SIZE;
    fitness = 0;
}

CIndividual::CIndividual(int gen_size)
{
    vec_genotype.resize(gen_size);
    this->gen_size = gen_size;
    fitness = 0;
}

int CIndividual::get_fitness()
{
    return fitness;
}

void CIndividual::set_fitness(CKnapsackProblem *prob)
{
    fitness = prob->genotype_to_value(vec_genotype);
    int weight = prob->genotype_to_weight(vec_genotype);
    if (prob->get_knap_capacity() <= weight)
        fitness = 0;
}

void CIndividual::crossover(CIndividual *parent1, CIndividual *parent2, int pivot)
{
    for (int i = 0; i < gen_size; ++i) {
        if (i < pivot)
            vec_genotype[i] = parent1->vec_genotype[i];
        else
            vec_genotype[i] = parent2->vec_genotype[i];
    }
}

void CIndividual::mutate(int mut_prob)
{
    for (int i = 0; i < gen_size; ++i)
        if (mut_prob*100 > Rand_int::guess(0, 1))
            vec_genotype[i] = !(vec_genotype[i]);
}

void CIndividual::mutate_mod(int mut_prob, CIndividual *mask)
{
    for (int i = 0; i < gen_size; ++i) {
        if (vec_genotype[i] != mask->vec_genotype[i]) {
            if (mut_prob*100 > Rand_int::guess(0, 1))
                vec_genotype[i] = !(vec_genotype[i]);
        }
    }
}

void CIndividual::random_genotype() {
    for (int i = 0; i < gen_size; ++i)
        vec_genotype[i] = (Rand_int::guess(0, 1) == 0 ? false : true);
}

int CIndividual::get_gen_size()
{
    return gen_size;
}

std::vector<bool> CIndividual::get_vec_genotype()
{
    return vec_genotype;
}
