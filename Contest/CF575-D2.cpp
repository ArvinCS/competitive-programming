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

const int maxN = 2 * 1e5 + 10;

int prefix[maxN][5];
char c[3] = {'R', 'G', 'B'};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		fill(prefix[0], prefix[n], 0);
		for(int x=0;x<n;x++){
			prefix[x][0] = (x > 0 ? prefix[x-1][0] : 0);
			if(s[x] != c[x%3]) prefix[x][0]++;
		}
		for(int x=0;x<n;x++){
			prefix[x][1] = (x > 0 ? prefix[x-1][1] : 0);
			if(s[x] != c[(1+x)%3]) prefix[x][1]++;
		}
		for(int x=0;x<n;x++){
			prefix[x][2] = (x > 0 ? prefix[x-1][2] : 0);
			if(s[x] != c[(2+x)%3]) prefix[x][2]++;
		}
		
		int ans = inf_int;
		for(int x=0;x+k-1<n;x++){
//			cout << prefix[x][0] << " " << prefix[x][1] << " " << prefix[x][2] << "\n";
			for(int y=0;y<3;y++){
				ans = min(ans, prefix[x+k-1][y] - (x > 0 ? prefix[x-1][y] : 0));
			}
		}
		cout << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

