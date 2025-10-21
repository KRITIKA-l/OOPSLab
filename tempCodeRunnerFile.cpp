#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

// ===== Console Colors =====
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BLUE    "\033[34m"

// ====================================================
//               ABSTRACT BASE CLASS
// ====================================================
class Human 
{
    protected:
        string name;
        int energy, hunger, happiness, social;

    public:
        Human(string n) : name(n), energy(70), hunger(40), happiness(60), social(50) {}
        virtual void work() = 0;

        // ------------------- Common Actions -------------------
        void eat() {
            hunger -= 20;
            energy += 15;
            if (hunger < 0) hunger = 0;
            if (energy > 100) energy = 100;
            happiness += 5;
            cout << GREEN << name << " ate a meal and feels re-energized.\n" << RESET;
        }

        void sleep() {
            energy = 100;
            happiness += 10;
            if (happiness > 100) happiness = 100;
            cout << BLUE << name << " had a good sleep and feels fresh.\n" << RESET;
        }

        void talk() {
            social += 15;
            happiness += 10;
            if (social > 100) social = 100;
            if (happiness > 100) happiness = 100;
            cout << CYAN << name << " had a pleasant conversation with friends.\n" << RESET;
        }

        void relax() {
            energy += 10;
            happiness += 15;
            if (energy > 100) energy = 100;
            if (happiness > 100) happiness = 100;
            cout << YELLOW << name << " took some time to relax and feels peaceful.\n" << RESET;
        }

        void exercise() {
            energy -= 15;
            hunger += 10;
            happiness += 20;
            if (energy < 0) energy = 0;
            if (hunger > 100) hunger = 100;
            if (happiness > 100) happiness = 100;
            cout << GREEN << name << " exercised and feels more energetic.\n" << RESET;
        }

        // ------------------- Automatic Decay -------------------
        void updateMood() {
            energy -= 5;
            hunger += 5;
            happiness -= 3;
            if (energy < 0) energy = 0;
            if (hunger > 100) hunger = 100;
            if (happiness < 0) happiness = 0;
        }

        // ------------------- Random Life Event -------------------
        void randomEvent() {
            int event = rand() % 5;
            switch (event) {
                case 0: cout << "Positive feedback from peers. Happiness +10.\n"; happiness += 10; break;
                case 1: cout << "Weather is pleasant today. Mood improved slightly.\n"; happiness += 5; break;
                case 2: cout << "Minor disagreement with a friend. Happiness -10.\n"; happiness -= 10; break;
                case 3: cout << "Helped someone in need. Feeling proud and satisfied.\n"; happiness += 8; break;
                case 4: cout << "Feeling slightly unmotivated today. Energy +5.\n"; energy += 5; break;
            }
            if (happiness > 100) happiness = 100;
            if (happiness < 0) happiness = 0;
        }

        // ------------------- Mood Indicator -------------------
        string getMood() const {
            if (happiness > 80) return "Happy";
            if (happiness > 60) return "Good";
            if (happiness > 40) return "Neutral";
            if (happiness > 20) return "Low";
            return "Depressed";
        }

        // ------------------- Show Status -------------------
        virtual void showStatus() {
            cout << "\n------ " << name << "'s Current Status ------\n";
            cout << "Energy: " << energy
                << "\nHunger: " << hunger
                << "\nHappiness: " << happiness
                << "\nSocial: " << social
                << "\nMood: " << getMood() << "\n";
        }

        virtual ~Human() {}
};


// ====================================================
//                   STUDENT CLASS
// ====================================================
class Student : public Human 
{
    int knowledge;
    public:
        Student(string n) : Human(n), knowledge(40) {}

        void study() 
        {
            energy -= 20;
            hunger += 10;
            knowledge += 15;
            happiness -= 5;
            if (energy < 0) energy = 0;
            if (hunger > 100) hunger = 100;
            if (knowledge > 100) knowledge = 100;
            cout << YELLOW << name << " studied and gained more knowledge.\n" << RESET;
        }

        void work() override {
            cout << name << " is completing academic tasks and assignments.\n";
            study();
        }

        void showStatus() override {
            Human::showStatus();
            cout << "Knowledge: " << knowledge << "\n";
        }
};

// ====================================================
//                   EMPLOYEE CLASS
// ====================================================
class Employee : public Human 
{
    int salary;
    public:
        Employee(string n) : Human(n), salary(0) {}

        void work() override 
        {
            cout << name << " worked diligently at the office.\n";
            energy -= 30;
            hunger += 20;
            happiness -= 10;
            salary += 1000;
            if (energy < 0) energy = 0;
            if (hunger > 100) hunger = 100;
            if (happiness < 0) happiness = 0;
        }

        void showStatus() override {
            Human::showStatus();
            cout << "Total Salary Earned: ₹" << salary << "\n";
        }
};

// ====================================================
//                MAIN SIMULATION
// ====================================================
int main() 
{
    srand(static_cast<unsigned>(time(0)));

    cout << "===== Virtual Human with Emotions =====\n";

    Human* person = nullptr;
    int choice;

    cout << "Choose type of human:\n1. Student\n2. Employee\nEnter choice: ";
    while (!(cin >> choice) || (choice != 1 && choice != 2)) 
    {
        cout << RED << "Invalid input! Enter 1 or 2: " << RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string name;
    cout << "Enter name: ";
    cin >> name;

    if (choice == 1)
        person = new Student(name);
    else
        person = new Employee(name);

    int action;
    int turn = 0;
    do 
    {
        cout << "\n--------------------------------------\n";
        cout << "Choose an Action:\n"
             << "1. Eat\n2. Sleep\n3. Talk\n4. Work\n5. Exercise\n6. Relax\n7. Show Status\n0. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> action)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Invalid input! Try again.\n" << RESET;
            continue;
        }

        switch (action) {
            case 1: person->eat(); break;
            case 2: person->sleep(); break;
            case 3: person->talk(); break;
            case 4: person->work(); break;
            case 5: person->exercise(); break;
            case 6: person->relax(); break;
            case 7: person->showStatus(); break;
            case 0: cout << "Exiting simulation...\n"; break;
            default: cout << RED << "Invalid choice!\n" << RESET;
        }

        if (action != 0) {
            person->updateMood(); // decay emotion over time
            if (turn % 2 == 0) person->randomEvent(); // random events every few turns
            turn++;
        }

    } while (action != 0);

    delete person;
    cout << "\nSimulation ended successfully.\n";
    return 0;
}
