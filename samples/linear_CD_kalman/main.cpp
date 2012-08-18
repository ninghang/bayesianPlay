#include "ornstein_uhlenbeck.h"
#include <bfilt/simulator.h>
#include <bfilt/filter.h>

int main(int argc, char **argv)
{
    Ornstein_Uhlenbeck_Model model; // The model
    LTI_CD_Simulator sim(&model); // The simulator
    CD_Kalman filter(&model); // The Kalman filter
    
    sim.Simulate(10.);
    filter.Filtering(sim.Y);
    
    sim.Save_Y("output.dat");
    sim.Save_X("state.dat");
    
    filter.Save_X("estimation.dat");

    return 0;
}
