#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n,m,x,y;
	cin >> n >> m >> x >> y;
	if(x > ceil(n/2)){
		x -= n + 1;
	}
	if(y > ceil(m/2)){
		y -= m + 1;
	}
	if(y >= x) cout << abs(x);
	else cout << abs(y);
}
