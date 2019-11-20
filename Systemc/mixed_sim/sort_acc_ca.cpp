#include "sort_acc_ca.hpp"
#ifdef COSIM
#include "sort_acc_ca_calculate_rtl.hpp"
#else
#include "sort_acc_ca_calculate.hpp"
#endif

using namespace sc_core;
using namespace sc_dt;
using namespace std;

sort_acc_ca::sort_acc_ca(sc_module_name name) :
	sc_module(name),
	axi_aclk("m_axi_aclk", 100, SC_NS, 0.4, 5, SC_NS, true),
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
#ifndef COSIM
	core = new sort_acc_ca_calculate("core");

	core->axi_aclk(axi_aclk);
	core->s00_axil_awaddr(s00_axil_awaddr);
	core->s00_axil_awvalid(s00_axil_awvalid);
	core->s00_axil_awready(s00_axil_awready);
	core->s00_axil_wdata(s00_axil_wdata);
	core->s00_axil_wvalid(s00_axil_wvalid);
	core->s00_axil_wready(s00_axil_wready);
	core->s00_axil_bvalid(s00_axil_bvalid);
	core->s00_axil_bready(s00_axil_bready);

	core->s01_axis_tready(s01_axis_tready);
	core->s01_axis_tdata(s01_axis_tdata);
	core->s01_axis_tvalid(s01_axis_tvalid);

	core->m00_axis_tready(m00_axis_tready);
	core->m00_axis_tdata(m00_axis_tdata);
	core->m00_axis_tvalid(m00_axis_tvalid);
    core->axi_aresetn(axi_aresrtn);
#else
	core = new sort_acc_ca_calculate("core", "sort_acc_ca_calculate");
	core->axi_aclk(axi_aclk);
	core->s00_axil_awaddr(s00_axil_awaddr);
	core->s00_axil_awvalid(s00_axil_awvalid);
	core->s00_axil_awready(s00_axil_awready);
	core->s00_axil_wdata(s00_axil_wdata);
	core->s00_axil_wvalid(s00_axil_wvalid);
	core->s00_axil_wready(s00_axil_wready);
	core->s00_axil_bvalid(s00_axil_bvalid);
	core->s00_axil_bready(s00_axil_bready);
	core->s01_axis_tready(s01_axis_tready);
	core->s01_axis_tdata(s01_axis_tdata);
	core->s01_axis_tvalid(s01_axis_tvalid);
	core->m00_axis_tready(m00_axis_tready);
	core->m00_axis_tdata(m00_axis_tdata);
	core->m00_axis_tvalid(m00_axis_tvalid);
    core->axi_aresetn(axi_aresrtn);
#endif
}
void sort_acc_ca::axil_write(const sc_uint<32> &data,const unsigned int &address)
{
	//rst.write(false); //Negative reset
	wait(axi_aclk.posedge_event());
	s00_axil_awaddr  = address*4;
	s00_axil_awvalid = SC_LOGIC_1;
	s00_axil_wdata   = data;
	s00_axil_wvalid  = SC_LOGIC_1;
	s00_axil_bready  = SC_LOGIC_1;

	while(1)
	{
		wait(axi_aclk.posedge_event());
		if(s00_axil_awready == SC_LOGIC_1)
			break;
	}

	s00_axil_awvalid = SC_LOGIC_0;
	s00_axil_awaddr	= 0;

	while(1)
	{
		wait(axi_aclk.posedge_event());
		if(s00_axil_wready == SC_LOGIC_1)
			break;
	}

	s00_axil_wdata = 0;
	s00_axil_wvalid = SC_LOGIC_0;

	while(1)
	{
		wait(axi_aclk.posedge_event());
		if(s00_axil_bvalid == SC_LOGIC_1)
			break;
	}

	s00_axil_bready = SC_LOGIC_0;
	cout<<"AXIL WRITE Transaction translated. \n";
}

void sort_acc_ca::axis_write(const std::vector< sc_uint<48> > &data)
{
	m00_axis_tready.write(SC_LOGIC_0);
	s01_axis_tvalid.write(SC_LOGIC_0);
    wait(axi_aclk.negedge_event());

	for (size_t i = 0; i != data.size(); i++)
	{
		s01_axis_tdata = (sc_lv<48>)data[i];
		s01_axis_tvalid = SC_LOGIC_1;
		while(true)
		{
			wait(axi_aclk.negedge_event());

			if (s01_axis_tready == SC_LOGIC_1)
                break;
		}
	}
	s01_axis_tvalid = SC_LOGIC_0;
	cout << "Transaction translated.\n";
}

void sort_acc_ca::axis_read(std::vector< sc_uint<48> > &data)
{
	data.clear();
	m00_axis_tready = SC_LOGIC_1;
    wait(axi_aclk.negedge_event());
    int i = 0;

	while(1)
	{
		wait(axi_aclk.negedge_event());

        if (m00_axis_tvalid == SC_LOGIC_1)
		{
			data.push_back((sc_uint<48>)m00_axis_tdata);
            i++;
		}
		else if(i == 1024)
            break;
    }
	m00_axis_tready = SC_LOGIC_0;
}

void sort_acc_ca::reset_hardware()
{
    axi_aresrtn.write(false);

    for (int i = 0; i != 10; ++i)
        wait(axi_aclk.negedge_event());

    axi_aresrtn.write(true);
}

void sc_trace(sc_core::sc_trace_file* tf, const sort_acc_ca& obj, const std::string& name)
{
	sc_trace(tf, obj.axi_aclk, name + ".axi_aclk");
	sc_trace(tf, obj.s01_axis_tready, name + ".s01_axis_tready");
	sc_trace(tf, obj.s01_axis_tdata, name + ".s01_axis_tdata");
	sc_trace(tf, obj.s01_axis_tvalid, name + ".s01_axis_tvalid");
	sc_trace(tf, obj.m00_axis_tready, name + ".m00_axis_tready");
	sc_trace(tf, obj.m00_axis_tdata, name + ".m00_axis_tdata");
	sc_trace(tf, obj.m00_axis_tvalid, name + ".m00_axis_tvalid");
    sc_trace(tf, obj.s00_axil_awaddr, name + ".s00_axil_awaddr");
    sc_trace(tf, obj.s00_axil_awvalid, name + ".s00_axil_awvalid");
    sc_trace(tf, obj.s00_axil_awready, name + ".s00_axil_awready");
    sc_trace(tf, obj.s00_axil_wdata, name + ".s00_axil_wdata");
    sc_trace(tf, obj.s00_axil_wvalid, name + ".s00_axil_wvalid");
    sc_trace(tf, obj.s00_axil_wready, name + ".s00_axil_wready");
    sc_trace(tf, obj.s00_axil_bvalid, name + ".s00_axil_bvalid");
    sc_trace(tf, obj.s00_axil_bready, name + ".s00_axil_bready");
}
