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

bool customSort(pair<short, short> a, pair<short, short> b){
	return abs(a.first) < abs(b.first);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		short n;
		cin >> n;
		
		int ans[n];
		pair<short, short> data[n];

		for(short x=0;x<n;x++){
			cin >> data[x].first;
			data[x].second = x;
		}
		
		for(short x=0;x<n;x++){
			if(x > 0) cout << " ";
			if(x < n/2) cout << -data[n-x-1].first;
			else cout << data[n-x-1].first;
		}
		cout << "\n";
	}
	
    return 0;
}

