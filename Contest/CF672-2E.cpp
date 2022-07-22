#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 81;
const int logN = 81;

int table[maxN][maxN*maxN][maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	bool a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	vector<int> v;
	for(int x=0;x<n;x++){
		if(a[x]){
			v.push_back(x);
		}
	}
	
	
	int sz = v.size(), mx = n*(n-1)/2;
	
	fill(*table[0], *table[maxN], 1e9);
	
	if(sz > 0){
		for(int x=0;x<n;x++){
			table[x][abs(x-v[0])][1] = x*(x-1)/2+x;
		}
		for(int x=0;x<n;x++){
			for(int y=x+1;y<n;y++){
				int len = y-x-1;
				for(int c=0;c<=mx;c++){
					for(int z=0;z<sz;z++){
						if(c+abs(y-v[z]) > mx) continue;
						if(table[x][c][z] == 1e9) continue;
						
						table[y][c+abs(y-v[z])][z+1] = min(table[y][c+abs(y-v[z])][z+1], table[x][c][z]+len*(len-1)/2+len*z+y);
					}
				}
			}
		}
	}
	
	int ans = mx;
	for(int y=0;y<=mx;y++){
		for(int x=0;x<n;x++){
			int len = n-x-1;
			ans = min(ans, table[x][y][sz]+len*(len-1)/2+len*sz);
		}
		
		if(y > 0) cout << " ";
		cout << mx - ans;
	}
	cout << "\n";
    return 0;
}

