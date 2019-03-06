#include <iostream>
#include <string> 
#include <sstream> 

using namespace std; 

string int_to_string(int v) { 
    stringstream ss;
    ss << v;
    return ss.str();
}


// Address class here 
class Address {
	public:
		int house_no;	
		int street;
		string city;
		string country;
		
		string get_full_address() {
			string addr = "H. No. " + int_to_string(house_no) + ", Street " + int_to_string(street) + ", " + city + " " + country;
			return addr;
		}
};


// Employee class here 
class Employee {
	public:
		
		string name;
		Address current_address, permanent_address;
		void set_current_address(int house_no, int street, string city, string country) {
			current_address.house_no = house_no;
			current_address.street = street;
			current_address.city = city;
			current_address.country = country;
		}
		void set_permanent_address(int house_no, int street, string city, string country) {
			permanent_address.house_no = house_no;
			permanent_address.street = street;
			permanent_address.city = city;
			permanent_address.country = country;
		}
	
		void print_addresses() {
			cout << current_address.get_full_address() << endl;
			cout << permanent_address.get_full_address() << endl;
		}
};


// Wheel class here 
class Wheel {
	string state;
	
	public:
		void set_wheel_state(string s);
		string get_wheel_state();
};

void Wheel::set_wheel_state(string s) {
	state = s;
}

string Wheel::get_wheel_state() {
	return state;
}


// Car class here 
class Car {
	Wheel w[4];
	public:
		void set_car_to_moving();
		void set_car_to_stopped();
		void print_car_wheels_state();
};

void Car::set_car_to_moving() {
	for(int i=0; i<4; i++) {
		w[i].set_wheel_state("Turning");
	}
}

void Car::set_car_to_stopped() {
	for(int i=0; i<4; i++) {
		w[i].set_wheel_state("Stopped");
	}
}

void Car::print_car_wheels_state() {
	cout << "Car State: " << endl;
	for(int i=0; i<4; i++) {
		cout << "- Wheel " << i << " is " << w[i].get_wheel_state() << endl;
	}
}


int main() { 
	Address myAddress;
	myAddress.get_full_address();

    // Start of PART - 1  -----------------------
    
    Address a; 

    a.house_no = 4; 
    a.street = 25; 
    a.city = "Peshawar"; 
    a.country = "Pakistan";

    cout << a.get_full_address() << endl;

    // End of Part - 1    -----------------------




    // Start of PART - 2  -----------------------

    Employee e1; 

    e1.set_current_address(4, 25, "Peshawar", "Pakistan"); 
    e1.set_permanent_address(14, 9, "Lahore", "Pakistan"); 
    e1.print_addresses();  

    // End of Part - 2     -----------------------




    // Start of PART - 3   -----------------------

    Wheel w1; 

    w1.set_wheel_state("Turning"); 
    cout << w1.get_wheel_state() << endl; 

    // End of Part - 3     -----------------------




    // Start of PART - 4   -----------------------

    Car c; 
    
    c.set_car_to_moving(); 
    c.print_car_wheels_state(); 

    c.set_car_to_stopped(); 
    c.print_car_wheels_state();

    // End of Part - 4     -----------------------


    return 0; 
}
