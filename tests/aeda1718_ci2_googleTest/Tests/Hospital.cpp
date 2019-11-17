/*
 * Hospital.cpp
 */

#include "Hospital.h"
//
#include <algorithm>


Hospital::Hospital(unsigned trayC):trayCapacity(trayC)
{ }

void Hospital::addDoctor(const Doctor &d1) {
	doctors.push_back(d1);
}

list<Doctor> Hospital::getDoctors() const {
	return doctors;
}

void Hospital::addTrays(stack<Patient> tray1) {
	letterTray.push_back(tray1);
}

list<stack<Patient> > Hospital::getTrays() const {
	return letterTray;
}



unsigned Hospital::numPatients(string medicalSpecialty) const
{
    unsigned count = 0;
	for (auto it = doctors.begin(); it != doctors.end(); it++)
        if (it->getMedicalSpecialty() == medicalSpecialty)
            count += it->getPatients().size();
    return count;
}

void Hospital::sortDoctors() {
	// TODO

}



bool Hospital::addDoctor(unsigned codM1, string medicalSpecialty1) {
	// TODO
	return true;

}



queue<Patient> Hospital::removeDoctor(unsigned codM1) {
	// TODO
	queue<Patient> p1;
	return p1;

}


bool Hospital::putInLessBusyDoctor(unsigned cod1, string medicalSpecialty1) {
	// TODO
	return true;

}



void Hospital::processPatient(unsigned codM1) {
	// TODO

}


unsigned Hospital::removePatients(unsigned codP1) {
	// TODO
	return 0;

}



