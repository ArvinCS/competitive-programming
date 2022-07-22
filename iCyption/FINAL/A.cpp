#include <iostream>

using namespace std;

#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int d1, m1, y1;
	cin >> d1 >> m1 >> y1;
	
	int d2, m2, y2;
	cin >> d2 >> m2 >> y2;
	
	
	cout << abs( ((((y1 * 12) + m1) * 30) + d1) - ((((y2 * 12) + m2) * 30) + d2) )<< "\n";
    return 0;
}
