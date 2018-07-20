//¡°student. a am I¡±->¡°I am a student.¡±
class Solution {
public:
    string ReverseSentence(string str) {
        int len = str.length();
        string s1 = "",s2 = "";
        for(unsigned int i=0;i<len;i++)
        {
            if(str[i] == ' ' )
            {
                s1 = " " + s2 + s1;
                s2 = "";
                
            }
            else
                s2 += str[i];
        }
        if(s2.size())
            s1  = s2 + s1; 
        return s1;         
            
        }
};