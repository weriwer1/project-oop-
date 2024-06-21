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
    virtual void performRitual() const = 0; 
    virtual void celebrateHoliday() const = 0; 
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

    void performRitual() const override {
        cout << "Hinduism Ritual: Performing a Puja ceremony." << endl;
    }

    void celebrateHoliday() const override {
        cout << "Hinduism Holiday: Celebrating Diwali, the festival of lights." << endl;
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

    void performRitual() const override {
        cout << "Buddhism Ritual: Practicing meditation and chanting." << endl;
    }

    void celebrateHoliday() const override {
        cout << "Buddhism Holiday: Celebrating Vesak, Buddha's birthday." << endl;
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

    void performRitual() const override {
        cout << "Confucianism Ritual: Performing ancestral worship." << endl;
    }

    void celebrateHoliday() const override {
        cout << "Confucianism Holiday: Celebrating Confucius' Birthday." << endl;
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

    void performRitual() const override {
        cout << "Taoism Ritual: Practicing Tai Chi and Qigong." << endl;
    }

    void celebrateHoliday() const override {
        cout << "Taoism Holiday: Celebrating Chinese New Year." << endl;
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

    void performRitual() const override {
        cout << "Judaism Ritual: Observing Shabbat and holidays." << endl;
    }

    void celebrateHoliday() const override {
        cout << "Judaism Holiday: Celebrating Hanukkah, the festival of lights." << endl;
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

    void performRitual() const override {
        cout << "Islam Ritual: Performing the five daily prayers (Salah)." << endl;
    }

    void celebrateHoliday() const override {
        cout << "Islam Holiday: Celebrating Eid al-Fitr, the end of Ramadan." << endl;
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

    void performRitual() const override {
        cout << "Christianity Ritual: Attending church services and taking Communion." << endl;
    }

    void celebrateHoliday() const override {
        cout << "Christianity Holiday: Celebrating Christmas, the birth of Jesus Christ." << endl;
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

    void performRitual(const string& name) {
        for (const auto& religion : religions) {
            if (religion->getName() == name) {
                religion->performRitual();
                return;
            }
        }
        cout << "Religion not found." << endl;
    }

    void celebrateHoliday(const string& name) {
        for (const auto& religion : religions) {
            if (religion->getName() == name) {
                religion->celebrateHoliday();
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
        cout << "1. Display Asked Religions\n2. Guess Sacred Book\n3. Perform Ritual\n4. Celebrate Holiday\n5. Exit\n";
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
            cout << "Enter the name of the religion: ";
            cin >> choice;
            manager.performRitual(choice);
        } else if (option == 4) {
            cout << "Enter the name of the religion: ";
            cin >> choice;
            manager.celebrateHoliday(choice);
        } else if (option == 5) {
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}

