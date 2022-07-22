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
		
		int data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		sort(data, data+n, greater<int>());
		
		vector<int> odd, even;
		for(int x=0;x<n;x++){
			if(data[x]&1) odd.push_back(data[x]);
			else even.push_back(data[x]);
		}
		
		vector<int> v;
		for(auto e : even) v.push_back(e);
		for(auto e : odd) v.push_back(e);
		
		int ans = 0;
		for(int x=0;x<v.size();x++){
			for(int y=x+1;y<v.size();y++){
				if(__gcd(v[x], 2*v[y]) > 1){
					ans++;
				}
			}
		}
		
		cout << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

