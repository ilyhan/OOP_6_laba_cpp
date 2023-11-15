#include <iostream>
#include <fstream>
#include "List.h"
#include "Node.h"
#include "iterator.h"
//using namespace std;


int main() {
    setlocale(LC_ALL, "RU");
    List<int> new_list_1;
    List<int> new_list_2;
    int n, k;
    std::cout << "Введите количество элементов первого списка\n";
    std::cin >> n;
    std::cout << "Введите первый список\n";
    for (int i = 0; i < n; i++) {
        std::cin >> k;
        new_list_1.append(k);
    }

    std::cout << "Введите количество элементов вторго списка\n";
    std::cin >> n;
    std::cout << "Введите второй список\n";
    for (int i = 0; i < n; i++) {
        std::cin >> k;
        new_list_2.append(k);
    }

    std::cout << "List 1: ";
    std::cout<<new_list_1;

    std::cout << "List 2: ";
    std::cout << new_list_2;

    bool fl = true;
    int i;
    iterator<int> iter = new_list_1.begin();
   
    while (fl) {
        std::cout << "\n1 - удалить i-ый элемент из первого списка\n" << "2 - вставить перед i-ым элементом в первом списке\n"\
            << "3 - слияние списков\n" << "4 - слиние упорядоченных списков\n" << std::endl;
        std::cin >> k;
        switch (k) {
        case 1:
            iter = new_list_1.begin();
            std::cout << "Введите i " << std::endl;
            std::cin >> i;
            iter = iter + (i - 1);
            new_list_1.remove(iter);
            break;
        case 2:
            iter = new_list_1.begin();
            std::cout << "Введите i " << std::endl;
            std::cin >> i;
            std::cout << "Введите число, которое вставляем " << std::endl;
            int c;
            std::cin >> c;
            iter = iter + (i - 1);
            new_list_1.insert(c, iter);
            break;
        case 3:
            new_list_1.merge(new_list_2);
            break;
        case 4:
            new_list_1.mergeOrdered(new_list_2);
            break;
        default:
            fl = false;
        }
        std::cout << "List 1: " << new_list_1;
    }
}