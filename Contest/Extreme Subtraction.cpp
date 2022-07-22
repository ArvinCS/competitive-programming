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
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int data[n];
		for(int x=0;x<n;x++) cin >> data[x];
		
		int left = 0, right = 0;
		bool valid = true;
		for(int x=1;x<n;x++){
			if(data[x] - data[x-1] > 0) left += data[x] - data[x-1];
			if(data[x] < left){
				valid = false;
				break;
			}
		}
		
		for(int x=n-2;x>=0;x--){
			if(data[x] - data[x+1] > 0) right += data[x] - data[x+1];
			if(data[x] < right){
				valid = false;
				break;
			}
		}
		
		if(valid) cout << "YES\n";
		else cout << "NO\n";
	}
	
    return 0;
}

