#include <iostream>

using namespace std;

int data[10] = {4,1,4,6,1,4,7,8,6,10};
int hitung[10];

void test(int a, int l){
	for(int x=0;x<10;x++){
		hitung[data[x] - 1] = hitung[data[x] - 1] + 1;
	}
	
	for(int x=0;x<10;x++){
		while(hitung[x] > 0){
			cout << x << " ";
			hitung[x] = hitung[x] - 1;
		}
	}
}

int main(){
	for(int x=0;x<10;x++){
		hitung[data[x] - 1] = hitung[data[x] - 1] + 1;
	}
	
	for(int x=0;x<10;x++){
		while(hitung[x] > 0){
			cout << x << " ";
			hitung[x] = hitung[x] - 1;
		}
	}
}
