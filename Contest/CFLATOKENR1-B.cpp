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
		
		vector<pair<int, int>> v;
		int data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
			v.push_back({data[x], x});
		}
		
		sort(v.begin(), v.end());
		
		ll ans = 0;
		for(int x=0;x<n;x++){
			int tmp = max(0, data[v[x].second]-max(v[x].second > 0 ? data[v[x].second-1] : 0, v[x].second+1 < n ? data[v[x].second+1] : 0));
			
			ans += tmp;
			data[v[x].second] -= tmp;
		}
		
		ans += data[0] + data[n-1];
		for(int x=1;x<n;x++){
			ans += abs(data[x]-data[x-1]);
		}
		
		cout << ans << "\n";
	}

    return 0;
}

