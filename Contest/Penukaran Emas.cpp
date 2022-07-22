#include <iostream>

using namespace std;

int solve(short n){
	int table[n+1];
	
	for(int x=0;x<=11 && x<=n;x++) table[x] = x;
	for(int x=12;x<=n;x++){
		table[x] = table[x/2] + table[x/3] + table[x/4];
		//cout << x << ": " << table[x] << "\n";
	}	
	
	
	return table[n];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short n;
	cin >> n;
	
	cout << solve(n) << "\n";
	
    return 0;
}
