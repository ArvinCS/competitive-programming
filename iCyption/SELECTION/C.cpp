#include <iostream>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	float n, x, y, z;
	cin >> n >> x >> y >> z;
	
	float miring = (n-1) * sqrt(pow(x,2) + pow(y,2));
 	float total = (2 * miring) + x;
	float tolerance = pow(10, -4);
	
	if(total <= z || abs(z-total) < tolerance){
		cout << "Bisa\n";
	} else {
		cout << "Tidak Bisa\n";
	}
    return 0;
}
