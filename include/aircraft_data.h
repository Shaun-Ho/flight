#pragma once
#include <maths.h>

enum AircraftModel { AIRCRAFT_1, AIRCRAFT_2 };

typedef struct _BodyElement {
  double mass;
  Vector<double> coordinates_from_tail;
  Vector<double> local_inertia;
  double incidence_angle;
  double dihedral_angle;
  double element_area;
  double flap_incidence;
  Vector<double> center_of_gravity;
  Vector<double> normal_vector;

} BodyElement, *pBodyElement;

extern BodyElement Aircraft_1[8];
