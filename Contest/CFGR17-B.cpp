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
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		int c1 = -1, c2 = -1;
		for(int x=0;x<n/2;x++){
			if(a[x] != a[n-1-x]){
				c1 = a[x];
				c2 = a[n-1-x];
				break;
			}
		}
		
		bool possible = false;
		for(int y=0;y<2;y++){
			int l = 0, r = n-1;
			while(l < r){
				if(a[l] != a[r]){
					if(a[l] == c1){
						l++;
					} else if(a[r] == c1){
						r--;
					} else {
						break;
					}
				} else {
					l++;
					r--;
				}
			}
			
			if(l >= r){
				possible = true;
			}
			
			swap(c1, c2);
		}
		
		if(possible){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

