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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, q;
	cin >> n >> q;
	
	string s;
	cin >> s;
	
	int ans = 0;
	for(int x=0;x+2<n;x++){
		if(s[x] == 'a' && s[x+1] == 'b' && s[x+2] == 'c'){
			ans++;
		}
	}
	
	while(q--){
		int pos;
		char c;
		cin >> pos >> c;
		
		pos--;
		if(s[pos] != c){
			for(int y=pos-2;y<=pos;y++){
				if(y+2 >= n) break;
				
				if(s[y] == 'a' && s[y+1] == 'b' && s[y+2] == 'c'){
					ans--;
				}
			}
			
			s[pos] = c;
			
			for(int y=pos-2;y<=pos;y++){
				if(y+2 >= n) break;
				
				if(s[y] == 'a' && s[y+1] == 'b' && s[y+2] == 'c'){
					ans++;
				}
			}
		}	
		
		cout << ans << "\n";
	}
	
    return 0;
}

