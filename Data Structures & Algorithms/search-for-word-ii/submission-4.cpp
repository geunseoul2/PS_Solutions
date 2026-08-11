class TrieNode {
public:
    unordered_map<char,TrieNode*> child;
    bool eof = false;
};


class Solution {
public:
    vector<string> ans;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for(auto word : words) { //Insert the words to Trie
            TrieNode* curr = root;
            for(auto c : word) {
                if(curr->child.find(c) == curr->child.end()) curr->child[c] = new TrieNode();
                curr = curr->child[c];
            }
            curr->eof = true;
        }

        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                string word;
                vector<vector<bool>> used(m, vector<bool>(n,false));
                if(root->child.find(board[i][j]) != root->child.end()) {
                    word.push_back(board[i][j]);
                    findAword(root->child[board[i][j]],board,word,i,j,used);
                }
            }
        }

        return ans;
    }

    void findAword(TrieNode* curr, vector<vector<char>>& board, string word, int i, int j, vector<vector<bool>>& used) {
        used[i][j] = true;
        
        if(curr->eof) {
            ans.push_back(word);
            curr->eof = false;
        }
        
        int m = board.size();
        int n = board[0].size();

        if(i > 0 && !used[i-1][j] && curr->child.find(board[i-1][j]) != curr->child.end()) {
            word.push_back(board[i-1][j]);
            findAword(curr->child[board[i-1][j]],board,word,i-1,j,used);
            word.pop_back();
        }
        if(i < m-1 && !used[i+1][j] && curr->child.find(board[i+1][j]) != curr->child.end()) {
            word.push_back(board[i+1][j]);
            findAword(curr->child[board[i+1][j]],board,word,i+1,j,used);
            word.pop_back();
        }
        if(j > 0 && !used[i][j-1] && curr->child.find(board[i][j-1]) != curr->child.end()) {
            word.push_back(board[i][j-1]);
            findAword(curr->child[board[i][j-1]],board,word,i,j-1,used);
            word.pop_back();
        }
        if(j < n-1 && !used[i][j+1] &&  curr->child.find(board[i][j+1]) != curr->child.end()) {
            word.push_back(board[i][j+1]);
            findAword(curr->child[board[i][j+1]],board,word,i,j+1,used);
            word.pop_back();
        }

        used[i][j] = false;
    }
};
