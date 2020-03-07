#ifndef REC_H
#define REC_H



#include <experimental/filesystem>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
using namespace std::experimental::filesystem;

vector<path> input(const string directory);
void get_info(vector<path> files, vector<string>& countryName, vector<vector<int>>& scores);
void input_data(path file, vector<string>& countryName, vector<vector<int>>& scores);
void parsing(string line, vector<string>& countryName, vector<int>& score);
int** calculate_mark(vector<vector<int>>scores);
unsigned int* rating(vector<vector<int>>scores, int iterator);
int* sums(int** marks, int n, int m);
int calculate_sum(int* score, int m);



#endif