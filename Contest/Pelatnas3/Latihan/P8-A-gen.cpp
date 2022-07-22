#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll inf = 100;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	int t = 10 + rng() % 91;
	cout << t << "\n";
	
	for(int x=0;x<t;x++){
		int n = 1 + rng() % 50;
		int m = 1 + rng() % 50;
		int b = rng() % (n*m);
		int w = b + (rng() % (3*b+2-b));
		
		cout << n << " " << m << " " << b << " " << w << "\n";
	}
    return 0;
}

