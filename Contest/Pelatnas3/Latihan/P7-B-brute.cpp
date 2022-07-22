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
		
		int table[n+1];
		fill(table, table+n+1, -1e9);
		
		table[0] = 0;
		for(int x=1;x<=n/2;x++){
			for(int y=0;y<x;y++){
				int length = x-y;
				
				bool same = true;
				for(int z=0;z<length;z++){
//					if(x == 2) cout << x << " " << y << " " << z << " == " << s[y+z] << " " << s[n-y-(length-z)] << "\n";
					if(s[y+z] != s[n-y-(length-z)]){
						same = false;
						break;
					}
				}
				
				if(same){
					table[x] = max(table[x], table[y]+2);
				}
			}
		}
		
		int ans = 0;
		for(int x=0;x<=n/2;x++){
			ans = max(ans, table[x]+(n-2*x != 0));
		}
		
		cout << ans << "\n";
//		int ans = 0;
//		int l = 0, r = n-1;
//		while(l <= r){
//			int lst = last[r][(s[l] - 'a')];
////			cout << l << " " << r << " " << lst << " -\n";
//			if(lst > l && l+(r-lst+1)-1 < lst){
//				bool same = true;
//				for(int y=0;y<r-lst+1;y++){
//					if(s[l+y] != s[lst+y]){
//						same = false;
//					}
//				}
//				
//				if(!same){
//					ans++;
//					break;
//				} else {
//					ans += 2;
//					l += r-lst+1;
//					r = lst-1;
//				}
//			} else {
//				ans++;
//				break;
//			}
//		}
		
//		cout << ans << "\n";
	}
	
    return 0;
}

