class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> v;
        if(k==0 || input.size()<=0 || k > input.size())
            return v;
        if(k == input.size())
            return input;
        int k1 = partion(input,0,input.size()-1);
        int start = 0;
        int end = input.size()-1;
        while(k1!=k-1)
        {
            if(k1>k-1)
            {
                end = k1-1;
                k1 = partion(input,start,end);
            }
            else
            {
                start = k1+1;
                k1 = partion(input,start,end);
            }
        }
       for(int i =0;i<k;i++)
       v[i] = input[i];
            return v;          
    }
    int partion(vector<int> &a,int low,int high)
    {
        int pv = a[low];
        while(low<high)
        {
            while(low<high && pv<=a[high])
                high--;
            swap(a,low,high);
            while(low<high && pv>=a[low])
                low++;
            swap(a,low,high);
        }
        return low;               
    }
    void swap(vector<int> &a,int i,int j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;        
    }
};