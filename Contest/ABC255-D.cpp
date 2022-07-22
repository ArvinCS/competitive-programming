#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	ll sumL = 0, sumR = 0;
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		sumR += a[x];
	}
	
	sort(a, a+n);
	
	vector<pair<int, int>> v;
	for(int x=0;x<q;x++){
		int val;
		cin >> val;
		
		v.push_back({val, x});
	}
	
	ll ans[q];
	sort(v.begin(), v.end());
	
	int pos = -1;
	for(int x=0;x<q;x++){
		while(pos+1 < n && a[pos+1] < v[x].first){
			sumR -= a[pos+1];
			sumL += a[pos+1];
			pos++;
		}
		
		ans[v[x].second] = (pos+1)*1ll*v[x].first-sumL + sumR-(n-pos-1)*1ll*v[x].first;
	}
	
	for(int x=0;x<q;x++){
		cout << ans[x] << "\n";
	}
    return 0;
}

