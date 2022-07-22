#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool ask(int x){
	cout << "MOVE " << x << endl;
	
	string ans;
	cin >> ans;
	
	return (ans == "YES");
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int pos = 0;
	int left = 0, right = n-1, ans = 0;
	while(left <= right){
		int mid = (left+right) >> 1;
		
		int dist = (n+mid-pos)%n;
		bool res = ask(dist);
		pos = mid;
		if(res){
			ans = max(ans, mid);
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	
	int dist = (n+ans-pos) % n;
	ask(dist);
	
	cout << "DONE" << endl;
    return 0;
}

