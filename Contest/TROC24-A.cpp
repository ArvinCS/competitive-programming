#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n], b[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
	}
	
	int ans = 0;
	for(int x=0;x<n;x++){
		if(a[x] == b[x]){
			ans++;
		}
	}
	
	cout << ans << "\n";
	return 0;
}
