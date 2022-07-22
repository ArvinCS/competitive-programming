#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	int p;
	cin >> p;
	
	int n = s.length();
	vector<int> v;
	for(int x=1;x*x<=p;x++){
		if(p%x == 0){
			v.push_back(x);
			if(p/x != x) v.push_back(p/x);
		}
	}
	
	sort(v.begin(), v.end());
	
	int mn[n];
	fill(mn, mn+n, 1e9);
	
	for(int x=0;x<v.size();x++){
		if(v[x] == p) break;
		for(int y=0;y<n;y++){
			int sum = 0;
			for(int z=y;z<n;z++){
				sum += (s[z] - '0');
				
				if(sum > v[x]) break;
				if(sum == v[x]){
					mn[y] = min(mn[y], z);
				}
			}
		}
	}
	
	for(int x=0;x<n;x++){
		int r = n;
		for(int y=x;y<n;y++){
			r = min(r, nxt[y]);
			if(r <= y) break;
		}
	}
    return 0;
}

