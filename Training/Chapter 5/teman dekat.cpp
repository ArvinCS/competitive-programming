#include <iostream>
#include <cmath>

using namespace std;

int funcKedekatan(int d, int x1, int x2, int y1, int y2){
	return pow(abs(x2-x1), d) + pow(abs(y2-y1), d);
}

int main(){
	int n,d;
	cin >> n;
	cin >> d;
	
	int array[n][2];
	for(int x=0;x<n;x++){
		cin >> array[x][0];
		cin >> array[x][1];
	}
	
	int lowest = 2 * pow(100, d);
	int highest = -1;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(x != y){
				int dekat = funcKedekatan(d, array[x][0], array[y][0], array[x][1], array[y][1]);
				if(dekat > highest) highest = dekat;
				if(dekat < lowest) lowest = dekat;
			}
		}
	}
	
	cout << lowest << " " << highest << "\n";
	return 0;
}
