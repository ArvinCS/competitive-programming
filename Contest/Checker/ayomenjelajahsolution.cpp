#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int n, m;
	cin >> n >> m;
	
	ll sum = 0;
	for(int x=0;x<n;x++){
		int val;
		cin >> val;
		
		sum += val;
	}
	
	ll mx = 0;
	for(int x=0;x<m;x++){
		int val;
		cin >> val;
		
		if(mx < val){
			mx = val;
		}
	}
	
	cout << sum+n*mx << "\n";
}
