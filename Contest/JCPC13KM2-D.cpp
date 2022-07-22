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
	
	int n;
	cin >> n;
	
	int a[n];
	vector<int> v[n];
	
	for(int x=0;x<n;x++){
		cin >> a[x];
		a[x]--;
		
		v[a[x]].push_back(x);
	}
	
	vector<pair<int, int>> w;
	for(int x=0;x<n;x++){
		if(v[x].size() > 0){
			w.push_back({v[x].size(), x});
		}
	}
	
	sort(w.rbegin(), w.rend());
	
	vector<int> picked;
	ll sum = 0;
	for(int x=0;x<w.size();x++){
		if(sum+w[x].first <= n/2){
			sum += w[x].first;
			picked.push_back(w[x].second);
		}
	}
	
	int ans[n];
	fill(ans, ans+n, -1);
	
	int pos = 0;
	for(int x=0;x<n;x+=2){
		while(pos < picked.size() && v[picked[pos]].empty()){
			pos++;
		}
		if(pos == picked.size()) break;
		
		ans[x] = v[picked[pos]].back();
		v[picked[pos]].pop_back();
	}
	
	pos = 0;
	for(int x=0;x<n;x++){
		while(pos < w.size() && v[pos].empty()){
			pos++;
		}
		
		if(ans[x] == -1){
			ans[x] = v[pos].back();
			v[pos].pop_back();
		}
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << ans[x]+1;
	}
	cout << "\n";
    return 0;
}

