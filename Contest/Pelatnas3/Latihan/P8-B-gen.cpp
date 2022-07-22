#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll inf = 20;
const ll inf2 = 1e9;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	int n = 1 + rng() % inf;
	int m = n-1 + rng() % (inf - (n-1));
	
	cout << n << " " << m << "\n";
	for(int x=0;x<m;x++){
		int a = rng() % n + 1, b = rng() % n + 1;
		int c = rng() % inf2;
		
		cout << a << " " << b << " " << c << "\n";
	}
    return 0;
}

