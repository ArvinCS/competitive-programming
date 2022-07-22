#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e7 + 5;

int table[maxN];

int length(int x){
	int ans = 0;
	while(x > 0){
		ans++;
		x/=10;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll a, n;
	cin >> a >> n;
	
	fill(table, table+maxN, 1e9);
	
	priority_queue<pair<int, ll>, vector<pair<int, ll>>, greater<pair<int, ll>>> pq;
	table[1] = 0;
	pq.push({table[1], 1});
	
	while(!pq.empty()){
		pair<int, ll> p = pq.top();
		pq.pop();
		
		if(table[p.second] < p.first) continue;
		if(p.second >= 10 && p.second%10 != 0){
			ll cur = p.second/10 + (p.second%10)*pow(10, length(p.second/10));
			if(cur < maxN && table[cur] > table[p.second]+1){
				table[cur] = table[p.second]+1;
				pq.push({table[cur], cur});	
			}
		}
		
		if(p.second*a < maxN && table[p.second*a] > table[p.second]+1){
			table[p.second*a] = table[p.second]+1;
			pq.push({table[p.second*a], p.second*a});
		}
	}
	
	cout << (table[n] == 1e9 ? -1 : table[n]) << "\n";
    return 0;
}

