#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

int n;
int X[100], Y[100]; //# luu toa do cac buoc di chuyen cua quan ma 
int mark[100][100]; //# Ðánh dau vi tri cac o ma quan ma da di chuyen qua 

//# Mang hx, hy mô ta 8 vi trí quân ma có the di chuyen ke tu vi trí hien tai
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

//# In ra day các di chuyen tim duoc 
void print_sol(){
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}

bool check(int xx, int yy){
    if(mark[xx][yy] == 1) return false;
    if(xx < 1 || xx > n || yy < 1 || yy > n) return false;
    //cout << xx << " " << yy << endl;
    return true;
}

//# Thuat toán quay lui
void TRY(int k){
    for(int i = 0; i < 8; i++){
        int xx = X[k-1] + hx[i];
        int yy = Y[k-1] + hy[i];
      
        if(check(xx,yy)){
            mark[xx][yy] = 1;
            X[k] = xx;
            Y[k] = yy;

            if(k == n*n) print_sol();
            else TRY(k+1);

            mark[xx][yy] = 0;
        }
        /*****************/
    }
}
int main(){
    cout << "Ho va Ten: Srey Sovanrith" << endl;
    cout << "MSSV: 20200845\n\n";
    cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}
