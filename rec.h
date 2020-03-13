#ifndef REC_H
#define REC_H




#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


vector<string> input();
void get_info(vector<string> files, vector<string>& countryName, vector<vector<int> >& scores);
void input_data(string file, vector<string>& countryName, vector<vector<int> >& scores);
vector<int> parsing(string line, vector<string>& countryName);
int** calculate_mark(vector<vector<int> >scores);
unsigned int* rating(vector<vector<int> >scores, int iterator);
int* sums(int** marks, int n, int m);
int calculate_sum(int* score, int m);
void sort(vector<string>& countryName, int* sum, int n);
void print_top(vector<string> countryName, int* sum);




#endif