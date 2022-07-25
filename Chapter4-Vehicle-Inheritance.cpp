#include <iostream>
#include <string>

using namespace std;


class Vehicle
{
protected:
	string m_Make;
	string m_Model;
	float  m_Miles;

public:
	Vehicle(string make, string model, float miles)
		:m_Make(make)
		, m_Model(model)
		, m_Miles(miles)
	{
	
	}
	Vehicle()
	{
	
	}

	virtual void Drive()
	{
		cout << "Today you are going to drive....something I swear." << endl;
	}
};

class Car : public Vehicle
{
	bool m_IsDented;

public:
	void setCarInformation()
	{
		m_Make = "Subaru";
		m_Model = "2018 Outback";
		m_Miles = 27779;
	}

	Car(string make, string model, float miles)
		: Vehicle(make, model, miles)
		, m_IsDented(false)
	{
		
	}

	Car()
	{
		setCarInformation();
	}

	void Drive() override
	{
		cout << "Today we are driving a " << m_Make << " " << m_Model << " with " << m_Miles << " miles on it!" << endl;
	}
};

class Plane : public Vehicle
{
	int m_HoursLogged;

public:
	void SetPlaneInformation()
	{
		m_Make = "Airbus";
		m_Model = "A321";
		m_Miles = 357895;
	}

	Plane(string make, string model, float miles, int hours)
		: Vehicle(make, model, miles)
		, m_HoursLogged(hours)
	{

	}

	Plane()
	{
		SetPlaneInformation();
	}

	void Drive() override
	{
		cout << "Today we are flying a " << m_Make << " " << m_Model << " with " << m_Miles << " miles on it!" << endl;
	}
};

class Boat : public Vehicle
{
	bool m_IsSinking;

public:
	void SetBoatInformation()
	{
		m_Make = "Benetau";
		m_Model = "2023 Swift Trawler";
		m_Miles = 200.5;
	}

	Boat(string make, string model, float miles, int hours)
		: Vehicle(make, model, miles)
		, m_IsSinking(false)
	{
		
	}

	Boat()
	{
		SetBoatInformation();
	}

	void Drive() override
	{
		cout << "Today we are piloting a " << m_Make << " " << m_Model << " with " << m_Miles << " miles on it!" << endl;
	}
};

int main()
{
	Vehicle vehicle;
	Car car;
	Plane plane;
	Boat boat;

	car.Drive();
	plane.Drive();
	boat.Drive();
}