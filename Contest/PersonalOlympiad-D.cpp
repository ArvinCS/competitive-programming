#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e6 + 5;

int last[maxN][26];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	fill(last[0], last[maxN], 1e9);
	
	int cnt[26];
	fill(cnt, cnt+26, 0);
	
	for(int x=0;x<n;x++){
		cnt[(s[x] - 'a')]++;
		last[cnt[(s[x] - 'a')]][(s[x] - 'a')] = x;
	}
	
	int q;
	cin >> q;
	
	while(q--){
		string t;
		cin >> t;
		
		fill(cnt, cnt+26, 0);
		
		int ans = 0;
		for(int x=0;x<t.length();x++){
			cnt[(t[x] - 'a')]++;
			ans = max(ans, last[cnt[(t[x] - 'a')]][(t[x] - 'a')]);
		}
		
		cout << (ans != 1e9 ? ans+1 : -1) << "\n";
	}
	
    return 0;
}

