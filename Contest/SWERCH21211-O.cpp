#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		vector<array<int, 3>> v, w;
		for(int x=0;x<n;x++){
			char c;
			cin >> c;
			
			if(c == 'C'){
				int r, a, b;
				cin >> r >> a >> b;
				
				v.push_back({r, a, b});
			} else if(c == 'S'){
				int r1, r2, a;
				cin >> r1 >> r2 >> a;
				
				w.push_back({r1, r2, a});
			}
		}
		
		bool table[220][3610];
		fill(table[0], table[220], false);
		
		bool valid[220][3610];
		fill(valid[0], valid[220], true);
		
		for(int x=0;x<v.size();x++){
			for(int a=v[x][1]*10;a<=v[x][2]*10+(v[x][1] > v[x][2] ? 3600 : 0);a++){
				valid[v[x][0]*10][a%3600] = false;
			}
		}
		for(int x=0;x<w.size();x++){
			for(int r=w[x][0]*10;r<=w[x][1]*10;r++){
				valid[r][w[x][2]*10 % 3600] = false;
			}
		}
		
		queue<pair<int, int>> q;
		for(int x=0;x<3600;x++){
			table[0][x] = true;
			q.push({0, x});
		}
		
		while(!q.empty()){
			pair<int, int> p = q.front();
			q.pop();
			
			if(p.first+1 <= 210 && valid[p.first+1][p.second] && !table[p.first+1][p.second]){
				table[p.first+1][p.second] = true;
				q.push({p.first+1, p.second});
			}
			if(p.first-1 >= 0 && valid[p.first-1][p.second] && !table[p.first-1][p.second]){
				table[p.first-1][p.second] = true;
				q.push({p.first-1, p.second});
			}
			if(valid[p.first][(p.second+1)%3600] && !table[p.first][(p.second+1)%3600]){
				table[p.first][(p.second+1)%3600] = true;
				q.push({p.first, (p.second+1)%3600});
			}
			if(valid[p.first][(p.second-1+3600)%3600] && !table[p.first][(p.second-1+3600)%3600]){
				table[p.first][(p.second-1+3600)%3600] = true;
				q.push({p.first, (p.second-1+3600)%3600});
			}
		}
		
		bool possible = false;
		for(int x=0;x<3600;x++){
			possible |= table[210][x];
		}
		
		cout << (possible ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

