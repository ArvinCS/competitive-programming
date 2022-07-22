#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int s, t, x;
	cin >> s >> t >> x;
	
	if(s > t) t += 24;
	if(s <= x && x < t){
		cout << "Yes\n";
	} else if(s <= (x+24) && (x+24) < t){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	
    return 0;
}

