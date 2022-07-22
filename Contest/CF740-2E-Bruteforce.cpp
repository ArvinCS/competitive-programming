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
	
	int a[n], b[n];
	for(int x=0;x<n;x++){
		a[x] = x+1;
		b[x] = a[x];
	}
	
	for(int x=0;x<n;x+=2){
		for(int y=0;y<n;y+=2){
			for(int z=0;z<=x/2;z++){
				swap(b[z], b[x-z]);
			}
			for(int z=0;z<=y/2;z++){
				swap(b[z], b[y-z]);
			}
			
			for(int z=0;z<n;z++){
				cout << b[z] << " ";
			}
			cout << "\n";
			
			for(int z=0;z<n;z++) b[z] = a[z];
		}
	}

    return 0;
}

