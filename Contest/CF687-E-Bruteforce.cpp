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

int n, c[50005];
int ans = -inf_int;
vector<int> w;
bool picked[50005];

void solve(int sz, int cnt, int cur, int k, vector<int> v){
	if(sz == n){
		if(cnt > ans){
			ans = cnt;
			w = v;
		}
		return;
	}
	
	if(cnt == 71) return;	
	if(k > 0 && sz >= n-4){
		v.push_back(-1);
		solve(sz, cnt, 0, k-1, v);
		v.pop_back();
	}
	
	for(int x=0;x<n;x++){
		if(!picked[x]){
			picked[x] = true;
			v.push_back(x+1);
			solve(sz+1, cnt+cur, cur+c[x], k, v);
			v.pop_back();
			picked[x] = false;
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int k;
	cin >> n >> k;
	
	for(int x=0;x<n;x++){
		cin >> c[x];
		picked[x] = false;
	}
	
	vector<int> v;
	solve(0, 0, 0, k, v);
	
	cout << ans << "\n";
	for(int x=0;x<w.size();x++){
		cout << w[x] << " ";
	}
	cout << "\n";
    return 0;
}

