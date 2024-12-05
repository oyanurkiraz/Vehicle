#include <iostream>
using namespace std;

class Vehicle {
private:
	int speed;
	int gearNumber;
	bool isWork;
	string brand;
	double price;

public:

	Vehicle(double vehicle_price = 0.0, string vehicle_brand = "") {
		speed = 0;
		gearNumber = 0;
		isWork = false;
		price = vehicle_price;
		brand = vehicle_brand;
		cout << "Vehicle constructor worked" << endl;
    }

	void setSpeed(int veh_speed) { speed = veh_speed; }
	void setgearNumber(int veh_gearn) { gearNumber = veh_gearn; }
	void setPrice(double veh_price) { price = veh_price; }
	void setBrand(string veh_brand) { brand = veh_brand; }
	void setisWork(bool is_work) { isWork = is_work; }

	int getSpeed()const { return speed; }
	int getgearNumber()const { return gearNumber; }
	double getPrice()const { return price; }
	string getBrand() const { return brand; }
	bool getisWork()const { return isWork; }

	void startEngine() {
		isWork = true;
		gearNumber = 1;
	}

	void stopEngine() {
		isWork = false;
		gearNumber = 0;
	}

	virtual void displayInformation() {
		cout << "Brand:" << brand << endl;
		cout << "Price:" << price << endl;
		cout << "Speed:" << speed << " and Gear Number:" << gearNumber << endl;
		isWork ? cout << "Engine on" << endl : cout << "Engine off" << endl;
	}

	virtual void increaseSpeed() = 0;
	virtual void decreaseSpeed() = 0;
	//bu ikisi pure virtual functiondur. 
	//artýk vehicle sýnýfýmýz soyut bir sýnýf oldu ve nesne üretilemez
	//ama vehicle sýnýfýndan miras alan sýnýflar nesne üretebilir
	//abstraction iþlemi

};


class Car : public Vehicle {
public:

	Car(double car_price, string car_brand): Vehicle(car_price,car_brand){
		cout << "Car constructor worked" << endl;
	}

	void increaseSpeed() {
		if (getisWork()) {
			int speed_temp = getSpeed();
			if (speed_temp <= 120) {
				int gear_temp = getgearNumber();
				setSpeed(speed_temp + 30);
				if (gear_temp < 6) {
					setgearNumber(gear_temp + 1);
				}
			}

		}
		else {
			cout << "You should start the engine" << endl;
		}
	}

	void decreaseSpeed() {
		if (getisWork()) {
			int speed_temp = getSpeed();
			if (speed_temp >=30) {
				int gear_temp = getgearNumber();
				setSpeed(speed_temp -30);
				if (gear_temp >=2) {
					setgearNumber(gear_temp - 1);
				}
			}

		}
		else {
			cout << "You should start the engine" << endl;
		}

	}

	void displayInformation() {
		cout << "----------------CAR INFORMATIONS-------------------" << endl;
		Vehicle::displayInformation();
	}

};

class MotorCycle :public Vehicle {
public:
	MotorCycle(double motor_price, string motor_brand) : Vehicle(motor_price, motor_brand) {
		cout << "Motorcycle constructor worked" << endl;
	}

	void increaseSpeed() {
		if (getisWork()) {
			int speed_temp = getSpeed();
			if (speed_temp <= 90) {
				int gear_temp = getgearNumber();
				setSpeed(speed_temp + 20);
				if (gear_temp < 6) {
					setgearNumber(gear_temp + 1);
				}
			}
		}
		else {
			cout << "You should start the engine" << endl;
		}
	}

	void decreaseSpeed() {
		if (getisWork()) {
			int speed_temp = getSpeed();
			if (speed_temp > 20) {
				int gear_temp = getgearNumber();
				setSpeed(speed_temp - 20);
				if(gear_temp>1){
					setgearNumber(gear_temp - 1);
				}
			}
		}
		else {
			cout<<"You should start the engine" << endl;
		}
	}

	void displayInformation() {
		cout << "----------MOTORCYCLE INFORMATIONS---------------" << endl;
		Vehicle::displayInformation();
	}

};