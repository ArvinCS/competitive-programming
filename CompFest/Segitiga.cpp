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
	
	int a, b, c;
	cin >> a >> b >> c;
	
	if(a + b > c && a + c > b && b + c > a){
		cout << "segitiga\n";
	} else {
		cout << "bukan segitiga\n";
	}
    return 0;
}

