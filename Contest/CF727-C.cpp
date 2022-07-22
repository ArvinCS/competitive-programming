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

	ll n, m, p;
	cin >> n >> m >> p;
	
	ll data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	sort(data, data+n);
	
	vector<ll> v;
	for(int x=0;x+1<n;x++){
		if(data[x+1] - data[x] > p){
			v.push_back((data[x+1]-data[x]-1)/p);
		}
	}
	
	sort(v.begin(), v.end());
	
	for(int x=0;x<v.size();x++){
		if(v[x] > m){
			cout << v.size()-x+1 << "\n";
			return 0;
		}
		
		m -= v[x];
	}
	cout << "1\n";
    return 0;
}

