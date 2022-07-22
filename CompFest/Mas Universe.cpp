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
	
	int n, tmp, ans = 0;
	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> tmp;
		ans = (tmp > ans ? tmp : ans);
	}
	
	cout << ans << "\n";
    return 0;
}

