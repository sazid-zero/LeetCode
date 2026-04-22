struct TrieNode {
    bool isEnd;
    TrieNode* children[26];
    TrieNode() : isEnd(false) {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    TrieNode* root;

    bool dfs(const string& word, int pos, TrieNode* node) {
        if (!node) return false;
        if (pos == (int)word.size()) return node->isEnd;

        char ch = word[pos];
        if (ch == '.') {
            for (int i = 0; i < 26; ++i) {
                if (node->children[i] && dfs(word, pos + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int idx = ch - 'a';
            return dfs(word, pos + 1, node->children[idx]);
        }
    }
};