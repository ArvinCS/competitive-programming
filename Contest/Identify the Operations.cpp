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
		int n, k;
		cin >> n >> k;
		
		int a[n], b[k], c[n+1];
		unordered_set<int> exist;
		
		for(int x=0;x<n;x++){
			cin >> a[x];
			c[a[x]] = x;
		}
		for(int x=0;x<k;x++){
			cin >> b[x];
			exist.insert(b[x]);	
		}
		
		int ans = 1;
		for(int x=0;x<k;x++){
			int i = c[b[x]];
			if((i == 0 || exist.count(a[i-1])) && (i == n-1 || exist.count(a[i+1]))){
				ans = 0;
				break;
			} else if(!(i == 0 || exist.count(a[i-1])) && !(i == n-1 || exist.count(i+1))){
				ans *= 2;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

