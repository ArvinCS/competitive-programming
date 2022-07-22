#include <bits/stdc++.h>

using namespace std;

#define ll long long

int ask(int i, int j){
	cout << "? " << i << " " << j << endl;
	
	int res;
	cin >> res;
	
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a = ask(1, 2);
	int b = ask(1, 3);
	int c = ask(2, 3);
	
	int sum = (a+b+c)/2;
	
	int ans[n];
	ans[0] = (a+b-sum);
	ans[1] = (a-ans[0]);
	ans[2] = (b-ans[0]);
	
	for(int x=3;x<n;x++){
		ans[x] = ask(1, x+1)-ans[0];
	}
	
	cout << "!";
	for(int x=0;x<n;x++){
		cout << " " << ans[x];
	}
	cout << endl;
    return 0;
}

