#include <iostream>

using namespace std;

int price;

long long solve(short a, short d){
	if(a == 0 && d == 0) return 0;
	
	long long best = 100000000;
	if(a > 0) best = min(best, solve(a-1,d) + price/2);
	if(d > 0) best = min(best, solve(a,d-1) + price);
	if(a + d >= 3){
		short total = min(4, a+d);
		for(int x=0;x<=total;x++){
			if(d-(total-x) >= 0 && a-x >= 0) best = min(best, solve(a-x,d-(total-x)) + 2*price);
		}
	}
	return best;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short a, d;
	cin >> price >> a >> d;
	
	cout << solve(a,d) << "\n";
    return 0;
}
