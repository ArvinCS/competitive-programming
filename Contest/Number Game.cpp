#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	short t;
	cin >> t;
	
	while(t--){
		long long n;
		cin >> n;
		
		if(n % 2 == 0 || n == 1){
			short turn = -1;
			for(long long x=3;x<n;x+=2){
				if(n % x == 0){
					if((n/x) % 2 == 0 && (n/x) > 2){
						turn = 0;
					} else {
						turn = 1;
					}
					break;
				}
			}
			//cout << n << ": " << turn << "\n";
			if(turn == -1){
				if(n-1 % 2 == 1) turn = 0;
				else turn = 1;	
			}
			
			if(turn == 1 || n == 1){
				cout << "FastestFinger\n";
			} else {
				cout << "Ashishgup\n";
			}
		} else {
			cout << "Ashishgup\n";
		}	
	}
	
    return 0;
}
