#include <iostream>

using namespace std;

int main(){
	int ukuran;
	cin >> ukuran;
	
	for(int x=1;x<=ukuran;x++){
		for(int o=0;o<ukuran;o++){
			if(ukuran-o <= x){
				cout << "*";	
			} else {
				cout << " ";
			}
		}
		cout << "\n";
	}
	
	return 0;
}
