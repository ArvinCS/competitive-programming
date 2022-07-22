#include <bits/stdc++.h>



using namespace std;



#define ll long long



int main(){

	ios_base::sync_with_stdio(0);

	cin.tie(0); cout.tie(0);

	

	int n;

	cin >> n;

	

	int a[n];

	for(int x=0;x<n;x++){

		cin >> a[x];

	}

	

	ll ans = 0;

	for(int l=0;l<n;l++){

		set<pair<int, int>> st;

		for(int r=l;r<n;r++){

			st.insert({a[r], r-l});

			

			int mx = -1;

			int cnt = 0;

			for(auto p : st){

				if(mx < cnt){

					ans++;

				}

				

				cnt++;

				mx = max(mx, p.second);

			}

		}

	}

	

	cout << ans << "\n";

	return 0;

}


