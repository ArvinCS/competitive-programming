#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll inf = 100;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	int t = 1 + rng() % 20;
	cout << t << "\n";
	
	while(t--){
		int n = 1 + rng() % 100;
		string s;
		for(int x=0;x<n;x++){
			char c = ('a' + (rng() % 5));
			s.push_back(c);
		}
		
		cout << s << "\n";
	}
    return 0;
}

