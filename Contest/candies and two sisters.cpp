#include <iostream>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	for(int c=0;c<t;c++){
		int n;
		cin >> n;
		
		double temp;
		int ways = 0;
		if(modf(n/2.0, &temp) == 0 ){
			ways = (n/2) - 1;
		} else {
			ways = n/2;
		}
		cout << ways << "\n";
	}
    return 0;
}
