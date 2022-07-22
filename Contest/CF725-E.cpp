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

char b[4] = {'h', 'a', 'h', 'a'};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		map<string, string> mp;
		map<string, ll> cnt;
		for(int x=1;x<=n;x++){
			string name;
			cin >> name;
			
			char c;
			cin >> c;
			
			if(c == ':'){
				cin >> c;
				
				string res;
				cin >> res;
				
				cnt[name] = 0;
				for(int x=0;x+3<res.length();x++){
					bool valid = true;
					for(int y=0;y<4;y++){
						if(res[x+y] != b[y]){
							valid = false;
							break;
						}	
					}
					
					if(valid) cnt[name]++;
				}
				
				mp[name] = res;
			} else {
				string res, res2;
				cin >> res >> c >> res2;
				
				cnt[name] = cnt[res] + cnt[res2];
				
				int sz = mp[res].length(), sz2 = mp[res2].length();
				
				string tmp;
				for(int x=max(sz-3, 0);x<sz;x++){
					tmp.push_back(mp[res][x]);
				}
				for(int x=0;x<min(sz2, 3);x++){
					tmp.push_back(mp[res2][x]);
				}
				
				for(int x=0;x+3<tmp.length();x++){
					bool valid = true;
					for(int y=0;y<4;y++){
						if(tmp[x+y] != b[y]){
							valid = false;
							break;
						}
					}
					
					if(valid) cnt[name]++;
				}
				
				tmp.clear();
				if(sz+sz2 <= 6){
					for(int x=0;x<sz;x++){
						tmp.push_back(mp[res][x]);
					}
					for(int x=0;x<sz2;x++){
						tmp.push_back(mp[res2][x]);
					}
				} else {
					for(int x=0;x<min(sz, 3);x++){
						tmp.push_back(mp[res][x]);
					}
					for(int x=0;x<max(0, 3-sz);x++){
						tmp.push_back(mp[res2][x]);
					}
					for(int x=0;x<max(0, 3-sz2);x++){
						tmp.push_back(mp[res][sz-x-1]);
					}
					for(int x=max(sz2-3, 0);x<sz2;x++){
						tmp.push_back(mp[res2][x]);
					}
				}
				mp[name] = tmp;
			}
			
			if(x == n) cout << cnt[name] << "\n";
		}
	}
	
    return 0;
}



