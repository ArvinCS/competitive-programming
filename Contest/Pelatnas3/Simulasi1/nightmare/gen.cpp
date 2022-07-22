#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	int n = 1 + rng() % 20;
	cout << n << "\n";
	for(int x=0;x<n;x++){
		int val = 1 + rng() % 2;
		bool neg = rng() % 2;
		
		cout << (neg ? -val : val) << " ";
	}
	cout << "\n";
	return 0;
}
