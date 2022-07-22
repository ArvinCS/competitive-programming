#include <iostream>

using namespace std;

int n;
string s;

int solve(int n){
	int table[n+1][2] = { 0 }, minIndex[(2 * n) + 2]; // gunanya minIndex, kita setor index paling kecil yang indexnya merupakan perbedaan jumlah 1 dan 0 (jika 0 lebih banyak maka maxN - x) (jika 1 lebih banyak maka maxN + x)
	fill(minIndex, minIndex+(2*n)+2, -1);
	
	table[0][0] = 0;
	table[0][1] = 0; // base case
	
	minIndex[0+n+1] = 0;

	for(int x=1;x<=n;x++){
		table[x][0] = table[x-1][0] + (s[x-1] == '0');
		table[x][1] = table[x-1][1] + (s[x-1] == '1');
		
		//cout << table[x][0] << " " << table[x][1] << "\n";
		int diff = table[x][1] - table[x][0];
		if(minIndex[diff + n + 1] == -1){
			minIndex[diff + n + 1] = x; // kita ketemu minIndex, cek apakah sudah di-isi, jika belum maka ini index terkecil yang mempunyai nilai perbedaan x
		}
	}

	int best = 0;
	for(int x=0;x<=n;x++){
		int index = minIndex[table[x][1] - table[x][0] + n + 1]; // kita cari minIndex yang memiliki jumlah perbedaan yang sama ([-x] - [-x] = -x + x = 0, maka seimbang)
		if(index != -1) {
			best = max(best, x-index); // jika ada minIndexnya, jika kurangkan dengan panjang a dikurang panjang minIndex.
		}
		//cout << a << " " << index << "\n";
	}
	
	return best;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	cin >> s;
	
	cout << solve(n) << "\n";
	
    return 0;
}
