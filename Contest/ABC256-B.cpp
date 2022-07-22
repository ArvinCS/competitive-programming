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
	
	int cur[10*n];
	fill(cur, cur+10*n, 0);
	
	int idx = 10*n-1;
	for(int x=0;x<n;x++){
		cur[idx]++;
		
		idx -= a[x];
	}
	
	int ans = 0;
	for(int x=idx+4;x<10*n;x++){
		ans += cur[x];
	}
	
	cout << ans << "\n";
    return 0;
}

