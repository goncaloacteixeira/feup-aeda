#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Doctor.h"
#include "Hospital.h"
#include <vector>
#include <string>

using testing::Eq;

// numPatients
TEST(test_1, a){
	Hospital hosp;
	queue<Patient> q1;
	q1.push(Patient(123,"medicalSpecialtyX"));
	q1.push(Patient(456,"medicalSpecialtyX"));
	q1.push(Patient(456,"medicalSpecialtyX"));
	Doctor d1(1,"medicalSpecialtyX",q1);
	hosp.addDoctor(d1);
	Doctor d2(2,"medicalSpecialtyZ");
	hosp.addDoctor(d2);
	queue<Patient> q3;
	q3.push(Patient(111,"medicalSpecialtyA"));
	q3.push(Patient(666,"medicalSpecialtyA"));
	q3.push(Patient(777,"medicalSpecialtyA"));
	Doctor d3(3,"medicalSpecialtyA",q3);
	hosp.addDoctor(d3);
	queue<Patient> q4;
	q4.push(Patient(456,"medicalSpecialtyX"));
	Doctor d4(4,"medicalSpecialtyX",q4);
	hosp.addDoctor(d4);
    EXPECT_EQ(0,hosp.numPatients("medicalSpecialtyZ"));
    EXPECT_EQ(4,hosp.numPatients("medicalSpecialtyX"));
    EXPECT_EQ(3,hosp.numPatients("medicalSpecialtyA"));
}


//sortDoctors
TEST(test_1, b){

	Hospital hosp;

	queue<Patient> q1;
	q1.push(Patient(123,"medicalSpecialtyZ"));
	q1.push(Patient(456,"medicalSpecialtyZ"));
	Doctor d1(1,"medicalSpecialtyZ",q1);
	hosp.addDoctor(d1);

	queue<Patient> q2;
	q2.push(Patient(321,"medicalSpecialtyZ"));
	Doctor d2(2,"medicalSpecialtyZ",q2);
	hosp.addDoctor(d2);

	queue<Patient> q3;
	q3.push(Patient(111,"medicalSpecialtyZ"));
	q3.push(Patient(666,"medicalSpecialtyZ"));
	Doctor d3(3,"medicalSpecialtyZ",q3);
	hosp.addDoctor(d3);

	queue<Patient> q4;
	Doctor d4(4,"medicalSpecialtyX",q4);
	hosp.addDoctor(d4);

	queue<Patient> q5;
	q5.push(Patient(341,"medicalSpecialtyB"));
	Doctor d5(5,"medicalSpecialtyB",q5);
	hosp.addDoctor(d5);

	hosp.sortDoctors();
	list<Doctor> res = hosp.getDoctors();
    EXPECT_EQ(5, res.size());

    EXPECT_EQ(4,res.front().getCode());
    EXPECT_EQ(0,res.front().getPatients().size());
	res.pop_front();
    EXPECT_EQ(5,res.front().getCode());
    EXPECT_EQ(1,res.front().getPatients().size());
	res.pop_front();
    EXPECT_EQ(2,res.front().getCode());
    EXPECT_EQ(1,res.front().getPatients().size());
	res.pop_front();
    EXPECT_EQ(1,res.front().getCode());
    EXPECT_EQ(2,res.front().getPatients().size());
	res.pop_front();
    EXPECT_EQ(3,res.front().getCode());
    EXPECT_EQ(2,res.front().getPatients().size());
	res.pop_front();
}


//moveToFront
TEST(test_1, c){
	Doctor d1(1,"medicalSpecialtyX");
	d1.moveToFront(111);
	queue<Patient> res = d1.getPatients();
    EXPECT_EQ(0,res.size());

	queue<Patient> q1;
	q1.push(Patient(123,"medicalSpecialtyX"));
	q1.push(Patient(456,"medicalSpecialtyX"));
	q1.push(Patient(789,"medicalSpecialtyX"));
	Doctor d2(2,"medicalSpecialtyX",q1);

	d2.moveToFront(789);
	res = d2.getPatients();
    EXPECT_EQ(3,res.size());
    EXPECT_EQ(789,res.front().getCode());
	res.pop();
    EXPECT_EQ(123,res.front().getCode());
	res.pop();
    EXPECT_EQ(456,res.front().getCode());

	Doctor d3(3,"medicalSpecialtyX",q1);
	d3.moveToFront(111);
	res = d3.getPatients();
    EXPECT_EQ(3,res.size());
    EXPECT_EQ(123,res.front().getCode());
	res.pop();
    EXPECT_EQ(456,res.front().getCode());
	res.pop();
    EXPECT_EQ(789,res.front().getCode());

}



