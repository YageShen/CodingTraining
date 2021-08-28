#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 升序
// 不稳定
void shellSort(vector<int>& array) {
    int len = array.size();
    for(int h = len / 2; h > 0; h /= 2) {
        for(int i = h; i < len; ++i) {
            int temp = array[i];
            int j = i - h;
            while(j >= 0 && array[j] > temp) {
                array[j+h] = array[j];
                j -= h;
            }
            array[j+h] = temp;
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
//     vector<int> tmpArray(array.size());
    shellSort(array);
    printArray(array);
    return 0;
}