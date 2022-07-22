#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int h, w, c, q;
	cin >> h >> w >> c >> q;
	
	int t[q], v[q], m[q];
	for(int x=0;x<q;x++){
		cin >> t[x] >> v[x] >> m[x];
		m[x]--;
	}
	
	ll ans[c];
	fill(ans, ans+c, 0);
	
	set<int> row, col;
	for(int x=q-1;x>=0;x--){
		if(t[x] == 1){ // row
			if(!row.count(v[x])){
				ans[m[x]] += w-col.size();
				row.insert(v[x]);
			}
		} else { // column
			if(!col.count(v[x])){
				ans[m[x]] += h-row.size();
				col.insert(v[x]);
			}
		}
	}
	
	for(int x=0;x<c;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

