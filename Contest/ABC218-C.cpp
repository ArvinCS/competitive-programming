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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	char s[n][n], t[n][n];
	vector<pair<int, int>> v, w, z, m, p, q;
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cin >> s[x][y];
			
			if(s[x][y] == '#'){
				v.push_back({y, x});
			}
		}
	}
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cin >> t[x][y];
			
			if(t[x][y] == '#'){
				m.push_back({y, x});
			}
		}
	}
	
	for(int y=0;y<n;y++){
		for(int x=0;x<n;x++){
			if(s[n-1-x][x] == '#'){
				w.push_back({x, y});
			}
		}
	}
	for(int y=n-1;y>=0;y--){
		for(int x=0;x<n;x++){
			if(s[x][y] == '#'){
				z.push_back({x, y});
			}
		}
	}
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(s[n-1-x][y] == '#'){
				p.push_back({y, x});
			}
		}
	}
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){			
			if(s[x][n-1-y] == '#'){
				q.push_back({y, x});
			}
		}
	}
	
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	sort(z.begin(), z.end());
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());
	sort(m.begin(), m.end());
	
	bool possible[5];
	fill(possible, possible+5, true);
	
	for(int x=0;x<v.size();x++){
		for(int y=x+1;y<v.size();y++){
			if(v.size() != m.size()){
				possible[0] = false;
				break;
			}
			
			if(v[y].first-v[x].first != m[y].first-m[x].first || v[y].second-v[x].second != m[y].second-m[x].second){
				possible[0] = false;
				break;
			}
		}
	}
	
	for(int x=0;x<w.size();x++){
		for(int y=x+1;y<w.size();y++){
			if(w.size() != m.size()){
				possible[1] = false;
				break;
			}
			
			if(w[y].first-w[x].first != m[y].first-m[x].first || w[y].second-w[x].second != m[y].second-m[x].second){
				possible[1] = false;
				break;
			}
		}
	}
	
	for(int x=0;x<z.size();x++){
		for(int y=x+1;y<z.size();y++){
			if(z.size() != m.size()){
				possible[2] = false;
				break;
			}
			
			if(z[y].first-z[x].first != m[y].first-m[x].first || z[y].second-z[x].second != m[y].second-m[x].second){
				possible[2] = false;
				break;
			}
		}
	}
	
	for(int x=0;x<p.size();x++){
		for(int y=x+1;y<p.size();y++){
			if(p.size() != m.size()){
				possible[3] = false;
				break;
			}
			
			if(p[y].first-p[x].first != m[y].first-m[x].first || p[y].second-p[x].second != m[y].second-m[x].second){
				possible[3] = false;
				break;
			}
		}
	}
	
	for(int x=0;x<q.size();x++){
		for(int y=x+1;y<q.size();y++){
			if(q.size() != m.size()){
				possible[3] = false;
				break;
			}
			
			if(q[y].first-q[x].first != m[y].first-m[x].first || q[y].second-q[x].second != m[y].second-m[x].second){
				possible[4] = false;
				break;
			}
		}
	}
	
	cout << possible[0] << " " << possible[1] << " " << possible[2] << "\n";
	
	if(possible[0] || possible[1] || possible[2] || possible[3] || possible[4]){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
    return 0;
}

