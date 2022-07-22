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
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		int prefix[n][2]; // D K
		for(int x=0;x<n;x++){
			prefix[x][0] = (x > 0 ? prefix[x-1][0] : 0);
			prefix[x][1] = (x > 0 ? prefix[x-1][1] : 0);
			
			if(s[x] == 'D'){
				prefix[x][0]++;
			} else {
				prefix[x][1]++;
			}
		}
		
		map<pair<int, int>, int> mp;
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			int gc = __gcd(prefix[x][0], prefix[x][1]);
			int d = prefix[x][0]/gc, k = prefix[x][1]/gc;
			
			cout << mp[{d, k}]+1;
			mp[{d, k}]++;
		}
		cout << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

