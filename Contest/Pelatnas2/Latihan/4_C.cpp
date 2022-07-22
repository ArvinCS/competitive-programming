#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int sz = (1 << m);
	int mark[n];
	bool d[n][m];
	for(int x=0;x<n;x++){
		int state = 0;
		for(int y=0;y<m;y++){
			char c;
			cin >> c;
			
			d[x][y] = (c == '#');
			
			state *= 2;
			state |= (!d[x][y]);
		}
		mark[x] = state;
	}
	
	int comp[sz];
	fill(comp, comp+sz, 1e9);
	
	for(int state=0;state<sz;state++){
		for(int state2=0;state2<sz;state2++){
			int cnt = 0;
			int prv = 0;
			
			for(int y=m-1;y>=0;y--){
				int bit = (1 << y);
				
				if((state&bit) && !(state2&bit)){
					cnt++;
					prv = 0;
				} else if(state&bit){
					if(prv == 0){
						cnt++;
						prv = 1;
					}
				} else if(!(state&bit)){
					prv = 0;
				}
			}
			
			comp[state] = min(comp[state], cnt);
		}
	}
	
	int table[n+1][sz];
	fill(table[0], table[n+1], 1e9);
	
	for(int x=0;x<sz;x++){
		table[n-1][x] = comp[x];
	}
	
	for(int x=n-1;x>=0;x--){
		ll new_table[sz];
		for(int state=0;state<sz;state++){
			new_table[state] = table[x][state];
		}
		
		for(int state=0;state<sz;state++){
			if((mark[x]&state) != mark[x]){
				continue;
			}
			
			int cnt = table[x][state];
			int prv = 0;
			
			for(int y=m-1;y>=0;y--){
				int bit = (1 << y);
				
				if(mark[x]&bit){
					prv = 0;
				} else if(state&bit){
					if(prv == 0){
						cnt++;
						prv = 1;
					}
				} else {
					prv = 0;
				}
			}
			
			new_table
		}
	}
	
	cout << table[0][sz-1] << "\n";
    return 0;
}

