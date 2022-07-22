#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const int maxN = 2005;

pair<ll, ll> city[maxN];
ll c[maxN], k[maxN], parrent[maxN];
bool visited[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> city[x].first >> city[x].second;
	}
	for(int x=0;x<n;x++){
		cin >> c[x];
	}
	for(int x=0;x<n;x++){
		cin >> k[x];
	}
	
	ll total = 0;
	vector<int> ans1;
	vector<pair<int, int>> ans2;
	
	for(int x=0;x<n;x++){
		parrent[x] = x;
		visited[x] = false; 
	}
	
	for(int i=0;i<n;i++){
		ll best = inf_ll, bestIdx = -1;
		for(int x=0;x<n;x++){
			if(visited[x]) continue;
			
			if(best > c[x]){
				best = c[x];
				bestIdx = x;
			}
		}
		
		total += best;
		visited[bestIdx] = true;
		if(parrent[bestIdx] == bestIdx){
			ans1.push_back(bestIdx);
		} else {
			ans2.push_back({bestIdx, parrent[bestIdx]});
		}
		
		for(int x=0;x<n;x++){
			if(visited[x]) continue;
			
			ll dist = abs(city[x].first-city[bestIdx].first) + abs(city[x].second-city[bestIdx].second);
			if(dist*(k[x]+k[bestIdx]) < c[x]){
				c[x] = dist*(k[x]+k[bestIdx]);
				parrent[x] = bestIdx;
			}
		}
	}
	
	cout << total << "\n";
	cout << ans1.size() << "\n";
	for(int x=0;x<ans1.size();x++){
		if(x > 0) cout << " ";
		cout << ans1[x]+1;
	}
	cout << "\n";
	cout << ans2.size() << "\n";
	for(auto p : ans2) cout << p.first+1 << " " << p.second+1 << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

