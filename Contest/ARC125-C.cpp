#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	bool exist[n+1];
	fill(exist, exist+n+1, false);
	
	int a[k];
	for(int x=0;x<k;x++){
		cin >> a[x];
	}
	
	int ans[n], idx = 0;
	int last = 1;
	for(int x=0;x<k-1;x++){
		if(a[x] == last){
			exist[a[x]] = true;
			ans[idx++] = a[x];
		} else {
			exist[a[x]] = exist[last] = true;
			ans[idx++] = a[x];
			ans[idx++] = last;
		}
		while(exist[last] && last <= n) last++;
	}
	
	for(int x=n;x>=last;x--){
		if(exist[x]) continue;
		ans[idx++] = x;
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

