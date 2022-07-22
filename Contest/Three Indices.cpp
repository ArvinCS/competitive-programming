#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

us data[1001];
us i, j, k;

void solve(us n){
	for(int x=0;x<n-2;x++){
		if(data[x] < data[x+1] && data[x+1] > data[x+2]){
			cout << "YES\n";
			cout << x+1 << " " << x+2 << " " << x+3 << "\n";
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		us n;
		cin >> n;
		
		for(us x=0;x<n;x++) cin >> data[x];
		
		solve(n);
	}
	
    return 0;
}
