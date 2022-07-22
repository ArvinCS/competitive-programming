#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mx = (1 << 5);
const int maxN = 1e5+5;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<tuple<string, short, short>> v;
	for(int x=0;x<n;x++){
		string s;
		cin >> s;
		
		if(s == "end_if"){
			v.push_back(make_tuple(s, -1, -1));
		} else {
			int a, b;
			cin >> a >> b;
			
			v.push_back(make_tuple(s, a, b));
		}
	}
	
	
	int state = (1 << m);
	bool table[n+1][state];
	stack<array<int, 3>> st;
	st.push({0, state-1, 0});
	
	for(int sta=0;sta<state;sta++){
		fill(table[0], table[n+1], false);
		
		table[0][sta] = true;
		
		for(int x=0;x<n;x++){
			string s = get<0>(v[x]);
			short a = get<1>(v[x]);
			short b = get<2>(v[x]);
			
			if(s == "if"){
				st.push({a, b, x});
				for(int y=a;y<=b;y++){
					table[x+1][y] = table[x][y];
				}
			} else if(s == "end_if"){
				int prv = st.top()[2];
				int prvA = st.top()[0], prvB = st.top()[1];
				st.pop();
				
				if(prvA <= prvB){
					for(int y=0;y<prvA;y++){
						table[x+1][y] = table[prv][y];
					}
					for(int y=prvB+1;y<state;y++){
						table[x+1][y] = table[prv][y];
					}
				} else {
					for(int y=0;y<state;y++){
						table[x+1][y] = table[prv][y];
					}
				}
				
				for(int y=0;y<state;y++){
					table[x+1][y] |= table[x][y];
				}
//				assert(false);
			} else {
				if(s == "add"){
					for(int y=0;y<state;y++){
						table[x+1][(y+a)%state] |= table[x][y];
						if(b == 0){
							table[x+1][y] |= table[x][y];
						}
					}
				} else if(s == "mul"){
					for(int y=0;y<state;y++){
						table[x+1][(y*a)%state] |= table[x][y];
						if(b == 0){
							table[x+1][y] |= table[x][y];
						}
					}
				} else if(s == "mod"){
					for(int y=0;y<state;y++){
						table[x+1][y%a] |= table[x][y];
						if(b == 0){
							table[x+1][y] |= table[x][y];
						}
					}
				} else {
					assert(false);
				}
			}
		}
		
		for(int y=0;y<state;y++){
			if(table[n][y]){
				cout << "1";
			} else {
				cout << "0";
			}
		}
		cout << "\n";
	}
	
	return 0;
}
