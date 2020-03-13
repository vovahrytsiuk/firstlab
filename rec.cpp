#include "rec.h"

vector<string> input() {
  vector<string>files;
  cout << "Enter number of files to process" << endl;
  int numberOfFiles;
  cin >> numberOfFiles;
  cout << "Enter name of files" << endl;
  for(int i = 0; i < numberOfFiles; i++){
    string fileName;
    cin >> fileName;
    files.push_back(fileName);
  }
  return files;
}

void get_info(vector<string> files, vector<string>& countryName, vector<vector<int> >& scores) {
  for (auto& f : files) {
    input_data(f, countryName, scores);
  }
}

void input_data(string file, vector<string>& countryName, vector<vector<int> >& scores) {
  fstream f(file);
  int n;
  f >> n;
  string str;
  getline(f, str);
  for (int i = 0; i < n; i++) {
    getline(f, str);

    scores.push_back(parsing(str, countryName));
  }
}

vector<int> parsing(string line, vector<string>& countryName) {
  vector<int> score;
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
    if (line[iter] == ',' || iter == line.length()-1) {
      if(line[iter] != ','){
        temp += line[iter];
      }
      int tempr = stoi(temp);
      score.push_back(tempr);
      temp = "";
    }
    else {
      temp += line[iter];
    }
  }
 
  return score;

}

int** calculate_mark(vector<vector<int> >scores) {
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

unsigned int* rating(vector<vector<int> >scores, int iterator) {
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
int calculate_sum(int* score, int m) {
  int sum = 0;
  for (int j = 0; j < m; j++) {
    sum += score[j];
  }
  return sum;
}
void sort(vector<string>& countryName, int* sum, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (sum[i] < sum[j]) {
        int temp = sum[i];
        sum[i] = sum[j];
        sum[j] = temp;
        string tempr = countryName[i];
        countryName[i] = countryName[j];
        countryName[j] = tempr;
      }
    }
  }
}

void print_top(vector<string> countryName, int* sum) {
  fstream fout("result.csv");
  for (int i = 0; i < 10; i++) {
    cout << countryName[i] << "," << sum[i] << endl;
  }
}