#!/bin/bash

# 
if [ -f "dev2.4.exe" ]; then
	rm -f "dev2.4.exe"
fi

g++ -std=c++11 core/proto.cpp core/buffer.cpp core/timer.cpp core/inport.cpp core/outport.cpp gen/gen.class.cpp event/pitch_unit.cpp event/duration_unit.cpp dev2.4_main.cpp -o dev2.4.exe
exit 0