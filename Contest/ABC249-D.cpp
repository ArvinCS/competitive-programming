#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxA = 2e5 + 5;

int cnt[maxA];

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
	
	fill(cnt, cnt+maxA, 0);
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		cnt[a[x]]++;
	}
	
	for(int x=1;x<maxA;x++){
		for(int y=1;y*1ll*x<maxA;y++){
			ans += cnt[x*y] * 1ll * cnt[y] * 1ll * cnt[x];
		}
	}
	
	cout << ans << "\n";
    return 0;
}

