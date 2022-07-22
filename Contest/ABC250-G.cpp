#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int p[n];
	for(int x=0;x<n;x++){
		cin >> p[x];
	}
	
	priority_queue<int, vector<int>, greater<int>> pq;
	ll ans = 0;
	for(int x=0;x<n;x++){
		ans -= p[x];
		pq.push(p[x]);
		pq.push(p[x]);
		pq.pop();
	}
	
	for(int x=0;x<n;x++){
		ans += pq.top();
		pq.pop();
	}
	
	cout << ans << "\n";
    return 0;
}

