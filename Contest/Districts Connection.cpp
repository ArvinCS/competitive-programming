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
		short n;
		cin >> n;
		
		unordered_set<int> s;
		int gang[n], road[n], cnt = 0;
		for(short x=0;x<n;x++){
			cin >> gang[x];
			
			if(x > 0) road[x] = 0;
			if(!s.count(gang[x])){
				cnt++;
			}
			s.insert(gang[x]);
		}
		
		for(short x=1;x<n;x++){
			if(gang[road[x]] == gang[x]){
				for(short y=1;y<n;y++){
					if(x == y) continue;
					if(gang[y] != gang[x]){
						road[x] = y;
						break;
					}
				}
			}
		}
		
		if(cnt > 1){
			cout << "YES\n";
			for(short x=1;x<n;x++){
				cout << road[x]+1 << " " << x+1 << "\n";
			}
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

