#include <iostream>
#include <cmath>
using namespace std;

long long friendship(long long n){
	return (n) * (n-1)/2;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	long long n, m;
	cin >> n >> m;
	
	long long temp = n%m;
	long long min = friendship(n/m) * (m-(temp)) + friendship((n/m) + 1) * temp;
	long long max = friendship(n-m+1);
	
	cout << min << " " << max << "\n";
    return 0;
}
