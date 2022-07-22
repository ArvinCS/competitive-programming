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
		string s;
		cin >> s;
		
		bool exist[26];
		fill(exist, exist+26, false);
		
		for(int x=0;x<s.length();x++){
			exist[(s[x] - 'a')] = true;
		}
		
		int cnt[26];
		bool possible = true;
		for(int x=0;x<s.length();x++){
			fill(cnt, cnt+26, 0);
			
			for(int y=0;y<30;y++){
				if(x+y >= s.length()) break;
				cnt[(s[x+y] - 'a')]++;
				
				int mn = 1e9, mx = -1e9;
				for(int y=0;y<26;y++){
					if(exist[y]){
						mn = min(mn, cnt[y]);
						mx = max(mx, cnt[y]);
					}
				}
				
				if(mx-mn > 1){
					possible = false;
					break;
				}
			}
			
			if(!possible) break;
		}
		
		cout << (possible ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

