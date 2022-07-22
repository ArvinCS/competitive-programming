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

struct Line{
	int x1, y1, x2, y2;
};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, q;
	cin >> n >> q;
	
	Line l[n];
	for(int x=0;x<n;x++){
		cin >> l[x].x1 >> l[x].y1 >> l[x].x2 >> l[x].y2;
	}
	
	for(int i=1;i<=q;i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		int ans = 0;
		if(a == c){ // x axis
			for(int y=0;y<n;y++){
				if(l[y].y1 == l[y].y2){
					if(l[y].x1 < a && c < l[y].x2 && l[y].y1 > b && l[y].y2 < d){
						ans++;
					}
				}
			}
		} else {
			for(int y=0;y<n;y++){
				if(l[y].x1 == l[y].x2){
					if(a < l[y].x1 && l[y].x1 < c && l[y].y1 < b && l[y].y2 > d){
						ans++;
					}
				}
			}
		}
		cout << ans << "\n";
	}
    return 0;
}

