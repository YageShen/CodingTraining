#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 升序
// 不稳定
void maxHeapify(vector<int>& array, int index, int heapSize) {
    int largest = index;
    int left = 2 * index + 1; // 左节点索引
    int right = 2 * index + 2; // 右节点索引
    if((left <= heapSize) && (array[largest] < array[left])) {
        largest = left;
    }
    if((right <= heapSize) && (array[largest] < array[right])) {
        largest = right;
    }
    if(largest != index) {
        swap(array[index], array[largest]);
        maxHeapify(array, largest, heapSize);
    }
}

void buildMaxHeap(vector<int>& array) {
    int len = array.size();
    for(int i = (len >> 1) - 1; i >= 0; --i) {
        maxHeapify(array, i, len - 1);
    }
}

void heapSort(vector<int>& array) {
    buildMaxHeap(array);
    int len = array.size();
    int heapSize = len - 1;
    for(int i = len - 1; i >= 1; --i) {
        swap(array[0], array[i]);
        --heapSize;
        maxHeapify(array, 0, heapSize);
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
    heapSort(array);
    printArray(array);
    return 0;
}