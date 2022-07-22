#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us q;
	cin >> q;
	
	int left = 0, right = 1001;
	while(q--){
		int mid = left + (right-left)/2;
		cout << mid << endl;
		
		string tmp;
		cin >> tmp;
		if(tmp == "BENAR") break;
		cin >> tmp;
		if(tmp.compare("KECIL")){
			left = mid;
		} else if(tmp.compare("BESAR")){
			right = mid;
		}
	}
	
    return 0;
}

