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

	int n, m;
	cin >> n >> m;
	
	short stat[n];
	fill(stat, stat+n, 0);
	
	vector<pair<int, int>> v;
	for(int i=0;i<m;i++){
		int t, l, r;
		cin >> t >> l >> r;
		
		if(t == 1){
			for(int x=l;x<r;x++){
				if(stat[x] == 0) stat[x] = 1;
			}
		} else {
			v.push_back({l, r});
		}
//		v.push_back(make_tuple(l,r,t));
	}

//	sort(v.begin(), v.end());
	
	for(int x=0;x<v.size();x++){
		bool contain = false;
		int index = -1;
		for(int y=v[x].first;y<v[x].second;y++){
			if(stat[y] == -1){
				contain = true;
				break;
			}
			if(stat[y] == 0){
				index = y;
			}
		}	
		
		if(!contain){
			if(index >= 0) stat[index] = -1;
			else {
				cout << "NO\n";
				return 0;
			}
		}
	}
	
	cout << "YES\n";
	int cnt = 5000;
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		
		cnt += stat[x];
		cout << cnt;
	}
	cout << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

