#include <bits/stdc++.h>

using namespace std;

#define ll long long



int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	array<ll, 2> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x][0];
	}
	for(int x=0;x<n;x++){
		cin >> p[x][1];
	}
	
	pair<ll, ll> l = {0, 1}, r = {1e9, 1};
	for(int x=0;x+1<n;x++){
		bool bx = (p[x][0] > p[x+1][0]);
		bool by = (p[x][1] > p[x+1][1]);
		
		if(!bx && !by){
			cout << "NO\n";
			return 0;
		}
		if(bx&&by) continue;
		
		pair<ll, ll> cur = {p[x+1][1] - p[x][1], p[x][0] - p[x+1][0]};
		
		if(bx){
			if(l.first*cur.second < cur.first*l.second){
				l = cur;
			}
		} else if(by){
			cur.first *= -1; cur.second *= -1;
			if(r.first*cur.second > cur.first*r.second){
				r = cur;
			}
		}
	}
	
	if(l.first*r.second < r.first*l.second){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
    return 0;
}

