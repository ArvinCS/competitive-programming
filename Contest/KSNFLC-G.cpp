#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007

const int maxK = 1e6 + 5;
const int logN = log2(1e18);
const ll maxN = 1e18;
const int boundN = 1e6 + 5;

ll table_top[41*maxK], table_bot[boundN];
ll n, k;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	// f(x) = a + 2b + 4c + 8d + ... + ??z
	// odd : 1 + f(x-1)
	
	cin >> n >> k;
	
	cout << solve(30, n) << "\n";
    return 0;
}

