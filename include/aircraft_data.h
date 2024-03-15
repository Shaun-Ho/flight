#pragma once
#include <maths.h>

enum AircraftModel { AIRCRAFT_1, AIRCRAFT_2 };

typedef struct _BodyElement {
  double mass;
  Vector coordinates_from_tail;
  Vector local_inertia;
  double incidence_angle;
  double dihedral_angle;
  double element_area;
  double flap_incidence;
  // Vector center_of_gravity;
  // Vector normal_vector;

} BodyElement, *pBodyElement;

extern BodyElement Aircraft_1[8];
