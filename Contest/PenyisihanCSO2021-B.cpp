#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	for(int x=0;x<n;x++){
		int cur = a[x];
		int ans = cur%10;
		
		while(cur >= 10){
			cur /= 10;
		}
		ans += cur;
		
		cout << ans << "\n";
	}
	
	return 0;
}
