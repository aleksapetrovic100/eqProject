#ifndef _SCGENMOD_sort_acc_ca_calculate_
#define _SCGENMOD_sort_acc_ca_calculate_

#include "systemc.h"

class sort_acc_ca_calculate : public sc_foreign_module
{
public:
    sc_core::sc_in< bool > axi_aclk;
	sc_core::sc_in< bool > axi_aresetn;

	sc_core::sc_in<sc_lv<7>> 	s00_axil_awaddr	;
	sc_core::sc_in<sc_logic>	s00_axil_awvalid;
	sc_core::sc_out<sc_logic>	s00_axil_awready;
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


    sort_acc_ca_calculate(sc_module_name nm, const char* hdl_name,
       int num_generics, const char** generic_list)
     : sc_foreign_module(nm),
       axi_aclk("m_axi_aclk"),
        axi_aresrtn("axi_aresetn"),
        //AXI LITE
        s00_axil_awaddr("s00_axil_awaddr"),
        s00_axil_awvalid("s00_axil_awvalid"),
        s00_axil_awready("s00_axil_awready"),
        s00_axil_wdata("s00_axil_wdata"),
        s00_axil_wvalid("s00_axil_wvalid"),
        s00_axil_wready("s00_axil_wready"),
        s00_axil_bvalid("s00_axil_bvalid"),
        s00_axil_bready("s00_axil_bready"),
        //AXI STREAM SLAVE
        s01_axis_tready("s01_axis_tready"),
        s01_axis_tdata("s01_axis_tdata"),
        s01_axis_tvalid("s01_axis_tvalid"),
        //AXI STREAM MASTER
        m00_axis_tready("m00_axis_tready"),
        m00_axis_tdata("m00_axis_tdata"),
        m00_axis_tvalid("m00_axis_tvalid")
    {
        elaborate_foreign_module(hdl_name, num_generics, generic_list);
    }
    ~sort_acc_ca_calculate()
    {}

};

#endif

