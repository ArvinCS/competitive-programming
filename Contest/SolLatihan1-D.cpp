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
		int n, k;
		cin >> n >> k;
		
		// butuh berapa segment untuk mencapai bilangan ke (k-1)
		// segment di sini adalah bilangan yang dipotong berukuran n dimulai dari 1..n, n+1..2n, dst.
		int div = (k-1)/(n-1);
		
		// kita tambahkan berapa langkah lagi untuk mencapai bilangan ke k jika mulai dari akhir segment yang
		// sudah dihitung di atas
		cout << div*n + (k-div*(n-1)) << "\n";
	}
	
    return 0;
}

