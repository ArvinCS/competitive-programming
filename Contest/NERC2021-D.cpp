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


const int maxN = 1e5 + 5;

int n, m, data[maxN];
ll table[maxN][11];

ll ans = -1;

ll solve(int index, int digit){
	if(index == n){
		return 1;
	}
	if(table[index][digit] != -1) return table[index][digit];
	
	ll best = solve(index+1, digit);
	for(int x=0;x<=10;x++){
		if(x*)
	}
	return max(solve(index+1, digit), data[index] * solve(index+1, digit*(data[index]%10)));
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n >> m;
	
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	cout << solve(0, m) << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

