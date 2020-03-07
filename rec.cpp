#include "rec.h"

vector<path> input(const string directory) {
  vector<path>files;
  const directory_iterator begin(directory);
  const directory_iterator end;
  copy_if(begin, end, back_inserter(files),
    [](const path& p) {
      return is_regular_file(p) && p.extension() == ".csv";
    });
  return files;
}

void get_info(vector<path> files, vector<string>& countryName, vector<vector<int>>& scores) {
  for (auto& f : files) {
    input_data(f, countryName, scores);
  }
}

void input_data(path file, vector<string>& countryName, vector<vector<int>>& scores) {
  fstream f(file);
  int n;
  f >> n;
  string str;
  getline(f, str);
  for (int i = 0; i < n; i++) {
    getline(f, str);
    parsing(str, countryName, scores[i]);
  }
}

void parsing(string line, vector<string>& countryName, vector<int>& score) {
  string temp = "";
  int iter = 0;
  while (line[iter] != ',') {
    temp += line[iter];
    iter++;
  }
  iter++;
  countryName.push_back(temp);
  temp = "";
  for (; iter < line.length(); iter++) {
    if (line[iter] == ',') {
      score.push_back(stoi(temp));
      temp = "";
    }
    else {
      temp += line[iter];
    }
  }
}
