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
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		ll data[n+2], sum = 0;
		for(int x=0;x<n+2;x++){
			cin >> data[x];
			sum += data[x];
		}
		
		sort(data, data+n+2);
		
		int not1 = -1, not2 = -1;
		for(int x=0;x<n+2;x++){
			ll remain = sum-data[x];
			if(x != n+1 && remain-data[n+1] == data[n+1]){
				not1 = n+1;
				not2 = x;
				break;
			}
			if(x != n && remain-data[n] == data[n]){
				not1 = n;
				not2 = x;
				break;
			}
		}
		
		if(not1 == -1 || not2 == -1){
			cout << "-1\n";
			continue;
		}
		
		bool firstLine = true;
		for(int x=0;x<n+2;x++){
			if(x == not1 || x == not2) continue;
			
			if(!firstLine) cout << " ";
			cout << data[x];
			firstLine = false;
		}
		cout << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

