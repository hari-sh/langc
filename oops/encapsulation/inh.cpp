#include <iostream>
using std::string;

class AbstractEmployee  {
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee {
private:
    string Company;
    int Age;

protected:
    string Name;
    
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


class Developer : public Employee{
    public: 
    string Lang;
    Developer(string name, string company, int age, string lang) : Employee(name, company, age) {
        Lang = lang;
    }
    void FixBug()   {
        std::cout << Name << " fix bug using " << Lang << std::endl;
    }
};
int main()  {
    Developer d = Developer("Rana", "Github", 28, "C");
    d.FixBug();
    d.AskForPromotion();
    
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

See derived constructor. Its nice.

Derived classes cannot access private data of Base
We need to keep it under protected to make it accessible by derived class

Inheritence is by default private. Keep it public if you want to access those things outside derived class

*/