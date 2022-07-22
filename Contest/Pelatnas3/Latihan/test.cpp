#include <bits/stdc++.h>



using namespace std;



#define ll long long



const ll mod = 1e9 + 7;



void chadd(ll &a, ll b){

	a += b;

	if(a >= mod) a -= mod;

	if(a < 0) a += mod;

}



int main(){

	ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

	

	int n, m;

	cin >> n >> m;

	

	int l[m], r[m], w[m];

	vector<array<int, 2>> v[n+1];

	for(int x=0;x<m;x++){

		cin >> l[x] >> r[x] >> w[x];

		

		l[x]--; r[x]--;

		

		v[l[x]].push_back({0, x});

		v[r[x]+1].push_back({1, x});

	}

	

	ll table[n+1][n+1][n+1];

	fill(*table[0], *table[n+1], 0);

	

	table[0][0][0] = 1;

	for(int x=0;x<n;x++){

		for(int l1=0;l1<=x;l1++){

			for(int l2=l1;l2<=x;l2++){

				if(l1 == l2 && l1 != 0) continue;

				

				int l3 = (max(l1, l2) != x ? x : 0);

				

				bool valid = true;

				for(int y=0;y<m;y++){

					if(l[y] <= x && x <= r[y]){

						int cnt = 1;

						if(l[y] <= l1-1){

							cnt++;

						}

						if(l[y] <= l2-1){

							cnt++;

						}

						

						if(x == r[y] && cnt != w[y]){

							valid = false;

							break;

						}
					}

				}

				

				if(valid){

					chadd(table[x+1][l1][l2], (x == 0 ? 3 : 1) * table[x][l1][l2] % mod);

				}

				

				valid = true;

				for(int y=0;y<m;y++){

					if(l[y] <= x && x <= r[y]){

						int cnt = 1;

						if(l[y] <= l1-1){

							cnt++;

						}

						if(l[y] <= l3-1){

							cnt++;

						}

						

						if(x == r[y] && cnt != w[y]){

							valid = false;

							break;

						}
					}

				}

				

				if(valid && l3 != 0){

					chadd(table[x+1][l1][x], (1+(l2 == 0)) * table[x][l1][l2] % mod);

				}

				

				valid = true;

				for(int y=0;y<m;y++){

					if(l[y] <= x && x <= r[y]){

						int cnt = 1;

						if(l[y] <= l2-1){

							cnt++;

						}

						if(l[y] <= l3-1){

							cnt++;

						}

						

						if(x == r[y] && cnt != w[y]){

							valid = false;

							break;

						}
					}

				}

				

				if(valid && l2 != 0){

					chadd(table[x+1][l2][x], table[x][l1][l2]);

				}

			}

		}

	}

	

//	for(int x=1;x<=n;x++){

//		for(int l1=0;l1<=x;l1++){

//			for(int l2=l1;l2<=x;l2++){

//				int l3 = (max(l1, l2) != x ? x : -1);

//				cout << x << " [" << l1 << "," << l2 << "," << l3 << "] -> " << table[x][l1][l2] << "\n"; 

//			}

//		}

//	}



	ll ans = 0;

	for(int l1=0;l1<=n;l1++){

		for(int l2=l1;l2<=n;l2++){

			int l3 = (max(l1, l2) != n ? n : -1);

			chadd(ans, table[n][l1][l2]);

		}

	}

	

	cout << ans << "\n";

    return 0;

}
