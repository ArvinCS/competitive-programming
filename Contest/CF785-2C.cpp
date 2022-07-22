#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 50000;
const ll mod = 1e9 + 7;

ll table[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(table, table+maxN, 0);
	table[0] = 1;
	
	for(int x=1;x<1000;x++){
		int val = x;
		vector<int> v;
		while(val > 0){
			v.push_back(val%10);
			val /= 10;
		}
		
		reverse(v.begin(), v.end());
		
		int pw = 1;
		int val2 = 0;
		for(int y=0;y<2*v.size()-1;y++){
			if(y >= v.size()){
				val2 += pw * v[v.size()-2-(y%v.size())];
			} else {
				val2 += pw * v[y];
			}
			pw *= 10;
		}
		
		for(int y=0;y<maxN;y++){
			if(y+val2 >= maxN) break;
			
			table[y+val2] += table[y];
			if(table[y+val2] >= mod) table[y+val2] -= mod;
		}
		
		pw = 1;
		val2 = 0;
		for(int y=0;y<2*v.size();y++){
			if(y >= v.size()){
				val2 += pw * v[v.size()-1-(y%v.size())];
			} else {
				val2 += pw * v[y];
			}
			pw *= 10;
		}
		
		for(int y=0;y<maxN;y++){
			if(y+val2 >= maxN) break;
			
			table[y+val2] += table[y];
			if(table[y+val2] >= mod) table[y+val2] -= mod;
		}
	}
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		cout << table[n] << "\n";
	}
	
    return 0;
}

