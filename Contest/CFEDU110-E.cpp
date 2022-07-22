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

const int maxN = 3e5 + 5;
const int logN = log2(maxN)+2;

int n, q, a[maxN], c[maxN];
int parrent[logN][maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> q >> a[0] >> c[0];
	n = 1;
	
	for(int x=0;x<logN;x++) parrent[x][0] = 0;
	for(int i=1;i<=q;i++){
		int t;
		cin >> t;
		
		if(t == 1){
			int p;
			cin >> p >> a[i] >> c[i];
			
			parrent[0][i] = p;
			for(int x=1;x<logN;x++){
				parrent[x][i] = parrent[x-1][parrent[x-1][i]];
			}
			
			n++;
		} else {
			int v, w;
			cin >> v >> w;
			
			ll cnt = 0, cost = 0;
			
			while(w > 0){
				int curNode = v;
				for(int x=logN-1;x>=0;x--){
					if(a[parrent[x][curNode]] > 0){
						curNode = parrent[x][curNode];
					}
				}
				
				if(a[curNode] == 0){
					break;
				}
				
				int mn = min(w, a[curNode]);
				
				w -= mn;
				a[curNode] -= mn;
				
				cnt += mn;
				cost += mn*1ll*c[curNode];
			}
			
			cout << cnt << " " << cost << endl;
		}
	}

    return 0;
}

