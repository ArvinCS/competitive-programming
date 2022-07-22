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

void solve(){
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	for(char c='a';c<='z';c++){
		bool found = false;
		for(int x=0;x<n;x++){
			if(s[x] == c){
				found = true;
				break;
			}
		}
		
		if(!found){
			cout << c << "\n";
			return;
		}
	}
	
	for(char c='a';c<='z';c++){
		for(char d='a';d<='z';d++){
			bool found = false;
			for(int x=0;x+1<n;x++){
				if(s[x] == c && s[x+1] == d){
					found = true;
					break;
				}
			}
			
			if(!found){
				cout << c << d << "\n";
				return;
			}	
		}
	}
	
	for(char c='a';c<='z';c++){
		for(char d='a';d<='z';d++){
			for(char e='a';e<='z';e++){
				bool found = false;
				for(int x=0;x+2<n;x++){
					if(s[x] == c && s[x+1] == d && s[x+2] == e){
						found = true;
						break;
					}
				}
				
				if(!found){
					cout << c << d << e << "\n";
					return;
				}		
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		solve();
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

