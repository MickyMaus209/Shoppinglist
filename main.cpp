#include "main.h"
#include "shoppingList.h"

std::vector<std::string> list;

void quit() {
    std::string l;
    for (auto & i : getList()) {
        l.append(i).append(" ");
    }
    std::ofstream outfile(path);;
    outfile << l << std::endl;
    outfile.close();
    getList().clear();
}

void menu() {
    std::cout
            << "(0): Etwas zur Einkaufsliste hinzufügen\n(1): Einkaufsliste lesen\n(2): Einkaufsliste löschen\n(3/q/s): Beenden und speichern"
            << std::endl;
    char input = ' ';
    std::cin >> input;
    switch (input) {
        case '0':
            addToList();
            break;
        case '1':
            readList();
            break;
        case '2':
            clearList();
            break;
        case '3':
        case 'q':
        case 's':
            quit();
            break;
        default:
            menu();
            break;
    }
}

void add(std::string push){
    list.push_back(push);
}

void clear(){
    list.clear();
}

std::vector<std::string> getList(){
    return list;
}

int main() {
    loadList();
    return 0;
}
