#include <iostream>
#include <cmath>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int i;
	cin >> i;
	
	while(i--){
		int h,c,t;
		cin >> h >> c >> t;
		
		int a = (h+c)/2;
		double previous = h;
		
		if(previous == t){
			cout << "1\n";
			continue;	
		}
		
		bool find = t > a;
		int ans = find ? 1 : 2;
		while(find){
			double temp = (previous + a)/2;
			if(abs(temp-t) < abs(previous-t)){
				previous = temp;
				ans += 2;
			} else {
				break;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}
