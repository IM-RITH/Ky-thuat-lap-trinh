#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int n, c[MAX][MAX]; //# so thành pho va ma tran chi phi 
int cmin = INT_MAX; //# chi phí di lai nho nhat giua hai thành pho khác nhau
int best = INT_MAX; //# tong chi phí nho nhat can tim, ban dau dat bong giá tri vô cùng lon INT_MAX = 2^31-1
int curr; //# tong chi phí toi thoi diiem hien tai
int mark[MAX]; //# danh dau nhung thành pho da di 
int x[MAX]; //# luu giu các thành pho da di 

//# Ðoc diu lieu vao  
void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
    for(int i=0; i<MAX; i++)
            mark[i] = 0;
    curr = 0;
}

bool check(int k, int i){
    if(mark[i] == 1) return false;
    return true;
}
void solution(){
    best = min(best,curr);
}
//# Thuat toán quay lui
void TRY(int k){
    for(int i = 2; i <= n; i++){
        /****************
            Ho va ten : Srey Sovanrith
            MSSV : 20200845 
            ***********************/

        if(check(k,i)){
            mark[i] = 1;
            curr += c[x[k-1]][i];

            x[k] = i;

            if(k == n) {
                curr += c[x[n]][1];
                solution();
                curr -= c[x[n]][1];
            }
            else TRY(k+1);

            mark[i] = 0;
            curr -= c[x[k-1]][i];
        }
        /*****************/
    }
}

int main() {
    cout << "Ho va ten: Srey Sovanrith" << endl;
    cout << "MSSV: 20200845\n\n";
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}
