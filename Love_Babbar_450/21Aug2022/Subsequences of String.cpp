//CPP DSA Love Babbar 450
void helper(string str, string output, int index, vector<string>& ans){
    //base case
    if(index>=str.length()){
        if(output.length()>0){
            //no need to insert "" => empty string
            ans.push_back(output);
        }
        return;
    }
    //excluded element call
    helper(str, output, index+1, ans);
    
    //included element call
    char element = str[index];
    output.push_back(element);
    helper(str, output, index+1, ans);
}
vector<string> subsequences(string str){
    vector <string> res;
    string output = "";
    int index = 0;
    helper(str, output, index, res);
    return res;
}
