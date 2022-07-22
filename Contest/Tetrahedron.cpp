#include <iostream>

using namespace std;

long long n;

long long solve(){
	long long table[2][4];
	
	for(char x = 0;x<=3;x++){
		table[0][x] = 0;
		if(x != 0) table[1][x] = 1;
		else table[1][x] = 0;
	}
	
	for(long long x=2;x<=n;x++){
		int previous = x % 2 == 1 ? 0 : 1;
		table[x%2][0] = ((table[previous][1] + table[previous][2]) % 1000000007 + table[previous][3]) % 1000000007;
		table[x%2][1] = ((table[previous][0] + table[previous][2]) % 1000000007 + table[previous][3]) % 1000000007;
		table[x%2][2] = ((table[previous][0] + table[previous][1]) % 1000000007 + table[previous][3]) % 1000000007;
		table[x%2][3] = ((table[previous][0] + table[previous][1]) % 1000000007 + table[previous][2]) % 1000000007;
	}
	
	return table[n%2][0];
}


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	
	cout << solve() << "\n";	
	
    return 0;
}
