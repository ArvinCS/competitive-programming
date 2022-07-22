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

	int m, d, w;
	cin >> m >> d >> w;
	
	int curM = 1, curD = 1;
	while(curM < m){
		for(int x=1;x<=w;x++){
			if(curM > m) break;
			
			cout << curD << " ";
			curD++;
			
			if(curD > d){
				curM++;
				curD = 1;
			}
		}
		cout << "\n";
	}
	
	for(int x=1;x<=d;x++){
		for(int y=x+1;y<=m;y++){
			if(y <= d && ((y-1)*d + x) % w == ((x-1)*d + y) % w){
				cout << x << " " << y << "\n";
			}
		}
	}
    return 0;
}

