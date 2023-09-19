#include <iostream>
#include <string>
#include "List.h"


int main()
{
    List<int> myList;;
    myList.insert(1); //добавление элемента в список
    myList.insert(2);
    myList.insert(3);
    myList.insert(2); //этот элемент уже есть в списке, поэтому не добавится
    
    std::cout << "myList: ";
    for (int i = 0; i < myList.GetSize(); ++i) {
        std::cout << myList[i] << " ";
    }
    std::cout << std::endl;
    
    myList.remove(2); //удаление элемента со значением 2 из списка

    std::cout << "myList: ";
    for (int i = 0; i < myList.GetSize(); ++i) {
        std::cout << myList[i] << " ";
    }
    std::cout << std::endl;

    bool isFound = myList.search(2); //поиск элемента со значением 2 в списке
    std::cout << "isFound: " << isFound << std::endl;

    List<int> myList1;
    myList1.insert(1);
    myList1.insert(2);
    myList1.insert(3);

    std::cout << "myList1 ";
    for (int i = 0; i < myList1.GetSize(); ++i) {
        std::cout << myList1[i] << " ";
    }
    std::cout << std::endl;

    List<int> myList2;
    myList2.insert(4);
    myList2.insert(5);
    myList2.insert(6);

    std::cout << "myList2 ";
    for (int i = 0; i < myList2.GetSize(); ++i) {
        std::cout << myList2[i] << " ";
    }
    std::cout << std::endl;

    myList1.merge(myList2); //объединение списков myList1 и myList2


    std::cout << "myList1 ";
    for (int i = 0; i < myList1.GetSize(); ++i) {
        std::cout << myList1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "myList2 ";
    for (int i = 0; i < myList2.GetSize(); ++i) {
        std::cout << myList2[i] << " ";
    }
    std::cout << std::endl;

    myList2.insert(4);
    myList2.insert(2);

    std::cout << "myList2 ";
    for (int i = 0; i < myList2.GetSize(); ++i) {
        std::cout << myList2[i] << " ";
    }
    std::cout << std::endl;

    myList1.deleteList(myList2); //удаление из списка myList1 всех элементов, которые есть в списке myList2

    std::cout << "myList2 ";
    for (int i = 0; i < myList1.GetSize(); ++i) {
        std::cout << myList1[i] << " ";
    }
    std::cout << std::endl;

    myList1.insert(4);
    myList1.insert(2);
    std::cout << "myList1 ";
    for (int i = 0; i < myList1.GetSize(); ++i) {
        std::cout << myList1[i] << " ";
    }

    std::cout << std::endl;
    List<int> list3;
    list3.insert(1);
    list3.insert(2);
    list3.insert(3);
    list3.insert(4);
    list3.insert(5);

    List<int> list4;
    list4.insert(3);
    list4.insert(4);
    list4.insert(5);
    list4.insert(6);
    list4.insert(7);

    List<int> intersect = getIntersection(list3, list4);

    std::cout << "Intersection of lists: ";
    for (int i = 0; i < intersect.GetSize(); ++i) {
        std::cout << intersect[i] << " ";
    }
    std::cout << std::endl;
    return 0;
    

   
    
        
}

