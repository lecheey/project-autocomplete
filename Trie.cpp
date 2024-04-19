#include <iostream>
#include <string>
#include "Trie.h"

TrieNode* TrieNode::getNewNode(void){ // Возвращает новый узел с пустыми детьми
	struct TrieNode *pNode =  new TrieNode; // Выделяем память под новый узел

	pNode->isEndOfWord = false;// устанавливаем флаг конца слова в false
	
	for (int i = 0; i < ALPHABET_SIZE; i++){
		pNode->children[i] = nullptr;
	}
	return pNode;
}

void TrieNode::insert(TrieNode* root, std::string key){
    TrieNode* current = root;

    for(int i = 0; i < key.length(); i++){
        int ind = key[i] - 'a';
        if(current->children[ind] == nullptr){
            current->children[ind] = getNewNode();
        }
        
		current = current->children[ind];
		current->count++;
    }
    current->isEndOfWord = true;
}

void TrieNode::autocomplete(TrieNode* root, WordList& list,std::string search, std::string& res, char buf[], int ind){
	if(!root){ return; } // проверка рута

	if(root->isEndOfWord){ // если дошли до конца слова, то сохраняем его
        buf[ind] = '\0';
 //       res.append(buf);
//        res.push_back(' ');
		std::string temp;
		temp.append(buf); // сохранение данных буфера в переменную		
		list.addWord(temp); // перенос данных в массив для последующего доступа
		return;
	}
	
	if(ind < search.size()){ // ищем совпадения с входными данными и записываем их в буфер
		for(int i = 0; i < ALPHABET_SIZE; i++){
			if(root->children[i] != nullptr && (i + 'a') == search[ind]){
				buf[ind] = i + 'a';
				autocomplete(root->children[i], list, search, res, buf, ind + 1);
			}
		}
	}
	else if(ind >= search.size()){ // если сохранили все входные данные, ищем возможные варианты слов
		for(int i = 0; i < ALPHABET_SIZE; i++){
			if(root->children[i] != nullptr){
				buf[ind] = i + 'a';
				autocomplete(root->children[i], list, search, res, buf, ind + 1);
			}
		}
	}
}

void WordList::addWord(std::string word){ // сохранение слова в массив
	if(wordcount < 5){
		wordlist[wordcount] = word;
		wordcount++;
	}
}

std::string WordList::getWord(int index){ // получение слова
	return wordlist[index];
}
