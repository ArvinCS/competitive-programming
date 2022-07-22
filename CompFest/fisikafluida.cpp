#include <iostream>
#include <cmath>

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
	while(n--){
		us h;
		cin >> h;
		
		cout << "h: " << h << " -> " << sqrt(2.0*9.8*h) << "\n";	
	}
	
    return 0;
}

