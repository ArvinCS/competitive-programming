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
		int n, k;
		cin >> n >> k;
		
		pair<int, int> data[n];
		for(int x=0;x<n;x++){
			cin >> data[x].first >> data[x].second;
		}
				
		bool valid = false;
		for(int x=0;x<n;x++){
			int cnt = 0;
			for(int y=0;y<n;y++){
				if(abs(data[y].first-data[x].first) + abs(data[y].second-data[x].second) <= k){
					cnt++;
				}
			}	
			if(cnt == n){
				valid = true;
				break;
			}
		}
		
		if(valid) cout << "1\n";
		else cout << "-1\n";
	}
	
    return 0;
}

