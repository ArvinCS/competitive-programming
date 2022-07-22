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
	
	short n;
	cin >> n;
	
	us data[n];
	for(short x=0;x<n;x++) cin >> data[x];
	
	for(short x=n-1;x>=0;x--){
		cout << data[x] << "\n";
	}
	
    return 0;
}

