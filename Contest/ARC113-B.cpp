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

ll power(ll a, ll b, ll c){
	if(b == 0) return 1;
	ll tmp = power(a, b/2, c) % c;
	if(b & 1) return ((a * tmp) % c * tmp) % c;
	return (tmp * tmp) % c;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	ll a, b, c;
	cin >> a >> b >> c;
	
	vector<int> v;
	unordered_set<int> st;
	
	ll tmp = a;
	while(true){
		ll digit = tmp % 10;
		if(st.count(digit)) break;
		
		v.push_back(digit);
		st.insert(digit);
		
		tmp %= 10;
		tmp *= a;
	}
	
	int pos = power(b, c, v.size());
	if(pos == 0) pos = v.size();
	cout << v[pos-1] << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

