#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define inf_int 1e9
#define inf_ll 1e18

bool sortByX(pair<long long, long long> a, pair<long long, long long> b){
	if(a.first < b.first){
		return true;
	} else if(a.first == b.first){
		return a.second < b.second;
	} else {
		return false;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<long long, long long> data[n];
	for(int i=0;i<2;i++){
		for(int x=0;x<n;x++){
			cin >> (i == 0 ? data[x].first : data[x].second);
		}
	}
	
	sort(data, data+n, sortByX);
	
	pair<double, double> checkpoint;
	if(n % 2 == 1){
		int median = (n-1) / 2;
		checkpoint = {data[median]};
	} else {
		checkpoint = {(data[n-1].first - data[0].first)/2.0, (data[n-1].second - data[0].second)/2.0};
	}
	double ans = 0;
	for(int x=0;x<n;x++){
		ans += abs(data[x].first - checkpoint.first) + abs(data[x].second - checkpoint.second);
	}
	
	cout << fixed << setprecision(1) << ans << "\n";
    return 0;
}
