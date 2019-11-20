#include "sort_acc_ca_calculate.hpp"

using namespace sc_core;
using namespace sc_dt;
using namespace std;

sort_acc_ca_calculate::sort_acc_ca_calculate(sc_module_name name) :
	sc_module(name)
{
	SC_CTHREAD(sort, axi_aclk.pos());
	reset_signal_is(axi_aresetn,false);
}

void sort_acc_ca_calculate::sort()
{
    /*** READ AMPLIFICATIONS ***/
    for(int i = 0; i < 10; i++)
    {
        cout << "Starting P...\n";
        wait();
        s00_axil_bvalid.write(SC_LOGIC_0);
        s00_axil_awready.write(SC_LOGIC_0);
        s00_axil_wready.write(SC_LOGIC_0);
        wait();

        while(1)
        {
            wait();
            if(s00_axil_awvalid.read() == SC_LOGIC_1)
                adress_p[i] = (sc_uint<7>)s00_axil_awaddr.read();
            if(s00_axil_wvalid.read() == SC_LOGIC_1)
                data_p[i] = (sc_uint<32>)s00_axil_wdata.read();
            if(s00_axil_bready.read() == SC_LOGIC_1)
                break;
        }
        wait();
        s00_axil_awready.write(SC_LOGIC_1);
        s00_axil_wready.write(SC_LOGIC_1);

        wait();

        s00_axil_bvalid.write(SC_LOGIC_1);

        cout << "amplification[" <<i<<"] receved."<<endl;
        wait();
    }
    /*** READ BOUNDARIES ***/
    for(int i = 0; i < 9; i++)
    {
        cout << "Starting PR...\n";
        wait();
        s00_axil_bvalid.write(SC_LOGIC_0);
        s00_axil_awready.write(SC_LOGIC_0);
        s00_axil_wready.write(SC_LOGIC_0);
        wait();

        while(1)
        {
            wait();
            if(s00_axil_awvalid.read() == SC_LOGIC_1)
                adress_pr[i] = (sc_uint<7>)s00_axil_awaddr.read();
            if(s00_axil_wvalid.read() == SC_LOGIC_1)
                data_pr[i] = (sc_uint<32>)s00_axil_wdata.read();
            if(s00_axil_bready.read() == SC_LOGIC_1)
                break;
        }
        wait();
        s00_axil_awready.write(SC_LOGIC_1);
        s00_axil_wready.write(SC_LOGIC_1);

        wait();

        s00_axil_bvalid.write(SC_LOGIC_1);

        cout << "boundary[" << i<<"] receved."<<endl;
        wait();
    }

    for(int i = 0; i < number_of_amplifications; i++)
    {
        pp[i] = data_p[i];
        p[i] = (double)pp[i] / (1 << 22);
        cout << "amplification["<<i<<"] = " <<p[i]<<",  address-> "<<adress_p[i]  <<endl;
    }
    for(int i = 0; i < number_of_boundaries; i++)
    {
        pr[i] = data_pr[i];
        cout << "amplification["<<i<<"] = " <<pr[i]<<",  address-> "<<adress_pr[i]  <<endl;
    }

    /*** EQUALIZER EVALUATION ***/
	while(1)
	{
        cout << "Starting...\n";
		arsize = 0;
		m00_axis_tvalid.write(SC_LOGIC_0);
		s01_axis_tready.write(SC_LOGIC_1);
		wait();

		while(1)
		{
            wait();

            if(arsize == 1024)
                break;
			else if (s01_axis_tvalid.read() == SC_LOGIC_1)
			{

                sc_uint<48> x = s01_axis_tdata.read();
                sc_uint<24> x_ree = x & 0x000000ffffff;
                sc_uint<24> x_imm = (x & 0xffffff000000) >> 24 ;
                unsigned int x_reee = x_ree;
                unsigned int x_immm = x_imm;
                x_re2[arsize] = double(x_reee) / (1 << 23);
                x_im2[arsize] = double(x_immm) / (1 << 23);
                arsize++;
			}
		}

		cout << "Received transaction of size " << arsize << endl;
		s01_axis_tready.write(SC_LOGIC_0);

        /*** AUXILIARY VARIABLES ***/
		N = arsize;
        double *x_re1 = new double[package_length];
        double *x_im1 = new double[package_length];
        double *y_re1 = new double[package_length];
        double *y_im1 = new double[package_length];

		/*** READ AUDIO SAMPLES ***/
        for(unsigned int i = 0; i < N; i++)
        {
            x_re1[i] = x_re2[i].to_double();
            x_im1[i] = x_im2[i].to_double();
        }

        /*** MULTIPLY EACH FREQUENCY RANGE WITH CORRESPONDING AMPLIFICATION ***/
        double k = p[0];
        for(unsigned int i=0; i<N; i++)
        {
            if(i == pr[0])
                k = p[1];
            else if(i == pr[1])
                k = p[2];
            else if(i == pr[2])
                k = p[3];
            else if(i == pr[3])
                k = p[4];
            else if(i == pr[4])
                k = p[5];
            else if(i == pr[5])
                k = p[6];
            else if(i == pr[6])
                k = p[7];
            else if(i == pr[7])
                k = p[8];
            else if(i == pr[8])
                k = p[9];
            else if(i == (N+1 - pr[8]))
                k = p[8];
            else if(i == (N+1 - pr[7]))
                k = p[7];
            else if(i == (N+1 - pr[6]))
                k = p[6];
            else if(i == (N+1 - pr[5]))
                k = p[5];
            else if(i == (N+1 - pr[4]))
                k = p[4];
            else if(i == (N+1 - pr[3]))
                k = p[3];
            else if(i == (N+1 - pr[2]))
                k = p[2];
            else if(i == (N+1 - pr[1]))
                k = p[1];
            else if(i == (N+1 - pr[0]))
                k = p[0];

            y_re1[i] = x_re1[i]*k;
            y_im1[i] = x_im1[i]*k;
        }
        delete[] x_re1;
        delete[] x_im1;

        /*** DELAY OF CYCLE ACCURATE CORE ***/
        for(int i =0; i <3; i++)
            wait();

		cout << "Cycle accurate core done equalizing.\n";

		unsigned int i = 0;
		sc_fixed<24, 1> buff_re = y_re1[0];
        unsigned int b_re = buff_re << 23;
        sc_uint<24> buf_re = b_re;

        sc_fixed<24, 1> buff_im = y_im1[0];
        unsigned int b_im = buff_im << 23;
        sc_uint<24> buf_im = b_im;

		sc_fixed<24, 1> buff1_re = y_re1[1];
		unsigned int b1_re = buff1_re << 23;
		sc_uint<24> buf1_re = b1_re;

        sc_fixed<24, 1> buff1_im = y_im1[1];
		unsigned int b1_im = buff1_im << 23;
		sc_uint<24> buf1_im = b1_im;

		/*** WRITE EQUALIZED AUDIO SAMPLES ON HARDWARE OUTPUT ***/
		while(i != N)
		{
			wait();
			m00_axis_tvalid.write(SC_LOGIC_1);
			m00_axis_tdata.write((buf_im << 24) | buf_re);

            if (m00_axis_tready.read() == SC_LOGIC_1)
			{
				i++;
				buf_re = buf1_re;
				buf_im = buf1_im;

				buff1_re = y_re1[i+1];
				buff1_im = y_im1[i+1];

                b1_re = buff1_re << 23;
                b1_im = buff1_im << 23;

                buf1_re = b1_re;
                buf1_im = b1_im;
			}
		}
		wait();
		m00_axis_tvalid.write(SC_LOGIC_0);
		delete[] y_re1;
		delete[] y_im1;
		cout << "Transaction sent from cycle accurate core.\n";
	}
}
