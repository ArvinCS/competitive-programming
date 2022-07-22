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

const int maxN = 1e6 * 2;

ull suffix[maxN];
pair<ull, ull> data[maxN], table[maxN][2];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		for(int x=0;x<n;x++) cin >> data[x].first;
		for(int x=0;x<n;x++) cin >> data[x].second;
		
		sort(data, data+n);
		
		suffix[n] = 0;
		for(int x=n-1;x>=0;x--){
			suffix[x] = suffix[x+1] + data[x].second;
		}
		
		ull best = suffix[0], high = 0;
		for(int x=0;x<n;x++){
			high = max(high, data[x].first);
			best = min(best, max(high, suffix[x+1]));
		}
		
		cout << best << "\n";
	}
	
    return 0;
}

