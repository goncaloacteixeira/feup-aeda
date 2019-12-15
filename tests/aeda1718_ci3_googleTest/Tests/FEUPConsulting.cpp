/*
 * FEUPConsulting.cpp
 *
 *  Created on: 10/12/2017
 *      Author: CS
 */

#include "FEUPConsulting.h"

FEUPConsulting::FEUPConsulting(): expertizes(Expertize("", 0)) {
}

FEUPConsulting::FEUPConsulting(vector<Project*> projects): expertizes(Expertize("", 0)) {
	this->projects = projects;
}

void FEUPConsulting::addProjects(vector<Project*> projects) {
	this->projects = projects;
}

vector<Project*> FEUPConsulting::getProjects() const{
	return this->projects;
}


// get the expertize objet with the given name, including all students with the corresponding skills
Expertize FEUPConsulting::getExpertize(string name, unsigned cost) {
	Expertize itemNotFound("", 0);
	Expertize expertize(name, cost);
	Expertize search = expertizes.find(expertize);

	return search;
}


void FEUPConsulting::addProject(Project* project) {
	//TODO
	Expertize itemNotFound("", 0);
	Expertize expertize(project->getExpertize(), project->getCost());
	Expertize search = expertizes.find(expertize);

	if(search == itemNotFound) {
		this->expertizes.insert(expertize);
	}

	projects.push_back(project);
}

BST<Expertize> FEUPConsulting::getExpertizes() const {
	return this->expertizes;
}

void FEUPConsulting::addNewExpertize(const Expertize & expertize1) {
	this->expertizes.insert(expertize1);
}

vector<StudentPtr> FEUPConsulting::getStudents() const {
	vector<StudentPtr> ptrs;
	HashTabStudentPtr::const_iterator it1 = this->students.begin();
	HashTabStudentPtr::const_iterator it2 = this->students.end();
	for(; it1 != it2; it1++) {
			ptrs.push_back(*it1); //We can make it a bit more complex by considering only records with a condition!
	}
	return ptrs;
}

void FEUPConsulting::setStudents(vector<StudentPtr>& newStudents) {
	for(int i = 0; i < newStudents.size(); i++) students.insert(newStudents[i]);
}

priority_queue<Student> FEUPConsulting::getActiveStudents() const {
	return activeStudents;
}
void FEUPConsulting::setActiveStudents(priority_queue<Student>& students) {
	activeStudents = students;
}


//
// TODO: Part I   - BST
//

void FEUPConsulting::addAvailability(Student* student, string expertizeAvailable, unsigned cost) {
	BSTItrIn<Expertize> it(this->expertizes);

	while (!it.isAtEnd()) {
	    if (it.retrieve() == Expertize(expertizeAvailable,cost)) {
	        it.retrieve().addConsultant(student);
	        return;
	    }
	    it.advance();
	}

	Expertize exp1(expertizeAvailable,cost);
	exp1.addConsultant(student);
	expertizes.insert(exp1);
}

vector<Student*> FEUPConsulting::getCandidateStudents(Project* project) const {
	vector<Student*> temp;

    BSTItrIn<Expertize> it(this->expertizes);
    while(!it.isAtEnd()) {
        if (it.retrieve() == Expertize(project->getExpertize(),project->getCost())) {
            for (auto &s : it.retrieve().getConsultants()) {
                if (s->getCurrentProject().empty()) {
                    temp.push_back(s);
                }
            }
        }
        it.advance();
    }

	return temp;
}


bool FEUPConsulting::assignProjectToStudent(Project* project, Student* student) {
    if (project->getConsultant() != nullptr)
        return false;
    if (!student->getCurrentProject().empty())
        return false;

    vector<Student *> availableStuds = this->getCandidateStudents(project);

    for (auto &s : availableStuds) {
        if (s->getName() == student->getName() && s->getEMail() == student->getEMail()) {
            project->setConsultant(student);
            student->addProject(project->getTitle());
            return true;
        }
    }
    return false;
}

//
// TODO: Part II  - Hash Table
//

void FEUPConsulting::addStudent(Student* student) {
	students.insert(student);

}

void FEUPConsulting::changeStudentEMail(Student* student, string newEMail) {
	student->setEMail(move(newEMail));
}


//
// TODO: Part III - Priority Queue
//

void FEUPConsulting::addActiveStudents(const vector<Student>& candidates, int min) {

    for (auto &c : candidates) {
        if (c.getPastProjects().size() >= min) {
            activeStudents.push(c);
        }
    }

}


int FEUPConsulting::mostActiveStudent(Student& studentMaximus) {
    int count = activeStudents.size();

    if (activeStudents.empty())
        return 0;

    if (count == 1) {
        studentMaximus = activeStudents.top();
        return 1;
    }

    Student aux = activeStudents.top();
    activeStudents.pop();
    Student aux2 = activeStudents.top();
    activeStudents.push(aux);

    if (aux.getPastProjects().size() == aux2.getPastProjects().size())
        return 0;

    studentMaximus = aux;
    return count;

}





















