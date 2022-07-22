#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short n,m;
	cin >> n >> m;
	
	short rasyid[n], rahman[m];
	for(int x=0;x<n;x++) cin >> rasyid[x];
	for(int x=0;x<m;x++) cin >> rahman[x];
	
	
    return 0;
}
