#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Religion {
protected:
    string name;
    string sacredBook;
    string bookDescription;
    int bookCreationYear;

public:
    Religion(const string& name, const string& sacredBook, const string& bookDescription, int bookCreationYear)
        : name(name), sacredBook(sacredBook), bookDescription(bookDescription), bookCreationYear(bookCreationYear) {}

    virtual ~Religion() {}

    string getName() const {
        return name;
    }

    string getSacredBook() const {
        return sacredBook;
    }

    virtual void displayInfo() const = 0;
};

class Hinduism : public Religion {
public:
    Hinduism() : Religion("Hinduism", "Vedas", "Ancient scriptures containing hymns, philosophy, and guidance on ritual.", -1500) {}

    void displayInfo() const override {
        cout << "Religion: " << name << endl;
        cout << "Sacred Book: " << sacredBook << endl;
        cout << "Description: " << bookDescription << endl;
        cout << "Creation Year: " << bookCreationYear << " BCE" << endl;
    }
};

class Buddhism : public Religion {
public:
    Buddhism() : Religion("Buddhism", "Tripitaka", "The traditional term for Buddhist scriptures.", -29) {}

    void displayInfo() const override {
        cout << "Religion: " << name << endl;
        cout << "Sacred Book: " << sacredBook << endl;
        cout << "Description: " << bookDescription << endl;
        cout << "Creation Year: " << bookCreationYear << " BCE" << endl;
    }
};

class Confucianism : public Religion {
public:
    Confucianism() : Religion("Confucianism", "Analects", "A collection of sayings and ideas attributed to Confucius.", -475) {}

    void displayInfo() const override {
        cout << "Religion: " << name << endl;
        cout << "Sacred Book: " << sacredBook << endl;
        cout << "Description: " << bookDescription << endl;
        cout << "Creation Year: " << bookCreationYear << " BCE" << endl;
    }
};

class Taoism : public Religion {
public:
    Taoism() : Religion("Taoism", "Tao Te Ching", "A fundamental text for both philosophical and religious Taoism.", -400) {}

    void displayInfo() const override {
        cout << "Religion: " << name << endl;
        cout << "Sacred Book: " << sacredBook << endl;
        cout << "Description: " << bookDescription << endl;
        cout << "Creation Year: " << bookCreationYear << " BCE" << endl;
    }
};

class Judaism : public Religion {
public:
    Judaism() : Religion("Judaism", "Tanakh", "The canonical collection of Jewish texts.", -500) {}

    void displayInfo() const override {
        cout << "Religion: " << name << endl;
        cout << "Sacred Book: " << sacredBook << endl;
        cout << "Description: " << bookDescription << endl;
        cout << "Creation Year: " << bookCreationYear << " BCE" << endl;
    }
};

class Islam : public Religion {
public:
    Islam() : Religion("Islam", "Quran", "The holy book of Islam, considered by Muslims to be a revelation from God.", 610) {}

    void displayInfo() const override {
        cout << "Religion: " << name << endl;
        cout << "Sacred Book: " << sacredBook << endl;
        cout << "Description: " << bookDescription << endl;
        cout << "Creation Year: " << bookCreationYear << " CE" << endl;
    }
};

class Christianity : public Religion {
public:
    Christianity() : Religion("Christianity", "Bible", "A collection of religious texts or scriptures sacred in Christianity.", 30) {}

    void displayInfo() const override {
        cout << "Religion: " << name << endl;
        cout << "Sacred Book: " << sacredBook << endl;
        cout << "Description: " << bookDescription << endl;
        cout << "Creation Year: " << bookCreationYear << " CE" << endl;
    }
};

class ReligionManager {
private:
    vector<shared_ptr<Religion>> religions;
    vector<string> askedReligions;

public:
    void addReligion(shared_ptr<Religion> religion) {
        religions.push_back(religion);
    }

    void displayReligionNames() const {
        if (askedReligions.empty()) {
            cout << "No religions asked about yet." << endl;
            return;
        }
        cout << "Religions asked about:" << endl;
        for (const auto& name : askedReligions) {
            cout << "- " << name << endl;
        }
    }

    void guessSacredBook(const string& name, const string& guess) {
        for (const auto& religion : religions) {
            if (religion->getName() == name) {
                if (religion->getSacredBook() == guess) {
                    cout << "Correct! Access granted to detailed information about the book." << endl;
                    religion->displayInfo();
                    askedReligions.push_back(name);
                } else {
                    cout << "Incorrect. Access denied to detailed information about the book." << endl;
                }
                return;
            }
        }
        cout << "Religion not found." << endl;
    }
};

int main() {
    ReligionManager manager;
    manager.addReligion(make_shared<Hinduism>());
    manager.addReligion(make_shared<Buddhism>());
    manager.addReligion(make_shared<Confucianism>());
    manager.addReligion(make_shared<Taoism>());
    manager.addReligion(make_shared<Judaism>());
    manager.addReligion(make_shared<Islam>());
    manager.addReligion(make_shared<Christianity>());

    string choice;
    while (true) {
        cout << "1. Display Asked Religions\n2. Guess Sacred Book\n3. Exit\n";
        cout << "Enter your choice: ";
        int option;
        cin >> option;

        if (option == 1) {
            manager.displayReligionNames();
        } else if (option == 2) {
            cout << "Enter the name of the religion: ";
            cin >> choice;
            string guess;
            cout << "Enter your guess for the sacred book: ";
            cin >> guess;
            manager.guessSacredBook(choice, guess);
        } else if (option == 3) {
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}
