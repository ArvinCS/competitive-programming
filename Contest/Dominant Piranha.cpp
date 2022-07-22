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
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		unordered_map<int, int> mp;
		int data[n], cnt = 0, highest = 0;
		for(int x=0;x<n;x++){
			cin >> data[x];
			mp[data[x]]++;
			
			if(mp[data[x]] == 1){
				cnt++;
			}
			if(data[x] > highest){
				highest = data[x];
			}
		}
		
		if(cnt > 1){
			int ans = 0;
			for(int x=0;x<n;x++){
				if(data[x] == highest){
					if((x > 0 && data[x-1] < data[x]) || (x+1 < n && data[x] > data[x+1])){
						ans = x+1;
						break;
					}
				}
			}
			cout << ans << "\n";
		} else {
			cout << "-1\n";
		}
		
		
	}
	
    return 0;
}

