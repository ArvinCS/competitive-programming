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

	int k[3], n = 0;
	for(int x=0;x<3;x++){
		cin >> k[x];
		n += k[x];
	}
	
	vector<int> v[3];
	for(int x=0;x<3;x++){
		for(int y=0;y<k[x];y++){
			int val;
			cin >> val;
			
			val--;
			v[x].push_back(val);
		}
		sort(v[x].begin(), v[x].end());
	}
	
	int suffix[n+2];
	suffix[n+1] = inf_int;
	
	for(int x=n;x>=0;x--){
		int idx3 = lower_bound(v[2].begin(), v[2].end(), x) - v[2].begin();
		int idx2 = lower_bound(v[1].begin(), v[1].end(), x) - v[1].begin();
		
		suffix[x] = min(idx3 + (k[1] - idx2), suffix[x+1]);
	}
	
	int ans = k[0] + suffix[0];
	for(int x=0;x<n;x++){
		int idx1 = lower_bound(v[0].begin(), v[0].end(), x+1) - v[0].begin();
		int idx2 = lower_bound(v[1].begin(), v[1].end(), x+1) - v[1].begin();
		
		ans = min(ans, (k[0] - idx1) + idx2 + suffix[x+1]);
	}
	
	cout << ans << "\n";
    return 0;
}

