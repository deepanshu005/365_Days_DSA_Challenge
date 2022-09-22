// CPP DSA Love Babbar 450 CN Lec 16
// class TrieNode {
//    public:
//     char data;
//     TrieNode **children;
//     bool isTerminal;

//     TrieNode(char data) {
//         this->data = data;
//         children = new TrieNode *[26];
//         for (int i = 0; i < 26; i++) {
//             children[i] = NULL;
//         }
//         isTerminal = false;
//     }
// };

// class Trie {
//     TrieNode *root;

//    public:
//     int count;

//     Trie() {
//         this->count = 0;
//         root = new TrieNode('\0');
//     }

//     bool insertWord(TrieNode *root, string word) {
//         // Base case
//         if (word.size() == 0) {
//             if (!root->isTerminal) {
//                 root->isTerminal = true;
//                 return true;
//             } else {
//                 return false;
//             }
//         }

//         // Small calculation
//         int index = word[0] - 'a';
//         TrieNode *child;

//         if (root->children[index] != NULL) {
//             child = root->children[index];
//         } else {
//             child = new TrieNode(word[0]);
//             root->children[index] = child;
//         }

//         // Recursive call
//         return insertWord(child, word.substr(1));
//     }

//     void insertWord(string word) {
//         if (insertWord(root, word)) {
//             this->count++;
//         }
//     }

//     void autoComplete(vector<string> input, string pattern) {
//         // Write your code here
//     }
// };


class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    
    TrieNode *findword(TrieNode* root, string word){
        if(word.length() == 0){
            return root;
        }
        int childIndex = word[0] - 'a';
        TrieNode * child = root -> children[childIndex];
        if(child == NULL){
            return NULL; 
        }
        return findword(child, word.substr(1));
    }
    
    void allwords(TrieNode * root, string word, string output){
        int count = 0;
        for(int i = 0; i < 26; i ++){
            if(root -> children[i] != NULL){
                count++;
                break;
            }
        }
        if(count == 0){
            if(output.length() > 0){
                string ans = word + output;
                cout << ans << endl;
            }
            return;
        }
        if(root -> isTerminal == true) {
            string ans = word + output;
            cout << ans << endl;
        }

        for(int i = 0; i < 26; i++) {
            if(root -> children[i] != NULL) {
                TrieNode * s = root -> children[i];
                char sa = s -> data;
                string ans = output + sa; 
                allwords(root -> children[i], word, ans);
            }
       }
    }

    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
        for(int i = 0; i < input.size(); i++){
            insertWord(input[i]);
        }
        TrieNode * a = findword(root, pattern);
        if( a == NULL){
            return;
        }
        string output = ""; 
        allwords(a, pattern, output); 
    }
};
