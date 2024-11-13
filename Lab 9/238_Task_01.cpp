#include <bits/stdc++.h>

using namespace std;

class Vehicle
{
protected:
    string licensePlate;
    string manufacturer;
    double carriageSizeLimit;

public:
    Vehicle(string plate, string manu, double sizeLimit)
        : licensePlate(plate), manufacturer(manu), carriageSizeLimit(sizeLimit) {}

    virtual void performMaintenance() = 0;

    double getCarriageSizeLimit() const
    {
        return carriageSizeLimit;
    }

    virtual void displayInfo() const
    {
        cout << "License Plate: " << licensePlate << "\nManufacturer: " << manufacturer << "\nCarriage Size Limit: " << carriageSizeLimit << " kg\n";
    }
};

class GasolineVehicle : virtual public Vehicle
{
protected:
    double fuelTankCapacity;
    string fuelType;

public:
    GasolineVehicle(string plate, string manu, double sizeLimit, double tankCapacity, string fuel)
        : Vehicle(plate, manu, sizeLimit), fuelTankCapacity(tankCapacity), fuelType(fuel) {}

    virtual double calculateFuelConsumption(double distance){}

    void performMaintenance() override
    {
        cout << "Gasoline Vehicle Maintenance done.\n";
    }

    void displayInfo() const override
    {
        Vehicle::displayInfo();
        cout << "Fuel Tank Capacity: " << fuelTankCapacity << " L\nFuel Type: " << fuelType << "\n";
    }
};

class ElectricVehicle : virtual public Vehicle
{
protected:
    double batteryCapacity;
    int chargingTime;

public:
    ElectricVehicle(string plate, string manu, double sizeLimit, double battery, int chargeTime)
        : Vehicle(plate, manu, sizeLimit), batteryCapacity(battery), chargingTime(chargeTime) {}

    double electricityConsumption(double distance)
    {
        return ((distance*100.0)/batteryCapacity);
    }

    void performMaintenance() override
    {
        cout << "Electric Vehicle Maintenance done.\n";
    }

    void displayInfo() const override
    {
        Vehicle::displayInfo();
        cout << "Battery Capacity: " << batteryCapacity << " KWh\nCharging Time: " << chargingTime << " minutes\n";
    }
};

class Motorcycle : public GasolineVehicle
{
public:
    Motorcycle(string plate, string manu, double sizeLimit, double tankCapacity, string fuel)
        : Vehicle(plate, manu, sizeLimit), GasolineVehicle(plate, manu, sizeLimit, tankCapacity, fuel) {}

    double calculateFuelConsumption(double distance) override
    {
        double consumptionRate = 3.0 / 100.0;
        return distance * consumptionRate;
    }

    void performMaintenance() override
    {
        cout << "Motorcycle Maintenance done.\n";
    }
};

class Car : public GasolineVehicle
{
    int passengerCapacity;

public:
    Car(string plate, string manu, double sizeLimit, double tankCapacity, string fuel, int capacity)
        : Vehicle(plate, manu, sizeLimit), GasolineVehicle(plate, manu, sizeLimit, tankCapacity, fuel), passengerCapacity(capacity) {}

    double calculateFuelConsumption(double distance) override
    {
        double consumptionRate = 8.0 / 100.0;
        return distance * consumptionRate;
    }

    void performMaintenance() override
    {
        cout << "Car Maintenance done.\n";
    }

    void displayInfo() const override
    {
        GasolineVehicle::displayInfo();
        cout << "Passenger Capacity: " << passengerCapacity << "\n";
    }
};

class Truck : public GasolineVehicle
{
    double cargoCapacity;

public:
    Truck(string plate, string manu, double sizeLimit, double tankCapacity, string fuel, double cargoCap)
        : Vehicle(plate, manu, sizeLimit), GasolineVehicle(plate, manu, sizeLimit, tankCapacity, fuel), cargoCapacity(cargoCap) {}

    double calculateFuelConsumption(double distance) override
    {
        double consumptionRate = 25.0 / 100.0;
        return distance * consumptionRate;
    }

    void performMaintenance() override
    {
        cout << "Truck Maintenance done.\n";
    }

    void displayInfo() const override
    {
        GasolineVehicle::displayInfo();
        cout << "Cargo Capacity: " << cargoCapacity << " tons\n";
    }
};


class HybridVehicle : public GasolineVehicle, public ElectricVehicle
{
    double energyRegenerationEfficiency;

public:
    HybridVehicle(string plate, string manu, double sizeLimit, double tankCapacity, string fuel, double battery, int chargeTime, double efficiency)
        : Vehicle(plate, manu, sizeLimit), GasolineVehicle(plate, manu, sizeLimit, tankCapacity, fuel),
          ElectricVehicle(plate, manu, sizeLimit, battery, chargeTime), energyRegenerationEfficiency(efficiency) {}

    double calculateFuelConsumption(double distance)
    {
        double fuelConsumption = GasolineVehicle::calculateFuelConsumption(distance);
        double electricityUsed = ElectricVehicle::electricityConsumption(distance);
        return (fuelConsumption + electricityUsed);
    }

    void performMaintenance() override
    {
        cout << "Hybrid Vehicle Maintenance done.\n";
    }

    void displayInfo() const override
    {
        GasolineVehicle::displayInfo();
        ElectricVehicle::displayInfo();
        cout << "Energy Regeneration Efficiency: " << energyRegenerationEfficiency << "%\n";
    }
};

void sort_vehicles_by_capacity(Vehicle** vehicles, int n)
{
    sort(vehicles, vehicles + n, [](Vehicle* a, Vehicle* b) {
        return a->getCarriageSizeLimit() > b->getCarriageSizeLimit();
    });
}

int main()
{
    vector<Vehicle*> vehicles = {
        new Motorcycle("M123", "Yamaha", 200, 15, "Petrol"),
        new Car("C456", "Toyota", 500, 45, "Petrol", 4),
        new Truck("T789", "Ford", 3000, 150, "Diesel", 10)
    };

    HybridVehicle* hybridVehicle = new HybridVehicle("H321", "Tesla", 600, 50, "Petrol", 75, 60, 85);

    cout << "Vehicles before sorting by capacity:\n";
    for (int i = 0; i < vehicles.size(); i++)
    {
        vehicles[i]->displayInfo();
        vehicles[i]->performMaintenance();
        cout << endl;
    }

    sort_vehicles_by_capacity(vehicles.data(), vehicles.size());

    cout << "Vehicles after sorting by capacity:\n";
    for (int i = 0; i < vehicles.size(); i++)
    {
        vehicles[i]->displayInfo();
        vehicles[i]->performMaintenance();
        cout << endl;
    }

    cout << "\nHybrid Vehicle Information:\n";
    hybridVehicle->displayInfo();
    hybridVehicle->performMaintenance();

    return 0;
}

