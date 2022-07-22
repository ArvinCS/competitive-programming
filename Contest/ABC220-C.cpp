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
	
	int n;
	cin >> n;
	
	ll a[n], sum = 0, m;
	for(int x=0;x<n;x++){
		cin >> a[x];
		sum += a[x];
	}
	cin >> m;
	
	ll div = m/sum;
	m %= sum;
	sum = 0;
	for(int x=0;x<n;x++){
		if(sum > m){
			cout << (div*n)+x << "\n";
			return 0;
		}
		sum += a[x];
	}
	cout << (div*n)+n << "\n";
	
    return 0;
}

