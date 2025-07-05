class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        int result = 0;
        int sign = 1;


        for(int i=0;i<s.size();i++){
            if(s[i]-'0' >=0 && s[i]-'0'<=9){
                //integer;
                num = (num*10) + (s[i]-'0'); //number banate jao
            }
            else{
                //+,-,(,),' '
                if(s[i] == '+'){
                    //ab number ban chuka hoga already 
                    //uslo result me add karo
                    result+=(num*sign);
                    num=0;
                    sign = 1;

                }
                else if(s[i] == '-'){
                    //ab number ban chuka hoga already 
                    //uslo result me add karo
                    result+=(num*sign);
                    num=0;
                    sign = -1;
                }
                else if(s[i] == '('){
                    st.push(result);
                    st.push(sign); //last result save kr ke rakh lena h

                    num=0;//yaha se bracket ke andar ka evaluation hoga
                    result=0;
                    sign=1;
                }
                else if(s[i] == ')'){
                    result+=(sign*num); //bach hua num ko add kr lo


                    num=0;
                    int stack_sign = st.top(); st.pop();
                    int last_result = st.top(); st.pop();
                    
                    //stack ke rsult ko add karo
                    result*= stack_sign;
                    result+=last_result;
                }
            }

        }
        if(num!=0){ //agr last me num me kuch bacha h toh add kr lo
            result+=(num*sign);
        }
        return result;
    }
};