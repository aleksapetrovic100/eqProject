#ifndef _SORT_ACC_CA_CALCULATE_HPP_
#define _SORT_ACC_CA_CALCULATE_HPP_

#include <systemc>
#include <sysc/datatypes/fx/sc_fixed.h>
#include <complex>
#include "math.h"

#define package_length 1024
#define number_of_amplifications 10
#define number_of_boundaries 9
#define NN 1024

using namespace std;
using namespace sc_dt;
typedef complex<double> dcomp;

SC_MODULE(sort_acc_ca_calculate)
{
public:
	SC_HAS_PROCESS(sort_acc_ca_calculate);

	sort_acc_ca_calculate(sc_core::sc_module_name);

	sc_core::sc_in< bool > axi_aclk;
	sc_core::sc_in< bool > axi_aresetn;

	sc_core::sc_in<sc_lv<7>> 	s00_axil_awaddr	;
	sc_core::sc_in<sc_logic>	s00_axil_awvalid	;
	sc_core::sc_out<sc_logic>	s00_axil_awready	;
	sc_core::sc_in<sc_lv<32>> 	s00_axil_wdata	;
    sc_core::sc_in<sc_logic> 	s00_axil_wvalid	;
	sc_core::sc_out<sc_logic> 	s00_axil_wready	;
	sc_core::sc_out<sc_logic> 	s00_axil_bvalid	;
	sc_core::sc_in<sc_logic> 	s00_axil_bready	;

	sc_core::sc_out< sc_dt::sc_logic > s01_axis_tready;
	sc_core::sc_in< sc_dt::sc_lv<48> >s01_axis_tdata;
	sc_core::sc_in< sc_dt::sc_logic > s01_axis_tvalid;

	sc_core::sc_in< sc_dt::sc_logic > m00_axis_tready;
	sc_core::sc_out< sc_dt::sc_lv<48> > m00_axis_tdata;
	sc_core::sc_out< sc_dt::sc_logic > m00_axis_tvalid;

protected:
    /*** MAIN METHOD ***/
	void sort();

    /*** AUXILIARY VARIABLES ***/
	unsigned int arsize, N;
	typedef sc_dt::sc_fixed<24,1> num_t;
	num_t x_re2[1024];
	num_t x_im2[1024];
    sc_uint<32> data_p[10];
    sc_uint<7> adress_p[10];
    unsigned int pp[number_of_amplifications];
    double p[number_of_amplifications];
    sc_uint<32> data_pr[9];
    sc_uint<7> adress_pr[9];
    unsigned int pr[number_of_boundaries];
};

#endif
