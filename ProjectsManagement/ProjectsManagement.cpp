#include <iostream>

#include "CustomAllocator.h"
#include "CustomAllocator.cpp"

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


   // t->createTask("d", dat, dat);
   // t->createFile();
    //FileHandler::saveFile(xd);
    //Task task("XD", "xd", )
    
}

