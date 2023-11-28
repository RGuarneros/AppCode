#include <iostream>
#include <cstdlib> // For rand() function
using namespace std;

class Disease {
    int infectionRate;
    int recoveryTime;

public:
    Disease(int rate, int time) : infectionRate(rate), recoveryTime(time) {}

    int getInfectionRate() const {
        return infectionRate;
    }

    int getRecoveryTime() const {
        return recoveryTime;
    }
};

class Person {

public:
    int status = 0;
    bool vax = false;
    int infection = 0;
    string status_string() {
        if (status == 1) {
            return "sick";
        }
        else if (status == 2) {
            return "recovered";
        }
        else {
            return "healthy";
        }
    }

    void one_more_day() {
        if (infection > 0) {
            infection--;
        }
    }

    void infect(int recoveryTime) {
        infection = recoveryTime;
        status = 1;
    }

    bool is_recovered() {
        if (infection == 0) {
            status = 2;
            return true;
        }
        else {
            return false;
        }
    }

    void vaccinate() {
        vax = true;
    }

    bool is_vaccinated() const {
        return vax;
    }

    bool is_infected() const {
        return status == 1;
    }
};

int main() {
    srand(time(0)); // Seed for rand() function
    Person joe;

    // Create a disease with infection rate and recovery time
    Disease covid19(90, 14);

    for (int step = 1;; ++step) {
        joe.one_more_day();

        // Simulate random infection
        if (!joe.is_vaccinated() && !joe.is_infected() && rand() % 100 < covid19.getInfectionRate()) {
            joe.infect(covid19.getRecoveryTime());
        }

        if (joe.is_recovered()) {
            cout << "Joe has recovered!" << endl;
            joe.status = 3;
            break;
        }
        cout << "On day " << step << ", Joe is " << joe.status_string() << endl;

    }

    return 0;
}
