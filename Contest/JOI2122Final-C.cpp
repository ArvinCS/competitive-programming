#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool customSort(pair<int, int> a, pair<int, int> b){
	if(a.second == b.second){
		return a.first > b.first;
	}
	return a.second < b.second;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int k;
	cin >> k;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		if(p[x].second == -1) p[x].second = 1e9;
	}
	
	sort(p, p+n, customSort);
	
	double ans = 1e9;
	double cur = 0;
	for(int x=0;x<=k;x++){
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		for(int y=x;y<n;y++){
			pq.push({p[y].first, -y});
		}
		
		double val = cur;
		int cnt = x+1;
		
		vector<int> v;
		for(int y=0;y<k-x;y++){
			if(pq.empty()) break;
			
			if(pq.top().first == p[-pq.top().second].second){
				val += pq.top().first*1.0/cnt;
				cnt++;
			} else {
				v.push_back(pq.top().first);
			}
			
			pq.pop();
		}
		
		for(int y=0;y<v.size();y++){
			val += v[y]*1.0/cnt;
		}
		
//		cout << x << " " << fixed << val << "\n";
		ans = min(ans, val);
		
		if(x == n || p[x].second == 1e9) break;
		cur += p[x].second*1.0/(x+1);
	}
	
	cout << fixed << setprecision(4) << ans << "\n";
    return 0;
}
