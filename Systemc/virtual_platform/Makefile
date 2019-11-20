vp_sim: hardware_calculate.cpp hardware.cpp software.cpp tb.cpp main.cpp
	g++ -o $@ $^ -DSC_INCLUDE_FX -w -g -I${SYSTEMC}/include -L${SYSTEMC}/lib-linux64 -lsystemc -lsndfile

clean:
	rm $(TARGET)
