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

const int maxN = 1005;
const double eps = 1e-9;

pair<double, double> s[maxN], t[maxN];
int n;

bool isSame(double a, double b){
	if(std::abs(a-b) <= eps){
		return true;
	} else {
		return false;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
		
	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> s[x].first >> s[x].second;
	}
	
	int centerX = 0, centerY = 0;
	for(int x=0;x<n;x++){
		centerX += s[x].first;
		centerY += s[x].second;
		
		s[x].first *= n;
		s[x].second *= n;
	}
	for(int x=0;x<n;x++){
		s[x].first -= centerX;
		s[x].second -= centerY;
	}
	
	for(int x=0;x<n;x++){
		cin >> t[x].first >> t[x].second;
	}
	
	centerX = 0, centerY = 0;
	for(int x=0;x<n;x++){
		centerX += t[x].first;
		centerY += t[x].second;
		
		t[x].first *= n;
		t[x].second *= n;
	}
	for(int x=0;x<n;x++){
		t[x].first -= centerX;
		t[x].second -= centerY;
	}
	
	for(int x=0;x<n;x++){
		if(s[x].first != 0 || s[x].second != 0){
			swap(s[x], s[0]);
		}
	}
	
	bool possible = false;
	for(int i=0;i<n;i++){
		double angle = atan2(t[i].second,t[i].first) - atan2(s[0].second, s[0].first);
		
		bool valid = true;
		for(int x=0;x<n;x++){
			double newX = s[x].first*cos(angle) - s[x].second*sin(angle);
			double newY = s[x].first*sin(angle) + s[x].second*cos(angle);
			
			bool ok = false;
			for(int y=0;y<n;y++){
				if(abs(newX-t[y].first) <= eps && abs(newY-t[y].second) <= eps){
					ok = true;
					break;
				}
			}
			
			if(!ok){
				valid = false;
				break;
			}
		}
		
		if(valid){
			possible = true;
			break;
		}
	}
	
	if(possible) cout << "Yes\n";
	else cout << "No\n";
	
    return 0;
}

