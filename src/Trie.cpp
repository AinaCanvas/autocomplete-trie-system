#include "Trie.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_SUGGESTIONS = 100;

TrieNode::TrieNode() {
    isEnd = false;
    frequency = 0;
    for (int i = 0; i < 26; i++)
        children[i] = NULL;
}

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const char* word) {
    TrieNode* temp = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (temp->children[index] == NULL)
            temp->children[index] = new TrieNode();

        temp = temp->children[index];
    }

    temp->isEnd = true;
    temp->frequency++;
}

void Trie::collectSuggestions(TrieNode* node, char currentWord[],
                              int level, Suggestion suggestions[],
                              int &count) {
    if (node == NULL) return;

    if (node->isEnd) {
        currentWord[level] = '\0';
        strcpy(suggestions[count].word, currentWord);
        suggestions[count].freq = node->frequency;
        count++;
    }

    for (int i = 0; i < 26; i++) {
        if (node->children[i] != NULL) {
            currentWord[level] = 'a' + i;
            collectSuggestions(node->children[i],
                               currentWord,
                               level + 1,
                               suggestions,
                               count);
        }
    }
}

void Trie::sortSuggestions(Suggestion suggestions[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (suggestions[j].freq < suggestions[j + 1].freq) {
                Suggestion temp = suggestions[j];
                suggestions[j] = suggestions[j + 1];
                suggestions[j + 1] = temp;
            }
        }
    }
}

void Trie::autocomplete(const char* prefix) {
    TrieNode* temp = root;

    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';

        if (temp->children[index] == NULL) {
            cout << "No suggestions found.\n";
            return;
        }

        temp = temp->children[index];
    }

    Suggestion suggestions[MAX_SUGGESTIONS];
    int count = 0;
    char currentWord[50];

    strcpy(currentWord, prefix);

    collectSuggestions(temp, currentWord, strlen(prefix),
                       suggestions, count);

    sortSuggestions(suggestions, count);

    cout << "\nSuggestions:\n";
    for (int i = 0; i < count; i++) {
        cout << suggestions[i].word
             << " (freq: " << suggestions[i].freq << ")\n";
    }
}

// Load dictionary file
void Trie::loadFromFile(const char* filename) {
    ifstream file(filename);
    char word[50];

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    while (file >> word) {
        insert(word);
    }

    file.close();
}
