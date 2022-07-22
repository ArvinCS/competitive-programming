#include <iostream>

using namespace std;

int main(){
	string kalimat, kata;
	cin >> kalimat;
	cin >> kata;
	
	while(kalimat.find(kata) != -1){
		int loc = kalimat.find(kata);
		kalimat.erase(loc, kata.length());
	}
	
	cout << kalimat.c_str() << "\n";
	return 0;
}
