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
	
	us t;
	cin >> t;
	
	while(t--){
		us n, x, tmp;
		cin >> n >> x;
		
		us odd = 0;
		for(int i=0;i<n;i++){
			cin >> tmp;
			if(tmp % 2 == 1){
				odd++;
			}
		}
		
		int need = x % 2 == 0;
		if(odd > 0 && n-odd >= max(x-(odd-(odd % 2 == 0)), need)){
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	
    return 0;
}
