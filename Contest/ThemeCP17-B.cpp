#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	int n = s.length();
	int sum = 0;
	for(int x=0;x<n;x++){
		if(s[x] == 'b') sum++;
	}
	
	int a = 0, b = 0;
	
	int ans = min(sum, n-sum);
	int cur = 0;
	for(int x=n-1;x>=0;x--){
		if(s[x] == 'a'){
			a++;
		} else {
			b++;
		}
		
		ans = min(ans, a+cur+(sum-b));
		cur = min(cur, b-a);
	}
	
	cout << n-ans << "\n";
    return 0;
}

