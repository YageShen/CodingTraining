class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        int leftMulti[len], rightMulti[len];
        leftMulti[0] = 1; //leftMulti[1] = 1;
        for(int i = 1; i < len; ++i) {
            leftMulti[i] = A[i-1] * leftMulti[i-1];
        }
        rightMulti[len-1] = 1; //rightMulti[len-2] = 0;
        for(int i = len - 2; i >= 0; --i) {
            rightMulti[i] = A[i+1] * rightMulti[i+1];
        }
        
        vector<int> B(len);
        for(int i = 0; i < len; ++i) {
            B[i] = leftMulti[i] * rightMulti[i];
        }
        return B;
    }
};