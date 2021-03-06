//丑数
/*把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯
上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。 */
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<7)
            return index;
        vector<int> a(index);
        int t2 = 0;
        int t3 = 0;
        int t5 = 0; 
        a[0] = 1;
        for(int i =1;i<index;i++)
        {
            a[i] = min(a[t2] * 2,min(a[t3]*3,a[t5]*5));
            if(a[i] == a[t2] * 2) t2++;
            if(a[i] == a[t3] * 3) t3++;
            if(a[i] == a[t5] * 5) t5++;
        }
        return a[index - 1];
        
    
    }
};