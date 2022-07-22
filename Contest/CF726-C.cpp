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
		
		int h[n];
		for(int x=0;x<n;x++){
			cin >> h[x];
		}
		
		sort(h, h+n);
		
		ll mn = inf_ll;
		int idx = 0;
		for(int x=0;x+1<n;x++){
			if(mn > h[x+1]-h[x]){
				mn = h[x+1]-h[x];
				idx = x;
			}
		}
		
		cout << h[idx];
		for(int x=idx+2;x<n;x++){
			cout << " " << h[x];
		}
		for(int x=0;x<idx;x++){
			cout << " " << h[x];
		}
		cout << " " << h[idx+1] << "\n";
	}
	
    return 0;
}

