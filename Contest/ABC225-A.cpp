#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	ll fac = 1;
	map<ll, int> mp;
	for(int x=0;x<s.length();x++){
		mp[(s[x] - 'a')]++;
		fac *= (x+1);
	}
	
	for(auto p : mp){
		for(int x=1;x<=p.second;x++){
			fac /= x;
		}
	}
	
	cout << fac << "\n";
    return 0;
}

