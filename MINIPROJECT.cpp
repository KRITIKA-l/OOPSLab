#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// ===== Utility Functions =====
int clamp(int value, int min = 0, int max = 100) 
{
    return value < min ? min : (value > max ? max : value);
}

void drawBar(int value) 
{
    int bars = value / 5;
    for (int i = 0; i < bars; i++) 
        cout << "#";
    for (int i = bars; i < 20; i++) 
        cout << "-";
}

// Convert 24-hour to 12-hour format with AM/PM
string formatTime(int hour24) 
{
    string period = (hour24 >= 12) ? "PM" : "AM";
    int hour12 = hour24 % 12;
    if(hour12 == 0) hour12 = 12;
    return to_string(hour12) + " " + period;
}

string getTimeOfDay(int hour24) 
{
    if(hour24 >= 5 && hour24 < 12) return "Morning";
    if(hour24 >= 12 && hour24 < 17) return "Afternoon";
    if(hour24 >= 17 && hour24 < 21) return "Evening";
    return "Night";
}

// ===== Base Class =====
class Human 
{
    protected:
        string name;
        int energy, hunger, happiness, social, health, stress;
    public:
        Human(string n)
            : name(n), energy(70), hunger(40), happiness(60),
            social(50), health(100), stress(10) {}

        virtual void work() = 0;

        void eat() 
        {
            hunger -= 25; 
            energy += 15; 
            happiness += 5;
            hunger = clamp(hunger); energy = clamp(energy); happiness = clamp(happiness);
            cout << name << " ate and feels better.\n";
        }

        void sleep() 
        {
            energy = 100; 
            stress -= 10; 
            happiness += 10;
            stress = clamp(stress); happiness = clamp(happiness);
            cout << name << " slept well.\n";
        }

        void relax() 
        {
            happiness += 10; 
            stress -= 10;
            happiness = clamp(happiness); stress = clamp(stress);
            cout << name << " relaxed and feels peaceful.\n";
        }

        void socialize() 
        {
            social += 15; 
            happiness += 10; 
            stress -= 5;
            social = clamp(social); happiness = clamp(happiness); stress = clamp(stress);
            cout << name << " socialized and feels happier.\n";
        }

        void updateStats() 
        {
            energy -= 2; 
            hunger += 3; 
            happiness -= 1; 
            stress += 1; 
            social -= 1;
            if (energy < 20 || hunger > 80) 
                health -= 5;
            energy = clamp(energy); hunger = clamp(hunger); happiness = clamp(happiness);
            stress = clamp(stress); health = clamp(health); social = clamp(social);
        }

        string getMood() const 
        {
            if (happiness > 80 && stress < 30) return "Happy";
            if (happiness > 60) return "Good";
            if (happiness > 40) return "Neutral";
            if (happiness > 20) return "Low";
            return "Depressed";
        }

        virtual void showStatus() 
        {
            cout << "\n------ " << name << "'s Status ------\n";
            cout << "Energy   : "; drawBar(energy); cout << " " << energy << "/100\n";
            cout << "Hunger   : "; drawBar(hunger); cout << " " << hunger << "/100\n";
            cout << "Happiness: "; drawBar(happiness); cout << " " << happiness << "/100\n";
            cout << "Social   : "; drawBar(social); cout << " " << social << "/100\n";
            cout << "Stress   : "; drawBar(stress); cout << " " << stress << "/100\n";
            cout << "Health   : "; drawBar(health); cout << " " << health << "/100\n";
            cout << "Mood     : " << getMood() << "\n";
        }

        virtual ~Human() {}
};

// ===== Student Class =====
class Student : public Human 
{
    int knowledge;
    public:
        Student(string n) : Human(n), knowledge(40) {}

        void work() override 
        {
            energy -= 20; hunger += 10; knowledge += 15; stress += 5; happiness -= 5; social -= 2;
            energy = clamp(energy); hunger = clamp(hunger); knowledge = clamp(knowledge);
            stress = clamp(stress); happiness = clamp(happiness); social = clamp(social);
            cout << name << " studied hard and gained knowledge.\n";
        }

        void showStatus() override 
        {
            Human::showStatus();
            cout << "Knowledge: "; drawBar(knowledge); cout << " " << knowledge << "/100\n";
        }
};

// ===== Employee Class =====
class Employee : public Human 
{
    int salary;
    public:
        Employee(string n) : Human(n), salary(0) {}

        void work() override 
        {
            energy -= 25; hunger += 15; stress += 10; happiness -= 5; salary += 1000; social -= 2;
            energy = clamp(energy); hunger = clamp(hunger); stress = clamp(stress); happiness = clamp(happiness); social = clamp(social);
            cout << name << " worked and earned salary.\n";
        }

        void showStatus() override 
        {
            Human::showStatus();
            cout << "Salary   : " << salary << "\n";
        }
};

// ===== MAIN =====
int main() 
{
    Human* person = nullptr;
    string name;
    int type, action;
    int hour = 8;  // simulation starts at 8:00 AM
    int day = 1;   // start day

    cout << "Enter name: ";
    cin >> name;
    cout << "Choose type: 1=Student, 2=Employee: ";

    while (!(cin >> type) || (type != 1 && type != 2)) 
    { 
        cout << "Invalid input! Enter 1 or 2: "; 
        cin.clear(); 
        cin.ignore(1000, '\n'); 
    }

    if(type == 1) 
        person = new Student(name);
    else 
        person = new Employee(name);

    do 
    {
        cout << "\n--- Day " << day << ", Time: " << formatTime(hour) << " (" << getTimeOfDay(hour) << ") ---\n";
        cout << "Actions:\n1.Eat  2.Sleep  3.Relax  4.Socialize  5.Work  6.Show Status  0.Exit\nChoose: ";

        if (!(cin >> action)) 
        { 
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "Invalid input! Try again.\n" ; 
            continue; 
        }
        switch(action) 
        {
            case 1: person->eat(); hour += 1; break;
            case 2: person->sleep(); hour += 8; break;
            case 3: person->relax(); hour += 1; break;
            case 4: person->socialize(); hour += 2; break;
            case 5: person->work(); hour += 3; break;
            case 6: person->showStatus(); break;
            case 0: cout << "Exiting simulation.\n"; break;
            default: cout << "Invalid choice.\n";
        }

        if(hour >= 24) { hour -= 24; day++; } // next day

        if(action != 0) person->updateStats();
    } while(action != 0);

    delete person;
    return 0;
}
