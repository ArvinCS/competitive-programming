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
		ll a, b;
		cin >> a >> b;
		
		ull ans = 0;
		
		if(a > 0 && b > 0){
			while(a > 0){
				if(b > a && b > 1) b--;
				else a--;
				ans++;
			}
			
			cout << ans << "\n";
		} else if(a == 0 || b == 0){
			cout << "1\n";
		}
	}
    return 0;
}

