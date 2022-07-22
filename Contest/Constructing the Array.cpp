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

	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		vector<int> idx[n+1];
		queue<pair<int, int>> q;
		q.push({1,n});
		
		while(!q.empty()){
			pair<int, int> p = q.front();
			q.pop();
			
			if(p.first > p.second) continue;
			
			idx[p.second-p.first+1].push_back((p.second+p.first)/2);	
					
			q.push({p.first, (p.second+p.first)/2-1});
			q.push({(p.second+p.first)/2+1, p.second});
		}
//		cout << "A\n";
//		sort(begin(idx), end(idx));
		
		sort(idx[1].begin(), idx[1].end());
		
		int ans[n+1], cnt = 1;
		for(int x=n;x>=1;x--){
			for(int y=0;y<idx[x].size();y++){
				ans[idx[x][y]] = cnt++;
			}
		}
		
		for(int x=1;x<=n;x++){
			if(x > 1) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}

    return 0;
}

