// Цей файл містить функцію "main". Тут починається та закінчується виконання програми.

#include <iostream>
#include <windows.h>
#undef min
#undef max
#include "TouristQuide.h"
#include "HotTrips.h"
#include "CountryTrips.h"

void mainMenu();
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    mainMenu();

}

void mainMenu() {
    int action, numGuide;
    TouristQuide* quide;
    cout << "Виберіть тип екскурсовода: \n";
    cout << "1 - Гарячі подорожі: \n";
    cout << "2 - Подорожі по країні: \n:> ";

    cin >> numGuide;
    if (numGuide == 1) {
        double discount;
        cout << "Введіть знижку: ";
        cin >> discount;
        quide = new HotTrips(discount);
    }
    else {
        string country;
        cout << "Введіть країну: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, country);
        quide = new CountryTrips(country);
    }
    string value;
    while (1 == 1) {
        cout << "Виберіть дію:\n";
        cout << "0 - Вихід\n";
        cout << "1 - Додати нове місце\n";
        cout << "2 - Пошук місця за назвою\n";
        cout << "3 - Пошук місця за категорією\n";
        cout << "4 - Пошук місця за розташуванням\n";
        cout << "5 - Повний список місць\n";
        cin >> action;
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

        switch (action) {
        case 0:
            return;
            break;
        case 1:
            quide->addPlace();
            break;
        case 2:
            cout << "Введіть назву місця: ";
            getline(cin, value);
            try {
                quide->searchPlaceByTitle(value);
            }
            catch (NoSearchedPlace& e) {
                cerr << "Помилка: " << e.what() << endl;
            }
            break;
        case 3:
            cout << "Введіть категорію місця: ";
            getline(cin, value);
            try {
                quide->searchPlacesByCategory(value);
            }
            catch (NoSearchedPlace& e) {
                cerr << "Помилка: " << e.what() << endl;
            }
            break;
        case 4:
            cout << "Введіть розташування місця: ";
            getline(cin, value);
            try {
                quide->searchPlacesByLocation(value);
            }
            catch (NoSearchedPlace& e) {
                cerr << "Помилка: " << e.what() << endl;
            }
            break;
        case 5:
            quide->printAllPlaces();
            break;
        default:
            cout << "Дія не визначена\n";
            break;
        }
        system("pause");
        system("cls");

    }

    delete quide;
}