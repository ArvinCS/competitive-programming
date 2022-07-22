#include <bits/stdc++.h>

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
	
	int h, w, a, b;
	cin >> h >> w >> a >> b;
		
	for(us x=0;x<h;x++){
		for(us y=0;y<w;y++){
			if((x < b && y >= a) || (x >= b && y < a)) cout << 1;
			else cout << 0;
		}
		cout << "\n";
	}

    return 0;
}

