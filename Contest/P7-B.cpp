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
		
		int n = s.length();
		int last[n][26];
		fill(last[0], last[n], -1);
		
		for(int x=0;x<n;x++){
			for(int y=0;y<26;y++){
				last[x][y] = (x > 0 ? last[x-1][y] : -1);
			}
			
			last[x][(s[x] - 'a')] = x;
		}
		
		int ans = 0;
		int l = 0, r = n-1;
		while(l <= r){
			int lst = last[r][(s[l] - 'a')];
//			cout << l << " " << r << " " << lst << " -\n";
			if(lst > l){
				bool same = true;
				for(int y=0;y<r-lst+1;y++){
					if(s[l+y] != s[lst+y]){
						same = false;
					}
				}
				
				if(!same){
					ans = 0;
					break;
				} else {
					ans += 2;
					l += r-lst+1;
					r = lst-1;
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

