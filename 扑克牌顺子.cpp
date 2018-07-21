class Solution {
public:
    bool IsContinuous( vector<int> numbers ) { //�ж��ǲ��ǡ�˳�ӡ������Ԫ��,���ظ�����������ĸ���������ֵ������
        int len = numbers.size();//�ռ任ʱ��
        if(len == 0)
            return false;
        int count[14] = {0};
        int max = -1;
        int min = 14;
        for(int i=0;i<len ;i++)
        {   
            if(numbers[i] == 0)
              continue;
            count[numbers[i]]++;
            if(count[numbers[i]] > 1)
               return false;
            if(numbers[i] > max)
                max = numbers[i];
            if(numbers[i] < min)
                min = numbers[i];            
        }
        if(max - min < 5)
            return true;
        return false;
    }
};