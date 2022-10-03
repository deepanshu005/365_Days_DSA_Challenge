// CPP DSA CN Lec 19 Love Babbar 450
/* Time complexity: O(3 ^ min(N, M)) Space complexity: O(min(N, M)) where N and M are the lengths of the two strings */ 
int editDistance(string s1, string s2) {
    int n = s1.length(); 
    int m = s2.length(); 
    if (n == 0 || m == 0) {
        return max(n, m);
    }
    if (s1[0] == s2[0]) {
        return editDistance(s1.substr(1), s2.substr(1)); 
    }
    int deleteCost = editDistance(s1.substr(1), s2);
    int insertCost = editDistance(s1, s2.substr(1)); 
    int replaceCost = editDistance(s1.substr(1), s2.substr(1));
    return 1 + min(deleteCost, min(insertCost, replaceCost)); 
}
