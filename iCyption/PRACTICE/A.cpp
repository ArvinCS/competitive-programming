#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	
	long long ans = abs(x1-x2) + abs(y1-y2);
	cout << ans << "\n";
    return 0;
}
