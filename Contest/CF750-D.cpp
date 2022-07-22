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
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		ll b[n];
		int pos = 0;
		ll sum = 0;
		for(int x=0;x<n;x++){
			sum += a[x];
		}
		for(int x=0;x<n;x++){
			if(sum-a[x] != 0 && a[x] != 0){
				pos = x;
				sum -= a[x];
				break;
			}
		}
		
		ll lcm = abs(a[pos])*abs(sum)/__gcd(abs(a[pos]), abs(sum));
		
		b[pos] = lcm/a[pos];
		if(sum < 0 && a[pos]*b[pos] < 0){
			b[pos] *= -1;
		}
		if(sum > 0 && a[pos]*b[pos] > 0){
			b[pos] *= -1;
		}
		
		for(int x=0;x<n;x++){
			if(x == pos) continue;
			
			b[x] = abs(lcm/sum);
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << b[x];
		}
		cout << "\n";
	}

    return 0;
}

