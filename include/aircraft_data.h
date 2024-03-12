#pragma once
#include <maths.h>

void populate_aircraft();

enum AircraftModel {
    AIRCRAFT_1,
    AIRCRAFT_2
};

typedef struct _BodyElement{
	double	mass;
	Vector	coordinates_from_tail;
	Vector	center_of_gravity;
	Vector	local_inertia;
	double	incidence_angle;
	double	dihedral_angle;
	Vector	normal_vector;
	double	element_area;
	int		flap_incidence;

} BodyElement, *pBodyElement;

extern BodyElement Aircraft_1[8];