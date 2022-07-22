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

	ll n;
	cin >> n;
	
	vector<int> v;
	v.push_back(2);
	
	ll a = 0, b = 1;
	for(ll i=0;i<61;i++){
		ll bit = (1ll << i);
		
		if(n&bit){
			
		} else {
			
		}
	}
	
	cout << v.size() << "\n";
	for(auto ans : v){
		cout << ans << "\n";
	}
    return 0;
}



