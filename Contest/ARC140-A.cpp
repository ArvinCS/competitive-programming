#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
	int cnt[n];
	fill(cnt, cnt+n, 0);
	
	for(int x=1;x<n;x++){
		for(int y=0;y<n;y++){
			if(s[y] != s[(x+y)%n]){
				cnt[x]++;
			}
		}
	}
	
	for(int x=0;x<n;x++) cout << cnt[x] << " ";
	cout << "\n";
	
	sort(cnt, cnt+n);
	
	int ans = 1;
	for(int x=0;x<n;x++){
		int mn = min(cnt[x], k);
		cnt[x] -= mn;
		k -= mn;
		
		if(cnt[x] > 0){
			cout << x << "\n";
			ans++;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

