#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 升序
// 稳定
void mergeArray(vector<int>& array, vector<int>& tempArray, int l, int mid, int r) {
    int p1 = l, p2 = mid+1, p = l;
    while(p1 <= mid && p2 <= r) {
        if(array[p1] <= array[p2]) {
            tempArray[p++] = array[p1++];
        }
        else {
            tempArray[p++] = array[p2++];
        }
    }
    while(p1 <= mid) tempArray[p++] = array[p1++];
    while(p2 <= r) tempArray[p++] = array[p2++];
    copy(tempArray.begin() + l, tempArray.begin() + r + 1, array.begin() + l);
}

void mergeSort(vector<int>& array, vector<int>& tempArray, int l, int r) {
    if(l >= r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort(array, tempArray, l, mid);
    mergeSort(array, tempArray, mid+1, r);
    mergeArray(array, tempArray, l, mid, r);
}

void printArray(vector<int>& array) {
    for(int i(0); i < array.size(); ++i)
        cout << array[i] << " ";
    cout << endl;
}
int main() {
    vector<int> array = {7,3,5,8,9,1,2,4,6};
    vector<int> tmpArray(array.size());
    mergeSort(array, tmpArray, 0, array.size()-1);
    printArray(array);
    return 0;
}