#include <iostream>
#include <string>
#define ALPHABET_SIZE 26

// класс массива полученных совпадений
struct WordList{
	std::string *wordlist{};
	int wordcount = 0;

	WordList(){
		wordlist = new std::string[5];
	}
	~WordList(){
		delete[] wordlist;
	}

	void addWord(std::string word);
	std::string getWord(int index);
};

// класс префиксного дерева
struct TrieNode{
	struct TrieNode *children[ALPHABET_SIZE];
	bool isEndOfWord;
	int count;
	
	TrieNode* getNewNode(void);
	void insert(TrieNode* root, std::string key);

	void autocomplete(TrieNode* root, WordList& list,std::string search, std::string& res, char buf[], int ind);
};
