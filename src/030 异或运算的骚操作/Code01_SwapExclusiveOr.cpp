#include <bits/stdc++.h>
using namespace std;

//当i==j时,会出错
void swapele(int arr[], int i, int j){
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
}

int main(){
    int a = -2323;
    int b = 10;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << endl;
    cout << b << endl;
    int arr[2] = {3, 5};
    swapele(arr, 0, 1);
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    swapele(arr, 0, 0);
    cout << arr[0] << endl;
    return 0;
}
