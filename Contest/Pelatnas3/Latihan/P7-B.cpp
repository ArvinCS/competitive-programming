#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const ll key = 31;
const int maxN = 1e6 + 5;

ll pw[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	pw[0] = 1;
	for(int x=1;x<maxN;x++){
		pw[x] = (key * pw[x-1]) % mod;
	}
	
	int t;
	cin >> t;
	
	while(t--){
		string s;
		cin >> s;
		
		int n = s.length();
		int last[n][26];
		fill(last[0], last[n], -1);
		
		for(int x=0;x<n;x++){
			for(int y=0;y<26;y++){
				last[x][y] = (x > 0 ? last[x-1][y] : -1);
			}
			
			last[x][(s[x] - 'a')] = x;
		}
		
		ll hash[n];
		for(int x=0;x<n;x++){
			hash[x] = (x > 0 ? hash[x-1] : 0) * key % mod + (s[x] - 'a' + 1);
			if(hash[x] >= mod) hash[x] -= mod;
		}
		
		auto query = [&hash](int l, int r) -> ll {
			return (hash[r] - (l > 0 ? hash[l-1] : 0) * pw[r-l+1] % mod + mod) % mod;
		};
		
		int ans = 0;
		int cnt = 0;
		int l = 0, r = n-1;
		while(l <= r){
			int lst = last[r][(s[l] - 'a')];
			int length = n-lst-cnt;
			if(lst > l && l+length-1 < lst){
				if(query(l, l+length-1) != query(lst, lst+length-1)){
					r = lst-1;
					continue;
				} else {
					ans += 2;
					l += length;
					r = lst-1;
					cnt += length;
				}
			} else {
				ans++;
				break;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

