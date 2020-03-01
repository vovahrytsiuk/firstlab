#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "rec.h"

using namespace std;


int main(){
	country ukr = invert_score("Albania,0,181737,32637,444914,363969,26359,49820,926995,982799,71682,84338,197258,648121,371950,780342,380583,439108,764246,855351,353137");
	cout << "name " << ukr.country_name << endl;
	for(int i = 0; i < ukr.score.size(); i++){
		cout << ukr.score[i] << "\t";
	}
	return 0;
}
