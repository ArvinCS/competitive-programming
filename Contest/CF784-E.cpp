#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s[n];
		for(int x=0;x<n;x++){
			cin >> s[x];
		}
		
		int cnt[26][26];
		fill(cnt[0], cnt[26], 0);
		
		for(int x=0;x<n;x++){
			cnt[(s[x][0] - 'a')][(s[x][1] - 'a')]++;
		}
		
		ll ans = 0;
		for(int x=0;x<n;x++){
			for(char c='a';c<s[x][0];c++){
				ans += cnt[(c - 'a')][(s[x][1] - 'a')];
			}
			for(char c='a';c<s[x][1];c++){
				ans += cnt[(s[x][0] - 'a')][(c - 'a')];
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

