#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int p[n];
	for(int x=0;x<n;x++){
		cin >> p[x];
		p[x]--;
	}
	
	vector<pair<int, int>> v;
	for(int x=0;x<n;x++){
		v.push_back({p[x], x});
	}
	
	sort(v.rbegin(), v.rend());
	
	ll ans1 = 0, ans2 = 1;
	vector<int> w;
	for(int x=0;x<k;x++){
		w.push_back(v[x].second);
		ans1 += v[x].first+1;
	}
	
	sort(w.begin(), w.end());
	for(int x=0;x+1<k;x++){
		ans2 *= w[x+1]-w[x];
		ans2 %= mod;
	}
	cout << ans1 << " " << ans2 << "\n";
    return 0;
}

