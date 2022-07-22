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

	int n;
	cin >> n;
	
	int data[2*n];
	for(int x=0;x<2*n;x++){
		cin >> data[x];
	}
	
	bool sorted = true;
	for(int x=0;x<2*n;x++){
		if(data[x] != x+1){
			sorted = false;
			break;
		}
	}
	
	if(sorted){
		cout << "0\n";
		return 0;
	} else {
		int ans = inf_int;
		int bef[2*n];
		for(int x=0;x<2*n;x++) bef[x] = data[x];
		for(int x=1;x<=2*n;x++){
			for(int y=0;y<n;y++){
				swap(data[y], data[n+y]);
			}
			bool sorted = true;
			for(int y=0;y<2*n;y++){
				if(data[y] != y+1){
					sorted = false;
					break;
				}
			}
			
			if(sorted){
				ans = min(ans, 2*(x-1) + 1);
				break;
			}
			
			for(int y=0;y<2*n;y+=2){
				swap(data[y], data[y+1]);
			}
			
			sorted = true;
			for(int y=0;y<2*n;y++){
				if(data[y] != y+1){
					sorted = false;
					break;
				}
			}
			
			if(sorted){
				ans = min(ans, 2*x);
				break;
			}
		}
		for(int x=0;x<2*n;x++) data[x] = bef[x];

		for(int x=1;x<=2*n;x++){
			for(int x=0;x<2*n;x+=2){
				swap(data[x], data[x+1]);
			}
			
			bool sorted = true;
			for(int y=0;y<2*n;y++){
				if(data[y] != y+1){
					sorted = false;
					break;
				}
			}
			
			if(sorted){
				ans = min(ans, 2*(x-1) + 1);
				break;
			}
			
			for(int y=0;y<n;y++){
				swap(data[y], data[n+y]);
			}
			
			sorted = true;
			for(int y=0;y<2*n;y++){
				if(data[y] != y+1){
					sorted = false;
					break;
				}
			}
			
			if(sorted){
				ans = min(ans, 2*x);
				break;
			}
		}
		
		if(ans != inf_int) cout << ans << "\n";
		else cout << "-1\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

