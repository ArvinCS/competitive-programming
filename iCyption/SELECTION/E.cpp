#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	float n;
	cin >> n;
	
	if(n == 0){
		cout << "-1\n";
	} else {
		float cons = 4.0;
		float side = ceil((n - cons) / 4);
		if(side >= 1){
			float ans = side*2 + (n - side*4);
			cout << std::fixed << std::setprecision(0) << ans << "\n";
		} else {
			cout << "-1\n";
		}
	}
	
    return 0;
}
