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
	
	string tmp;
	cin >> tmp;
	
	us n, k;
	cin >> n >> k;
	
	short left = 1, right = n;
	while(left < right){
		short mid = left + (right-left)/2;
		
		cout << "TIMBANG " << mid-left+1;
		for(us x=left;x<=mid;x++) cout << " " << x;
		
		cout << " " << right-mid;
		for(us x=mid+1;x<=right;x++) cout << " " << x;
		cout << endl;
		
		string res;
		cin >> res;
		if(res == "KIRI"){
			right = mid;
		} else if(res == "KANAN"){
			left = mid+1;
		}
	}
	
	cout << "AMBIL " << left << endl;
    return 0;
}

