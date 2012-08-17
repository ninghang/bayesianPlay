#include "ar_process.h"
#include <bfilt/simulator.h>
#include <bfilt/filter.h>


int main(int argc, char **argv)
{
AR_Process model;
G_Simulator sim(&model);
DD_Kalman
filter(&model);
// The AR model
// The simulator
// The Kalman filter
sim.Simulate(100);
sim.Save_Y("output.dat");
sim.Save_X("state.dat");
filter.Save_X("estimation.dat");
}