//addDoctor
TEST(test_1, d){

	Hospital hosp;

	queue<Patient> q;
	Doctor d1(1,"medicalSpecialtyZ",q);
	hosp.addDoctor(d1);

	Doctor d2(2,"medicalSpecialtyX",q);
	hosp.addDoctor(d2);

	queue<Patient> q3;
	Doctor d3(3,"medicalSpecialtyZ",q);
	hosp.addDoctor(d3);

	Doctor d4(4,"medicalSpecialtyX",q);
	hosp.addDoctor(d4);

    EXPECT_EQ(true, hosp.addDoctor(50,"medicalSpecialtyX"));
	list<Doctor> res = hosp.getDoctors();
    EXPECT_EQ(5, res.size());
    EXPECT_EQ(50, res.back().getCode());
    EXPECT_EQ(1, res.front().getCode());

    EXPECT_EQ(false, hosp.addDoctor(55,"medicalSpecialtyX"));
	res = hosp.getDoctors();
    EXPECT_EQ(5, res.size());

    EXPECT_EQ(true, hosp.addDoctor(60,"medicalSpecialtyA"));
	res = hosp.getDoctors();
    EXPECT_EQ(6, res.size());
    EXPECT_EQ(60, res.back().getCode());
    EXPECT_EQ(1, res.front().getCode());
}


//removeDoctor
TEST(test_1, e) {
    Hospital hosp;

    queue<Patient> q1;
    q1.push(Patient(123, "medicalSpecialtyX"));
    q1.push(Patient(456, "medicalSpecialtyX"));
    q1.push(Patient(789, "medicalSpecialtyX"));
    Doctor d1(10, "medicalSpecialtyX", q1);
    hosp.addDoctor(d1);

    Doctor d2(20, "medicalSpecialtyZ");
    hosp.addDoctor(d2);

    queue<Patient> q3;
    q3.push(Patient(111, "medicalSpecialtyZ"));
    q3.push(Patient(666, "medicalSpecialtyZ"));
    q3.push(Patient(777, "medicalSpecialtyZ"));
    Doctor d3(30, "medicalSpecialtyZ", q3);
    hosp.addDoctor(d3);

    queue<Patient> q4;
    q4.push(Patient(341, "medicalSpecialtyX"));
    Doctor d4(40, "medicalSpecialtyX", q4);
    hosp.addDoctor(d4);

    queue<Patient> q5;
    q5.push(Patient(111, "medicalSpecialtyZ"));
    q5.push(Patient(666, "medicalSpecialtyZ"));
    Doctor d5(50, "medicalSpecialtyZ", q5);
    hosp.addDoctor(d5);

    EXPECT_THROW(hosp.removeDoctor(44), Hospital::DoctorInexistent);
    EXPECT_EQ(5, hosp.getDoctors().size());

    queue<Patient> p1 = hosp.removeDoctor(50);
    EXPECT_EQ(2, p1.size());
    EXPECT_EQ(111, p1.front().getCode());
    EXPECT_EQ(4, hosp.getDoctors().size());

    p1 = hosp.removeDoctor(20);
    EXPECT_EQ(0, p1.size());
    EXPECT_EQ(3, hosp.getDoctors().size());
}


//putInLessBusyDoctor
TEST(test_1, f){
	Hospital hosp;

	queue<Patient> q1;
	q1.push(Patient(123,"medicalSpecialtyX"));
	q1.push(Patient(456,"medicalSpecialtyX"));
	q1.push(Patient(456,"medicalSpecialtyX"));
	Doctor d1(1,"medicalSpecialtyX",q1);
	hosp.addDoctor(d1);

	Doctor d2(2,"medicalSpecialtyZ");
	hosp.addDoctor(d2);

	queue<Patient> q3;
	q3.push(Patient(111,"medicalSpecialtyZ"));
	q3.push(Patient(666,"medicalSpecialtyZ"));
	q3.push(Patient(777,"medicalSpecialtyZ"));
	Doctor d3(3,"medicalSpecialtyZ",q3);
	hosp.addDoctor(d3);

	queue<Patient> q4;
	q4.push(Patient(341,"medicalSpecialtyX"));
	Doctor d4(4,"medicalSpecialtyX",q4);
	hosp.addDoctor(d4);

    EXPECT_EQ(true,hosp.putInLessBusyDoctor(321,"medicalSpecialtyX"));
	list<Doctor> docs = hosp.getDoctors();
	queue<Patient> Patients1 = docs.front().getPatients();
    EXPECT_EQ(3, Patients1.size());
	docs.pop_front(); docs.pop_front(); docs.pop_front();

	queue<Patient> patients2 = docs.front().getPatients();
    EXPECT_EQ(2, patients2.size());
    EXPECT_EQ(321, patients2.back().getCode());

    EXPECT_EQ(true,hosp.putInLessBusyDoctor(888,"medicalSpecialtyZ"));
	docs = hosp.getDoctors();
	queue<Patient> patients3 = docs.front().getPatients();
    EXPECT_EQ(3, patients3.size());

	docs.pop_front();
	patients3 = docs.front().getPatients();
    EXPECT_EQ(1, patients3.size());
    EXPECT_EQ(888, patients3.back().getCode());

	docs.pop_front();
	patients3 = docs.front().getPatients();
    EXPECT_EQ(3, patients3.size());

    EXPECT_EQ(false,hosp.putInLessBusyDoctor(222,"medicalSpecialtyK"));
    EXPECT_EQ(false,hosp.putInLessBusyDoctor(444,"medicalSpecialtyW"));
}


