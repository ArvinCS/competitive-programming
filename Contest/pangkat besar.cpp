#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

long long pangkat(unsigned long long a, unsigned long long b){
	if(b==0) return 1;
	long long value = pangkat(a,b/2) % 1000000;
	if(b % 2 == 0) return (value * value) % 1000000;
	else return ((a % 1000000) * value * value) % 1000000;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	unsigned long long a, b;
	cin >> a >> b;
	long long result = pangkat(a, b);
	int limit = 0;
	if(a != 1 && a <= 999999){
		for(int x=2;x<21;x++){
			if(pow(a,x) > 999999){
				limit = x;
				break;
			}
		}
	}
	if(a != 1 && b >= limit) cout << setfill('0') << setw(6) << result << "\n";
	else cout << result << "\n";
    return 0;
}
