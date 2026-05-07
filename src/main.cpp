#include <iostream>
#include "Trie.h"
using namespace std;

int main() {
    Trie trie;

    // Load dataset
    trie.loadFromFile("data/dictionary.txt");

    int choice;
    char word[50];

    while (true) {
        cout << "\n1. Search\n2. Insert\n3. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter prefix: ";
            cin >> word;
            trie.autocomplete(word);
            break;

        case 2:
            cout << "Enter word: ";
            cin >> word;
            trie.insert(word);
            cout << "Inserted successfully!\n";
            break;

        case 3:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
