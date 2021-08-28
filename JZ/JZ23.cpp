class Solution {
public:
    bool recur(vector<int>& posSeq, int begin, int end) {
        if(begin >= end)
            return true;
        int x = begin;
        while(posSeq[x] < posSeq[end]) {
            ++x;
        }
        int y = x;
        while(posSeq[y] > posSeq[end]) {
            ++y;
        }
        return y == end && recur(posSeq, begin, x-1) && recur(posSeq, x, y-1);
    }
    bool VerifySquenceOfBST(vector<int>& sequence) {
        if(sequence.empty())
            return false;
        else
            return recur(sequence, 0, sequence.size()-1);
    }
};