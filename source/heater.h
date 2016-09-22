/*
heater.h
Class definition for the heating object
*/

#ifndef HEATER_H
#define HEATER_H

#include "helper.h"
#include "../rsp_toolkit/source/xmlreader.h"

// Heater object
//
// Class for configuring time-dependent heating profiles.
// Accepts a properly formatted XML node <heating_node> and
// calculates the heating rate at any time. Heating profiles
// must be specified in terms of <num_events> heating pulses
// plus a static background <background>.
//
class Heater {
private:

  /*Background heating rate*/
  double background;

  /* Number of events */
  int num_events;

  /*Starting time of the rise phase*/
  std::vector<double> time_start_rise;

  /*Ending time of the rise phase*/
  std::vector<double> time_end_rise;

  /*Starting time of the decay phase*/
  std::vector<double> time_start_decay;

  /*Ending time of the decay phase*/
  std::vector<double> time_end_decay;

  /*Magnitudes of the events*/
  std::vector<double> magnitude;

public:

  /* Partition of energy between electrons and ions; 1 corresponds to pure electron heating and 0 pure ion heating. For a single-fluid treatment, use 0.5 */
  double partition;

  // Default constructor
  // @heating_node XML node holding the heating information
  //
  Heater(tinyxml2::XMLElement * heating_node);

  /* Destructor */
  ~Heater(void);

  // Get heating at time <t>
  // @time current time
  //
  // Given the heating profile specified by the configuration file,
  // return the heating rate at the given time <time>
  //
  // @return heating rate at time <time>
  //
  double Get_Heating(double time);

};
typedef Heater* HEATER;

#endif