//����
/*��ֻ����������2��3��5��������������Ugly Number����
����6��8���ǳ�������14���ǣ���Ϊ������������7�� ϰ��
�����ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N�������� */
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