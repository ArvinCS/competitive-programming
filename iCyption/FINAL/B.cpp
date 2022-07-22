#include <iostream>

using namespace std;

#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	unsigned long long s, h, c, bungkus = 0;
	cin >> s >> h >> c;
	
	unsigned long long ans = 0;
	
	while(s >= h || bungkus >= c){
		unsigned long long tmp = s/h;
		s -= tmp * h;
		bungkus += tmp;
		unsigned long long bonus = bungkus/c;
		ans += tmp + bonus;
//		cout << "+ " << bonus << " - " << bungkus%c << "\n";
		bungkus %= c;
		bungkus += bonus;
//		cout << tmp << " " << bonus << "\n";
	}
	
	cout << ans << "\n";
    return 0;
}
