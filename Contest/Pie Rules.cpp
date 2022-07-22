#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(int n, int data[]){
	long long table[n][2]; // index 0, Alice - index 1, Bob	
	table[0] = 0;
	table[1] = 0;
	
	sort(data, data+n);
	
	int best = 0;
	int turn = 1;
	for(int x=0;x<n;x++){
		int best = table[n-1][0] - (table[n-1][1] + data[x]);
		if((table[n-1][0] + data[x] - table[n-1][1]) < best){
			best = 
		}
		turn = abs(turn-1);
	}
	
	cout << table[0] << " " << table[1] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int data[n];
	for(int x=0;x<n;x++) cin >> data[x];
	
	solve(n, data);
	
    return 0;
}
