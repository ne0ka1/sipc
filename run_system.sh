#!/bin/bash
command cd build 
command cmake ..
command make -j19
command cd ../bin/
command ./runtests.sh -s
