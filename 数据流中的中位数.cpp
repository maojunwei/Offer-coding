/*
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
那么中位数就是所有数值排序之后位于中间的数值。如果从数据流
中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数
的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方
法获取当前读取数据的中位数。
*/
class Solution {
public:
    void Insert(int num)
    {
        v.push_back(num);
    }

    double GetMedian()
    { 
        int len = v.size();
       sort(v.begin(),v.end());
        if(len % 2 == 0)
            return double((v[len/2 -1] + v[len/2])/2.0 );
        else
            return double(v[len/2]);
    }
private: 
    vector<int> v;
};