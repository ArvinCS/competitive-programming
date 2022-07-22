#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	int nxt[n], prv[n];
	for(int x=0;x<n;x++) nxt[x] = prv[x] = x;
	
	for(int i=1;i<=q;i++){
		int t;
		cin >> t;
		
		if(t == 1){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			
			nxt[a] = b;
			prv[b] = a;			
		} else if(t == 2){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			nxt[a] = a;
			prv[b] = b;
		} else {
			int a;
			cin >> a;
			
			a--;
			
			while(prv[a] != a){
				a = prv[a];
			}
			
			vector<int> v;
			while(nxt[a] != a){
				v.push_back(a);
				a = nxt[a];
			}
			v.push_back(a);
			
			cout << v.size();
			for(int x=0;x<v.size();x++){
				cout << " " << v[x]+1;
			}
			cout << "\n";
		}
	}
	
    return 0;
}

