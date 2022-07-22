#include <bits/stdc++.h>



using namespace std;



#define ll long long



int main(){

	ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

	

	int n, m;

	cin >> n >> m;

	

	vector<string> v;

	for(int x=0;x<n;x++){

		string s;

		cin >> s;

		

		v.push_back(s);

	}

	

	// step:

	// compare config i and j

	// start from n to 1

	// if string_i idx == string_j idx

	// continue

	// if string_i idx < string_j idx

	// i best

	// else 

	// j best

	

	vector<string> best = v;

	for(int i=0;i<n;i++){

		for(int y=0;y<m;y++){

			bool better = true;

			for(int x=n-1;x>=0;x--){

				if(v[x] == best[x]){

					continue;

				}

				

				for(int y=m-1;y>=0;y--){

					if(v[x][y] == best[x][y]) continue;

					

					better = (v[x][y] > best[x][y]);

					break;

				}

				break;

			}

			

			if(better) best = v;

			

			for(int x=0;x<n;x++){

				for(int y=0;y+1<m;y++){

					swap(v[x][y], v[x][y+1]);

				}

			}

		}

		

		for(int x=0;x+1<n;x++){

			swap(v[x], v[x+1]);

		}

	}

	

	for(int x=0;x<n;x++){

		for(int y=0;y<m;y++){

			cout << best[x][y];

		}

		cout << "\n";

	}

    return 0;

}
