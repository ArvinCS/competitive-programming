#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us n, tmp;
	cin >> n;
	
	us oddCnt = 0, evenCnt = 0;
	us oddIndex = 0, evenIndex = 0;
	
	for(us x=0;x<n;x++){
		cin >> tmp;
		if(tmp % 2 == 1){
			oddIndex = x;
			oddCnt++;
		} else {
			evenIndex = x;
			evenCnt++;
		}
	}
	
	cout << (oddCnt == 1 ? oddIndex : evenIndex) + 1 << "\n";
    return 0;
}
