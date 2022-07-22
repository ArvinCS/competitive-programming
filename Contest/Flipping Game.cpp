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
	
	int data[n], ones = 0;
	for(us x=0;x<n;x++){
		cin >> data[x];
		if(data[x] == 1){
			data[x] = -1;
			ones++;
		}
		else data[x] = 1;
	}
	
	if(ones < n){
		int ans = 0, cnt = 0;
		for(us x=0;x<n;x++){
			cnt = max(0, cnt + data[x]);
			ans = max(ans, cnt);
		}
		cout << ans + ones << "\n";
	} else {
		cout << n-1 << "\n";
	}
    return 0;
}
