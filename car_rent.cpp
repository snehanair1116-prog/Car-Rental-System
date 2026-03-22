#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Car {
public:
    string id;
    string model;
    double rate;
    bool isAvailable;

    Car(string i, string m, double r) : id(i), model(m), rate(r), isAvailable(true) {}
};

class RentalSystem {
private:
    vector<Car> fleet;

public:
    RentalSystem() {
        // Pre-loading some cars into the system
        fleet.push_back(Car("C001", "Tesla Model 3", 120.0));
        fleet.push_back(Car("C002", "Hyundai Ioniq 5", 100.0));
        fleet.push_back(Car("C003", "Tata Nexon EV", 80.0));
        fleet.push_back(Car("C004", "BMW i4", 250.0));
    }

    void displayCars() {
        cout << "\n" << left << setw(10) << "ID" << setw(20) << "Model" << setw(10) << "Rate/Day" << "Status" << endl;
        cout << "------------------------------------------------------------" << endl;
        for (const auto& car : fleet) {
            cout << left << setw(10) << car.id << setw(20) << car.model << "$" << setw(9) << car.rate 
                 << (car.isAvailable ? "Available" : "Rented") << endl;
        }
    }

    void rentCar() {
        string carID;
        int days;
        cout << "\nEnter Car ID to rent: ";
        cin >> carID;

        for (auto& car : fleet) {
            if (car.id == carID) {
                if (car.isAvailable) {
                    cout << "Enter number of days: ";
                    cin >> days;
                    cout << "\n--- Rental Receipt ---" << endl;
                    cout << "Car: " << car.model << endl;
                    cout << "Days: " << days << endl;
                    cout << "Total Cost: $" << (car.rate * days) << endl;
                    car.isAvailable = false;
                    cout << "Booking Confirmed!" << endl;
                } else {
                    cout << "Error: Car is already rented!" << endl;
                }
                return;
            }
        }
        cout << "Error: Car ID not found!" << endl;
    }
};

int main() {
    RentalSystem system;
    int choice;

    while (true) {
        cout << "\n===== CAR RENTAL SYSTEM =====";
        cout << "\n1. View Fleet\n2. Rent a Car\n3. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) system.displayCars();
        else if (choice == 2) system.rentCar();
        else if (choice == 3) break;
        else cout << "Invalid Choice!";
    }
    return 0;
}