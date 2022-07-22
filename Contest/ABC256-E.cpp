#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<ll, int> val[n];
	int m[n], c[n];
	vector<int> w[n];
	for(int x=0;x<n;x++){
		cin >> m[x];
		m[x]--;
		w[m[x]].push_back(x);
		val[x] = {0, x};
	}
	for(int x=0;x<n;x++){
		cin >> c[x];
	}
	
	bool exist[n];
	fill(exist, exist+n, true);
	
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	ll ans = 0;
	for(int x=0;x<n;x++){
		val[m[x]].first += c[x];
//		val[x].first += c[x];
	}
	
	for(int x=0;x<n;x++){
//		cout << " = " << val[x].first << "\n";
		pq.push(val[x]);
	}
	
	int q[n];
	for(int x=0;x<n;x++){
		while(!pq.empty() && (val[pq.top().second].first != pq.top().first || !exist[pq.top().second])){
			pq.pop();
		}
		assert(!pq.empty());
		
		exist[pq.top().second] = false;
		
		int nxt = m[pq.top().second];
		val[nxt].first -= c[pq.top().second];
		
		int tmp = pq.top().second;
//		cout << tmp << " =\n";
		pq.pop();
		pq.push(val[nxt]);
		
		q[x] = tmp;
	}
	
	for(int x=0;x<n;x++){
		if(exist[m[q[x]]]){
			ans += c[q[x]];
		}
		exist[q[x]] = true;
	}
	
	cout << ans << "\n";
    return 0;
}

