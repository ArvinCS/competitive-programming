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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	bool valid[3005];
	fill(valid, valid+3005, false);
	
	for(int x=0;x<n;x++){
		int tmp;
		cin >> tmp;
		
		valid[tmp] = true;
	}
	
	for(int x=0;x<m;x++){
		int tmp;
		cin >> tmp;
		
		if(valid[tmp]){
			valid[tmp] = false;
		} else {
			valid[tmp] = true;
		}
	}
	
	vector<int> ans;
	for(int x=1;x<=1000;x++){
		if(valid[x]) ans.push_back(x);
	}
	
	for(int x=0;x<ans.size();x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

