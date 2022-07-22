#include <iostream>
#include <numeric>

using namespace std;

int gcd(int a, int b){
	if(a == 0) return b;
	return gcd(b%a, a);	
}

int lcm(int a, int b){
	int temp = gcd(a,b);
	return (a * b) / temp;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	int numbers[n];
	for(int i=0;i<n;i++){
		cin >> numbers[i];
	} 
	
	int result = lcm(numbers[0], numbers[1]); 
	for(int x=2;x<n;x+=2){
		if(x+1>=n){
			result = lcm(result,numbers[x]);
		} else {
			result = lcm(result, lcm(numbers[x], numbers[x+1]));
		}
	}
	
	cout << result << "\n";
	
    return 0;
}
