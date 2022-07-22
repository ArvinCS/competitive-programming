#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxA = 4e6;
const int maxN = 40;

bool customSort(array<int, 3> a, array<int, 3> b){
	if(a[0] == b[0]){
		return a[1] > b[1];
	}
	return a[0] < b[0];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		ll sum = 0;
		array<int, 3> p[n];
		for(int x=0;x<n;x++){
			cin >> p[x][1] >> p[x][0];
			p[x][2] = x;
			sum += p[x][0];
		}
		
		sort(p, p+n);
		
		vector<int> ans;
		bool exist[n];
		fill(exist, exist+n, true);
		
		pair<ll, int> table[n+1][k+1];
		fill(table[0], table[n+1], make_pair(-1e18, -1));
		
		table[0][0] = {0, -1};
		for(int x=0;x<n;x++){
			table[x+1][0] = max(table[x+1][0], {table[x][0].first+(k-1)*p[x][0], table[x][0].second});
			for(int y=1;y<=k;y++){
				table[x+1][y] = max(table[x+1][y], {table[x][y-1].first+(y-1)*p[x][0]+p[x][1], x});
				table[x+1][y] = max(table[x+1][y], {table[x][y].first+(k-1)*p[x][0], table[x][y].second});
			}
		}
		
		int cur = table[n][k].second;
		while(cur >= 0 && k > 0){
			exist[p[cur][2]] = false;
			ans.push_back(p[cur][2]+1);
			
			k--;
			cur = table[cur][k].second;
		}
		
		reverse(ans.begin(), ans.end());
		
		int tmp = ans.back();
		ans.pop_back();
		
		for(int x=0;x<n;x++){
			if(exist[x]){
				ans.push_back(x+1);
				ans.push_back(-x-1);
			}
		}
		
		ans.push_back(tmp);
		
		cout << ans.size() << "\n";
		for(int x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

