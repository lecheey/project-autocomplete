#include <iostream>
#include <string>
#include "Trie.h"

int main(){

	// создаем дерево и словарь
	TrieNode *_root = new TrieNode();
    
	_root->insert(_root, std::string("information"));
    _root->insert(_root, std::string("informatics"));
    _root->insert(_root, std::string("intermediate"));
    _root->insert(_root, std::string("intervention"));
    _root->insert(_root, std::string("interpreter"));
    _root->insert(_root, std::string("algorithm"));
    _root->insert(_root, std::string("alcohol"));
    _root->insert(_root, std::string("alley"));
    _root->insert(_root, std::string("allocation"));
    _root->insert(_root, std::string("allegory"));
    _root->insert(_root, std::string("alligator"));
	
	
	// начинаем вводить слово
	char choice;
	
	// цикл работы программы
	while(true){
		std::string search; // искомое слово
		std::cout << "Введите несколько букв слова: ";
		bool loop = true;
		
		// цикл ввода слова
		while(loop){
			std::cout << search;
			std::string s;
			std::cin >> s;
			search += s; // постепенно добавляем буквы

			std::cout << "возможные варианты:\n";
	
			WordList _list; // сюда сохраняем список возможных вариантов (не более 5 вариантов)

			char *buf = new char[20];
			std::string res;
			_root->autocomplete(_root, _list, search, res, buf, 0); // функция поиска для автозаполнения
			
			for(int i = 0; i < _list.wordcount; i++){ // вывод найденных совпадений
				std::cout << _list.getWord(i) << " | ";
			}

			if(_list.wordcount == 0){
				std::cout << _list.getWord(0);
			}
			
			std::cout << '\n' << '\n';
			std::cout << "выберите номер нужного слова; [c]ontinue для продолжения ввода; [q]uit для выхода: ";	
			std::cin >> choice;
			
			if(choice == 'q'){ break; } // завершение цикла
			switch(choice){ // вывод одного из полученных результатов
				case '1':
					std::cout << _list.getWord(0) << '\n';
					loop = false;
					break;
				case '2':
					std::cout << _list.getWord(1) << '\n';
					loop = false;
					break;
				case '3':
					std::cout << _list.getWord(2) << '\n';
					loop = false;
					break;
				case '4':
					std::cout << _list.getWord(3) << '\n';
					loop = false;
					break;
				case '5':
					std::cout << _list.getWord(4) << '\n';
					loop = false;
					break;
				case 'c':
					break;
				default:
					break;
			}
		}
		std::cout << "\nначать заново? y/n ";
		std::cin >> choice;
		if(choice == 'n'){ break; }
	}	

	return 0;
}
