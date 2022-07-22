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

	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		int pos = -1;
		for(int x=0;x<n;x++){
			if(s[x] != '?'){
				pos = x;
				break;
			}
		}
		
		if(pos == -1){
			pos = 0;
			s[0] = 'R';
		}
		
		for(int x=pos-1;x>=0;x--){
			if(s[x+1] == 'B'){
				s[x] = 'R';
			} else {
				s[x] = 'B';
			}
		}
		
		for(int x=pos+1;x<n;x++){
			if(s[x] == '?'){
				if(s[x-1] == 'B'){
					s[x] = 'R';
				} else {
					s[x] = 'B';
				}
			}
		}
		
		cout << s << "\n";
	}

    return 0;
}

