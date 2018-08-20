
#! bin/sh
echo  “Running the Cmake File”
cmake .
ls -l Makefile
make
echo “Build Succeded”
echo “Running Program”
ls -l Lanedetection
./Lanedetection