// processPatient
TEST(test_1, g){
	Hospital hosp(2);
	queue<Patient> q1;
	q1.push(Patient(123,"medicalSpecialtyX"));
	q1.push(Patient(456,"medicalSpecialtyX"));
	q1.push(Patient(456,"medicalSpecialtyX"));
	Doctor d1(1,"medicalSpecialtyX",q1);
	hosp.addDoctor(d1);

	Doctor d2(2,"medicalSpecialtyZ");
	hosp.addDoctor(d2);

	queue<Patient> q3;
	q3.push(Patient(111,"medicalSpecialtyZ"));
	q3.push(Patient(666,"medicalSpecialtyZ"));
	q3.push(Patient(777,"medicalSpecialtyZ"));
	Doctor d3(3,"medicalSpecialtyZ",q3);
	hosp.addDoctor(d3);

	queue<Patient> q4;
	q4.push(Patient(341,"medicalSpecialtyX"));
	Doctor d4(4,"medicalSpecialtyX",q4);
	hosp.addDoctor(d4);

	stack<Patient> s1;
	s1.push(Patient(222,"medicalSpecialtyA"));
	hosp.addTrays(s1);
	stack<Patient> s2;
	s2.push(Patient(555,"medicalSpecialtyB"));
	s2.push(Patient(865,"medicalSpecialtyC"));
	hosp.addTrays(s2);
	stack<Patient> s3;
	s3.push(Patient(341,"medicalSpecialtyD"));
	hosp.addTrays(s3);

	hosp.processPatient(2);
	list<stack<Patient> > b1 = hosp.getTrays();
    EXPECT_EQ(3, b1.size());
    EXPECT_EQ(222, b1.front().top().getCode());

	hosp.processPatient(1);
	b1 = hosp.getTrays();
    EXPECT_EQ(3, b1.size());
    EXPECT_EQ(123, b1.front().top().getCode());

	hosp.processPatient(3);
	b1=hosp.getTrays();
    EXPECT_EQ(3, b1.size());
    EXPECT_EQ(123, b1.front().top().getCode());
    EXPECT_EQ(2, b1.back().size());
    EXPECT_EQ(111, b1.back().top().getCode());

	hosp.processPatient(3);
	b1=hosp.getTrays();
    EXPECT_EQ(4, b1.size());
    EXPECT_EQ(1, b1.back().size());
    EXPECT_EQ(666, b1.back().top().getCode());

	hosp.processPatient(6);
	b1=hosp.getTrays();
    EXPECT_EQ(4, b1.size());
    EXPECT_EQ(1, b1.back().size());
    EXPECT_EQ(666, b1.back().top().getCode());
}


//removePatients
TEST(test_1, h){
	Hospital hosp(2);

	stack<Patient> s1;
	s1.push(Patient(222,"medicalSpecialtyA"));
	hosp.addTrays(s1);

	stack<Patient> s2;
	s2.push(Patient(555,"medicalSpecialtyB"));
	s2.push(Patient(341,"medicalSpecialtyC"));
	hosp.addTrays(s2);

	stack<Patient> s3;
	s3.push(Patient(341,"medicalSpecialtyC"));
	hosp.addTrays(s3);

	stack<Patient> s4;
	s4.push(Patient(341,"medicalSpecialtyC"));
	s4.push(Patient(111,"medicalSpecialtyC"));
	hosp.addTrays(s4);

    EXPECT_EQ(0, hosp.removePatients(777));
	list<stack<Patient> > b1 = hosp.getTrays();
    EXPECT_EQ(4, b1.size());
    EXPECT_EQ(222, b1.front().top().getCode());

    EXPECT_EQ(2, hosp.removePatients(341));
	b1 = hosp.getTrays();
    EXPECT_EQ(3, b1.size());
    EXPECT_EQ(222, b1.front().top().getCode());
	b1.pop_front();
    EXPECT_EQ(1, b1.front().size());
    EXPECT_EQ(555, b1.front().top().getCode());
	b1.pop_front();
    EXPECT_EQ(2, b1.front().size());
    EXPECT_EQ(111, b1.front().top().getCode());

    EXPECT_EQ(1, hosp.removePatients(222));
	b1 = hosp.getTrays();
    EXPECT_EQ(2, b1.size());
}



