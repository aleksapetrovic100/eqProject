#ifndef _SORT_GEN_CHECK_HPP_
#define _SORT_GEN_CHECK_HPP_

#include "coeficients.hpp"

#include "sort_ifs.hpp"
#include <systemc>
#include <sndfile.h>
#include <fstream>
#include <math.h>
#include <sysc/datatypes/fx/sc_fixed.h>

#define package_length 1024

typedef std::vector< sc_uint<48> > u48_array;
typedef std::vector< sc_uint<24> > u24_array;


SC_MODULE(sort_gen_check)
{
public:
	SC_HAS_PROCESS(sort_gen_check);

	sort_gen_check(sc_core::sc_module_name);

	sc_core::sc_port< axil_master_if > wr_lite_port;
	sc_core::sc_port< axis_master_if > wr_port;
	sc_core::sc_port< axis_slave_if > rd_port;
	sc_core::sc_port< reset_if > reset;
protected:
    /*** MAIN METHOD ***/
	void test();

    /*** AUXILIARY VARIABLES ***/
    u48_array tran, res;
    u24_array output_re, output_im;
};

#endif
