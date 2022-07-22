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
		int k, n, m;
		cin >> k >> n >> m;
		
		int a[n], b[m];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		for(int x=0;x<m;x++){
			cin >> b[x];
		}
		
		bool possible = true;
		int ans[n+m];
		int idx = 0, p1 = 0, p2 = 0;
		while(p1 < n || p2 < m){
			while(p1 < n && a[p1] == 0){
				ans[idx++] = a[p1];
				p1++;
				k++;
			}
			while(p2 < m && b[p2] == 0){
				ans[idx++] = b[p2];
				p2++;
				k++;
			}
			
			if(p1 == n && p2 == m) break;
			
			bool change = false;
			if(p1 < n && a[p1] <= k){
				ans[idx++] = a[p1++];
				change = true;
			}
			if(p2 < m && b[p2] <= k){
				ans[idx++] = b[p2++];
				change = true;
			}
			
			if(!change){
				possible = false;
				break;
			}
		}
		
		if(possible){
			for(int x=0;x<n+m;x++){
				if(x > 0) cout << " ";
				cout << ans[x];
			}
			cout << "\n";
		} else {
			cout << "-1\n";
		}
	}

    return 0;
}

