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

const int maxN = 1e5 + 5;
const int maxP = 8;

ll a[maxN], s[maxN][maxP];
ll table[maxN][(1 << maxP)];

int n, p, k;

bool customSort(int idx1, int idx2){
	return a[idx1] > a[idx2];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> n >> p >> k;
	
	vector<int> idx;
	for(int x=0;x<n;x++){
		cin >> a[x];
		idx.push_back(x);
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<p;y++){
			cin >> s[x][y];
		}
	}
	
	sort(idx.begin(), idx.end(), customSort);
	
	fill(table[0], table[n+1], -inf_ll);
	table[0][0] = 0;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<(1 << p);y++){
			int remain = k-(x-__builtin_popcount(y));
			for(int z=0;z<p;z++){
				int bit = (1 << z);
				if(!(y&bit)){
					table[x+1][y|bit] = max(table[x+1][y|bit], table[x][y]+s[idx[x]][z]);
				}
			}
			if(remain > 0) table[x+1][y] = max(table[x+1][y], table[x][y]+a[idx[x]]);
			else table[x+1][y] = max(table[x+1][y], table[x][y]);
//			cout << table[x][y] << " ";
		}
//		cout << "\n";
	}
	
	cout << table[n][(1 << p)-1] << "\n";
    return 0;
}

