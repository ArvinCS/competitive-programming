#include <bits/stdc++.h>

using namespace std;

#define ll long long

int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int h, w, n;
	cin >> h >> w >> n;
	
	vector<pair<int, int>> v;
	int r[n], c[n], a[n];
	for(int x=0;x<n;x++){
		cin >> r[x] >> c[x] >> a[x];
		v.push_back({a[x], x});
	}
	
	sort(v.rbegin(), v.rend());
	
	ll ans[n];
	ll row[h+2], col[w+2];
	fill(row, row+h+2, -1);
	fill(col, col+w+2, -1);
	
	queue<tuple<ll, int, int>> q;
	for(int x=0;x<n;x++){
		if(x > 0 && a[v[x-1].second] > a[v[x].second]){
			while(!q.empty()){
				tuple<ll, int, int> t = q.front();
				q.pop();
				
				row[get<1>(t)] = max(row[get<1>(t)], get<0>(t));
				col[get<2>(t)] = max(col[get<2>(t)], get<0>(t));
			}
		}
		
		ans[v[x].second] = max(row[r[v[x].second]], col[c[v[x].second]])+1;
		q.push(make_tuple(ans[v[x].second], r[v[x].second], c[v[x].second]));
	}
	
	for(int x=0;x<n;x++){
		cout << ans[x] << "\n";
	}
    return 0;
}

