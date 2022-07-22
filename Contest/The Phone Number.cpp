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
	
	int n;
	cin >> n;
	
	if(n <= 3){
		for(int x=1;x<=n;x++){
			if(x > 1) cout << " ";
			cout << x;
		}
		cout << "\n";
	} else {
		vector<int> ans;
		int square = sqrt(n);
		
		bool firstLine = true;
		for(int x=n-square+1;;x-=square){
			for(int y=0;y<square;y++){
				if(x+y <= 0) continue;
				if(!firstLine) cout << " ";
				cout << x+y;
				firstLine = false;
			}
			if(x <= 0) break;
		}
		cout << "\n";
	}
	
    return 0;
}

