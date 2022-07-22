#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

ll solve(int n){
	if(n == 1) return 1;
	return 1 + solve((n+1)/2) + solve(n/2);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n;
	cin >> n;
	
	cout << solve(n) << "\n";
    return 0;
}

