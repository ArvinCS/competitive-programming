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
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}

	for(int m=2;m<=1000;m++){
		bool ok = true;
		for(int x=1;x<n;x++){
			if(a[x]%m != a[0]%m){
				ok = false;
				break;
			}
		}
		
		if(ok){
			cout << m << "\n";
		}
	}
    return 0;
}

