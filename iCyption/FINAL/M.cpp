#include <iostream>

using namespace std;

#define inf_int 1e9
#define inf_ll 1e18

void config

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string asli,acak;
	int n;
	cin >> asli >> acak >> n;
	
	if(config(asli,acak,n)){
		cout << "BISA\n";
	} else {
		cout << "TIDAK\n";
	}
    return 0;
}
