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
		
		sort(a, a+n);
		
		int cnt[n+1];
		fill(cnt, cnt+n+1, 0);
		
		for(int x=0;x<n;x++){
			int cur = a[x];
			
			while(cur > n){
				cur /= 2;
			}
			
			cnt[cur]++;
		}
		
		bool valid = true;
		for(int x=1;x<=n;x++){
			while(cnt[x] > 1){
				int cur = x;
				
				while(cnt[cur] > 0){
					cur /= 2;
				}
				
				if(cur > 0){
					cnt[cur]++;
					cnt[x]--;
				} else {
					break;
				}
			}
		}
		for(int x=1;x<=n;x++){
			if(cnt[x] == 0){
				valid = false;
			}
		}
		cout << (valid ? "YES" : "NO") << "\n";
		
		
	}
	
    return 0;
}

