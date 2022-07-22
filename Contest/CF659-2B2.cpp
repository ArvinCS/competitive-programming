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
		int n, k, m;
		cin >> n >> k >> m;
		
		int d[n];
		for(int x=0;x<n;x++){
			cin >> d[x];
		}
		
		bool possible = true, down = true;
		int cur = k;
		for(int x=0;x<n;x++){
			if(d[x]+k <= m){
				cur = k;
				down = true;
			} else {
				if(d[x]+cur > m){
					if(!down){
						possible = false;
						break;
					}
					cur = m-d[x];
					if(cur < 0){
						possible = false;
						break;
					}
				}
				
				if(cur == 0 || cur == k) down = !down;
				cur += (down ? -1 : 1);
			}
		}
		
		if(possible) cout << "Yes\n";
		else cout << "No\n";
	}

    return 0;
}

