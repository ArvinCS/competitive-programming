#include <iostream>
#include <cctype>
#include <iomanip>

using namespace std;

struct Orang{
	string nama;
	int telepon;
};

int search(Orang arr[], long long n, string x){
	long long l = 0, h = n-1;
	while (l<=h){
		long long mid = (h + l)/2;
		int res = 0;
		if(x == arr[mid].nama) return mid;
		else if(x>arr[mid].nama) l = mid + 1;
		else h = mid - 1;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	long long q;
	cin >> n >> q;
	Orang daftar[n];
	for(int x=0;x<n;x++){
		cin >> daftar[x].nama >> daftar[x].telepon;
	}
	
	for(int x=0;x<q;x++){
		string target;
		cin >> target;
		int index = search(daftar, n, target);
		if(index == -1) cout << "NIHIL\n";
		else {
			Orang contact = daftar[index];
			cout  << std::setfill('0') << std::setw(6) << right << contact.telepon << "\n";
		}
	}
	
    return 0;
}
