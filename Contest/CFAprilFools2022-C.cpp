#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	assert(n >= 1 && n <= 100);
	
	map<int, int> mp;
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		mp[a[x]]++;
		assert(a[x] >= 0 && a[x] <= 3979);
	}
	
	for(auto p : mp){
		if(p.second&1){
			cout << p.first << "\n";
			break;
		}
	}
    return 0;
}

