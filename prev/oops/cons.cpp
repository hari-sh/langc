#include <iostream>
using std::string;

class Employee {
    public:
    string Name;
    string Company;
    int Age;
    
    void Intro()    {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }

    Employee(string name, string company, int age)  {
        Name = name;
        Company = company;
        Age = age;
    }
};

int main()  {
    Employee e1 = Employee("Rana", "Github", 28);
    e1.Intro();

    Employee e2 = Employee("Bhai", "Gitlab", 29);
    e2.Intro();
    
}

//by default all class members are private
//Three rules of creating constructors

/*
Constructor dont have the return type
Constructor has the same name as the class
Keep Constructor as public. Private constructor are beyond scope
Default constructor is lost once we create our own constructor
*/