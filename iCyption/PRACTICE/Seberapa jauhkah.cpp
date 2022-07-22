#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	
	int ans = x2-x1 + y2-y1;
	cout << ans << "\n";
    return 0;
}
