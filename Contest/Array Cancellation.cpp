#include <iostream>

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
		ui n;
		cin >> n;
		
		int data[n];
		for(ui x=0;x<n;x++) cin >> data[x];
		
		ll suffixSum[n+1];
		suffixSum[n] = 0;
		for(int x=n-1;x>=0;x--){
			suffixSum[x] = suffixSum[x+1] + data[x];
		}
		
		ll cost = 0;
		for(int x=0;x<n;x++){
			cost = max(cost, suffixSum[x]);
		}
		
		cout << cost << "\n";
	}
		
    return 0;
}

