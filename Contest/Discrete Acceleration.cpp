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
	
	us t;
	cin >> t;
	
	while(t--){
		int n, l;
		cin >> n >> l;
		
		vector<int> flags;
		for(int x=0;x<n;x++){
			int tmp;
			cin >> tmp;
			
			flags.push_back(tmp);
		}
		
		int a = 0, b = l, speedA = 1, speedB = 1, flagA = 0, flagB = n-1;
		double ans = 0, inc = 1;
		while(a < b){
			if(a+speedA >= max(b-speedB, 0)){
				double distance = b-a, totalSpeed = speedA + speedB;
				cout << a << " - " << b << "(" << totalSpeed << ")" << "\n";
				ans += distance/totalSpeed;
				break;	
			}
//			cout << a << " - " << b << "(" << ans << ")" << "\n";
			a += speedA;
			b -= speedB;
			if(flagA < n){
				while(flags[flagA] <= a){
					speedA++;
					flagA++;	
				}
			}
			if(flagB >= 0 && flags[flagB] >= b){
				while(flags[flagB] >= b){
					speedB++;
					flagB--;	
				}
			}
			ans += inc;
		}
		
		cout << fixed << setprecision(15) << ans << "\n";
	}
	
    return 0;
}

