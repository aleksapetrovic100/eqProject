vp_sim: sort_acc_ca_calculate.cpp sort_acc_ca.cpp sort_gen_check.cpp tb_sort_acc.cpp main.cpp
	g++ -o $@ $^ -DSC_INCLUDE_FX -w -g -I${SYSTEMC}/include -L${SYSTEMC}/lib-linux64 -lsystemc

clean:
	rm $(TARGET)
