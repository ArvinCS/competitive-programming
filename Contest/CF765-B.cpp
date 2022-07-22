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
		
		vector<int> v;
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			v.push_back(a[x]);
		}
		
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		
		vector<int> w[n];
		for(int x=0;x<n;x++){
			w[lower_bound(v.begin(), v.end(), a[x]) - v.begin()].push_back(x);
		}
		
		int left = 1, right = n-1, ans = -1;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			bool possible = false;
			for(int x=0;x<n;x++){
				int mn = n, mx = -1;
				
				for(auto pos : w[x]){
					int r = mid+min(0, pos-mid+1);
					int l = max(1, pos+mid-n+1);
					
					if(!(r < mn || l > mx)){
						possible = true;
					}
					
					mn = min(mn, l);
					mx = max(mx, r);
				}
			}
			
			if(possible){
				ans = max(ans, mid);
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

