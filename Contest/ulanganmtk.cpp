#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14

struct Data{
	double x,y;
};

double round_up(double value, int decimal_places) {
    const double multiplier = std::pow(10.0, decimal_places);
    return std::ceil(value * multiplier) / multiplier;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string formula;
	int limit;
	cin >> formula >> limit;
	
	double a,b,c,d;
	cin >> a >> b >> c >> d;
	cout << a << " * " << formula << " " << b << "(x + " << c << ") + " << d << "\n";
	for(int x=0;x<=limit;x+= 15){
		double target_trigono = b * (x + c);
		double multiplier = a;
		double addition = d;
		double trigono = 0;
		if(formula == "sin") trigono = sin(target_trigono * PI / 180);
		else if(formula == "cos") trigono = cos(target_trigono * PI / 180);
		else trigono = tan(target_trigono * PI / 180);
		double result = (a * trigono) + d;
		cout << x << " : " << round_up(result, 2) << "\n";
	}	
	
    return 0;
}
