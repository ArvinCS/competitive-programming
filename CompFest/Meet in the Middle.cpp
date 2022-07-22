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

	us n;
	cin >> n;
	
	us data[n];
	for(us x=0;x<n;x++) cin >> data[x];
	
	bool first = true;
	for(us x=0;x<(n+1)/2;x++){
		if(!first) cout << " ";

		if(n % 2 == 1 && x == n/2) cout << data[x];
		else cout << data[x] << " " << data[n-x-1];
		
		first = false;
	}
	cout << "\n";
	
    return 0;
}

