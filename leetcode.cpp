class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int a, b, c;
        std::stack<int> stuck;

        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+")
            {
                a = stuck.top(); stuck.pop();
                b = stuck.top(); stuck.pop();
                stuck.push(a + b);
            }
            else if (tokens[i] == "-")
            {
                a = stuck.top(); stuck.pop();
                b = stuck.top(); stuck.pop();
                stuck.push(b - a);
            }
            else if (tokens[i] == "*")
            {
                a = stuck.top(); stuck.pop();
                b = stuck.top(); stuck.pop();
                stuck.push(a * b);
            }
            else if (tokens[i] == "/")
            {
                a = stuck.top(); stuck.pop();
                b = stuck.top(); stuck.pop();
                stuck.push(b / a);
            }
            else
            {
                stuck.push(stoi(tokens[i]));
            }

        }
        return stuck.top();
    }
};