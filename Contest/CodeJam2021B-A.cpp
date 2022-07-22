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
	
	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		cout << "Case #" << i << ": ";
		ll a, b, c;
		cin >> a >> b >> c;
		
		ll tmp = pow(10, 10), tmp2 = pow(10ll, 9);
		a /= (tmp*12);
		b /= (tmp*12);
		c /= (tmp*12);
		
		for(int r=0;r<360;r++){
			ll deg[3] = {(a+r)%360, (b+r)%360, (c+r)%360};
			
			bool found = false;
			for(int x=0;x<3;x++){
				for(int y=0;y<3;y++){
//					cout << x << "-" << y << "\n";
					if(x == y) continue;
//					cout << x << "-" << y << "\n";
					int z = (-(x+y)+3)%3;
					
					ll hour = (deg[x]/30)%12, minute = (deg[y]/6), second = (deg[z]/6);
					ll remH = (deg[x]%30), remM = (deg[y]%6), remZ = (deg[z]%6);
					
					if(remH*2 != minute){
//						cout << remH << " " << minute << "fail4\n";
						continue;
					}
					if(remM > 0 && remM*10 != second){
//						cout << remM << " " << second << " " << "fail3\n";
						continue;
					}
					if(remZ > 0 && 6%remZ != 0){
						continue;
					}
					if(remZ > 0 && tmp2%(6/remZ) != 0){
						continue;
					}
					
					ll nano = (remZ == 0 ? 0 : tmp2/(6/remZ));
					if(nano >= tmp2){
						continue;
					}
					
					found = true;
//					cout << x << " " << y << "\n";
					cout << hour << " " << minute << " " << second << " " << nano;
					break;
				}
				if(found) break;
			}
			if(found) break;
		}
		cout << "\n";
	} 
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

