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
		int n, m;
		cin >> n >> m;
		
		int data[n], weight[m], buy[m];
		for(int x=0;x<n;x++) cin >> data[x];
		for(int x=0;x<m;x++){
			cin >> weight[x];
			buy[x] = false;
		}
		
		sort(data, data+n);
		
		ull cost = 0, index = 0;
		for(int x=n-1;x>=0;x--){			
			if(data[x]-1 >= index){
				cost += weight[index++];
			} else {
				cost += weight[data[x]-1];
			}
//			cout << cost << "\n";
		}
		
		cout << cost << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar
