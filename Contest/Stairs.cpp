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
		ull n;
		cin >> n;
		
		ull need = 1, ans = 0, block = 1;
		
		while(n >= need){
//			cout << ans << "\n";
			n -= need;
			ans++;
			need += 4*block + need;
			block *= 4;
//			cout << "next need: " << need << "\n";
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

