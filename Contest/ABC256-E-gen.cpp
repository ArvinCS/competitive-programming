#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	int n = 2 + rng() % 7;
	
	bool exist[n];
	fill(exist, exist+n, false);
	
	int m[n], c[n];
	for(int x=0;x<n;x++){
		m[x] = rng() % n;
		while(m[x] == x){
			m[x] = rng() % n;
		}	
		
//		exist[m[x]] = true;
		m[x]++;
	}
	for(int x=0;x<n;x++){
		c[x] = rng() % 10000000;
	}
	
	cout << n << "\n";
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << m[x]; 
	}
	cout << "\n";
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << c[x]; 
	}
	cout << "\n";
    return 0;
}

