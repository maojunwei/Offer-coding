/*
����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ�����磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3��
	��ôһ������6���������ڣ����ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}�� �������{2,3,4,2,6,2,5,1}�Ļ�������������6���� {[2,3,4],2,6,2,5,1}�� 
{2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}�� {2,3,4,[2,6,2],5,1}�� {2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��
*/
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) //vector<int>���͵����ã�(int ���������)��numΪʵ�εı���
        //const�����ñ���ӵ��ֻ������
    {
        int len = num.size();
        vector<int> vec;
        if(len == 0 || size ==0)
            return vec;
        for(int i=0;i<len-size+1;i++)
        {
            vector<int> v;
            for(int j = i;j<i+size;j++)
            {
                v.push_back(num[j]);
            }
            sort(v.begin(),v.end());
            vec.push_back(v[size-1]);
            
        }
        return vec;
    }
};