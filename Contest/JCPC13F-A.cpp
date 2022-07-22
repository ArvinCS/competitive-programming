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

const int maxN = 1e6 + 5;

string s[maxN];
vector<int> ans;
int n, m;

void solve(int idx, vector<int> v){
	if(v.empty()) return;
	if(idx == m){
		for(auto s : v) ans.push_back(s);
		return;
	}	
	
	vector<int> w[27];
	for(auto x : v){
		w[(s[x][idx] - 'A')].push_back(x);
	}
	
	if(idx % 2 == 0){
		for(int x=0;x<=26;x++){
			solve(idx+1, w[x]);
		}
	} else {
		for(int x=26;x>=0;x--){
			solve(idx+1, w[x]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m;
	
	for(int x=0;x<n;x++){
		cin >> s[x];
	}
	
	vector<int> v;
	for(int x=0;x<n;x++) v.push_back(x);
	
	solve(0, v);
	
	for(int x=0;x<ans.size();x++){
		if(x > 0) cout << " ";
		cout << ans[x]+1;
	}
	cout << "\n";
    return 0;
}

