#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> v[n];
	
	for(int x=0;x<n;x++){
		int val;
		cin >> val;
		
		val--;
		v[val].push_back(x);
	}
	
	int q;
	cin >> q;
	
	while(q--){
		int l, r, val;
		cin >> l >> r >> val;
		
		l--; r--;
		val--;
		
		cout << (lower_bound(v[val].begin(), v[val].end(), r+1) - v[val].begin()) - (lower_bound(v[val].begin(), v[val].end(), l) - v[val].begin()) << "\n";
	}
    return 0;
}

