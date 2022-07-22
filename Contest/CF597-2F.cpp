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

const int maxBit = 33;

ll table[maxBit][4][4]; // maxBit, bitmask state 2 slot for a, bitmask state 2 slot for b (less/great)
int l, r;

ll solve(int i, int stateA, int stateB){
	if(i < 0){
		return 1;
	}
	if(table[i][stateA][stateB] != -1) return table[i][stateA][stateB];
	
	int bit = (1 << i);
	ll ans = 0;
	
	// i-th bit belong to A
	if(!(l&bit) || (stateB&1)){
		if(r&bit || (stateA&2)){
			ans += solve(i-1, stateA|(l&bit ? 0 : 1)|(r&bit ? 0 : 2), stateB|(l&bit ? 1 : 0)|(r&bit ? 2 : 0));
		}
	}
	
	// i-th bit belong to B
	if(!(l&bit) || (stateA&1)){
		if(r&bit || (stateB&2)){
			ans += solve(i-1, stateA|(l&bit ? 1 : 0)|(r&bit ? 2 : 0), stateB|(l&bit ? 0 : 1)|(r&bit ? 0 : 2));
		}
	}
	
	// i-th bit belong to nothing
	if(!(l&bit) || (stateA&1 && stateB&1)){
		ans += solve(i-1, stateA|(r&bit ? 2 : 0), stateB|(r&bit ? 2 : 0));
	}
	
	return table[i][stateA][stateB] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		cin >> l >> r;
		
		fill(*table[0], *table[maxBit], -1);
		
		cout << solve(29, 0, 0) << "\n";
	}

    return 0;
}

