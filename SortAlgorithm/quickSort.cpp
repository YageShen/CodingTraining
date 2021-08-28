#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 升序
// 不稳定
void quickShort(vector<int>& array, int left, int right) {
    if(left >= right)
        return;
    int pivot = array[left];
    int l = left, r = right;
    while(l < r) {
        while(array[r] >= pivot && r > l) --r;
        if(r > l) array[l++] = array[r];
        while(array[l] <= pivot && l < r) ++l;
        if(l < r) array[r--] = array[l];
    }
    array[l] = pivot;
    quickShort(array, left, l - 1);
    quickShort(array, r + 1, right);
}

void printArray(vector<int>& array) {
    for(int i(0); i < array.size(); ++i)
        cout << array[i] << " ";
    cout << endl;
}
int main() {
    vector<int> array = {7,3,5,8,9,1,2,4,6};
//     vector<int> tmpArray(array.size());
    quickShort(array, 0, array.size() - 1);
    printArray(array);
    return 0;
}