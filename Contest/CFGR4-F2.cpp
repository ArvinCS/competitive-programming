#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 998244353

const int maxN = 2005;
const int maxM = 1e6 + 5;
const int lgN = log2(maxN);

ll table[maxN][maxN];
int n, m, mnPos[lgN+1][maxN], mxPos[lgN+1][maxN], mnC[lgN+1][maxN], c[maxM];
vector<int> v, pos[maxN];

int queryMinPos(int left, int right){
	if(right < left) return inf_int;
	
	int lg = log2(right-left+1);
	int length = (1 << lg);
	
	return min(mnPos[lg][left], mnPos[lg][right-length+1]);	
}

int queryMaxPos(int left, int right){
	if(right < left) return -1;
	
	int lg = log2(right-left+1);
	int length = (1 << lg);
	
	return max(mxPos[lg][left], mxPos[lg][right-length+1]);	
}

int queryMinColor(int left, int right){
	if(right < left) return inf_int;
	
	int lg = log2(right-left+1);
	int length = (1 << lg);
	
	return min(mnC[lg][left], mnC[lg][right-length+1]);	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n >> m;
	
	fill(table[0], table[maxN], 1);
	
	for(int x=0;x<m;x++){
		cin >> c[x];
		c[x]--;
	}
	
	for(int x=0;x<m;x++){
		if(v.size() == 0 || v.back() != c[x]){
			pos[c[x]].push_back(v.size());
			v.push_back(c[x]);
		}
	}
	
	if(v.size() > 2*n){
		cout << "0\n";
		return 0;
	}
	
	for(int i=0;i<=lgN;i++){
		int length = (1 << i);
		for(int x=0;x+length<=v.size();x++){
			if(i == 0){
				mnC[i][x] = v[x];
				mnPos[i][x] = pos[v[x]].front();
				mxPos[i][x] = pos[v[x]].back();
			} else {
				mnC[i][x] = min(mnC[i-1][x], mnC[i-1][x+length/2]);
				mnPos[i][x] = min(mnPos[i-1][x], mnPos[i-1][x+length/2]);
				mxPos[i][x] = max(mxPos[i-1][x], mxPos[i-1][x+length/2]);
			}
		}
	}
	
//	for(int x=0;x<v.size();x++){
//		cout << v[x] << " ";
//	}
//	cout << "\n";
	
	for(int x=0;x<n;x++){
		if(queryMinColor(pos[x].front()+1, pos[x].back()-1) < x){
			cout << "0\n";
			return 0;
		}
	}
	
	for(int l=2;l<=v.size();l++){
		for(int x=0;x+l<=v.size();x++){
			if(queryMinPos(x, x+l-1) == x && queryMaxPos(x, x+l-1) == x+l-1){
				int mn = queryMinColor(x, x+l-1);
				
				ll ansLeft = 0, ansRight = 0;
				for(int y=x;y<=pos[mn].front();y++){
					if(queryMinPos(y, pos[mn].front()) == y){
						ansLeft += (y-1 >= 0 ? table[x][y-1] : 1ll) * (pos[mn].front()-1 >= 0 ? table[y][pos[mn].front()-1] : 1ll) % mod;
						ansLeft %= mod;
					}
				}
				for(int y=pos[mn].back();y<=x+l-1;y++){
					if(queryMaxPos(pos[mn].front(), y) == y){
						ansRight += table[pos[mn].back()+1][y] * table[y+1][x+l-1] % mod;
						ansRight %= mod;
					}
				}
				
				table[x][x+l-1] = ansLeft * ansRight % mod;
				
				for(int y=1;y<pos[mn].size();y++){
					table[x][x+l-1] *= table[pos[mn][y-1]+1][pos[mn][y]-1];
					table[x][x+l-1] %= mod;
				}
			}
		}
	}
	
	cout << table[0][v.size()-1] << "\n";
    return 0;
}

