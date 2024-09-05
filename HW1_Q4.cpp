#include<systemc.h>

SC_MODULE(gas_station) {
	sc_event request1, request2, tank1_full, tank2_full;
	int tank1, tank2, filling;
	int request1_active = 0;
	int request2_active = 0;
	SC_CTOR(gas_station) {
		tank1 = 0;
		tank2 = 0;
		filling = false;
		SC_THREAD(attendant);
		SC_THREAD(customer1);
		SC_THREAD(customer2);
	}
	void attendant();
	void customer1();
	void customer2();
};

void gas_station::customer1() {
	while (true) {
		wait(SC_ZERO_TIME);
		tank1 = 0;
		cout << "new request from customer1" << endl;
		do {
			request1.notify();
			wait(tank1_full); // Use static sensitivity
		} while (tank1 == 0);
	}
}
void gas_station::attendant() {
	while (true) {
		wait(request1 | request2);
		if (!filling) {
			filling = true;
		}
		if (request1.triggered()) { request1_active = 1; }
		if (request2.triggered()) { request2_active = 1; }
		wait(sc_time(10, SC_NS));	//models the time to fill a tank

			if (request1_active) {
				tank1 = 100;	//prevent infinite do-while loop in customer1
				cout << "tank1 filled at: " << sc_time_stamp() << ", current value of tank1 is " << tank1 << endl;
				request1_active = 0;
				tank1_full.notify(SC_ZERO_TIME);
			}
			if (request2_active) {
				tank2 = 100;	//prevent infinite do-while loop in customer2
				cout << "tank2 filled at: " << sc_time_stamp() << ". current value of tank2 is " << tank2 << endl;
				request2_active = 0;
				tank2_full.notify(SC_ZERO_TIME);
			}
			filling = false;	//Assuming attendant can fill two customers' tanks simultaneously
		}
}

void gas_station::customer2() {
	while (true) {
		wait(SC_ZERO_TIME);
		tank2 = 0;
		cout << "new request from customer2" << endl;
		do {
			request2.notify();
			wait(tank2_full); // dynamic sensitivity
		} while (tank2 == 0);
	}
}

int sc_main(int argc, char* argv[]) {
	gas_station object("gas_station1");
	sc_start(sc_time(50, SC_NS));
	return 0;
}
