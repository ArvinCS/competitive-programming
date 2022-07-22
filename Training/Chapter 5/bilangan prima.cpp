#include <iostream>

using namespace std;

bool prima(int v){
	if(v <= 1) return false;
	else if(v <= 3) return true;
	else if(v % 2 == 0 || v % 3 == 0) return false;

	for(int x=5;x*x<v;x+=6){
		if(v % x == 0 || v % (x + 2) == 0) {
			return false;
		}
	}
	
	return true;
}

int main(){
	int ukuran, v;
	
	cin >> ukuran;
	
	for(int x=0;x<ukuran;x++){
		cin >> v;
		
		if(prima(v)) cout << "YA\n";
		else cout << "BUKAN\n";
	}
	return 0;
}
