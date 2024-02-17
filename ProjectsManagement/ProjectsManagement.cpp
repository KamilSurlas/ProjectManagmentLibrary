#include <iostream>

#include "CustomAllocator.h"
#include "User.h"
#include "ProjectManager.h"
#include "FileHandler.h"
#include "Project.h"


int main()
{

    ProjectManager* projectManager = ProjectManager::getInstance();
    Project storeApplication = projectManager->createProject("Store application in .NET", "Creating an application for a clothing store", Date(1, 3, 2024, 00, 00), Date(30, 7, 2024, 00, 00));
    Task database("Prepare Databse structure", "Prepare database strcuture for store using Entity Framework Core", Date(1, 3, 2024, 00, 00), Date(30, 3, 2024, 00, 00));
        projectManager->assignTaskToProject(storeApplication,database);
    Task API = projectManager->assignTaskToProject("Prepare API", "Write an API for entities", Date(1, 4, 2024, 00, 00), Date(30, 4, 2024, 00, 00), storeApplication);
    Task basic = projectManager->assignTaskToProject("Write basic functionalities", "Create authorization and authentication mechanism", Date(1, 5, 2024, 00, 00), Date(30, 5, 2024, 00, 00), storeApplication);
    Task adv = projectManager->assignTaskToProject("Write advanced functionalities", "Create pay mechanism", Date(1, 6, 2024, 00, 00), Date(30, 6, 2024, 00, 00),storeApplication);
    Task GUI = projectManager->assignTaskToProject("Make nice looking GUI", "Create GUI", Date(1, 7, 2024, 00, 00), Date(15, 7, 2024, 00, 00), storeApplication);
    Task tests = projectManager->assignTaskToProject("Test application", "Write tests for application", Date(15, 7, 2024, 00, 00), Date(30, 7, 2024, 00, 00),storeApplication);

    User programista1("Michal", "Wilkosz", "michalwilkosz1234@wp.pl", "michwil");
    User programista2("Kamil", "Surlas", "kamilsurlas1234@wp.pl", "kamsur");
    User programista3("Marcin", "Kowalski", "marcinkowalski@wp.pl", "markow");
    User programista4("Bartosz", "Nowak", "bartosznowak@wp.pl", "barnow");

    User kierownik1("Michal", "Kowalski", "michalkowalski@wp.pl", "michkow");
    User kierownik2("Szymon", "Dziendzielowski", "szymondziendzielowski@wp.pl", "szydzi");

    projectManager->assignManagerToProject(storeApplication,kierownik1);
    projectManager->assignUserToProject(storeApplication, programista1);
    projectManager->assignUserToProject(storeApplication, programista2);
    projectManager->assignUserToProject(storeApplication, programista3);
    projectManager->assignUserToProject(storeApplication, programista4);

    projectManager->assignLeaderToTask(storeApplication, database, programista1);
    projectManager->assignUserToTask(storeApplication, database, programista2);

    projectManager->assignLeaderToTask(storeApplication, API, programista1);
    projectManager->assignUserToTask(storeApplication, API, programista2);
    projectManager->assignUserToTask(storeApplication, API, programista3);

    projectManager->assignLeaderToTask(storeApplication, basic, programista1);
    projectManager->assignUserToTask(storeApplication, basic, programista3);
    projectManager->assignUserToTask(storeApplication, basic, programista4);

    projectManager->assignLeaderToTask(storeApplication, adv, programista1);
    projectManager->assignUserToTask(storeApplication, adv, programista2);
    projectManager->assignUserToTask(storeApplication, adv, programista3);
    projectManager->assignUserToTask(storeApplication, adv, programista4);
    
    projectManager->assignLeaderToTask(storeApplication, GUI, programista2);
    projectManager->assignUserToTask(storeApplication, GUI, programista4);

    projectManager->assignLeaderToTask(storeApplication, tests, programista3);
    projectManager->assignUserToTask(storeApplication, tests, programista4);

    //cout << projectManager->printProject(storeApplication);

    FileHandler::saveCSVFile();
 
}

