#ifndef _SORT_IFS_HPP_
#define _SORT_IFS_HPP_

#include <systemc>
#include <vector>

using namespace sc_dt;

class axil_master_if : virtual public sc_core::sc_interface
{
public:
	virtual void axil_write(const sc_uint<32> &data,const unsigned int &address) = 0;
};

class axis_master_if : virtual public sc_core::sc_interface
{
public:
	virtual void axis_write(const std::vector<sc_uint<48>>& data) = 0;
};

class axis_slave_if : virtual public sc_core::sc_interface
{
public:
	virtual void axis_read(std::vector<sc_uint<48>>& data) = 0;
};

class reset_if : virtual public sc_core::sc_interface
{
public:
	virtual void reset_hardware() = 0;
};

#endif
