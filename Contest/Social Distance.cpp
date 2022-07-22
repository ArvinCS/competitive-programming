#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		long long n, k;
		string s;
		cin >> n >> k >> s;
		
		long long ans = 0;
		for(long long x=0;x<n;){
			long long i = x+1;
			for(;i<n && s[i] != '1';i++);
			
			long long left = (s[x] == '1' ? k : 0), right = (i<n && s[i] == '1' ? k : 0), length = i-x;
			
			if(left==k){
				length--;
			}
			
			length -= left+right;
			
			if(length > 0){
				ans += (length + k)/(k+1);
			}
			
			x = i;
			//cout << "last i: " << i << "\n";
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}
