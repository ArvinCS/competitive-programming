#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll p;
	cin >> n >> p;
	
	ll t[n];
	for(int x=0;x<n;x++){
		cin >> t[x];
	}
	
	priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
	set<int> q, wait;
	ll cur = 0;
	ll ans[n];
	
	for(int x=0;x<n;x++){
		pq.push(make_tuple(t[x], 1, x));
	}
	
	while(!pq.empty()){
		ll time = get<0>(pq.top());
		int type = get<1>(pq.top());
		int idx = get<2>(pq.top());
		pq.pop();
		
		if(type == 1){
			wait.insert(idx);
		} else {
			ans[idx] = time;
			q.erase(idx);
		}
		
		while(!pq.empty() && get<0>(pq.top()) == time){
			ll time = get<0>(pq.top());
			int type = get<1>(pq.top());
			int idx = get<2>(pq.top());
			pq.pop();
			
			wait.insert(idx);
		}
		
		if(!wait.empty()){
			if(q.empty() || *(wait.begin()) < *(q.begin())){
				q.insert(*(wait.begin()));
				wait.erase(wait.begin());
				
				cur = max(cur, time)+p;
				pq.push(make_tuple(cur, 0, *(q.begin())));
			}
		}
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

