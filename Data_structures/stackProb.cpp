#include <stack>
#include <string>
#include <vector>

using namespace std;

class StockSpanner {
public:

    stack<pair<int , int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {   
        int ans = 1;
        while(!st.empty() && price >= st.top().first){
            ans += st.top().second;
            st.pop();
        }


        pair<int , int > p = {price , ans};
        st.push(p);
        return ans;
    }
};


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

 void reverseString(string &str) {
        int s = 0, e = str.length() - 1;
        while (s < e) {
            str[s] = str[s] ^ str[e];
            str[e] = str[s] ^ str[e];
            str[s] = str[s] ^ str[e];
            s++;
            e--;
        }
    }

  

    string infixToPrefix(string s) {

        // 1. Reverse
        reverseString(s);

        // 2. Swap brackets
        for (char &c : s) {
            if (c == '(') c = ')';
            else if (c == ')') c = '(';
        }

        stack<char> st;
        string ans = "";

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // operand
            if (isalnum(ch)) {
                ans += ch;
            }
            // opening bracket
            else if (ch == '(') {
                st.push(ch);
            }
            // closing bracket
            else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop(); // remove '('
            }
            // operator
            else {
                
                if(ch == '^'){
                    while (!st.empty() &&
                       (priority(ch) <= priority(st.top())))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }else{
                
            
                while (!st.empty() &&
                       (priority(ch) < priority(st.top())))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
            
            }
        }

       
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // final reverse
        reverseString(ans);

        return ans;
    }


    string postToInfix(string postfix) {
    stack<string> st;

    int i = 0;

    while(i < postfix.length()){

        if(isalnum(postfix[i])) st.push(string(1,postfix[i]));

        else{
            string t1 = st.top(); 
            st.pop();
            string t2 = st.top();
            st.pop();

            string newString = "(" + t2 + postfix[i] + t1+ ")";

            st.push(newString);
        }


        i++;
    }

    return st.top();
}


string prefixToInfixConversion(string &s){
	stack<string> st;

	int i = s.length()-1;

	while(i >= 0){
		if(isalnum(s[i])) st.push(string(1,s[i]));

		else {
			string t1 = st.top() ; st.pop();
			string t2 = st.top() ; st.pop();

			string newString = "(" + t1 + s[i] + t2 + ")";

			st.push(newString);
		}


		i--;
	}

	return st.top();
}

string postfixToPrefix(string &s){
   stack<string> st;

   int i = 0;

   while(i < s.length()){
       if(isalnum(s[i])) st.push(string(1,s[i]));

       else{
           string t1 = st.top() ; st.pop();
           string t2 = st.top() ; st.pop();

           string exp = s[i] + t2 + t1;
            
            st.push(exp);
       }

       i++;
   }

   return st.top();
}


string preToPost(string s) {
  
   stack<string> st;

   int i = s.length()-1;

   while(i >= 0){
       if(isalnum(s[i])) st.push(string(1,s[i]));

       else{
           string t1 = st.top() ; st.pop();
           string t2 = st.top() ; st.pop();

           string exp =  t1 + t2 + s[i];
            
            st.push(exp);
       }

       i--;
   }

   return st.top();
}

vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	stack<int> st;
	vector<int> ans(n , -1);
	for(int i = 0 ; i < n ; i++){
		while(!st.empty() && arr[i] > arr[st.top()]){
			ans[st.top()] = arr[i];
			st.pop();
		}

		st.push(i);
	}

	return ans;
}


vector<int> nextGreaterElementII(vector<int>& a) {
    int n = a.size();

    stack<int> st;

    vector<int> ans(n);
    for(int i = 2 * n - 1 ; i >=0 ; i--){
        while(!st.empty() && a[i % n] >= st.top()){
            st.pop();
        }

        if(i < n){
            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
        }

        st.push(a[i % n]);

    }

    return ans;

   
}

vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        stack<int> st ;
        
        int n = arr.size();
        
        vector<int> ans(n);
        
        for(int i = 0; i < n ; i++){
            
            
            while(!st.empty() && arr[i] <= st.top()){
                st.pop();
            }
            
            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
            
            st.push(arr[i]);
        }
        
        return ans;
    }

      vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        
        vector<int> ans(n);
        
        stack<int> st;
        
        for(int i = n-1 ; i>= 0 ; i--){
            
            while(!st.empty() && arr[i] <= st.top()) {
                st.pop();
            }
            
            
            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
            
            
            st.push(arr[i]);
        }
        
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxi = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[i] < heights[st.top()]) {

                int compute = st.top();
                st.pop();

                int h = heights[compute];

                int nse = i;             
                int pse = st.empty() ? -1 : st.top();

                int w = nse - pse - 1;
                maxi = max(maxi, h * w);
            }

            st.push(i);
        }

        
        while (!st.empty()) {

            int compute = st.top();
            st.pop();

            int h = heights[compute];

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            int w = nse - pse - 1;
            maxi = max(maxi, h * w);
        }

        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> prefixSum(matrix.size() , vector<int>(matrix[0].size() , -1));

        for(int j = 0 ; j < matrix[0].size() ; j++){
            int sum = 0;

            for(int i = 0 ; i < matrix.size() ; i++){
               int num = (matrix[i][j] == '1') ? 1 : 0;

                sum += num;

                if(num == 0){
                    sum = 0;
                }

                prefixSum[i][j] = sum;

            }
        }


        int maxi = 0;

        for(int k = 0 ; k < matrix.size() ; k++){
            maxi = max(maxi , largestRectangleArea(prefixSum[k]));
        }


        return maxi;
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