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
	
	int n, m;
	cin >> n >> m;
	
	int a[n], b[n];
	bool changed[n];
	
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
		if(a[x] != b[x]) changed[x] = true;
		else changed[x] = false;
	}
	
	vector<int> edges[n];
	while(m--){
		int c, d;
		cin >> c >> d;
		
		c--;
		d--;
		edges[c].push_back(d);
		edges[d].push_back(c);
		
		int diff = min(abs(a[c]-b[c]), abs(a[d]-b[d]));
		if(a[c] > b[c] && a[d] < b[d]){
			a[c] -= diff;
			a[d] += diff;
		} else if(a[c] < b[c] && a[d] > b[d]){
			a[c] += diff;
			a[d] -= diff;
		}
	}
	
	for(int x=0;x<n;x++){
		if(!changed[x]){
//			int p = 0;
			for(int i=0;i<edges[x].size();i++){
				int y = edges[x][i];
				if(a[y] != b[y]){
					if(a[y] > b[y]){
						a[x] += a[y]-b[y];
						a[y] = b[y];
					} else if(a[y] < b[y]){
						a[x] -= b[y]-a[y];
						a[y] = b[y];
					}
				}
			}
			if(a[x] != b[x]){
				cout << "No\n";
				return 0;
			}
		}
	}
	cout << "Yes\n";
    return 0;
}

