#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "rec.h"

using namespace std;


int main(){
	string directory;
  getline(cin, directory);
  vector<path> files = input(directory);
  vector<string> countryName;
  vector<vector<int>> scores;
  get_info(files, countryName, scores);
  int** mark = calculate_mark(scores);
  int n = scores.size();
  int m = scores[0].size();
  int* sum = sums(mark, n, m);
  sort(countryName, sum, n);
  print_top(countryName, sum);

  
	return 0;
}
