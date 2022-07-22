#include <iostream>
using namespace std;

int panas(int awal, int x){
	int k = 0;
	while(x > (awal * 0.4)){
		x -= (x * 0.2);
		k++;
	}
	return k;
}

int main() {
	cout << "hasil:\n";
	cout << panas(10, 10) << "\n";
	return 0;
}
