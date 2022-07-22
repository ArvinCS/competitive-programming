#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n], b[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
	}
	
	vector<int> v;
	for(int x=0;x<n;x++){
		v.push_back(a[x]);
		v.push_back(b[x]);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for(int x=0;x<n;x++){
		a[x] = lower_bound(v.begin(), v.end(), a[x]) - v.begin();
		b[x] = lower_bound(v.begin(), v.end(), b[x]) - v.begin();
	}
	
	int lst[v.size()][2];
	fill(lst[0], lst[v.size()], n);
	
	for(int x=n-1;x>=0;x--){
		lst[a[x]][0] = x;
		lst[b[x]][1] = x;
	}
	
	int prefix[n][2];
	for(int x=0;x<n;x++){
		prefix[x][0] = (x > 0 ? prefix[x-1][0] : -1);
		prefix[x][0] = max(prefix[x][0], lst[a[x]][1]);
		
		prefix[x][1] = (x > 0 ? prefix[x-1][1] : -1);
		prefix[x][1] = max(prefix[x][1], lst[b[x]][0]);
	}
	
	int q;
	cin >> q;
	
	while(q--){
		int l, r;
		cin >> l >> r;
		
		l--; r--;
		if(prefix[l][0] > r || prefix[r][1] > l){
			cout << "No\n";
		} else {
			cout << "Yes\n";
		}
	}
    return 0;
}

