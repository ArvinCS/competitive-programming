#include <iostream>

using namespace std;

#define ll long long

int gcd(ll a, ll b){
	if(a == 0) return b;
	return gcd(b%a,a);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll comps[n];
		for(int x=0;x<n;x++){
			cin >> comps[x];
		}
		
		int colors[n] = { 0 };
		
		int color = 0;
		bool repeat = true;
		for(int r=0;r<n-1 && repeat;r++){
			for(int x=r;x<n;x++){
				if(colors[x] != 0) continue;
				color++;
				colors[x] = color;
				for(int y=x+1;y<n;y++){
					if(colors[y] == 0 && gcd(comps[x], comps[y]) > 1){
						bool valid = true;
						for(int c=0;c<y;c++){
							if(colors[c] == colors[x]){
								if(gcd(comps[c], comps[y]) == 1) {
									valid = false;
									break;
								}
							}
						}
						if(valid){
							colors[y] = color;
						}
					}
				}
			}
			if(color > 11){
				color = 0;
				fill_n(colors, colors+n
				
				\, 0);
			} else {
				repeat = false;
			}
		}
		
		cout << color << "\n";
		for(int x=0;x<n;x++){
			cout << colors[x];
			if(x != n-1) cout << " ";
		}
		cout << "\n";
	}
    return 0;
}
