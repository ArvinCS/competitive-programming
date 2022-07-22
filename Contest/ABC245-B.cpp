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
	
	sort(a, a+n);
	
	int ans = 0;
	for(int x=0;x<n;x++){
		if(a[x] == ans) ans++;
	}
	
	cout << ans << "\n";
    return 0;
}

