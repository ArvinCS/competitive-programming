#include <iostream>

using namespace std;

int main(){
	string kalimat;
	int k;
	cin >> kalimat;
	cin >> k;
	
	for(int x=0;x<kalimat.length();x++){
		int parse = kalimat[x] - 'a';
		int encrypted = (parse + k) % 26;
		kalimat[x] = encrypted + 'a';
	}
	
	cout << kalimat.c_str() << "\n";
	return 0;
}
