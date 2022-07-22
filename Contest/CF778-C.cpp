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
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		map<ll, int> mp;
		ll sum = 0;
		for(int x=0;x<n;x++){
			sum += a[x];
			mp[a[x]]++;
		}
		
		priority_queue<ll> pq;
		pq.push(sum);
		
		bool valid = true;
		for(int x=0;x<n-1;x++){
			if(pq.empty()){
				valid = false;
				break;
			}
			
			while(!pq.empty()){
				if(mp[pq.top()] > 0){
					mp[pq.top()]--;
					pq.pop();
				} else {
					break;
				}
			}
		
			if(mp[pq.top()] > 0){
				mp[pq.top()]--;
				pq.pop();
			} else {
				ll cur = pq.top();
				pq.pop();
				
				if(cur < 2){
					valid = false;
					break;
				}
				
				pq.push(cur/2);
				pq.push((cur+1)/2);
			}
		}
		
		while(!pq.empty()){
			ll cur = pq.top();
			pq.pop();
			
			if(mp[cur] > 0){
				mp[cur]--;
			} else {
				valid = false;
				break;
			}
		}
		
		cout << (valid ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

