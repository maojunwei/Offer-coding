//给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
class Solution {//无i
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int>B;
        int n = A.size();
        for(int i=0;i<n;i++)
        {
            int left =1,right =1;
            if(i != 0)
             for(int j=0;j<=i-1;j++)
                    left *= A[j];
             if(i!=n-1)
             for(int j=n-1;j>=i+1;j--)
                    right *= A[j];
            B.push_back(left*right);
        }
        return B;
    
    }
};