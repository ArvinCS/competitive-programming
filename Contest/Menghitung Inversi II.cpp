#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

ull solve(ui data[], ui l, ui r){
	if(r-l > 1){
		ui mid = l + (r-l)/2;
		ull ans = solve(data, l, mid) + solve(data, mid+1, r);
		
		
	} else {
		return data[l] > data[r];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui n;
	cin >> n;
	
	ui data[n];
	for(ui x=0;x<n;x++) cin >> data[x];
	
	cout << solve(data, 0, n-1) << "\n";
    return 0;
}

