#include <systemc>
#include <string>
#include "tb_sort_acc.hpp"

using namespace sc_core;

int sc_main(int argc, char* argv[])
{
	std::string cfg("tlm");
	/*std::string cfgtmp;
	if (argc > 1)
		cfgtmp = argv[1];
	if (cfgtmp == "ca")
		cfg = "ca";*/
    cfg = "ca";

	tb_sort_acc tb("TB", cfg);

	sc_trace_file *wf = sc_create_vcd_trace_file("sort");
	sc_trace(wf, tb, "clk");

	sc_start(40, SC_SEC);

	sc_close_vcd_trace_file(wf);

    return 0;
}
