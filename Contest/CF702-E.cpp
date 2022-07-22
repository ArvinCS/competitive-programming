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
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		ll data[n], tmp[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
			tmp[x] = data[x];
		}
		
		sort(data, data+n);
		
		int start = 0, last = 0;
		ll sum = 0, cnt = 0;
		for(int x=0;x<n-1;x++){
			sum += data[x];
			if(sum >= data[x+1]){
				continue;
			} else {
				start = data[x+1];
			}
		}
		
		vector<int> ans;
		for(int x=0;x<n;x++){
			if(tmp[x] >= start){
				ans.push_back(x+1);
			}
		}
		
		cout << ans.size() << "\n";
		for(int x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

