#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

const int mxN = 1e5 + 5;
int table[mxN], data[mxN];

ui n, d, m;

int dp(int index){
	if(index >= n){
		return 0;
	}	
	if(table[index] != -inf_int){
		return table[index];
	}
	
	int ans = dp(index+1);
	if(data[index] > m){
		ans = max(ans, data[index] + dp(min(n, index+d+1)));
	} else {
		ans = max(ans, data[index] + dp(index+1));
	}
	
	return table[index] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> d >> m;
	
	fill(table, table+n+1, -inf_int);
	for(ui x=0;x<n;x++) cin >> data[x];
	
	sort(data, data+n, greater<int>());
	cout << dp(0) << "\n";
	
	for(ui x=0;x<n;x++) cout << table[x] << " ";
	cout << "\n";
    return 0;
}

