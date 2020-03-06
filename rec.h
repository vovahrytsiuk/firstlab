#ifndef REC_H
#define REC_H

#include <string>
#include <vector>
#include <experimental/filesystem>


using namespace std;
using namespace std::experimental::filesystem;

struct country{
    string country_name;
    vector <int> score;
    long sum;
    int mark;
};

country invert_score(string record);
vector<country> decrypting(vector<string> input);
void calculate_sum(country& Country);
void sum_fo_all(vector<country>& input);
void sort_result(vector<country>&input);
void determine_marks(vector<country>&input);
vector<path> 


#endif