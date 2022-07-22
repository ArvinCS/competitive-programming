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
		
		int data[2*n];
		for(int x=0;x<2*n;x++){
			cin >> data[x];
		}
		
		sort(data, data+2*n);

		pair<int, int> ans[n];
		
		bool found = false;
		for(int i=2*n-2;i>=0;i--){
			multiset<int> s;
			for(int x=0;x<2*n-1;x++){
				if(x == i) continue;
				s.insert(data[x]);
			}

			int sum = data[2*n-1], z = 0;
			ans[z++] = {sum, data[i]};
			bool valid = true;
			for(int x=1;x<=n-1;x++){
				int last = *prev(s.end());
				s.erase(prev(s.end()));
				if(s.count(sum-last)){
					ans[z++] = {last, sum-last};
					s.erase(s.find(sum-last));
					sum = max(last, sum-last);
				} else {
					valid = false;
					break;
				}
			}
			
			if(valid){
				cout << "YES\n";
				cout << ans[0].first+ans[0].second << "\n";
				for(auto p : ans){
					cout << p.first << " " << p.second << "\n";
				}
				found = true;
				break;
			}
		}
		
		if(!found){
			cout << "NO\n";
			continue;
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

