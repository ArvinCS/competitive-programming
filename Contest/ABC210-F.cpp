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

const int maxN = 3e4 + 5;

vector<int> adj[2*maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	pair<int, int> card[n];
	int a[2*n];
	for(int x=0;x<n;x++){
		cin >> card[x].first >> card[x].second;
		a[2*x] = card[x].first;
		a[2*x+1] = card[x].second;
	}
	
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			if(__gcd(card[x].first, card[y].first) == 1){
				adj[2*x].push_back(2*y);
			}
			if(__gcd(card[x].first, card[y].second) == 1){
				adj[2*x].push_back(2*y+1);
			}
			if(__gcd(card[x].second, card[y].first) == 1){
				adj[2*x+1].push_back(2*y);
			}
			if(__gcd(card[x].second, card[y].second) == 1){
				adj[2*x+1].push_back(2*y+1);
			}
		}
	}
	
	queue<pair<int, vector<int>>> q;
	q.push({0, {}});
	q.push({1, {}});
	
	while(!q.empty()){
		pair<int, vector<int>> p = q.front();
		q.pop();
		
		bool valid = true;
		for(auto prv : p.second){
			if(__gcd(prv, a[p.first]) != 1){
				valid = false;
				break;
			}
		}
		
		if(valid){
			if(p.first/2 == n-1){
				cout << "Yes\n";
				return 0;
			}
			
			p.second.push_back(a[p.first]);
			for(auto nxt : adj[p.first]){
				q.push({nxt, p.second});
			}
		}
	}
	
	cout << "No\n";
    return 0;
}

