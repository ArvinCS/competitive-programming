#include <bits/stdc++.h>

using namespace std;

const int maxN = 2e5 + 5;

int c[maxN], table[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int n;
		cin >> n;
		
		for(int x=0;x<n;x++){
			cin >> c[x];
		}
		
		map<int, int> mp;
		for(int x=0;x<n;x++){
			table[x] = 1e9;
			if(mp.find(c[x]) != mp.end()){
				table[x] = min(table[x], table[mp[c[x]]]+1);
			}
			table[x] = min(table[x], (x-1 >= 0 ? table[x-1] : -1)+1);
			mp[c[x]] = x;
		}
		
		cout << table[n-1] << "\n";
	}
	
    return 0;
}

