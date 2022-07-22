#include <iostream>

using namespace std;

int main(){
	int ukuran;
	
	cin >> ukuran;
	
	int value = 0;
	for(int x=1;x<=ukuran;x++){
		for(int o=0;o<x;o++){
			cout << value;
			value += 1;
			if(value == 10) value = 0;
		}
		cout << "\n";
	}
	
	return 0;
}
