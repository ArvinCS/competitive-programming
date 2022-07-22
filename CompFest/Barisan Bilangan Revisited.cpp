#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

ull gcd(ull a, ull b){
	if(a == 0) return b;
	return gcd(b % a, a);
}

ull lcm(ull a, ull b){
	return (a*b)/gcd(a,b);
}

ull count(ull n, ull a, ull b){
	return n/a + n/b - n/lcm(a,b);	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ull n, a, b;
	cin >> n >> a >> b;
	
	ull left = 1, right = 10e18, ans;

	while(left < right){
		ull mid = left + (right-left)/2;
		ull cnt = count(mid, a, b);
		
		if(cnt == n){
			ans = mid;
		}
		
		if(cnt < n){
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	
	cout << ans << "\n";
	
    return 0;
}

