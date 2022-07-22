#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	vector<int> v;
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		v.push_back(a[x]);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	vector<int> w[n];
	for(int x=0;x<n;x++){
		w[lower_bound(v.begin(), v.end(), a[x]) - v.begin()].push_back(x);
	}
	
	while(q--){
		int m, k;
		cin >> m >> k;
		
		auto it = lower_bound(v.begin(), v.end(), m);
		if(it == v.end() || *it != m){
			cout << "-1\n";
			continue;
		}
		
		if(w[it - v.begin()].size() < k){
			cout << "-1\n";
			continue;
		}
		
		cout << w[it - v.begin()][k-1]+1 << "\n";
	}
    return 0;
}

