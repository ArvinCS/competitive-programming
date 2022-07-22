#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool sortPrice(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<int,int> digits[n+1];
	for(int x=0;x<=n;x++){
		digits[x].first = x;
		cin >> digits[x].second;	
	}
	
	long long m;
	cin >> m;
	
	sort(digits, digits+n+1, sortPrice);
	
	string strata;
	if(digits[0].first != 0){
		int bought = m/digits[0].second;
		string temp(bought, '0' + digits[0].first);
		strata.append(temp);
		
		m -= bought * digits[0].second;
	} else {
		if(m >= digits[1].second){
			string temp(1, '0' + digits[1].second);
			strata.append(temp);
		} else {
			strata = "0";
		}
	}
	
	cout << strata << "\n";
    return 0;
}
