#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 升序
// 稳定
void insertSort(vector<int>& array) {
    for(int i(1); i < array.size(); ++i) {
        int temp = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > temp) {
            array[j+1] = array[j];
            --j;
        }
        array[j+1] = temp;
    }
}

void printArray(vector<int>& array) {
    for(int i(0); i < array.size(); ++i)
        cout << array[i] << " ";
    cout << endl;
}
int main() {
    vector<int> array = {7,3,5,8,9,1,2,4,6};
    insertSort(array);
    printArray(array);
    return 0;
}