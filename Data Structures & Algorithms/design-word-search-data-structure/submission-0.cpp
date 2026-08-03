class TrieNode {
public:
    unordered_map<char,TrieNode*> child;
    bool eof = false;
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        TrieNode* dotNode = root;
        for(auto c : word) {
            if(curr->child.find(c) == curr->child.end()) curr->child[c] = new TrieNode();
            if(dotNode->child.find(c) == curr->child.end()) dotNode->child[c] = curr->child[c];
            if(curr->child.find('.') == curr->child.end()) curr->child['.'] = new TrieNode();
            if(dotNode->child.find('.') == dotNode->child.end()) dotNode->child['.'] = curr->child['.'];
            
            dotNode = curr->child['.'];
            curr = curr->child[c];
        }
        dotNode->eof = true;
        curr->eof = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(auto c : word) {
            if(curr->child.find(c) == curr->child.end()) return false;
            curr = curr->child[c];
        }
        return curr->eof;
    }
};
