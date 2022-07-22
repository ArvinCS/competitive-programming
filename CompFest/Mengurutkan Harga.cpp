#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us n;
	cin >> n;
	
	us data[n];
	for(us x=0;x<n;x++) cin >> data[x];
	
	for(us i=0;i<n;i++){
		for(us j=i+1;j<n;j++){
			if(data[i] > data[j]){
				us tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
				
				cout << i+1 << " " << j+1 << "\n";
			}
		}
	}
    return 0;
}

