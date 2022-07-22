#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int segitiga(int miring){
	int sum = 0;
	for(int x=miring;x>0;x--){
		sum += x;
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	int data[6];
	for(int x=0;x<6;x++){
		cin >> data[x];
	} 
	//(data[0] * (data[5] - 1)) + segitiga(data[4] - data[1] - 1) + 
	int hasil = abs(data[0] * (data[5] - 1)) + segitiga(abs(data[4] - data[1] - 1)) + abs((data[4] * data[3] + data[3] * data[2])) - segitiga(data[3]);
	if(data[2] > 1 || data[4] > 1) hasil += segitiga(abs(data[3] + data[4] - data[2])) + segitiga(abs(data[1] - data[5]));

	cout << hasil << "\n";
}
