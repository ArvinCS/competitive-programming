#include <iostream>

using namespace std;

int main(){
	string a,b;
	cin >> a >> b;
	int karakter = 0;
	for(int x=0;x<a.size();x++){
		for(int y=0;y<b.size();y++){
			if(a[x] == b[y]){
				a[x] = '.';
				karakter++;
				break;
			}
		}
	}
	if(karakter ==  a.size() - 1){
		cout << "Tentu saja bisa!\n";
	} else {
		cout << "Wah, tidak bisa :(\n";
	}
	return 0;
}
