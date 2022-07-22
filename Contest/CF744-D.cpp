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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		priority_queue<pair<int, int>> pq;
		for(int x=0;x<n;x++){
			int val;
			cin >> val;
			
			pq.push({val, x});
		}
		
		vector<pair<int, int>> ans;
		
		while(pq.size() > 1){
			pair<int, int> p = pq.top();
			pq.pop();
			pair<int, int> q = pq.top();
			pq.pop();
			
			if(p.first == 0 || q.first == 0){
				if(p.first != 0) pq.push(p);
				if(q.first != 0) pq.push(q);
				continue;
			}
			
			ans.push_back({p.second, q.second});
			q.first--;
			p.first--;
			
			pq.push(p);
			pq.push(q);
		}
		
		cout << ans.size() << "\n";
		for(auto p : ans){
			cout << p.first+1 << " " << p.second+1 << "\n";
		}
	}	
	
    return 0;
}

