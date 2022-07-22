#include <iostream>
#include <cmath>

using namespace std;

#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int x1,y1,r1;
	cin >> x1 >> y1 >> r1;
	
	int x2,y2,r2;
	cin >> x2 >> y2 >> r2;
	
	if(pow(x1-x2, 2) + pow(y1-y2,2) >= pow(r1-r2, 2) && pow(x1-x2, 2) + pow(y1-y2,2) <= pow(r1+r2, 2)){
		cout << "bersentuhan\n";
	} else {
		cout << "tidak bersentuhan\n";
	}
    return 0;
}
