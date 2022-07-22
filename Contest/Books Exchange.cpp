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
	
	int q;
	cin >> q;
	
	while(q--){
		int n;
		cin >> n;
		
		int data[n];
		for(int x=0;x<n;x++){
			int tmp;
			cin >> tmp;
			
			data[x] = tmp-1;
		}
		
		bool cycle[n];
		fill(cycle, cycle+n, false);
		
		int ans[n];
		for(int x=0;x<n;x++){
			if(!cycle[x]){
				vector<int> v;
				int cur = x;
				while(!cycle[cur]){
					v.push_back(cur);
					cycle[cur] = true;
					cur = data[cur];
				}
				
				for(auto p : v) ans[p] = v.size();
			}
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

