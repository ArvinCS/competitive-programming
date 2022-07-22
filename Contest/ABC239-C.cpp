#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	
	for(int x=-2;x<=2;x++){
		for(int y=-2;y<=2;y++){
			ll newXA = a+x, newYB = b+y;
			ll newXC = c+x, newYD = d+y;
			
			if((newXA-a)*(newXA-a)+(newYB-b)*(newYB-b) == 5 && (newXA-c)*(newXA-c)+(newYB-d)*(newYB-d) == 5){
				cout << "Yes\n";
				return 0;
			}
			if((newXC-a)*(newXC-a)+(newYD-b)*(newYD-b) == 5 && (newXC-c)*(newXC-c)+(newYD-d)*(newYD-d) == 5){
				cout << "Yes\n";
				return 0;
			}
		}
	}
	
	cout << "No\n";
    return 0;
}

