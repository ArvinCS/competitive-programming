#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

bool customSort(pair<ui, ui> a, pair<ui, ui> b){
	return a.second > b.second;	
}

ull calc(ui start, ui end){
	if(start > end) return 0;
	return (end * 1ull * (end+1) - start * 1ull * (start-1))/ 2;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui n;
	cin >> n;
	
	vector<pair<ui, ui>> data(n);
	for(ui x=0;x<n;x++){
		cin >> data[x].first >> data[x].second;
	}
	
	sort(data.begin(), data.end(), customSort);
	
	ull ans = calc(data[0].first, data[0].second);
	
//	cout << ans << "\n";
	ui cpoint = data[0].first;
	for(ui x=1;x<n;x++){
		ans += calc(min(cpoint, data[x].first), min(cpoint-1, data[x].second));
		cpoint = min(cpoint, data[x].first);
	}
	
	cout << ans << "\n";
    return 0;
}

