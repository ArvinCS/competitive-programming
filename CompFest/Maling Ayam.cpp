#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

bool customSort(pair<us, us> a, pair<us, us> b){
	return (a.second*1.0/a.first) > (b.second*1.0/b.first);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us n, m;
	cin >> n >> m;
	
	// First - berat
	// Second - harga
	pair<us, us> data[n];
	for(us x=0;x<n;x++) cin >> data[x].first >> data[x].second;
	
	sort(data, data+n, customSort);
	
//	for(us x=0;x<n;x++) cout << data[x].second*1.0/data[x].first << " ";
	
	ui table[m+1];
	fill(table, table+m+1, 0);
	
	for(us x=1;x<=m;x++){
		for(us y=0;y<n;y++){
			if(data[y].first <= x){
				table[x] = max(data[y].second + table[x-data[y].first], table[x]);
			}
		}	
	}
	
	cout << table[m] << "\n";
    return 0;
}

