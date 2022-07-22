#include <iostream>

using namespace std;

int main(){
	string kalimat;
	cin >> kalimat;
	
	for(int x=0;x<kalimat.length();x++){
		int huruf = kalimat[x] - 'a';
		if(huruf >= 0){
			kalimat[x] -= 32;
		} else {
			kalimat[x] += 32;
		}
	}
	
	cout << kalimat << "\n";
	return 0;
}
