#include <iostream>

using namespace std;

bool agakPrima(int v){
	int jumlah = 0;
	
	for(int x=2;x<v;x++){
		if(v % x == 0) {
			jumlah++;
			if(jumlah > 2) break;
		}
	}
	
	return jumlah <= 2;
}

int main(){
	int ukuran, v;
	
	cin >> ukuran;
	
	for(int x=0;x<ukuran;x++){
		cin >> v;
		
		if(agakPrima(v)) cout << "YA\n";
		else cout << "BUKAN\n";
	}
	return 0;
}
