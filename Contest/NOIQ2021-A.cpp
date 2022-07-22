#include <bits/stdc++.h>

using namespace std;

bool customSort(pair<int, int> a, pair<int, int> b){
	return abs(a.first-a.second) > abs(b.first-b.second);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, a, b;
	cin >> n >> a >> b;
	
	pair<int, int> data[n];
	for(int x=0;x<n;x++){
		cin >> data[x].first;
	}
	for(int x=0;x<n;x++){
		cin >> data[x].second;
	}
	
	sort(data, data+n, customSort);

	long long sum1 = 0, sum2 = 0;
	int x;
	for(x=0;x<n;x++){
		if(a == 0 || b == 0) break;
		if(data[x].first >= data[x].second){
			sum1 += data[x].first;
			a--;
		} else {
			sum2 += data[x].second;
			b--;
		}
	}
	for(;x<n;x++){
		if(a != 0){
			sum1 += data[x].first;
			a--;
		} else {
			sum2 += data[x].second;
			b--;
		}
	}
//	cout << sum1 << " " << sum2 << "\n";
	cout << sum1 + sum2 << "\n";
    return 0;
}

