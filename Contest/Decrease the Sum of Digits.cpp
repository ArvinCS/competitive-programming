#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

us getSum(ull x){
	us sum = 0;
	while(x > 0){
		sum += x%10;
		x /= 10;
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		ll n;
		us s;
		cin >> n >> s;
		
		short l = 0;
		ll tmp = n;
		while(tmp > 0){
			l++;
			tmp /= 10;
		}
		
		ll i = 1;
		tmp = n;
		while(getSum(tmp) > s){
			short digit = (tmp / i) % 10;
			if(digit != 0){
				tmp += (10-digit) * i;
			}
//			cout << tmp << " <- " << getSum(tmp) << "\n";
//				cout << sum << "\n";
			i *= 10;
		}
		cout << tmp - n << "\n";
	}
	
    return 0;
}

