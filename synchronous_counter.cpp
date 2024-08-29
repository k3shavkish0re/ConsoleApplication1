//#include <systemc.h>
//
//SC_MODULE (SYNC_COUNTER){
//	sc_in<bool>			clk;
//	sc_in<bool>			reset_n;
//	sc_in<bool>			enable;
//	sc_out<sc_uint<3>>	count;
//
//	sc_uint<3>			wire_cntr;				//need to create a wire similarly to verilog
//
//	void start(){
//		if (reset_n.read() == 0) {
//			wire_cntr = 0;
//			count.write(wire_cntr);
//		}
//		else if (enable.read() == 1) {
//			wire_cntr = wire_cntr + 1;
//			count.write(wire_cntr);				//you cannot directly assign to outputs
//			cout << "AT " << sc_time_stamp() << ": counter value is " << count.read()<<endl;
//		}
//		else {
//			cout << "waiting for Enable to assert" << endl;
//		}
//	}
//
//
//	SC_CTOR (SYNC_COUNTER) {						//Methods, sensitivity list goes in constructor
//		cout << "starting new counter" << endl;
//		SC_METHOD(start);							
//		sensitive << clk.pos();						
//		sensitive << reset_n.neg();
//	}
//};
//
//int main() {
//	SYNC_COUNTER counter1("counter1");    //class_name instance_name ("counstructor argument") , constructor argument is necessary
//
//	sc_signal<bool>			reset_n_sig;
//	sc_signal<bool>			enable_sig;
//	sc_signal<sc_uint<3>>	count_sig;
//
//	sc_clock clk("clk", 10, SC_NS);
//
//
//	counter1.clk(clk);					//sc_clock creates a signal object named clk. Thus, connect directly
//	counter1.reset_n(reset_n_sig);
//	counter1.enable(enable_sig);
//	counter1.count(count_sig);
//
//	// Open VCD file
//	sc_trace_file* wf = sc_create_vcd_trace_file("counter");
//	// Dump the desired signals
//	sc_trace(wf, clk, "clock");
//	sc_trace(wf, reset_n_sig, "reset");
//	sc_trace(wf, enable_sig, "enable");
//	sc_trace(wf, count_sig, "count");
//
//
//
//	// Initialize signals
//	reset_n_sig = 0;  // Assert reset
//	enable_sig = 0;   // Ensure enable is deasserted
//
//	sc_start(10, SC_NS);  // Run simulation to apply reset
//
//	reset_n_sig = 1;      // Deassert reset
//	enable_sig = 1;       // Assert enable
//
//	sc_start(100, SC_NS); // Run simulation to observe counter behavior
//	sc_close_vcd_trace_file(wf);
//	
//	return 0;
//}
