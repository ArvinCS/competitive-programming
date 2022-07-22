#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	bool table[m+1], new_table[m+1];
	fill(table, table+m+1, false);
	
	table[0] = 1;
	for(int x=0;x<n;x++){
		fill(new_table, new_table+m+1, false);
		
		for(int y=m-1;y>=0;y--){
			if(y+p[x].first <= m){
				new_table[y+p[x].first] |= table[y];
			}
			if(y+p[x].second <= m){
				new_table[y+p[x].second] |= table[y];
			}
		}
		
		for(int y=0;y<=m;y++){
			table[y] = new_table[y];
		}
	}
	
	cout << (table[m] ? "Yes" : "No") << "\n";
    return 0;
}

