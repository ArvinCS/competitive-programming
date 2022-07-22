#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		if(n == 1 && a[0] == 0){
			cout << "YES\n";
			continue;
		}
		
		bool valid = false;
		set<int> st;
		for(int x=0;x<n;x++){
			for(int y=x+1;y<n;y++){
				int dif = abs(a[y]-a[x]);
				
				if(dif == 0 || st.count(dif)) valid = true;
				st.insert(dif);
			}
		}
		
		for(int x=0;x<n;x++){
			st.clear();
			for(int y=0;y<n;y++){
				int dif = abs(a[y]-a[x]);
				
				if(st.count(a[x]+dif) || st.count(a[x]-dif)){
					cout << x << " " << y << " " << dif << "\n";
					valid = true;
				}
				st.insert(a[x]+dif);
				st.insert(a[x]-dif);
			}
		}
		cout << (valid ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

