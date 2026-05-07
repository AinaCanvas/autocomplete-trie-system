#ifndef TRIE_H
#define TRIE_H

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    int frequency;

    TrieNode();
};

struct Suggestion {
    char word[50];
    int freq;
};

class Trie {
private:
    TrieNode* root;

    void collectSuggestions(TrieNode* node, char currentWord[],
                            int level, Suggestion suggestions[],
                            int &count);

    void sortSuggestions(Suggestion suggestions[], int count);

public:
    Trie();

    void insert(const char* word);
    void autocomplete(const char* prefix);
    void loadFromFile(const char* filename);
};

#endif
