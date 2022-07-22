#include <iostream>

using namespace std;

int main(){
	string kalimat;
	cin >> kalimat;
	
	bool snakeCase = kalimat.find("_") != -1;
	
	if(snakeCase){
		while(kalimat.find("_") != -1){
			int loc = kalimat.find("_");
			char character = kalimat[loc + 1];
			kalimat.erase(loc, 2);
			character -= 32;
			kalimat.insert(loc, 1, character);
		}
	} else {
		for(int x=0;x<kalimat.length();x++){
			if(kalimat[x] - 'a' < 0){
				kalimat[x] += 32;
				kalimat.insert(x, 1, '_');
			}
		}
	}
	
	cout << kalimat << "\n";
}
