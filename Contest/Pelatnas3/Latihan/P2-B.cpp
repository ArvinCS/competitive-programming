#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const ll key = 31;
const int maxL = 2e6 + 5;

ll pw[maxL];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	pw[0] = 1;
	for(int x=1;x<maxL;x++){
		pw[x] = (pw[x-1] * key) % mod;
	}
	
	int n, m;
	cin >> n >> m;
	
	string s[n];
	for(int x=0;x<n;x++){
		cin >> s[x];
	}
	
	vector<ll> h[n];
	for(int x=0;x<n;x++){
		h[x].push_back((s[x][0] - 'A' + 1));
		for(int y=1;y<s[x].length();y++){
			h[x].push_back((h[x].back() * key + (s[x][y] - 'A' + 1)) % mod);
		}
	}
	
	for(int x=0;x<m;x++){
		string l, r;
		cin >> l >> r;
		
		ll hl = (l[0] - 'A' + 1), hr = (r[0] - 'A' + 1);
		for(int x=1;x<l.length();x++){
			hl *= key;
			hl += (l[x] - 'A' + 1);
			hl %= mod;
		}
		for(int x=1;x<r.length();x++){
			hr *= key;
			hr += (r[x] - 'A' + 1);
			hr %= mod;
		}
		
		int ans = 0;
		for(int y=0;y<n;y++){
			if(l.length() <= s[y].length() && r.length() <= s[y].length()){
				if(h[y][l.length()-1] == hl && (h[y].back() - (s[y].length()-r.length() > 0 ? h[y][s[y].length()-r.length()-1] * pw[r.length()] % mod : 0) + mod) % mod == hr){
					ans++;
				}
			}
		}
		
		cout << ans << "\n";
	}
    return 0;
}

