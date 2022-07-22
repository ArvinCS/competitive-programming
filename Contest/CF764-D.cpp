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
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		int cnt[26], old_cnt[26];
		fill(cnt, cnt+26, 0);
		fill(old_cnt, old_cnt+26, 0);
		
		for(int x=0;x<n;x++){
			cnt[(s[x] - 'a')]++;
			old_cnt[(s[x] - 'a')]++;
		}
		
		int left = 2, right = n, ans = 1;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			for(int x=0;x<26;x++){
				cnt[x] = old_cnt[x];
			}
			
			int cur = 0, rem = 0;
			for(int x=0;x<26;x++){
				while(cnt[x] >= mid-(mid&1)-rem){
					if(cur >= k) break;
					
					cur++;
					cnt[x] -= mid-(mid&1)-rem;
					rem = 0;
				}
				
				if(cur >= k) break;
				
				if(cnt[x] > 0){
					rem += cnt[x]-(cnt[x]&1);
					cnt[x] = (cnt[x]&1);
				}
			}
			
			if(cur < k){
				right = mid-1;
				continue;
			}
			
			int sum = 0;
			for(int x=0;x<26;x++){
				sum += cnt[x];
			}
			
			if(mid % 2 == 0 || sum >= k){
				left = mid+1;
				ans = max(ans, mid);
			} else {
				right = mid-1;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

