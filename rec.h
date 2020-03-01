#ifndef REC_H
#define REC_H

#include <string>
#include <vector>

using namespace std;

struct country{
    string country_name;
    vector <int> score;
};

country invert_score(string record);




#endif