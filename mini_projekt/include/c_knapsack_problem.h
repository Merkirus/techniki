#pragma once

#include <vector>
#include <deque>
#include <fstream>
#include <filesystem>
#include <numeric>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include "cmysmartpointer.h"
#include "error.h"

// .first -> value, .second -> weight
using item = std::pair<int,int>;
using gen = std::vector<bool>;
using knap_vec = std::vector<item>;
namespace fs = std::__fs::filesystem;

class CKnapsackProblem
{
public:
    CKnapsackProblem() = default;
    CKnapsackProblem(int knap_capacity, int vec_size, knap_vec &&vec);
    CKnapsackProblem(int knap_capacity, knap_vec &&vec);
    CKnapsackProblem(fs::path path);
    CKnapsackProblem(CKnapsackProblem& other);
    ~CKnapsackProblem();
    CKnapsackProblem& operator=(CKnapsackProblem& other);
    bool load_in_file(fs::path path);
    int genotype_to_value(gen& vec);
    int genotype_to_weight(gen& vec);
    int get_vec_size();
    int get_knap_capacity();
    Error get_error();
private:
    knap_vec vec_knap; 
    std::ifstream read_file;
    fs::path read_path;
    int vec_size;
    int knap_capacity;
    Error err;
};
