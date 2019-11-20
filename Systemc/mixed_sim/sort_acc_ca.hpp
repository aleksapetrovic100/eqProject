// Cycle accurate model of sort accelerator

#ifndef _SORT_ACC_CA_HPP_
#define _SORT_ACC_CA_HPP_

#include <systemc.h>
#include "sort_ifs.hpp"

using namespace sc_dt;

class sort_acc_ca_calculate;

class sort_acc_ca :
	public sc_core::sc_channel,
	public axil_master_if,
	public axis_master_if,
	public axis_slave_if,
	public reset_if
{
public:
	SC_HAS_PROCESS(sort_acc_ca);

	sort_acc_ca(sc_core::sc_module_name name);

	void axil_write(const sc_uint<32> &data,const unsigned int &address);
	void axis_write(const std::vector< sc_uint<48> >& data);
	void axis_read(std::vector< sc_uint<48> >& data);
	void reset_hardware();

	sc_core::sc_clock axi_aclk;
	sc_core::sc_signal< bool > axi_aresrtn;
    sc_core::sc_signal< sc_dt::sc_lv<7> > s00_axil_awaddr;
    sc_core::sc_signal< sc_dt::sc_logic >s00_axil_awvalid;
    sc_core::sc_signal< sc_dt::sc_logic > s00_axil_awready;
    sc_core::sc_signal< sc_dt::sc_lv<32> > s00_axil_wdata;
    sc_core::sc_signal< sc_dt::sc_logic > s00_axil_wvalid;
    sc_core::sc_signal< sc_dt::sc_logic > s00_axil_wready;
    sc_core::sc_signal< sc_dt::sc_logic > s00_axil_bvalid;
    sc_core::sc_signal< sc_dt::sc_logic > s00_axil_bready;
    sc_core::sc_signal< sc_dt::sc_logic > s01_axis_tready;
	sc_core::sc_signal< sc_dt::sc_lv<48> > s01_axis_tdata;
	sc_core::sc_signal< sc_dt::sc_logic > s01_axis_tvalid;
	sc_core::sc_signal< sc_dt::sc_logic > m00_axis_tready;
	sc_core::sc_signal< sc_dt::sc_lv<48> > m00_axis_tdata;
	sc_core::sc_signal< sc_dt::sc_logic > m00_axis_tvalid;

	friend void sc_trace(sc_core::sc_trace_file*, const sort_acc_ca&, const std::string& name);
protected:
	sort_acc_ca_calculate* core;
};

#endif
