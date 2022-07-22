#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int size,peserta;
	cin >> size;
	cin >> peserta;
	
	int kamar[size];
	for(int x=0;x<size;x++){
		cin >> kamar[x];
	}    
	
	sort(kamar, kamar+size);
	
	int diff = INT_MAX;
	for(int x=0;x<size && (x+peserta-1) < size;x++){
		if(kamar[x+peserta-1] - kamar[x] < diff){
			diff = kamar[x+peserta-1] - kamar[x];
		}
	}
	
	cout << diff << "\n";
    return 0;
}
