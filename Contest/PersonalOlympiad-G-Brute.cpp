#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	int mx = 0;
	int n = s.length();
	for(int x=0;x<n;x++){
		mx <<= 1;
		mx |= (s[x] == '1' ? 1 : 0);
	}
	
	map<int, int> mp;
	int ans = 0, ans2 = 0;
	for(int x=1;x<=mx;x++){
		int lg = ceil(log2(x+1));
		for(int y=0;y<(1 << n);y++){
			if((x&y) == x){
				mp[log2(x)]++;
				ans++;
			}
		}
	}
	
	for(auto p : mp){
		cout << p.first << " -> " << p.second << "\n";
	}
	
	cout << ans-ans2 << " " << ans2 << "\n";
	
    return 0;
}

