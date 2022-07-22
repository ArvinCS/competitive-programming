#include <iostream>

using namespace std;

#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	while(n--){
		short x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		
		
		// garis kiri
		if(max(x3,x4) >= min(x1,x2) && min(x3,x4) <= min(x1,x2) && max(y3,y4) >= min(y1,y2)){
			cout << "YA\n";
		} else if(max(x3, x4) >= max(x1,x2) && min(x3,x4) <= max(x1,x2) && min(y3,y4) >= max(y1,y2)){ // garis kanan
			cout << "YA\n";
		} else if(min(y3,y4) <= min(y1,y2) && max(y3,y4) >= min(y1,y2) && max(x3,x4) >= min(x1,x2)){ // garis bawah
			cout << "YA\n";
		} else if(min(y3,y4) <= max(y1,y2) && max(y3,y4) >= max(y1,y2) && min(x3,x4) <= max(x1,x2)){ // garis atas
			cout << "YA\n";
		} else {
			cout << "TIDAK\n";
		}
	}
    return 0;
}
