#include "sort_gen_check.hpp"

using namespace std;
using namespace sc_dt;
using namespace sc_core;



sort_gen_check::sort_gen_check(sc_module_name name) :
	sc_module(name)
{
  cout << "Constructed\n";
  SC_THREAD(test);
}

void sort_gen_check::test()
{
    coef c;
    unsigned int p_adress[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    unsigned int pr_adress[9] = {10, 11, 12, 13, 14, 15, 16, 17, 18};

    /*** RESET HARDWARE ***/
    reset->reset_hardware();

    /*** SEND AMPLIFICATION ***/
    for(int i = 0; i < 10; i++)
    {
        cout << "Generate transaction of amplification [" << i << "].\n";
        cout << "Transaction sent.\n";
        wr_lite_port->axil_write((sc_uint<32>)c.p[i],p_adress[i]);
    }

    /*** SEND BOUNDARIES ***/
    for(int i = 0; i < 9; i++)
    {
        cout << "Transaction of boundary [" << i << "] sent.\n";
        wr_lite_port->axil_write((sc_uint<32>)c.pr[i],pr_adress[i]);
    }

    /*** EQUALSATION PROCESS FOR EACH PACKAGE OF THE SONG ***/
    for(int i = 0; i != 1; i++)
	{
        /*** READ PACKAGE ***/
        cout << "Generate transaction of " << package_length << " audio_frames.\n";
        for (int j=0; j != package_length; ++j)
        {
            sc_uint<24> x_ree = c.x_re[package_length*i + j];
            sc_uint<24> x_imm = c.x_im[package_length*i + j];
            sc_uint<48> x = (x_imm << 24) | x_ree;
            tran.push_back(x);
		}

        /*** WRITE PACKAGE, AMPLIFICATIONS AND BOUDARIES TO HARDWARE ***/
        cout << "Transaction sent.\n";
        wr_port->axis_write(tran);

        /*** READ PACKAGE FROM HARDWARE ***/
        rd_port->axis_read(res);

        for(size_t j = 0; j <res.size(); j++)
        {
            sc_uint<48> y = res[j];
            sc_uint<24> y_ree = y & 0x000000ffffff;
            sc_uint<24> y_imm = (y & 0xffffff000000) >> 24;
            output_re.push_back(y_ree);
            output_im.push_back(y_imm);
        }
        cout << "Transaction received.\n";

        /*** CHECKING ***/
        if(tran.size() != res.size())
		{
            cout << "Test failed.\n";
            cout << "Expected size " << tran.size() << endl;
            cout << "Received size " << res.size() << endl;
            return;
		}
        tran.clear();
        res.clear();

        for (size_t ii = 0; ii != output_re.size(); ++ii)
		{
            if(abs(int(c.y_re[ii]) - int(output_re[ii])) > 2) // tacnost 2^(-22)
			{
                cout << "Test " << i << " failed.\n";
                cout << "Elemnt with index " << ii << endl;
                cout << "Expected value " << c.y_re[ii] << endl;
                cout << "Received value " << output_re[ii] << endl;
                return;
			}
			if(abs(int(c.y_im[ii]) - int(output_im[ii])) > 2)
			{
                cout << "Test " << i << " failed.\n";
                cout << "Elemnt with index " << ii << endl;
                cout << "Expected value " << c.y_im[ii] << endl;
                cout << "Received value " << output_im[ii] << endl;
                return;
			}
		}
        output_re.clear();
        output_im.clear();

        cout << "Test " << i << " passed.\n";
	}
}
