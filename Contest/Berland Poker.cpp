#include <iostream>
#include <cmath>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int n, m, k;
		
		cin >> n >> m >> k;
		
		if(m == 0){
			cout << "0\n";
			continue;
		}
		
		int a1 = min(m,n/k);
		int a2 = (m - a1 + k - 2) / (k-1); // ceil => (x + y - 1) / y
		cout << a1 - a2 << "\n";
	}
    return 0;
}
