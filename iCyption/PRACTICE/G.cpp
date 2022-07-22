#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
	if(a == 0) return b;
	return gcd(b % a, a);
}

long long lcm(long long a, long long b){
	return (a*b)/gcd(a,b);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	long long m,p;
	cin >> m >> p;
	
	cout << lcm(m,p) << "\n";
    return 0;
}
