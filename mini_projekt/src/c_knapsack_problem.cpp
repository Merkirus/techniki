#include "../include/c_knapsack_problem.h"

CKnapsackProblem::CKnapsackProblem(int knap_capacity, int vec_size, knap_vec &&vec)
: vec_knap {vec}
{
    if (knap_capacity < 0 || vec_size < 0)
        err = Error::WRONG_KNAP_PARAM;
    else {
        this->knap_capacity = knap_capacity;
        this->vec_size = vec_size;    
    }
}

CKnapsackProblem::CKnapsackProblem(int knap_capacity, knap_vec &&vec)
: vec_knap {vec}, vec_size {(int)vec.size()}
{
    if (knap_capacity < 0)
        err = Error::WRONG_KNAP_PARAM;
    else
        this->knap_capacity = knap_capacity;
}

CKnapsackProblem::CKnapsackProblem(fs::path path)
{
    load_in_file(path);
}

CKnapsackProblem::CKnapsackProblem(CKnapsackProblem& other)
{
    vec_knap = other.vec_knap; 
    read_file.open(other.read_path);
    read_path = other.read_path;
    vec_size = other.vec_size;
    knap_capacity = other.knap_capacity;
    err = other.err;
}

CKnapsackProblem::~CKnapsackProblem()
{
    if (read_file.is_open())
        read_file.close();
}


CKnapsackProblem& CKnapsackProblem::operator=(CKnapsackProblem &other)
{
    vec_knap = other.vec_knap;
    read_file.open(other.read_path);
    read_path = other.read_path;
    vec_size = other.vec_size;
    knap_capacity = other.knap_capacity;
    err = other.err;
    return *this;
}

bool CKnapsackProblem::load_in_file(fs::path path)
{
    read_path = path;
    if (!fs::exists(path)) {
        err = Error::PATH_NOT_FOUND;
        return false;
    }
    
    read_file.open(path);

    if (!read_file.is_open()) {
        err = Error::CANT_OPEN_FILE;
        return false;
    }

    std::stringstream file_holder;

    file_holder << read_file.rdbuf();

    std::string str_file_holder = file_holder.str();

    char *str_file_holder_c_string = (char*)str_file_holder.c_str();
    char *token;
    std::string delimiter = " \r\n";
    char *save_ptr;

    token = strtok_r(str_file_holder_c_string, delimiter.c_str(), &save_ptr);

    std::deque<std::string> deq_string;

    deq_string.push_back(std::string(token));

    while ((token = strtok_r(NULL, delimiter.c_str(), &save_ptr)))
        deq_string.push_back(std::string(token));

    std::string::size_type sz;

    vec_size = std::stoi(deq_string.front(), &sz);
    deq_string.pop_front();

    knap_capacity = std::stoi(deq_string.front(), &sz);
    deq_string.pop_front();

    int value;
    int weight;

    for (int i = 0; i < vec_size*2; ++i) {
        if (i % 2 == 0)
            value = std::stoi(deq_string.front(), &sz);
        else {
            weight = std::stoi(deq_string.front(), &sz);
            vec_knap.push_back(item{value, weight});
        }
        deq_string.pop_front();
    }

    return true;
}

int CKnapsackProblem::genotype_to_value(gen &vec)
{
    return std::inner_product(vec.begin(), vec.end(), vec_knap.begin(), 0,
            std::plus<>(), [&](const bool &x, const item &pair){return x * pair.first;});
}

int CKnapsackProblem::genotype_to_weight(gen &vec)
{
    return std::inner_product(vec.begin(), vec.end(), vec_knap.begin(), 0,
            std::plus<>(), [&](const bool &x, const item &pair){return x * pair.second;});
}

int CKnapsackProblem::get_vec_size()
{
    return vec_size;
}

int CKnapsackProblem::get_knap_capacity()
{
    return knap_capacity;
}

Error CKnapsackProblem::get_error()
{
    return err;
}
