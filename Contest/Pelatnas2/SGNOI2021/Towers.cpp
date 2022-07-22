#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	map<int, int> rg;
	array<int, 3> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x][0] >> p[x][1];
		p[x][2] = x;
		rg[p[x][1]] = max(rg[p[x][1]], p[x][0]);
	}
	
	sort(p, p+n);
	
	set<int> st;
	string ans(n, '0');
	
	map<int, int> mp, mp2;
	
	int l = 0;
	while(l < n){
		int r = l;
		int mn = 1e9, mnIdx = -1;
		int mx = -1e9, mxIdx = -1;
		
		while(r < n && p[r][0] == p[l][0]){
			if(!st.count(p[r][1]) || rg[p[r][1]] == p[r][0]){
				if(p[r][1] < mn){
					mn = p[r][1];
					mnIdx = r;
				}
				if(mx < p[r][1]){
					mx = p[r][1];
					mxIdx = r;
				}
			}
			r++;
		}
		
		if(mnIdx != -1){
			ans[p[mnIdx][2]] = '1';
			st.insert(p[mnIdx][1]);
			
			mp[p[mnIdx][0]]++;
			mp2[p[mnIdx][1]]++;
				
			if(mnIdx != mxIdx){
				ans[p[mxIdx][2]] = '1';
				st.insert(p[mxIdx][1]);
				
				mp[p[mxIdx][0]]++;
				mp2[p[mxIdx][1]]++;
			}
		}
		l = r;
	}
	
	for(int x=0;x<n;x++){
		swap(p[x][0], p[x][1]);
	}
	
	sort(p, p+n);
	
	st.clear();
	
	l = 0;
	while(l < n){
		int r = l;
		int mx = -1e9, mxIdx = -1;
		
		bool ok = false;
		while(r < n && p[r][0] == p[l][0]){
			if(ok && mp[p[r][1]] < 2){
				if(mx < p[r][1]){
					mx = p[r][1];
					mxIdx = r;
				}
			}
			if(ans[p[r][2]] == '1'){
				ok = true;
			}
			
			r++;
		}
				
		if(mp2[p[mxIdx][0]] < 2 && mxIdx != -1){
			mp2[p[mxIdx][0]]++;
			ans[p[mxIdx][2]] = '1';
			st.insert(p[mxIdx][1]);
			mp[p[mxIdx][1]]++;
		}
		l = r;
	}
	
	cout << ans << "\n";
	return 0;
}
