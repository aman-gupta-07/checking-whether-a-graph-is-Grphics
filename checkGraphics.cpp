#include <iostream>
#include <algorithm>
using namespace std;
bool checkGrahics(int arr[], int n){
    if(n == 0){
        return true;
    }
    sort(arr, arr + n, greater<int>());
    if(arr[0] >= n){
        return false;
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(arr[i] < 0){
            return false;
        }
        
    }
    if(sum == 0){
        return true;
    }
    if(sum % 2 == 1){
        return false;
    }
    for(int j =  0; j < arr[0]; j++){
        arr[j + 1] = arr[j+1] - 1;
    }
    
    checkGrahics(arr+1, n-1);
    
}
int main()
{
    cout << "Enter the number of vertex in the Graph: " << endl;
    int n;
    cin >> n;
    int degreeSequence[n];
    cout << "Enter the numbers of degree Sequence for the graph: " << endl;
    for(int i = 0; i < n; i++){
        cin >> degreeSequence[i];
    }
    if(checkGrahics(degreeSequence, n)){
        cout << "The given graph is a graphic." << endl;
    }
    else{
        cout << "The given graph is not a graphic." << endl;
    }

    return 0;
}
