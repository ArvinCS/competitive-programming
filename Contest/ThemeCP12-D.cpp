#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	while(true){
		string s;
		cin >> s;
		
		assert(s != "mistake");
		if(s == "end") break;
		
		cout << "? " << 0 << " " << 1 << endl;
		char res;
		cin >> res;
		
		if(res == 'x'){
			cout << "! " << 1 << endl;
			continue;
		}
		
		int cur = 1;
		while(true){
			cout << "? " << cur << " " << 2*cur << endl;
			
			char res;
			cin >> res;
			
			if(res == 'y'){
				cur *= 2;
			} else {
				break;
			}
		}
		
		int ans = cur;
		int left = cur+1, right = cur*2;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			cout << "? " << cur << " " << mid << endl;
			
			char res;
			cin >> res;
			
			if(res == 'y'){
				left = mid+1;
			} else {
				ans = mid;
				right = mid-1;
			}
		}
		
		cout << "! " << ans << endl;
	}
	
    return 0;
}

