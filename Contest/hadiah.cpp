#include <iostream>

using namespace std;

#define ll long long

ll moduloMul(ll a, ll b, ll mod) { 
    ll res = 0; // Initialize result 
    // Update a if it is more than 
    // or equal to mod 
    a %= mod; 
    
    while (b) { 
        // If b is odd, add a with result 
        if (b & 1) 
            res = (res + a) % mod; 

        // Here we assume that doing 2*a 
        // doesn't cause overflow 
        a = (2 * a) % mod; 

        b >>= 1; // b = b / 2 
    } 
    return res; 
} 

ll pangkat(ll a, ll b, ll modulo){
	if(b==0) return 1;
	ll value = pangkat(a,b/2, modulo);
	if(b % 2 == 0) return moduloMul(value, value % modulo, modulo);
	else return moduloMul(a, moduloMul(value, value % modulo, modulo), modulo);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	ll a,b,c,n;
	cin >> a >> b >> c >> n;
	if(c == 0){
		b = 1;
		c = 1;
	}
	if(a > 1){
		for(ll x=1;x<=c;x++){
			a = pangkat(a,b,n);
			if(a <= 1 && b <= 1) break;
		};
	}
	cout << a + 1 << "\n";
    return 0;
}
