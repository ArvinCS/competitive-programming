#include <iostream>

using namespace std;

int size;

bool check(int a, int b, int c){
	if(a == -1 || b == -1 || c == -1) return false;
	return (a > b && b < c) || (a < b && b > c);
}

bool arrayContains(int array[], int i){
	for(int x=0;x<size;x++){
		if(array[x] == i) return true;
	}
	return false;
}

void copyArray(int a[], int b[], int &s){
	for(int x=0;x<s;x++){
		a[x] = b[x];
	}
}

void zigZag(int array[], int kedalaman){
	if(kedalaman >= size){
		for(int x=0;x<size;x++){
			cout << array[x];
		}
		cout << "\n";
	} else {
		for(int x=1;x<=size;x++){
			if(arrayContains(array, x)) continue;
			
			int temp[size];
			copyArray(temp, array, size);
			temp[kedalaman] = x;
			if(kedalaman - 2 < 0 || kedalaman - 2 >= 0 && check(temp[kedalaman-2], temp[kedalaman-1], temp[kedalaman])){
				zigZag(temp, kedalaman + 1);
			}
		}
	}
}

int main(){
	cin >> size;
	
	for(int x=1;x<=size;x++){
		int array[size] = {-1};
		array[0] = x;
		zigZag(array, 1);
	}
		
	return 0;
}
