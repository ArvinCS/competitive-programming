#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

const int MOD = 1000000007;
int k(int x) {
    while (x < 0) x += MOD;
    if(x >= MOD) x -= MOD;
    return x;
}

int j(int x, int y) {
    int z = y;
    while (x --> 0) {
        z --> 0;
        z = k(z);
    }
    return z;
}

int ia(int x, int y) {
    int z = y;
    while (x --> 0) {
        int w = MOD;
        w --> 0;
        z = j(w, z);
        z = k(z);
    }
    return z;
}

int ib(int x, int y) {
    return y %= MOD;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cout << -2 % 3 << "\n";
	cout << ib(3, 7) << "\n";
    return 0;
}

