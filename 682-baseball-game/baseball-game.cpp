class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(const string& op:operations){
            if(op=="+"){
            int top=st.top();
            st.pop();
            int newtop=st.top()+top;
            st.push(top);
            st.push(newtop);
            }
        else if(op=="D")
            st.push(2*st.top());
        else if(op=="C")
            st.pop();
        else
            st.push(stoi(op));
    }
    int total=0;
    while(!st.empty()){
        total+=st.top();
        st.pop();
    }
    return total;
    }
};