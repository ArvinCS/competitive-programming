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
		
		bool exist[n+1], skip[m];
		fill(exist, exist+n+1, false);
		fill(skip, skip+m, false);
		
		int b[m];
		for(int x=0;x<m;x++){
			cin >> b[x];
			exist[b[x]] = true;
		}
		
		if(n == m){
			cout << "YES\n";
			continue;
		}
		
		vector<int> v;
		for(int x=1;x<=n;x++){
			if(!exist[x]) v.push_back(x);
		}
		
		int left = 0, right = v.size()-1, remain = n%k;
		bool possible = false;
		for(int x=0;x<n;x++){
			if(m+x*(k-1) == n){
				possible = true;
				break;
			}
		}
		
		bool possible2 = false;
		for(int x=0;x<m;x++){
			auto it = lower_bound(v.begin(), v.end(), b[x]);
			
			int left = (it - v.begin()), right = v.size()-left;
			
			if(left >= k/2 && right >= k/2){
				possible2 = true;
				break;
			}
		}
		
		if(possible && possible2) cout << "YES\n";
		else cout << "NO\n";
	}

    return 0;
}

