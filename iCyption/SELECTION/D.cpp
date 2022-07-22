#include <iostream>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short r, x, y, z;
	cin >> r >> x >> y >> z;
	
	long long ans = 0;
	short a = 0, b = 0, c = 0;
	
	while(cin >> a >> b >> c){
		if(pow(abs(a-x), 2) + pow(abs(b-y), 2) + pow(abs(c-z), 2) <= r*r){
			ans++;
		}
	}
	
	cout << ans << "\n";
    return 0;
}
