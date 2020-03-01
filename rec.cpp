#include "rec.h"

country invert_score(string record){
    country decrupt;//contry and its score int record
    string tempName;
    int i = 0; 
    while(record[i] != ','){
        tempName+=record[i];
        i++;
    }
    decrupt.country_name = tempName;
    i++;
    string markStr = "";
    for(; i < record.length();i++){
        if(record[i] == ',' || i == record.length()-1){
            decrupt.score.push_back(stoi(markStr));
            markStr = "";
        }
        else{
            markStr += record[i];
        }
    }
    return decrupt;
}