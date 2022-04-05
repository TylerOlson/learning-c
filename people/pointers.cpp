#include <iostream>
#include <string>

class Person;

class Person {
private:
    std::string name;
    int age;

public:
    Person() {
        name = "";
        age = 0;
    }

    Person(std::string name, int age) {
        this->name = name;
        (*this).age = age;
    }

    friend std::ostream &operator<<(std::ostream &os, const Person &p) {
        os << "{\"name\":\"" << p.name << "\", \"age\":\"" << p.age << "\"}\n";

        return os; // oh hey this thing
    }

    void setName(std::string newName) {
        name = newName;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    std::string getName() {
        return name;
    }

    int getAge() {
        return age;
    }
};

class PeopleManager {
private:
    Person *people;
    int size;

public:
    PeopleManager() {
        people = NULL;
        size = 0;
    }

    friend std::ostream &operator<<(std::ostream &os, const PeopleManager &pm) {
        for (int i = 0; i < pm.size; i++) {
            os << pm.people[i];
        }

        return os;
    }

    void addPerson(Person person) {
        Person *newPeople = new Person[size + 1];
        for (int i = 0; i < size; i++) {
            newPeople[i] = people[i];
        }
        newPeople[size] = person;

        if (people != NULL) {
            delete[] people;
        }
        people = newPeople;
        size++;
    }

    // if only we had a function to ADD A PERSON that resized for us
    void removePerson(Person person) {
        Person *newPeople = new Person[size];
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (people[i].getName() != person.getName()) {
                newPeople[j] = people[i];
                j++;
            }
        }

        if (people != NULL) {
            delete[] people;
        }
        people = newPeople;
        size--;
    }

    Person *getPersonByName(std::string name) {
        Person *p = NULL;
        for (int i = 0; i < size; i++) {
            if (people[i].getName() == name) {
                p = &people[i];
            }
        }

        return p;
    }
};

int main() {
    PeopleManager dmv;
    Person tom = Person("tom", 31);
    Person scott = Person("scott", 27);
    Person joe = Person("joe", 55);
    dmv.addPerson(tom);
    dmv.addPerson(scott);
    dmv.addPerson(joe);
    dmv.getPersonByName("joe")->setName("harry"); // but hey I knew how to use pointers there; i seen; mr nasa proud
    std::cout << dmv;
    // std::cout << dmv.getPersonByName("tom").getName() << std::endl;
    // std::cout << dmv.getPersonByName("scott").getName() << std::endl;
    // std::cout << dmv.getPersonByName("joe").getName() << std::endl;

    return 0;
}