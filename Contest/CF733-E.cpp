#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

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
		int cnt[26];
		fill(cnt, cnt+26, 0);
		
		for(int x=0;x<n;x++){
			cnt[(s[x] - 'a')]++;
		}
		
		int idx = 0;
		bool one = false;
		for(int x=0;x<26;x++){
			if(cnt[x] == 1){
				one = true;
				idx = x;
				break;
			}
		}
		
		if(one){
			char first = ('a' + idx);
			cout << first;
			
			cnt[idx]--;
			for(int x=0;x<26;x++){	
				char c = ('a' + x);
				
				while(cnt[x] > 0){
					cout << c;
					cnt[x]--;
				}
			}
			cout << "\n";
		} else {
			int smallest = 0;
			for(int x=0;x<26;x++){
				if(cnt[x] > 0){
					smallest = x;
					break;
				}
			}
			
			char c = ('a' + smallest);
			if(cnt[smallest]-2 <= n-cnt[smallest]){
				cnt[smallest] -= 2;
				cout << c << c;
				
				for(int x=smallest+1;x<26;x++){
					if(cnt[x] > 0){
						char c = ('a' + x);
						char d = ('a' + smallest);
						
						while(cnt[x] > 0){
							cout << c;
							cnt[x]--;
							
							if(cnt[smallest] > 0){
								cout << d;
								cnt[smallest]--;
							}
						}
					}
				}
				cout << "\n";
			} else {
				cout << c;
				cnt[smallest]--;
				
				int nxt = -1;
				for(int x=smallest+1;x<26;x++){
					if(cnt[x] > 0){
						nxt = x;
						break;
					}
				}
				
				bool more = false;
				for(int x=nxt+1;x<26;x++){
					if(cnt[x] > 0){
						more = true;
						break;
					}
				}
				
				if(nxt >= 0){
					c = ('a' + nxt);
					
					if(more){
						cnt[nxt]--;
						cout << c;
					} else {
						while(cnt[nxt] > 0){
							cnt[nxt]--;
							cout << c;
						}
					}
				}
				
				c = ('a' + smallest);
				while(cnt[smallest] > 0){
					cout << c;
					cnt[smallest]--;
				}
				
				for(int x=nxt+1;x<26;x++){
					if(cnt[x] > 0){
						char c = ('a' + x);
						char d = ('a' + nxt);
						cout << c;
						cnt[x]--;
						
						while(cnt[nxt] > 0){				
							cout << d;
							cnt[nxt]--;
						}
						
						while(cnt[x] > 0){
							cnt[x]--;
							cout << c;
						}
					}
				}
				cout << "\n";
			}
		}
	}
	
    return 0;
}

