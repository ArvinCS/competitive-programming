#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	string s;
	cin >> s;
	
	ll k;
	cin >> k;
	
	int n = s.length();
	
	ll prefix[n];
	for(int x=0;x<n;x++){
		prefix[x] = (x > 0 ? prefix[x-1] : 0);
		if(s[x] == 'Y') prefix[x] += x;
	}
	
	int left = 1, right = n, ans = 0;
	while(left <= right){
		int mid = (left+right) >> 1;
		
		bool possible = false;
		deque<int> q;
		for(int x=0;x<n;x++){
			if(s[x] == 'Y'){
				while(q.size() >= mid){
					q.pop_front();
				}
				
				q.push_back(x);
			
				if(q.size() == mid){
					int m = (mid+1)/2;
					
					ll cnt = 0;
					cnt += q[m-1]*1ll*m - (prefix[q[m-1]] - (q.front() > 0 ? prefix[q.front()-1] : 0)) - m*1ll*(m-1)/2;
					cnt += prefix[x] - prefix[q[m-1]] - q[m-1]*1ll*(mid-m) - (mid-m)*1ll*(mid-m+1)/2;
					
					if(cnt <= k){
						possible = true;
					}
				}
			}
		}
		
		if(possible){
			ans = max(ans, mid);
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

