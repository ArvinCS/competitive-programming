#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
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
		unsigned int x, y, z;
		cin >> x >> y >> z;
		
		if(x == y && y >= z){
			cout << "YES\n";
			cout << x << " " << z << " " << z << "\n";
		} else if(x == z && z >= y){
			cout << "YES\n";
			cout << y << " " << x << " " << y << "\n";
		} else if(y == z && y >= x){
			cout << "YES\n";
			cout << x << " " << x << " " << y << "\n";	
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}
