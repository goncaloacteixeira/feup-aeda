/*
 * Garage.h
 *
 *  Created on: 24/10/2017
 *      Author: hlc
 */

#ifndef SRC_GARAGE_H_
#define SRC_GARAGE_H_

#include <vector>

template <class Vehicle>
class Garage {
	std::vector<Vehicle *> vehicles;
	const unsigned int capacity;
public:
	Garage(int size);
	~Garage();
	std::vector<Vehicle *> getVehicles() const;
	void setVehicles(std::vector<Vehicle *> vehicles);
	int getCapacity() const;
	bool addVehicle(Vehicle *vehicle);
	Vehicle* removeVehicle(std::string brand, std::string model);
	float avgPrice(std::string brand) const;
	void sortVehicles();
};

class NoSuchVehicleException {
public:
	NoSuchVehicleException() { }
};

class NoSuchBrandException {
    std::string brand;
public:
    NoSuchBrandException(std::string brand) {this->brand = brand; };
    std::string getBrand() {return this->brand; };
};

template <class Vehicle>
Garage<Vehicle>::Garage(int size) : capacity(size) {
}

template <class Vehicle>
Garage<Vehicle>::~Garage() {
	typename std::vector<Vehicle *>::const_iterator it;
	for (it=vehicles.begin(); it!=vehicles.end(); it++) {
		delete *it;
	}
}

template<class Vehicle>
std::vector<Vehicle *> Garage<Vehicle>::getVehicles() const {
	return vehicles;
}

template<class Vehicle>
void Garage<Vehicle>::setVehicles(std::vector<Vehicle*> vehicles) {
	this->vehicles = vehicles;
}

template<class Vehicle>
int Garage<Vehicle>::getCapacity() const {
	return capacity;
}

template<class Vehicle>
bool Garage<Vehicle>::addVehicle(Vehicle *vehicle) {
    if (capacity == vehicles.size()) return false;

    for (int i = 0; i < vehicles.size(); i++)
        if (*vehicles[i] == *vehicle)
            return false;

    vehicles.push_back(vehicle);
    return true;
}

template<class Vehicle>
void Garage<Vehicle>::sortVehicles() {

    if (vehicles.size() == 0) return;

    for (unsigned int j = vehicles.size() - 1; j > 0; j--) {
        bool troca = false;
        for (unsigned int i = 0; i < j; i++) {
            if (vehicles[i+1]->getBrand() < vehicles[i]->getBrand()) {
                std::swap(vehicles[i], vehicles[i + 1]);
                troca = true;
            }
            if (vehicles[i+1]->getBrand() == vehicles[i]->getBrand())
            {
                if (vehicles[i+1]->getModel() < vehicles[i]->getModel())
                {
                    std::swap(vehicles[i+1], vehicles[i]);
                    troca = true;
                }
            }
        }
        if (!troca) return;
    }
}

template<class Vehicle>
Vehicle *Garage<Vehicle>::removeVehicle(std::string brand, std::string model) {
    Vehicle *ret;
    if (vehicles.size() == 0) throw NoSuchVehicleException();

    for (int i = 0; i < vehicles.size(); i++)
    {
        if (vehicles[i]->getBrand() == brand && vehicles[i]->getModel() == model){
            ret = vehicles[i];
            vehicles.erase(vehicles.begin() + i);
            return ret;
        }
    }

    throw NoSuchVehicleException();
}

template<class Vehicle>
float Garage<Vehicle>::avgPrice(std::string brand) const {
    if (vehicles.size() == 0)
        throw NoSuchBrandException(brand);

    float count = 0;
    float res = 0;
    for (int i = 0; i < vehicles.size(); i++)
        if (vehicles[i]->getBrand() == brand)
        {
            count += 1;
            res += vehicles[i]->getPrice();
        }
    if (count == 0)
        throw NoSuchBrandException(brand);

    return res / count;
}

#endif /* SRC_GARAGE_H_ */
