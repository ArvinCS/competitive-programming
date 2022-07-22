#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n*n];
	for(int x=0;x<n*n;x++){
		cin >> a[x];
	}
	
	vector<int> v[n+2];
	
	for(int x=0;x<n*n;x++){
		v[a[x]].push_back(x);
	}
	
	int b[n*n];
	fill(b, b+n*n, -1);
	
	int cnt = 1;
	
	for(int x=1;x<=n+1;x++){
		if(v[x].size() < n){
			for(int y=1;y<=n+1;y++){
				if(x == y) continue;
				
				if(v[x].size()+v[y].size() >= n){
					int rem = n-v[x].size();
					while(!v[x].empty()){
						b[v[x].back()] = cnt;
						v[x].pop_back();
					}
					
					for(int z=0;z<rem;z++){
						b[v[y].back()] = cnt;
						v[y].pop_back();
					}
					cnt++;
				}
			}
		}
	}
	
	bool valid = true;
	for(int x=1;x<=n+1;x++){
		if(!v[x].empty()){
			valid = false;
		}
	}
	
	if(!valid){
		cout << "NO\n";
		return 0;
	}
	
	cout << "YES\n";
	for(int x=0;x<n*n;x++){
		if(x > 0) cout << " ";
		assert(b[x] >= 1);
		cout << b[x];
	}
	cout << "\n";
	return 0;
}
