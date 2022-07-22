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
		int a,b,x,y,n;
		cin >> a >> b >> x >> y >> n;
		
		int minA = max(a-n, x), minB = max(b-n, y);
		if(max(a-max(n-b+minB, 0), x) * 1ll * minB > max(b-max(n-a+minA, 0), y) * 1ll * minA){
			cout << max(b-max(n-a+minA, 0), y) * 1ll * minA << "\n";
		} else {
			cout << max(a-max(n-b+minB, 0), x) * 1ll * minB << "\n";
		}
	}
	
    return 0;
}

