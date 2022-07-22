#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	pair<int, int> p[2*n];
	for(int x=0;x<2*n;x++){
		cin >> p[x].first;
		p[x].second = x;
	}
	
	int nxt[2*n];
	fill(nxt, nxt+2*n, -1);
	
	vector<pair<int, int>> v;
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		nxt[a] = b;
		nxt[b] = a;
		
		if(p[a] > p[b]){
			v.push_back({p[a].first-p[b].first, a});
		} else {
			v.push_back({p[b].first-p[a].first, b});
		}
	}
	
	sort(p, p+2*n);
	sort(v.rbegin(), v.rend());
	
	int t;
	cin >> t;
	
	bool exist[2*n];
	fill(exist, exist+2*n, true);
	
	if(t == 1){
		for(auto p : v){
			cout << p.second+1 << endl;
			
			int res;
			cin >> res;
			
			res--;
			exist[res] = exist[p.second] = false;
		}
		for(int x=2*n-1;x>=0;x--){
			if(exist[p[x].second]){
				cout << p[x].second+1 << endl;
			
				int res;
				cin >> res;
				
				res--;
				exist[res] = exist[p[x].second] = false;
			}
		}
	} else {
		for(int i=0;i<n;i++){
			int res;
			cin >> res;
			
			res--;
			
			exist[res] = false;
			
			if(nxt[res] != -1 && exist[nxt[res]]){
				cout << nxt[res]+1 << endl;
				exist[nxt[res]] = false;
			} else {
				bool found = false;
				for(auto p : v){
					if(!exist[p.second]) continue;
					
					cout << p.second+1 << endl;
					exist[p.second] = false;
					found = true;
					break;
				}
				
				if(!found){
					for(int x=2*n-1;x>=0;x--){
						if(exist[p[x].second]){
							cout << p[x].second+1 << endl;
							exist[p[x].second] = false;
							break;
						}
					}
				}
			}
		}
	}
    return 0;
}

