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

const int maxN = 2e5 + 5;

int cnt[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, k;
	cin >> n >> k;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	int c[k+1];
	for(int x=1;x<=k;x++){
		cin >> c[x];
	}
	
	for(int x=0;x<n;x++) cnt[data[x]]++;
	
	vector<int> ans[n+1];
	int idx = 0;
	for(int x=k;x>=1;x--){
		if(ans[0].size() < c[x]) idx = 0;
		while(cnt[x]--){
			while(ans[idx].size() >= c[x]){
				idx++;
			}
			ans[idx].push_back(x);
		}
	}
	
	int sz = 0;
	for(int x=0;x<=n;x++){
		if(ans[x].size() == 0){
			sz = x;
			break;
		}
	}
	
	cout << sz << "\n";
	for(int x=0;x<sz;x++){
		cout << ans[x].size();
		for(auto e : ans[x]){
			cout << " " << e;
		}
		cout << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

