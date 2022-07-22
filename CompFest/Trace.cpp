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
	
	us n;
	cin >> n;
	
	ui tmp, ans = 0;
	for(us x=0;x<n;x++){
		for(us y=0;y<n;y++){
			cin >> tmp;
			if(x == y) ans += tmp;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

