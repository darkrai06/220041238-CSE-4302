#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string licenseP;
    string manufacturer;
    double sizelim;

public:
    Vehicle(string license, string manuf, double limitKg)
        : licenseP(license), manufacturer(manuf), sizelim(limitKg) {}

    virtual void performMaintenance() const = 0;
};

class GasV : virtual public Vehicle
{
protected:
    double fuelCapL;
    string fuelType;

public:
    GasV(string license, string manuf, double limitKg, double tankCap, string fuel)
        : Vehicle(license, manuf, limitKg), fuelCapL(tankCap), fuelType(fuel) {}
};

class ElectrV : virtual public Vehicle
{
    double batteryCapa;
    int chargeMin;

public:
    ElectrV(string license, string manuf, double limitKg, double batteryCap, int chargeTime)
        : Vehicle(license, manuf, limitKg), batteryCapa(batteryCap), chargeMin(chargeTime) {}

    void performMaintenance() const
    {
        cout << "Electric Vehicle - maintenance" << endl;
    }
};

class Motorcycle : public GasV
{
public:
    Motorcycle(string license, string manuf, double limitKg, double tankCap, string fuel)
        : Vehicle(license, manuf, limitKg), GasV(license, manuf, limitKg, tankCap, fuel) {}

    void performMaintenance() const
    {
        cout << "Motorcycle - maintenance" << endl;
    }
};

class Car : public GasV
{
    int passengerCapacity;

public:
    Car(string license, string manuf, double limitKg, double tankCap, string fuel, int passengers)
        : Vehicle(license, manuf, limitKg), GasV(license, manuf, limitKg, tankCap, fuel), passengerCapacity(passengers) {}

    int getPassengerCapacity() const
    {
        return passengerCapacity;
    }

    void setPassengerCapacity(int passengers)
    {
        passengerCapacity = passengers;
    }

    string getLicensePlate() const
    {
        return licenseP;
    }

    void setLicensePlate(const string license)
    {
        licenseP = license;
    }

    string getManufacturer() const
    {
        return manufacturer;
    }

    void setManufacturer(const string manuf)
    {
        manufacturer = manuf;
    }


    void performMaintenance() const
    {
        cout << "Car - maintenance" << endl;
    }
};

class Truck : public GasV
{
    double cargoCapacity;

public:
    Truck(string license, string manuf, double limitKg, double tankCap, string fuel, double cargoCap)
        : Vehicle(license, manuf, limitKg), GasV(license, manuf, limitKg, tankCap, fuel), cargoCapacity(cargoCap) {}

    void performMaintenance() const
    {
        cout << "Truck - maintenance" << endl;
    }
};

class HybridV : public GasV, public ElectrV
{
private:
    double energyRegenEfficiency;

public:
    HybridV(const string plate, const string make, double size,
            double fuelCapacity, const string fuel, double batteryCap,
            int chargeTime, double regenEfficiency)
        : Vehicle(plate, make, size),
          GasV(plate, make, size, fuelCapacity, fuel),
          ElectrV(plate, make, size, batteryCap, chargeTime),
          energyRegenEfficiency(regenEfficiency) {}

    void performMaintenance() const override
    {
        cout << "Hybrid Vehicle - maintenance" << endl;
    }
};

class Employee
{
protected:
    string name;
    int id;

public:
    Employee(string empName, int empId) : name(empName), id(empId) {}

    virtual void introduce() const = 0;
};

class Manager : public Employee
{
public:
    Manager(string empName, int empId) : Employee(empName, empId) {}

    void introduce() const
    {
        cout << "Mr. " << name << endl;
    }
};

class Driver : public Employee
{
public:
    Driver(string empName, int empId) : Employee(empName, empId) {}

    void introduce() const
    {
        cout << name << endl;
    }
};

class Branch
{
    vector<Motorcycle> motorcycles;
    vector<Car> cars;
    vector<Truck> trucks;
    vector<ElectrV> ElectrVs;
    vector<HybridV> HybridVs;
    vector<Manager> managers;
    vector<Driver> drivers;

public:

    Branch()
    {
        for (int i = 0; i < 10; ++i)
            motorcycles.emplace_back("M" + to_string(i), "BMW", 200, 15, "Petrol");

        for (int i = 0; i < 10; ++i)
            cars.emplace_back("C" + to_string(i), "Toyota", 1000, 50, "Petrol", 4);

        for (int i = 0; i < 10; ++i)
            trucks.emplace_back("T" + to_string(i), "Volvo", 5000, 200, "Diesel", 10000);

        for (int i = 0; i < 10; ++i)
            ElectrVs.emplace_back("E" + to_string(i), "Tesla", 1200, 100, 60);

        for (int i = 0; i < 10; ++i)
         HybridVs.emplace_back("H" + to_string(i), "Toyota", 1500, 40, "Petrol", 80, 30, 0.85);

        for (int i = 0; i < 10; ++i)
            managers.emplace_back("Manager" + to_string(i + 1), i + 1);

        for (int i = 0; i < 30; ++i)
            drivers.emplace_back("Driver" + to_string(i + 1), i + 11);
    }

    void introduceEmployees() const
    {
        cout << "Managers:" << endl;
        for (int i = 0; i < managers.size(); ++i)
        {
            managers[i].introduce();
        }

        cout << "\nDrivers:" << endl;
        for (int i = 0; i < drivers.size(); ++i)
        {
            drivers[i].introduce();
        }
    }

    void performVehicleMaintenance() const
    {
        for (int i = 0; i < motorcycles.size(); ++i)
        {
            motorcycles[i].performMaintenance();
        }

        for (int i = 0; i < cars.size(); ++i)
        {
            cars[i].performMaintenance();
        }

        for (int i = 0; i < trucks.size(); ++i)
        {
            trucks[i].performMaintenance();
        }

        for (int i = 0; i < ElectrVs.size(); ++i)
        {
            ElectrVs[i].performMaintenance();
        }

        for (int i = 0; i < HybridVs.size(); ++i)
        {
         HybridVs[i].performMaintenance();
        }
     }

};

int main()
{
    Branch branch;
    Car cars("C1", "Toyota", 1000, 50, "Petrol", 4);
    branch.introduceEmployees();
    cout << "\nPerforming maintenance on vehicles:" << endl;
    branch.performVehicleMaintenance();

    return 0;
}

