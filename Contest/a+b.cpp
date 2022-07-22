#include <iostream>

using namespace std;

int mod(string num, int a) 
{ 
    // Initialize result 
    int res = 0; 
  
    // One by one process all digits of 'num' 
    for (int i = 0; i < num.length(); i++) 
         res = (res*10 + (int)num[i] - '0') %a; 
  
    return res; 
} 

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string a,b;
	cin >> a >> b;
	
	long long ans = mod(a, 1009) + mod(b, 1009);
	cout << ans % 1009 << "\n";
    return 0;
}
