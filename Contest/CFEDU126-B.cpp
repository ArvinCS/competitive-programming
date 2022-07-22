#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxA = 32768;

int table[maxA];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(table, table+maxA, maxA);
	
	table[0] = 0;
	for(int i=0;i<500;i++){
		for(int x=maxA-1;x>=0;x--){
			if(table[(2*x)%maxA] == i){
				table[x] = min(table[x], i+1);
			}
			if(table[(x+1)%maxA] == i){
				table[x] = min(table[x], i+1);
			}
		}
	}
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << table[a[x]];
	}
	cout << "\n";
    return 0;
}

