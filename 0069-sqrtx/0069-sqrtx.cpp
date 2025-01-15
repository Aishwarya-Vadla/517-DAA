class Solution {
public:
    int mySqrt(int x) {
        long long left=0,right=x;
        while(left<right){
            long long m=left+((right-left+1)>>1);
            if (m<=x/m){
                left=m;
            } else{
                right=m-1;
            }
        }
        return static_cast<int>(left);
    }
};