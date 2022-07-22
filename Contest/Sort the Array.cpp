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
	
	int n;
	cin >> n;
	
	unsigned int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	unsigned int decreaseSeg = (n <= 2), leftIndex = 0, rightIndex = n-1;
	bool decrease = false;
	for(int x=0;x<n-1;x++){
		if(data[x] > data[x+1]){
			decrease = true;
			rightIndex = x+1;
		} else if(decrease) {
			decreaseSeg++;
			decrease = false;
			leftIndex = x-1;
			cout << x << "\n";
		}
		if(decreaseSeg>1) break;
	}
	if(decrease) decreaseSeg++;
	if(decreaseSeg == 1){
		cout << "yes\n";
		cout << leftIndex+1 << " " << rightIndex+1 << "\n";
	} else {
		cout << "no\n";
	}
    return 0;
}
