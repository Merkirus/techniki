#include "../include/c_knapsack_problem.h"
#include "../include/c_genetic_algorithm.h"
#include <iostream>

int main ()
{
    CKnapsackProblem cknap("../instances_01_KP/low-dimensional/f10_l-d_kp_20_879");
    CGeneticAlgoritm cgen;
    cgen.add_knap(cknap);
    cgen.run_mod();
    std::cout << cgen.pcBestMatch().get_fitness();
}
