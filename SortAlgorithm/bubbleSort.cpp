#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 升序
// 稳定
void bubbleSort(vector<int>& array) {
    int len = array.size();
    for(int i(0); i < len - 1; ++i) {
        int exchange = 0;
        for(int j(0); j < len - i - 1; ++j) {
            if(array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
                exchange = 1;
            }
        }
        if(!exchange)
            return;
    }
}

void printArray(vector<int>& array) {
    for(int i(0); i < array.size(); ++i)
        cout << array[i] << " ";
    cout << endl;
}
int main() {
    vector<int> array = {7,3,5,8,9,1,2,4,6};
    bubbleSort(array);
    printArray(array);
    return 0;
}