#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

ll g(int x){
	int ans = 0;
	for(int i=1;i*i<=x;i++){
		if(x % i == 0){
			ans += 1 + (x / i != i);
		}
	}
	return ans;
}

ll h(int x){
	if(x == 1) return 1;
	return g(x)	+ h(x-1);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int x;
	cin >> x;
	
	cout << h(x) << "\n";
	
    return 0;
}

