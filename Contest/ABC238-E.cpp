#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	int cnt[n+1];
	fill(cnt, cnt+n+1, 0);
	
	vector<pair<int, int>> v;
	while(q--){
		int l, r;
		cin >> l >> r;
		
		l--; r--;
		v.push_back({l, r});
		cnt[l]++;
		cnt[r+1]--;
	}
	
	bool possible = true;
	for(int x=0;x<n;x++){
		if(x > 0) cnt[x] += cnt[x-1];
		
		if(cnt[x] == 0){
			possible = false;
		}
		if(cnt[x] > 1 && cnt[x] % 2 == 0){
			possible = false;
		}
	}
	
	for(int x=0;x<v.size();x++){
		if(v[x].first == 0 && v[x].second == n-1){
			possible = true;
		}
	}
	
	cout << (possible ? "Yes" : "No") << "\n";
    return 0;
}

