#include <iostream>
#include <vector>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

vector<ui> factors[100001];
ui parrent[100001];

ui getParrent(ui id){
	if(parrent[id] == id) return id;
	return parrent[id] = getParrent(parrent[id]);	
}

bool check(ui id1, ui id2){
	return getParrent(id1) == getParrent(id2);	
}

void merge(ui id1, ui id2){
	parrent[getParrent(id1)] = getParrent(id2);	
}

void factorize(ui index, ui n){
	for(ui x=1;x*x<=n;x++){
		if(n % x == 0){
			factors[x].push_back(index);
			if(n/x != x){
				factors[n/x].push_back(index);
			}
		}
	}	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	ui n;
	cin >> n;
	
	ui data[n];
	for(ui x=0;x<n;x++){
		cin >> data[x];
		factorize(x, data[x]);
		parrent[x] = x;
	}

	long long ans = 0;
	for(int x=100000;x>0;x--){
		if(factors[x].size() < 2) continue;
		for(ui y=1;y<factors[x].size();y++){
//			cout << factors[x][0] << " " << factors[x][y] << " -> " << !check(factors[x][0], factors[x][y]) << "\n";
			if(!check(factors[x][0], factors[x][y])){
				merge(factors[x][0], factors[x][y]);
				ans += x;
			}
		}	
	}
	
	cout << ans << "\n";
    return 0;
}

