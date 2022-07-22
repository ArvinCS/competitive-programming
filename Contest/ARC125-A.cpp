#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int a[n], b[m];
	int cnt[2];
	cnt[0] = cnt[1] = 0;
	
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<m;x++){
		cin >> b[x];
		cnt[b[x]]++;
	}
	
	int ans = 1e9;
	for(int x=0;x<n;x++){
		if(a[x] == b[0] && (min(cnt[0], cnt[1]) == 0 || a[x] != a[(x+1)%n] || a[x] != a[(x-1+n)%n])){
			ans = min(ans, min(x, n-x));
		}
	}
	
	if(ans == 1e9){
		cout << "-1\n";
		return 0;
	}
	
	ans++;
	for(int x=1;x<m;x++){
		ans++;
		if(b[x-1] != b[x]){
			ans++;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

