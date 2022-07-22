#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool priority(pair<int, int> a, pair<int, int> b){
	if(a.first < b.first) return true;
	else if(a.first == b.first){
		return a.second > b.second;
	}	
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	long long m;
	vector<pair<int, long long>> cost(n+1);
	
	for(int x=0;x<=n;x++){
		cin >> cost[x].second;
		cost[x].first = x;
	}
	cin >> m;
	
	for(int x=0;x<=n;x++){
		if(cost[x].second > m){
			cost.erase(cost.begin() + x);
		}
	}
	
	sort(cost.begin(), cost.end(), priority);
	
	vector<int> strata(cost[0].second/m, cost[0].first);
	cout << strata.size() << "\n";
    return 0;
}
