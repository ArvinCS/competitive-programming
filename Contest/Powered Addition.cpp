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
		
		int maxDiff = 0;
		for(int x=1;x<n;x++){
			if(data[x] < data[x-1]){
				int log = log2(data[x-1] - data[x]);
				maxDiff = max(maxDiff, log) + 1;
			}
		}
		
		cout << maxDiff << "\n";
	}
	
    return 0;
}

