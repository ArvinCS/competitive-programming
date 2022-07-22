#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	ll k;
	cin >> n >> m >> k;
	
	int a[n], b[m];
	vector<int> v;
	for(int x=0;x<n;x++){
		cin >> a[x];
		v.push_back(a[x]);
	}
	for(int x=0;x<m;x++){
		cin >> b[x];
		v.push_back(b[x]);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	int cnt[v.size()];
	fill(cnt, cnt+v.size(), 0);
	
	for(int x=0;x<n;x++){
		cnt[lower_bound(v.begin(), v.end(), a[x]) - v.begin()]++;
	}
	for(int x=0;x<m;x++){
		cnt[lower_bound(v.begin(), v.end(), b[x]) - v.begin()]--;
	}
	
	vector<pair<int, int>> w;
	for(int x=0;x<v.size();x++){
		if(cnt[x] != 0){
			if(cnt[x] > 0){
				w.push_back({cnt[x], 1});
			} else {
				w.push_back({-cnt[x], -1});
			}
		}
	}
	
	bool possible = false;
	ll sum = 0;
	for(int x=((int) w.size())-1;x>=0;x--){
		sum += w[x].first*1ll*w[x].second;
		
		if(w[x].second == 1){
			if(sum >= 1){
				possible = true;
			}
		}
	}
	
	cout << (possible ? "BISA" : "TIDAK") << "\n";
    return 0;
}

