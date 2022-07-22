#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

#define mod 1000000007

us n, m;
ui mx[2000];

ui brute(us i, us p, ui data[], bool newMem, bool canPass){
	if(i == n && p+1 == m && !newMem && canPass) return 1;
//	if(memo[i][p] < inf_int) return memo[i][p];
	
	ui cnt = 0;
	if(p < m && i < n){
		if(p+1 < m && !newMem && canPass){
			cnt += brute(i,p+1,data, true, false);
//			cout << i << "-" << data[i] << " " << p  << "\n";
			cnt %= mod;
		}
		if(data[i] <= mx[p]){
			cnt += brute(i+1,p,data, false, canPass || data[i] == mx[p]);
			cnt %= mod;
		}
	}
	
	return cnt % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
		
	cin >> n >> m;
	
	ui data[n];
	for(us x=0;x<n;x++) cin >> data[x];
	
	for(us x=0;x<m;x++) cin >> mx[x];
	
	cout << brute(0,0,data,true,false) << "\n";
    return 0;
}

