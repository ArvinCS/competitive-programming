#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n = 10;
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int ans = 0;
	for(int x=0;x<3;x++){
		ans = a[ans];
	}
	
	cout << ans << "\n";
    return 0;
}

