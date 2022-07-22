#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	map<int, int> mp;
	int a[n], b[n];
	int ans = 0, ans2 = 0;
	for(int x=0;x<n;x++){
		cin >> a[x];
		mp[a[x]]++;
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
		ans2 += mp[b[x]];
	}
	
	for(int x=0;x<n;x++){
		if(a[x] == b[x]){
			ans2--;
			ans++;
		}
	}
	
	cout << ans << "\n";
	cout << ans2 << "\n";
    return 0;
}

