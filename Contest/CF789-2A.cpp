#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		int cnt[101];
		fill(cnt, cnt+101, 0);
		
		for(int x=0;x<n;x++){
			cnt[a[x]]++;
		}
		
		int num = 0;
		int ans = 0;
		for(int x=1;x<=100;x++){
			if(cnt[x] > 0){
				ans += cnt[x]-1;
				num++;
			}
		}
		
		if(cnt[0] > 0 || ans > 0){
			ans += num;
		} else {
			ans += num+1;
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

