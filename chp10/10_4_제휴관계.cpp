/*

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Doctor;
class Patient
{
private:
	string m_name;
	vector<Doctor*> m_doctors;

public:
	Patient(const string &name_in) : m_name(name_in) {}
	
	void addDoctor(Doctor * new_doctor)
	{
		m_doctors.push_back(new_doctor);
	}

	void meetDoctors();

	friend class Doctor;
};

class Doctor
{
private:
	string m_name;
	vector<Patient*> m_patients;
public:
	Doctor(const string &name_in) : m_name(name_in) {}

	void addPatient(Patient * new_patient)
	{
		m_patients.push_back(new_patient);
	}

	void meetPatients()
	{
		for (const auto &e : m_patients)
		{
			cout << e->m_name << endl;
		}
	}

	friend class Patient;
};

void Patient::meetDoctors()
{
	for (auto & e : m_doctors)
	{
		cout << "Meet Doctor: " << e->m_name << endl;
	}
}

int main()
{
	Doctor doc1("Doctor1");
	Patient pat1("Patient1");
	Patient pat2("Patient2");

	doc1.addPatient(&pat1);
	doc1.addPatient(&pat2);
	pat1.addDoctor(&doc1);
	pat2.addDoctor(&doc1);

	doc1.meetPatients();
	pat1.meetDoctors();
	pat2.meetDoctors();

	return 0;
}