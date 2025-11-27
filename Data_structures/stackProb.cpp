#include <stack>
#include <string>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0 ; i < s.length() ; i++){
            char ch = s[i];

            if(ch == '('  || ch == '{' || ch == '['){
                st.push(ch);
            }else{

                if(st.empty()) return false;
                char top = st.top();
                st.pop();

                if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[') ){
                    continue;
                }else{
                    return false;
                }

            }
        }

        return st.empty();
    }

    #include<stack>
int priority(char ch){
    if (ch == '+' || ch == '-') {
        return 1;
    } 
    else if (ch == '*' || ch == '/') {
        return 2;
    } 
    else if (ch == '^') {
        return 3;
    } 
    else {
        return -1;
    }
}

string infixToPostfix(string exp){
	stack<char> st;
	string ans = "";
	int i = 0;

	while(i < exp.length()){
		char ch = exp[i];

		if(isalnum(ch)){
			ans += ch;
		}

		else if(ch == '('){
			st.push(ch);
		}

		else if(ch == ')'){
			while(!st.empty() && st.top() != '('){
				ans += st.top();
				st.pop();
			}

			st.pop();
		}
		
		else {
			while(!st.empty() && priority(ch) <= priority(st.top())){
			ans += st.top();
			st.pop();
		}

		st.push(ch);

		}

	
		
i++;


}

	while(!st.empty()){
			ans += st.top();
			st.pop();
		}

return ans;
}


   
};

 int main(){

        char ch1 = '-';

        char ch2 = '+';

        if(ch1 > ch2){
            printf("%c is grater \n",ch1);
        }else if(ch2 > ch1){
             printf("%c is grater \n",ch2);
        }else{
             printf("same \n");
        }
        return 0;
    }