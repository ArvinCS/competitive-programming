#include <iostream>

using namespace std;

#define mod 1000000007;

unsigned long long memoization[1000001] = {};

unsigned long long solve(short n, int s, int x, int t){
	if(memoization[s] > 0) return memoization[s];
	
	cout << s << "\n";
	
	unsigned long long ans = n % mod;
	for(int i=s+x;i<t;i++){
		ans += solve(n, i, x, t);
		ans %= mod;
	}
	
	memoization[s] = ans % mod;
	return memoization[s];	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short n,x;
	int t;
	
	cin >> n >> x >> t;
	
	cout << solve(n,0,x,t) << "\n";
    return 0;
}
