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
	
	ll n;
	cin >> n;
	
	vector<char> v;
	while(n > 0){
		if(n&1){
			v.push_back('A');
			n--;
		} else {
			v.push_back('B');
			n /= 2ll;
		}
	}
	
	for(int x=v.size()-1;x>=0;x--){
		cout << v[x];
	}
	cout << "\n";
    return 0;
}

