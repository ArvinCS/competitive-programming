#include <iostream>

using namespace std;

int coin[500], memo[50001] = { 0 };
bool computed[50001] = { false };

int solve(int n, int k){
	if(k == 0){
		return 0;
	}
	if(computed[k]){
		return memo[k];
	}
	
	int best = 1000000000;
	for(int x=0;x<n;x++){
		if(k-coin[x] >= 0){
			best = min(best, solve(n,k-coin[x]) + 1);
		}
	}
	computed[k] = true;
	memo[k] = best;
	return best;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n,k;
	cin >> n;
	
	for(int x=0;x<n;x++) cin >> coin[x];
	
	cin >> k;
	
	cout << solve(n,k) << "\n";
	
    return 0;
}
