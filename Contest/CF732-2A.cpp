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
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n], b[n];
		int sum = 0, sum2 = 0;
		for(int x=0;x<n;x++){
			cin >> a[x];
			sum += a[x];
		}
		for(int x=0;x<n;x++){
			cin >> b[x];
			sum2 += b[x];
		}
		
		if(sum != sum2){
			cout << "-1\n";
			continue;
		}
		
		vector<pair<int, int>> ans;
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				if(x == y) continue;
				
				while(b[x] < a[x] && b[y] > a[y]){
					a[x]--;
					a[y]++;
					ans.push_back({x, y});
				}
			}
		}
		
		cout << ans.size() << "\n";
		for(auto p : ans){
			cout << p.first+1 << " " << p.second+1 << "\n";
		}
	}
	
    return 0;
}

