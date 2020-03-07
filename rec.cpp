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

int** calculate_mark(vector<vector<int>>scores) {
  int** marks = new int* [scores.size()];
  for (int i = 0; i < scores.size(); i++) {
    marks[i] = new int[scores[i].size()];
  }
  for (int i = 0; i < scores[0].size(); i++) {
    unsigned int* rat = rating(scores, i);
    marks[rat[0]][i] = 12;
    marks[rat[1]][i] = 10;
    for (int j = 2; j < 10; j++) {
      marks[rat[j]][i] = 10 - j;
    }
    for (int j = 10; j < scores.size(); j++) {
      marks[rat[j]][i] = 0;
    }

  }
  return marks;

}

unsigned int* rating(vector<vector<int>>scores, int iterator) {
  unsigned int* rating = new unsigned int[scores.size()];
  for (unsigned int i = 0; i < scores.size(); i++) {
    rating[i] = i;
  }
  for (unsigned int i = 0; i < scores.size(); i++) {
    for (unsigned int j = i; j < scores.size(); j++) {
      if (scores[rating[i]][iterator] < scores[rating[j]][iterator]) {
        int temp = rating[i];
        rating[i] = rating[j];
        rating[j] = temp;

      }
    }
  }
  return rating;
}

int* sums(int** marks, int n, int m) {
  int* sums = new int[n];
  for (int i = 0; i < n; i++) {
    sums[i] = calculate_sum(marks[i], m);
  }
  return sums;
}
