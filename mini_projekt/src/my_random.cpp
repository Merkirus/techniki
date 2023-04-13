#include "../include/my_random.h"

int Rand_int::guess(int low, int high)
{
   dist = std::uniform_int_distribution<>(low, high);
   return dist(mt);
}

std::random_device Rand_int::rd = std::random_device();
std::mt19937 Rand_int::mt = std::mt19937(rd());
std::uniform_int_distribution<> Rand_int::dist;
