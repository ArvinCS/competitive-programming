#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	vector<pair<ll, int>> v;
	for(int x=0;x<n;x++){
		v.push_back({a[x], x});
	}
	
	sort(v.begin(), v.end());
	
	int prefix[n];
	fill(prefix, prefix+n, -1);
	
	for(int x=0;x<n/2;x++){
		prefix[v[x].second] = 1;
	}
	
	for(int x=1;x<n;x++){
		prefix[x] += prefix[x-1];
	}
	
	ll sum = 0;
	for(int x=n/2;x<n;x++){
		sum += v[x].first;
	}
	
	int mn = prefix[0];
	int pos = 0;
	for(int x=0;x<n;x++){
		if(prefix[x] < mn){
			mn = prefix[x];
			pos = x;
		}
	}
	
	cout << (pos+1)%n << " " << sum << "\n";
    return 0;
}

