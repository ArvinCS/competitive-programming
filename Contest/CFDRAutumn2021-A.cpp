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
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		ll cnt = 0, sum = 0;
		for(int x=0;x<n;x++){
			while(a[x] % 2 == 0){
				cnt++;
				a[x] /= 2;
			}
		}
		
		sort(a, a+n);
		
		for(int x=0;x<n-1;x++){
			sum += a[x];
		}
		sum += a[n-1] * 1ll * pow(2ll, cnt);
		
		cout << sum << "\n";
	}
	
    return 0;
}

