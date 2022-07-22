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
		int mx = 0, index = -1;
		for(int x=0;x<2*n;x++){
			cin >> data[x];
			if(data[x] > mx){
				mx = data[x];
				index = x;
			}
		}
		
		if(index < n){
			cout << "NO\n";
			continue;
		}
		
		mx = 0;
		for(int x=0;x<n;x++){
			mx = max(mx, data[x]);
		}

		vector<int> table[2];
		if(mx < data[n]){
			for(int x=0;x<n;x++){
				table[0].push_back(data[x]);
			}
			for(int x=n;x<2*n;x++){
				table[1].push_back(data[x]);
			}
		} else {
			int picked = 2*n-index;
			for(int x=0;x<n-picked;x++){
				table[1].push_back(data[x]);
			}
			for(int x=n-picked;x<index;x++){
				table[0].push_back(data[x]);
			}
			for(int x=index;x<2*n;x++){
				table[1].push_back(data[x]);
			}	
		}
		
		vector<int> tmp;
		int i = 0, j = 0;
		while(i < n && j < n){
			if(table[0][i] > table[1][j]){
				tmp.push_back(table[1][j++]);
			} else {
				tmp.push_back(table[0][i++]);
			}
		}
		if(i < n){
			for(int x=i;x<n;x++){
				tmp.push_back(table[0][x]);
			}
		}
		if(j < n){
			for(int x=j;x<n;x++){
				tmp.push_back(table[1][x]);
			}
		}
			
//		for(auto v : table[0]){
//			cout << v << " ";
//		}
//		cout << "\n";
//		
//		for(auto v : table[1]){
//			cout << v << " ";
//		}
//		cout << "\n";
		
		bool possible = true;
		for(int x=0;x<2*n;x++){
			if(tmp[x] != data[x]){
				possible = false;
				break;
			}
		}
		
		if(possible) cout << "YES\n";
		else cout << "NO\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

