#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	sort(data, data+n);
	
	long long moves = 0;
	if(data[0] <= 0) {
		moves += 1 - data[0];
		data[0] = 1;
	}
	
	for(int x=1;x<n;x++){
		moves += abs((x+1) - data[x]);
		data[x] = x+1;
	}
	
	cout << moves << "\n";
    return 0;
}
