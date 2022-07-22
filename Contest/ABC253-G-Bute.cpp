#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll l, r;
	cin >> n >> l >> r;
	
	vector<pair<int, int>> v;
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			v.push_back({x, y});
		}
	}
	
	sort(v.begin(), v.end());
	
	int a[n];
	for(int x=0;x<n;x++) a[x] = x;
	
	for(int x=l-1;x<r;x++){
		swap(a[v[x].first], a[v[x].second]);
		cout << x+1 << "(" << v[x].first+1 << "," << v[x].second+1 << ")" << " ->\n";
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << a[x]+1;
		}
		cout << "\n";
	}
    return 0;
}

