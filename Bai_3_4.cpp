#include <bits/stdc++.h>
using namespace std;
int a[1000], n;
int mem[1000]; //# mang ghi nho loi giai các bai toan con da duoc giai

void init(){
    memset(mem, -1, sizeof(mem));
}
//# Quy hoach dong 
//# Ham lis(i) tra ve do dai day con tãng dài nhat ket thúc bai a[i]
void incsubseq(){
    mem[0] = 1;

    for(int i=1; i<n; i++){
        mem[i] = 1;
        for(int j=0; j<i; j++){
            if(a[j] < a[i]){
                if(mem[i] < mem[j] + 1){
                    mem[i] = mem[j] + 1;
                }
            }
        }
    }
}
int lis(int i) {
    /****************
        Ho va ten : Srey Sovanrith
        MSSV : 20200845
    */
    return mem[i];
    /*****************/
}

//# Truy vet loi giai
void trace(int i){
    for(int j = 0; j < i; j++){
        if (a[j] < a[i] && mem[i] == 1 + mem[j]){
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}

int main(){
    cout << "Ho va ten: Srey Sovanrith" << endl;
    cout << "MSSV: 20200845\n\n";
    init();
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    incsubseq();

    int res = 1, pos = 0;
    for(int i = 1; i < n; i++){
        if (res < lis(i)){
            res = lis(i);
            pos = i;
        }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}

