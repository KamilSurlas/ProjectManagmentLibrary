#include <iostream>

#include "CustomAllocator.h"
#include "CustomAllocator.cpp"
#include "User.h"

int main()
{

    //TaskManager* t = TaskManager::getInstance();

    CustomAllocator<int, 5> allocator;

    // Dodajemy kilka elementów
    for (int i = 0; i < 5; ++i) {
        allocator.addElement(i);
    }

     //Wyświetlamy elementy za pomocą operatora indeksowania
    std::cout << "Elements in Allocator: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << allocator[i] << " ";
    }
    std::cout << std::endl;

     //Testujemy usuwanie elementu
    int elementToRemove = 3;
    if (allocator.removeElement(elementToRemove)) {
        std::cout << "Element " << elementToRemove << " removed successfully." << std::endl;
    }
    else {
        std::cout << "Element " << elementToRemove << " not found." << std::endl;
    }

    // Wyświetlamy aktualne elementy
    std::cout << "Elements in Allocator after removal: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << allocator[i] << " ";
    }
    std::cout << std::endl;

    CustomAllocator<User> allocator2;

    User u1("m", "w", "xdd@wp.pl", "koks");
    User u2("xd", "xd", "xdd2@wp.pl", "koks");
    try {
        allocator2.addElement(u1);
        allocator2.addElement(u1);
    }
    catch (std::invalid_argument s) {
        std::cout << s.what();
    }
    allocator2.addElement(u2);

    
    /*for (int i = 0; i < 3; ++i) {
        std::cout << &allocator2[i] << "\n";
    }

    allocator2.removeElement(u2);
    std::cout << "\nDDDDDD:\n";
    for (int i = 0; i < 2; ++i) {
        std::cout << &allocator2[i] << "\n";
    }*/

}

