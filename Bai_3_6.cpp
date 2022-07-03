#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}
int gcd2(int a, int b){

    //# Khu de quy 
    /****************
        Ho va ten : Srey Sovanrith
        MSSV : 20200845
    */
    while(b != 0){
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
   /*****************/
}
int main() {
    cout << "Ho va ten: Srey Sovanrith" << endl;
    cout << "MSSV: 20200845\n\n";
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}
