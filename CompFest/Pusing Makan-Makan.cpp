#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

#define mod 1000000007

ull table[100001];

bool customSort(pair<ui, ui> a, pair<ui, ui> b){
	return a.second < b.second;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui n;
	cin >> n;
	
	pair<ui, ui> data[n];
	for(ui x=0;x<n;x++) cin >> data[x].first >> data[x].second;
	
	fill(table, table+100001, 0);
	sort(data, data+n, customSort);
	
	ui y = 0;
	for(ui x=1;x<=data[n-1].second;x++){
		table[x] = table[x-1];
		while(y<n){
			if(data[y].second == x){
				table[x] += 1 + table[data[y].first-1];
				table[x] %= mod;
				y++;
			} else break;
		}
	}
	
//	for(ui x=0;x<=data[n-1].second;x++) cout << table[x] << " ";
//	cout << "\n";
	cout << table[data[n-1].second] << "\n";
    return 0;
}

