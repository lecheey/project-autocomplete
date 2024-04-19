Проект реализации функции подсказок при наборе текста.
В программе реализована функция подбора слов из словаря на основе вводимой пользователем информации.
Функция разбита на два блока: один блок отвечает за создание префиксного дерева, а второй - массива для хранения полученных совпадений.
Для поиска совпадений и спользуюет рекурсивныйц метод, в который передаются вводимы пользователем символы. При достижении конца слова, оно сохраняется в массив, который вводится через соответствующий класс. По умолчанию массив не может содержать больше 5 результатов.
При наличии совпадений пользавателю возвращаются возможные варианты. Пользователь также может продолжить вводить слово, например, если искомый вариант не был получен.
Для краткости в программе реализованы минимально необходимые функции класса: добавление и поиск элементов.