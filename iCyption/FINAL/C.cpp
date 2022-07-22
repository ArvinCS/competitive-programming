#include <iostream>

using namespace std;

#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	unsigned long long a,b,n;
	cin >> a >> b >> n;
	
	unsigned long high = n / max(a,b);
	while(high > 0){
		if(n - high * max(a,b) == 0 || (n - high * max(a,b)) % min(a,b) == 0) break;
		high--;
	}
	
	if(high >= 0) n -= high * max(a,b);
	
	unsigned long low = n / min(a,b);
	n -= low * min(a,b);
	
	if(n == 0){
		cout << (a > b ? high : low) << " " << (a < b ? high : low) << "\n";
	} else {
		cout << "Pesan Ulang\n";
	}
    return 0;
}
