#include <iostream>
#include <vector>

using namespace std;

int price[101], weight[101], table[2001][101] = {}, stone[2001][101] = {}, capacity[2001][101] = {};

void coutResult(int n, int k){
	if(table[n][k] > 0){
		coutResult(n-weight[stone[n][k]-1], stone[n][k]-1);
		cout << stone[n][k] << "\n";
	}
}

void solve(int n, int k){
	for(int i=1;i<=k;i++){
		for(int c=1;c<=n;c++){
			int best = table[c][i-1];
			int bestStone = stone[c][i-1];
			int bestCapacity = capacity[c][i-1];
			if(weight[i-1] <= c){
				int tmp = table[c-weight[i-1]][i-1] + price[i-1];
				if(tmp > best || (tmp == best && capacity[c-weight[i-1]][i-1] + weight[i-1] < bestCapacity)){
					best = tmp;
					bestStone = i;
					bestCapacity = capacity[c-weight[i-1]][i-1] + weight[i-1];
				}
			}
			//if(i == 1) cout << "stone: " << bestStone << "\n";
			stone[c][i] = bestStone;
			table[c][i] = best;
			capacity[c][i] = bestCapacity;
		}
	}
	
	//for(int x=1;x<=n;x++) cout << stone[x][k] << "\n";
	coutResult(n,k);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;

	for(int x=0;x<k;x++) cin >> weight[x] >> price[x];
	
	solve(n,k);
	
    return 0;
}
