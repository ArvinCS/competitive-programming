#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

short k;
ui n;
ll data[300005], table[300005][2][2];

ll dp(ui i, bool continueK, bool useK){
	if(i == n){
		return 0;
	}
	if(table[i][useK][continueK] != inf_ll){
		return table[i][useK][continueK];
	}
	
	ll best = 0;
	if(continueK){
		best = max(best, data[i] * k + dp(i+1, true, false)); // continue multiply k
		best = max(best, data[i] + dp(i+1, false, false)); // stop multiply k
	} else {
		best = max(best, data[i] + dp(i+1, false, useK)); // default
		if(useK){
			best = max(best, max(data[i], data[i] * k) + dp(i+1, true, false)); // start multiply k
		}
	}
	
	return table[i][useK][continueK] = best;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	cin >> n >> k;
	
	for(ui x=0;x<n;x++){
		cin >> data[x];
	}
	
	fill(table[0][0], table[n+1][2], inf_ll);
	
	ll ans = 0;
	for(ui x=0;x<n;x++){
		ans = max(ans, dp(x, false, true));
	}
	cout << ans << "\n";
	
//	for(ui x=0;x<n;x++){
//		cout << "x: " << x << "\n";
//		cout << table[x][0][0] << " " << table[x][0][1] << "\n";
//		cout << table[x][1][0] << " " << table[x][1][1] << "\n";
//	}
    return 0;
}

