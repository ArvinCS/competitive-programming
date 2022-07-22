#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int ans = 0;
	
	map<ll, int> mp;
	mp[0]++;
	ll sum = 0;
	for(int x=0;x<n;x++){
		sum += a[x];
		
		if(mp.find(sum) != mp.end()){
			mp.clear();
			mp[0]++;
			sum = a[x];
			ans++;
		}
		
		mp[sum]++;
	}
	
	cout << ans << "\n";
    return 0;
}

