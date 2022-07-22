#include <iostream>
#include <cmath>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int result = (n + m) / 3;
	int smallest = min(n,m);
	
	cout << min(smallest,result) << "\n";
	
    return 0;
}
