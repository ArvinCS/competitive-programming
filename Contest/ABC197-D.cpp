#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

#define PI 3.14159265

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	double angle = 360.0/n;
	double centerX = (a+c)/2.0, centerY = (b+d)/2.0;
	
	double x = cos(angle*PI/180.0) * (a-centerX) - sin(angle*PI/180.0) * (b-centerY);
	double y = sin(angle*PI/180.0) * (a-centerX) + cos(angle*PI/180.0) * (b-centerY);
	x += centerX;
	y += centerY;
	
	cout << fixed << setprecision(7) << x << " " << y << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

