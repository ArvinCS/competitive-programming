#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

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
		
		sort(data, data+n);
		
		int ans[n];
		int l = n/2 - 1, r = n/2;
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << (x % 2 == 1 ? data[l--] : data[r++]);
		}
		cout << "\n";
	}
	
    return 0;
}

