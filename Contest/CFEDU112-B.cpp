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
	
	us t;
	cin >> t;
	
	while(t--){
		int w, h;
		cin >> w >> h;
		
		int x1,x2,y1,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		int a, b, c, d;
		a = (x2-x1);
		b = (y2-y1);
		cin >> c >> d;
		
		int ans = inf_int;
		
		// left top
		if(a <= (w-c)){
			ans = min(ans, max(0, c-x1));
		}
		if(b <= (h-d)){
			ans = min(ans, max(0, y2-(h-d)));
		}
		
		// right top
		if(a <= (w-c)){
			ans = min(ans, max(0, x2-(w-c)));
		}
		if(b <= (h-d)){
			ans = min(ans, max(0, y2-(h-d)));
		}
		
		// left bot
		if(a <= (w-c)){
			ans = min(ans, max(0, c-x1));
		}
		if(b <= (h-d)){
			ans = min(ans, max(0, d-y1));
		}
		
		// right bot
		if(a <= (w-c)){
			ans = min(ans, max(0, x2-(w-c)));
		}
		if(b <= (h-d)){
			ans = min(ans, max(0, d-y1));
		}
		
		cout <<(ans == inf_int ? -1 : ans) << "\n";
	}
	
    return 0;
}

