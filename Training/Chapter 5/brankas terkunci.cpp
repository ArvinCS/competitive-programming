#include <iostream>

using namespace std;

int n,k;

void copyArray(int a[], int b[], int &s){
	for(int x=0;x<s;x++){
		a[x] = b[x];
	}
}

void findChance(int array[], int kedalaman){
	if(kedalaman >= k){
		for(int x=0;x<k;x++){
			if(x != 0) cout << " ";
			cout << array[x];
		}
		cout << "\n";
	} else {
		for(int x=array[kedalaman-1]+1;x<=n;x++){
			array[kedalaman] = x;
			findChance(array, kedalaman+1);
		}
	}
}

int main(){
	cin >> n;
	cin >> k;
	
	for(int x=1;x<=n;x++){
		int array[k];
		array[0] = x;
		findChance(array, 1);
	}
	
	return 0;
}
