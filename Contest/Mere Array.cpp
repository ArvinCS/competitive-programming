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
		
		int data[n], sorted[n], lowest = inf_int;

		for(int x=0;x<n;x++){
			cin >> data[x];
			sorted[x] = data[x];
			lowest = min(lowest, data[x]);
		}
		
		sort(sorted, sorted+n);
		
		bool possible = true;
		for(ui x=0;x<n;x++){
			if(data[x] != sorted[x] && data[x] % lowest != 0){
				possible = false;
			}
		}
		
		if(possible) cout << "YES\n";
		else cout << "NO\n";
	}
	
    return 0;
}

