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

vector<country> decrypting(vector<string> input){
    vector<country> inputData;
    for(int i = 0; i < input.size();i++){
        inputData.push_back(invert_score(input[i]));
    }
    return inputData;
}

void calculate_sum(country& Country){
    Country.sum = 0;
    for(int i = 0; i < Country.score.size(); i++){
        Country.sum += Country.score[i];
    }
}

void sum_fo_all(vector<country>& input){
    for(int i = 0; i< input.size(); i++){
        calculate_sum(input[i]);
    }
}

void sort_result(vector<country>&input){
    for(int i = 0; i < input.size();i++){
        for(int j = i; j < input.size(); j++){
            if(input[i].sum < input[j].sum){
                country temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
            else if(input[i].sum == input[j].sum && input[i].country_name < input[j].country_name){
                country temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }
}

void determine_marks(vector<country>&input){
    input[0].mark = 12;
    input[1].mark = 10;
    for(int i = 2; i < input.size();i++){
        input[i].mark = 1;
    }
}

