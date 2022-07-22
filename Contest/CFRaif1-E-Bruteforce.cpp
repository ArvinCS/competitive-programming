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

vector<int> ans;
int best = inf_int;

void solve(int idx, int k, vector<int> v, int cur){
	if(idx == k){
		if(cur != 0) return;
		
		ll cnt = 0;
		for(auto e : v){
			cnt += pow(e, 2);
		}
		if(cnt < best){
			best = cnt;
			swap(v, ans);
		}
		return;
	}
	
	for(int x=1;x<=cur;x++){
		v.push_back(x);
		solve(idx+1, k, v, cur-x);
		v.pop_back();
	}
}


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	vector<int> v;
	solve(0, 6-1, v, 9-1);
	
	cout << best << "\n";
	for(auto e : ans){
		cout << e << " ";
	}
    return 0;
}

