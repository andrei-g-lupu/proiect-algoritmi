#include <iostream>
#include <fstream>
#include <vector>

struct Person {
    std::string name;
    int age;
};

void printMenu() {
    std::cout << "1. Adauga persoana\n";
    std::cout << "2. Afiseaza persoanele\n";
    std::cout << "3. Salveaza persoanele in fisier\n";
    std::cout << "4. Iesire\n";
    std::cout << "Introduceti optiunea dorita: ";
}

void addPerson(std::vector<Person>& people) {
    Person person;
    std::cout << "Introduceti numele persoanei: ";
    std::cin >> person.name;
    std::cout << "Introduceti varsta persoanei: ";
    std::cin >> person.age;
    people.push_back(person);
    std::cout << "Persoana adaugata cu succes!\n";
}

void displayPeople(const std::vector<Person>& people) {
    if (people.empty()) {
        std::cout << "Nu exista persoane de afisat.\n";
    } else {
        std::cout << "Persoanele existente:\n";
        for (const auto& person : people) {
            std::cout << "Nume: " << person.name << ", Varsta: " << person.age << "\n";
        }
    }
}

void savePeopleToFile(const std::vector<Person>& people, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& person : people) {
            file << person.name << " " << person.age << "\n";
        }
        std::cout << "Persoanele au fost salvate in fisierul " << filename << "\n";
    } else {
        std::cout << "Nu s-a putut deschide fisierul " << filename << " pentru scriere!\n";
    }
}

int main() {
    std::vector<Person> people;
    int option;
    std::string filename = "people.txt";

    do {
        printMenu();
        std::cin >> option;

        switch (option) {
            case 1:
                addPerson(people);
                break;
            case 2:
                displayPeople(people);
                break;
            case 3:
                savePeopleToFile(people, filename);
                break;
            case 4:
                std::cout << "La revedere!\n";
                return 0; // Adăugăm un return 0 pentru a ieși din program când se alege opțiunea 4
            default:
                std::cout << "Optiune invalida. Va rugam selectati o optiune valida.\n";
        }
    } while (true); // Modificăm condiția buclei while pentru a continua până la return 0

    return 0;
}

