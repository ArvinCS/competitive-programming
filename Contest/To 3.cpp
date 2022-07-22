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

int k;
ull n;

int len(ull x){
	int ans = 0;
	while(x > 0){
		x /= 10;
		ans++;
	}
	return ans;
}

int digit(int i){
	int tmp = k-i;
	ull mo = 1;
	while(tmp--){
		mo *= 10;
	}
	return (n/mo) % 10;
}

ull solve(ull curr, int length, int i){
	if(i > k) return 0;
	
	ull best = solve(curr, length, i+1);
			
	curr = curr * 10 + digit(i);

	if(curr % 3 == 0){
		best = max(best, curr);
	}
	best = max(best, solve(curr, length+1, i+1));
	
	return best;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	k = len(n);
	
	int ans = k-len(solve(0,0,1));
	if(ans == k){
		cout << "-1\n";
	} else cout << k-len(solve(0,0,1)) << "\n";
	
    return 0;
}

