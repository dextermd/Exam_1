#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string.h>
#include <ctime>    
#include <algorithm>
#include "str_func.h"
#include "my_template.h"
#include "Data.h"
#include "Todo.h"

using namespace std;

int main()
{
    

#if 0

    /*
        Написать программу, фильтрующую текст, введенный с клавиатуры.
        Задача программы заключается в считывании текста и отображении его на экране,
        используя замену заданного набора символов на пробелы.

            Программа должна предлагать следующие варианты наборов символов для фильтрации :
                − Символы латинского алфавита
                − Символы кириллицы
                − Символы пунктуации
                − Цифры

        Фильтры могут накладываться последовательно.
        При повторной установке существующего фильтра данный фильтр должен сниматься.
        Использовать цветной вывод символов по фильтрам для наглядности.

        Для определения является ли символ строки символом латинского алфавита, символом
        кириллицы, символом пунктуации либо цифрой написать и использовать пользовательские
        функции.
    */

    //char str[100] = "Hello, Привет, (!@#$%), 777.";

    char buf[200];
    cout << "\nВведите строку: ";
    cin.getline(buf, sizeof(buf));
    char* str = new char[strlen(buf) + 1];

    if (str)
    {
        strcpy_s(str, strlen(buf) + 1, buf);
        char str_cpy[100];

        int menu = 0;
        strcpy_s(str_cpy, str);

        do
        {
            show_str_color(str);

            cout << "\n\nВыберите пункт меню:\n\n";
            cout << "1. Фильтр символов латинского алфавита\n";
            cout << "2. Фильтр кириллицы\n";
            cout << "3. Фильтр пунктуации\n";
            cout << "4. Фильтр цифр\n\n";
            cout << "5. Выход\n\n";

            cout << "Введите номер меню от 1 до 5: ";
            cin >> menu;

            switch (menu)
            {
            case 1:
                system("cls");
                str_filter(str, str_cpy, is_latin);
                break;
            case 2:
                system("cls");
                str_filter(str, str_cpy, is_сyrillic);
                break;
            case 3:
                str_filter(str, str_cpy, is_punctuation);
                system("cls");
                break;
            case 4:
                system("cls");
                str_filter(str, str_cpy, is_num_d);
                break;
            case 5:
                system("cls");
                menu = 5;
                cout << "\nВы вышли!\n";
                break;
            }

        } while (menu != 5);

        delete[]str;
        str = nullptr;
    }


#endif

#if 1
    using namespace std;
    /*
        Приложение должно позволять :

            Добавление дел.У дела есть :
                • название.
                • приоритет.
                • описание.
                • дата, время исполнения.

            Удаление дел.

            Редактирование дел.

            Поиск дел по :
                • названию.
                • приоритету.
                • описанию.
                • дате и времени исполнения.

            Отображение списка дел :
                • на день.
                • на неделю.
                • на месяц.

            При отображении должна быть возможность сортировки :
                • по приоритетy.
                • по дате и времени исполнения.
    */
    int index = 0, size = 1, menu = 1, id = -1;
    Todo* todo;
    todo = new Todo[size];


    do
    {
        cout << "\n\nВыберите пункт меню:\n\n";
        cout << "1. Создать дело\n";
        cout << "2. Показать весь список дел\n";
        cout << "3. Удаление дел\n";


        cout << "\n\nВведите номер меню от 1 до 2: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            if (index < size)
            {
                init(todo, index);
                index++;
                system("cls");
            }
            else {
                size += 1;
                Todo* new_todo = new Todo[size]; 
                copy(todo, todo + size - 1 , new_todo);
                delete[] todo; 
                todo = new_todo;
                init(todo, index);
                index++;
              system("cls");
            }
            break;        
        case 2:
            system("cls");
            show(todo, size);
            break;
        case 3:
            system("cls");
            show(todo, size);
            cout << "\nВыберите ID для удаления:";
            cin >> id;
            //if (res)
            //{
            //    for (int i = 0; i < index; i++)
            //    {
            //        res[i] = m[i];
            //    }

            //    for (int i = index; i < size; i++)
            //    {
            //        res[i + 1] = m[i];
            //    }
            //    res[index] = value;
            //}

            if (id -1 > 0)
            {
                size -= 1;
                Todo* delete_todo = new Todo[size];
                for (int i = 0; i < id - 1  ; i++)
                {
                    delete_todo[i] = todo[i];
                }

                for (int i = id + 1; i < size + 1 ; i++)
                {
                    delete_todo[i - 1] = todo[i];
                }
                

                for (int i = 0; i < size - 1; i++)
                {
                    todo[i] = delete_todo[i];
                }

                index--;
            }

            break;
        case 4: 
            break;
        }
    } while (menu != 10);


  
#endif


    _getch();
}