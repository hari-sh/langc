#include <iostream>
using std::string;

class AbstractEmployee  {
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee {
private:
    string Name;
    string Company;
    int Age;
    
public:
    void setName(string name)  {
        Name = name;
    }
    string getName()  {
        return Name;
    }
    void setCompany(string company)  {
        Company = company;
    }
    string getCompany()  {
        return Company;
    }
    void setAge(int age)  {
        Age = age;
    }
    int getAge()  {
        return Age;
    }
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
    void AskForPromotion()  {
        if(Age > 30)    {
            std::cout << Name << " got promoted" << std::endl;
        }
        else{
            std::cout << Name << " sorry, no promotion for you" << std::endl;
        }
    }
};

int main()  {
    Employee e1 = Employee("Rana", "Github", 28);
    e1.Intro();

    Employee e2 = Employee("Bhai", "Gitlab", 35);
    e2.Intro();

    e1.AskForPromotion();
    e2.AskForPromotion();
    e1.setAge(34);
    std::cout << e1.getName() << " is " << e1.getAge() << " years old" <<std::endl;
    
}

//by default all class members are private
//Three rules of creating constructors

/*
Constructor dont have the return type
Constructor has the same name as the class
Keep Constructor as public. Private constructor are beyond scope
Default constructor is lost once we create our own constructor

Lets make Name, company and Age to private
we need getters and setters to access private members

If we inherit a class with pure virtual function, for sure we should have an implementation 
for that function
*/