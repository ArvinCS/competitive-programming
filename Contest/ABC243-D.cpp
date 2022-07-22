#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n, m;
	cin >> n >> m;
	
	string s;
	cin >> s;
	
	string new_s;
	for(int x=0;x<n;x++){
		if(s[x] == 'U'){
			if(!new_s.empty() && new_s.back() != 'U') new_s.pop_back();
			else new_s.push_back(s[x]);
		} else {
			new_s.push_back(s[x]);
		}
	}
	
	swap(s, new_s);
	
	for(int x=0;x<s.length();x++){
		if(s[x] == 'U'){
			m >>= 1;
		} else if(s[x] == 'L'){
			m <<= 1;
		} else if(s[x] == 'R'){
			m <<= 1;
			m |= 1;
		}
	}
	
	cout << m << "\n";
    return 0;
}

