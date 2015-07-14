/// $Id: main.cpp 174 2011-04-12 20:30:36Z sunzhennian $
///
/// \file
/// \brief Top entry of the system-level simulator
///
/// LTE-SLS - C++ based 3GPP LTE/LTE-Advanced system-level simulator
///
/// Copyright (C) 2008-2009 NEC Laboratories China. All right reserved.
/// (see AUTHORS file for a list of contributors)

#include "base/include.hpp"
#include "base/directory.hpp"
#include "simulator/parameters.hpp"
#include "simulator/bs_manager.hpp"
#include "simulator/link_matrix.hpp"
#include "simulator/ue_manager.hpp"
#include "ran/bts.hpp"
#include "base/observer.hpp"
#include "simulator/simulator.hpp"
#include "base/point_3d.hpp"
#include "fstream"
#include "simulator/clock.hpp"
#include "simulator/bs_manager.hpp"
#include "simulator/link_matrix.hpp"
#include "simulator/ue_manager.hpp"
#include "statistics/statistics.hpp"
#include "simulator/parameters.hpp"
#include "channel/wrap_around.hpp"
#include "simulator/link_interface.hpp"
#include "ran/ue.hpp"

using namespace lte_sls;
int main()
{
	progress_timer stimer;
	itpp::Real_Timer timer;
	//	Parameters::Instance().LoadPara();
	timer.tic();
	char* filename = (char*) "/simulationTime";
	filename = Directory::Instance().GetPath(filename);
	ofstream ftime;
	ftime.open(filename, ios::app);
	if (P.Simulation.BRandom == true)
	{
		itpp::RNG_randomize();
	}
	Simulator::Instance().SystemRun();
	double time = timer.toc();
	int day = time / (60 * 60 * 24);
	int hour = (time - day * (60 * 60 * 24)) / (60 * 60);
	int min = (time - day * (60 * 60 * 24) - hour * 3600) / 60;
	double sec = time - day * (60 * 60 * 24) - hour * 3600 - min * 60;
	ftime << "Total simulation time is " << day << " day " << hour << " hour "
			<< min << " min " << sec << " sec " << endl;
	cout << "Total simulation time is " << day << " day " << hour << " hour "
			<< min << " min " << sec << " sec " << endl;
	return 0;
}

