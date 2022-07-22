#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	if(k == 1){
		cout << "! " << 1 << endl;
		return 0;
	}
	
	int val[n];
	fill(val, val+n, -1);
	
	bool exist[n];
	fill(exist, exist+n, true);
	
	int cnt = n;
	while(cnt > k-1){
		int cnt2 = 0;
		cout << "?";
		for(int x=0;x<n;x++){
			if(exist[x] && cnt2 < k){
				cnt2++;
				cout << " " << x+1;
			}
		}
		cout << endl;
		
		int pos;
		cin >> pos;
		
		pos--;
		exist[pos] = false;
		
		cin >> val[pos];
		cnt--;
	}
	
	int ans = 0;
	
	vector<int> v;
	for(int x=0;x<n;x++){
		if(exist[x]){
			v.push_back(x);
		}
	}
	
	int p1 = -1, p2 = -1;
	for(int x=0;x<n;x++){
		if(!exist[x]){
			if(p1 == -1){
				p1 = x;
			} else if(p2 == -1){
				p2 = x;
				break;
			}
		}
	}
	if(val[p1] > val[p2]) swap(p1, p2);
	
	for(int x=0;x<v.size();x++){
		cout << "?";
		for(int y=0;y<v.size();y++){
			if(x != y){
				cout << " " << v[y]+1;
			}
		}
		cout << " " << p1+1 << " " << p2+1;
		cout << endl;
		
		int pos, val;
		cin >> pos >> val;
		
		pos--;
		if(pos == p2){
			ans++;
		}
	}
	
	cout << "! " << ans+1 << endl;
    return 0;
}

