/**
 * Financial Management
 * http://poj.org/problem?id=1004
 */

#include <iostream>
#include <cmath>

using namespace std;

int mround(float number) {
    return number > 0.0 ? floor(number+0.5) : ceil(number+0.5);
}
int main() {
    float sum_b = 0;
    for (int m = 0; m < 12; m++) {
	float m_balance;
	cin>>m_balance;
	sum_b += m_balance;
    }
    cout<<"$"<<1.0*mround((sum_b*100)/12)/100<<endl;
    return 0;
}
