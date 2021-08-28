#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 不稳定
void selectSort(vector<int>& array) {
    int len = array.size();
    int minIdx;
    for(int i(0); i < len - 1; ++i) {
        minIdx = i;
        int minVal = array[minIdx];
        for(int j(i+1); j < len; ++j) {
            if(array[j] < minVal) {
                minIdx = j;
                minVal = array[minIdx];
            }
        }
        if(minIdx != i) {
            swap(array[i], array[minIdx]);
        }
    }
}

void printArray(vector<int>& array) {
    for(int i(0); i < array.size(); ++i)
        cout << array[i] << " ";
    cout << endl;
}
int main() {
    vector<int> array = {7,3,5,8,9,1,2,4,6};
    selectSort(array);
    printArray(array);
    return 0;
}