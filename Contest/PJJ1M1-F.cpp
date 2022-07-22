#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	sort(a, a+n);
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	set<int> st;
	
	for(int x=0;x<n;x++){
		pq.push(make_pair(1, a[x]-1));
		pq.push(make_pair(1, a[x]+1));
		st.insert(a[x]);
	}
	
	ll ans[m];
	ll cnt = 0;
	for(int x=0;x<m;x++){
		while(!pq.empty() && st.count(pq.top().second)) pq.pop();
		
		pair<int, int> p = pq.top();
		pq.pop();
		
		st.insert(p.second);
		ans[x] = p.second;
		cnt += p.first;
		
		if(!st.count(p.second-1)) pq.push(make_pair(p.first+1, p.second-1));
		if(!st.count(p.second+1)) pq.push(make_pair(p.first+1, p.second+1));
	}
	
	cout << cnt << "\n";
	for(int x=0;x<m;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

