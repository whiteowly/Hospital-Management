#include <iostream>
#include <vector>
using namespace std;

class Patient {
public:
    Patient(string name, int age, string address)
            : name(name), age(age), address(address) {
        static int id_counter = 1;
        patientID = id_counter++;
    }

    void displayDetails() const {
        cout << "Patient ID: " << patientID << "\n";
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Address: " << address << "\n";
    }

    int getPatientID() const {
        return patientID;
    }

private:
    int patientID;
    string name;
    int age;
    string address;
};

class Appointment {
public:
    Appointment(int patientID, string date)
            : patientID(patientID), date(date) {}

    void displayDetails() const {
        cout << "Patient ID: " << patientID << "\n";
        cout << "Date: " << date << "\n";
    }

private:
    int patientID;
    string date;
};

class Billing {
public:
    Billing(int patientID, double amount)
            : patientID(patientID), amount(amount) {}

    void displayDetails() const {
        cout << "Patient ID: " << patientID << "\n";
        cout << "Amount: Br. " << amount << "\n";
    }

private:
    int patientID;
    double amount;
};

class Hospital {
public:
    void addPatient(const Patient& patient) {
        patients.push_back(patient);
    }

    void scheduleAppointment(const Appointment& appointment) {
        appointments.push_back(appointment);
    }

    void generateBill(const Billing& bill) {
        bills.push_back(bill);
    }

    void displayPatients() const {
        for (const auto& patient : patients) {
            patient.displayDetails();
            cout << "\n";
        }
    }

    void displayAppointments() const {
        for (const auto& appointment : appointments) {
            appointment.displayDetails();
            cout << "\n";
        }
    }

    void displayBills() const {
        for (const auto& bill : bills) {
            bill.displayDetails();
            cout << "\n";
        }
    }

private:
    vector<Patient> patients;
    vector<Appointment> appointments;
    vector<Billing> bills;
};

int main() {
    Hospital hospital;

cout << "\n\tHospital Management System\n\n";
cout << "Type done when you're done registering the patients.\n\n";


    for (int i = 0;; ++i) {
        cout << "Enter details for Patient " << i + 1 << ":\n";
        string name;
        int age;
        string address;

        cout << "Name: ";
        getline(cin, name);
        if (name=="done")
            break;

        cout << "Age: ";
        cin >> age;
        cin.ignore();

        cout << "Address: ";
        getline(cin, address);

        Patient newPatient(name, age, address);
        hospital.addPatient(newPatient);

        cout << "Enter appointment details for Patient " << i + 1  << ":\n";
        int patientID = i + 1;
        string date;

        cout << "Date (YYYY-MM-DD): ";
        getline(std::cin, date);

        Appointment newAppointment(patientID, date);
        hospital.scheduleAppointment(newAppointment);

        cout << "Enter billing details for Patient " << i + 1 << ":\n";
        double amount;

        cout << "Amount: Br. ";
        cin >> amount;
        cin.ignore();

        Billing newBill(patientID, amount);
        hospital.generateBill(newBill);
    }

    cout << "\nPatients:\n";
    hospital.displayPatients();

    cout << "\nAppointments:\n";
    hospital.displayAppointments();

    cout << "\nBills:\n";
    hospital.displayBills();

    return 0;
}