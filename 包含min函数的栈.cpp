//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
class Solution {
public:
    void push(int value) {
        s.push(value);
        if(smin.empty())
            smin.push(value);
        else if(value <= smin.top())
            smin.push(value);
             
             
    }
    void pop() {
        if(s.top() == smin.top())
            smin.pop();
        s.pop();
         
    }
    int top() {
        return smin.top();
    }
    int min() {
        return smin.top();
         
    }
private:
    stack<int> s;
    stack<int> smin;
};