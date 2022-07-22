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
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		pair<int, int> data[n];
		for(int x=0;x<n;x++){
			cin >> data[x].first;
			data[x].second = x;
		}
		
		sort(data, data+n);
		
		if(data[0].first != data[1].first){
			cout << data[0].second+1 << "\n";
		} else if(data[n-1].first != data[n-2].first){
			cout << data[n-1].second+1 << "\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

