#pragma once

#include <random>

class Rand_int {
public:
	Rand_int();
	static int guess(int low, int high);
private:
	static std::random_device rd;
	static std::mt19937 mt;
	static std::uniform_int_distribution<> dist;
};
