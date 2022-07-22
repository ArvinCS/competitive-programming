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
		int n, k;
		cin >> n >> k;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		if(n == 1 && a[0] == k){
			cout << "yes\n";
			continue;
		}
		
		bool possible = false, exist = false;
		for(int x=0;x<n;x++){
			if(a[x] < k) continue;
			
			if(a[x] == k){
				exist = true;
			}
			for(int y=max(0, x-2);y<=min(n-1, x+2);y++){
				if(x == y) continue;
				
				if(a[y] >= k){
					possible = true;
				}
			}
		}
		
		if(possible && exist){
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}

    return 0;
}

