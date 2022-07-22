#include <iostream>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short n;
	string s, ans;
	cin >> n >> s;
	
	ans.push_back(s[0]);
	for(short x=1;x<n;x++){
		if(s[x] != s[x-1]){
			ans.push_back(s[x]);
		}
		
	}
	
	cout << ans << "\n";
    return 0;
}
