#include<iostream>
using namespace std;
// int a[] = * a
int sum(int *a , int size){

    int ans = 0;
    for (int i = 0; i< size; i++){
        ans += a[i];
    }
    return ans;
}

int main(){
    int a[10];
    cout << sizeof(a) << endl;
    cout << sum(a, 10) << endl;
    cout << sum (a+3 , 7) << endl;

}