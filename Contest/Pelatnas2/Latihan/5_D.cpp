#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		p[x].second *= -1;
	}
	
	sort(p, p+n);
	
	int cnt[n];
	for(int x=0;x<n;x++){
		cnt[x] = x;
	}
	
	priority_queue<int, vector<int>, greater<int>> pq;
	int lazy = 0;
	ll ans = 0;
	for(int x=n-1;x>=0;x--){
		pq.push(p[x].second *= -1);
		while(cnt[x]+lazy < p[x].first){
			ans += pq.top();
			pq.pop();
			lazy++;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

