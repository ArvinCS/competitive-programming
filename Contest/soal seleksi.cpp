#include <iostream>
using namespace std;
 
int X[15] = {194, 173, 892, 489, 123, 781, 273, 429, 332, 878, 303, 332, 234, 493, 432};
 
void Zaff(int &a, int &b){
   int tmp;
   tmp = a;a = b; b = tmp;
}
 
void panik(int s, int t, int m){
	int tmp = X[m];
	while(s<t){
      	while(X[s] < tmp) s++;
		while(tmp < X[t]) t--;
		Zaff(X[s], X[t]);
		for(int x=0;x<15;x++){
		   cout << X[x] << " ";
		}
		cout << "\n";
	}
}
 
int main() {
	cout << "Berjalan\n";
	panik(0,14,8);
	for(int x=0;x<15;x++){
	   cout << X[x] << " ";
	}
	return 0;
}
