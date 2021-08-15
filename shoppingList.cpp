#include "shoppingList.h"
#include "main.h"

void addToList() {
    std::cout << "Gebe nun ein, was du zu deiner Einkaufsliste hinzufügen willst." << std::endl;
    std::string input;
    std::cin >> input;
    add(input);
    std::cout << "Du hast erfolgreich " << input << " zu deiner Einkaufsliste hinzugefügt" << std::endl;

    Sleep(2000);
    menu();
}

void readList() {
    std::string l;
    for (auto & i : getList()) {
        l.append(i).append(" ");
    }
    std::cout << "Deine Einkaufsliste:\n" << l << std::endl;
    Sleep(2000);
    menu();
}

void clearList() {
    clear();
    std::cout << "Die Einkaufsliste wurde gelöscht!" << std::endl;
    Sleep(2000);
    menu();
}


void loadList() {
    std::fstream file;
    file.open(path, std::ios::in);
    std::string l;
    getline(file, l);
    add(l);
    std::cout << "Die Einkaufsliste wurde erfolgreich geladen";
    menu();
}
