/*
��Ŀ������һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ�������������
��С��һ����������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��

sort�еıȽϺ���compareҪ����Ϊ��̬��Ա������ȫ�ֺ�����������Ϊ��ͨ��Ա����������ᱨ�� 
��Ϊ���Ǿ�̬��Ա�����������ھ������ģ���std::sort���ຯ����ȫ�ֵģ�����޷���sort�е���
�Ǿ�̬��Ա��������̬��Ա��������ȫ�ֺ����ǲ������ھ�������, ���Զ������ʣ����봴���κζ�
��ʵ���Ϳ��Է��ʡ�ͬʱ��̬��Ա���������Ե�����ķǾ�̬��Ա��
*/
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int len = numbers.size();
        string s = "";
        if(len == 0)
            return s;
        sort(numbers.begin(),numbers.end(),cmp);
        for(int i=0;i<len;i++)
            s += to_string(numbers[i]);
        return s;
        }
       static bool cmp(int a,int b) //���塰С�ڡ�
        {
            string m = "";
            string n = "";
            m += to_string(a);
            m += to_string(b);
            n += to_string(b);
            n += to_string(a);
            return(m<n);
       }
};