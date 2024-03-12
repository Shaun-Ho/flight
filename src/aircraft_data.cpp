#include <../include/aircraft_data.h>

BodyElement Aircraft_1[8];

void populate_aircraft(){

    Aircraft_1[0].mass = 6.56;
    Aircraft_1[0].coordinates_from_tail = Vector(14.5, 12.0, 2.5);
    Aircraft_1[0].local_inertia = Vector(13.92, 10.50, 24.00);
    Aircraft_1[0].incidence_angle = -3.5;
    Aircraft_1[0].dihedral_angle = 0.0;
    Aircraft_1[0].element_area = 31.2;
    Aircraft_1[0].flap_incidence = 0.0;

    Aircraft_1[1].mass = 7.31;
    Aircraft_1[1].coordinates_from_tail = Vector(14.5, 5.5, 2.5);
    Aircraft_1[1].local_inertia = Vector(21.95, 12.22, 33.67);
    Aircraft_1[1].incidence_angle = -3.5;
    Aircraft_1[1].dihedral_angle = 0.0;
    Aircraft_1[1].element_area = 36.4;
    Aircraft_1[1].flap_incidence = 0.0;

    Aircraft_1[2].mass = 7.31;
    Aircraft_1[2].coordinates_from_tail = Vector(14.5, -5.5, 2.5);
    Aircraft_1[2].local_inertia = Vector(21.95, 12.22, 33.67);
    Aircraft_1[2].incidence_angle = -3.5;
    Aircraft_1[2].dihedral_angle = 0.0;
    Aircraft_1[2].element_area = 36.4;
    Aircraft_1[2].flap_incidence = 0.0;

    Aircraft_1[3].mass = 6.56;
    Aircraft_1[3].coordinates_from_tail = Vector(14.5, -12.0, 2.5);
    Aircraft_1[3].local_inertia = Vector(13.92, 10.50, 24.00);
    Aircraft_1[3].incidence_angle = -3.5;
    Aircraft_1[3].dihedral_angle = 0.0;
    Aircraft_1[3].element_area = 31.2;
    Aircraft_1[3].flap_incidence = 0.0;

    Aircraft_1[4].mass = 2.62;
    Aircraft_1[4].coordinates_from_tail = Vector(3.03, 2.5, 3.0);
    Aircraft_1[4].local_inertia = Vector(0.837, 0.385, 1.206);
    Aircraft_1[4].incidence_angle = 0.0;
    Aircraft_1[4].dihedral_angle = 0.0;
    Aircraft_1[4].element_area = 10.8;
    Aircraft_1[4].flap_incidence = 0.0;

    Aircraft_1[5].mass = 2.62;
    Aircraft_1[5].coordinates_from_tail = Vector(3.03, -2.5, 3.0);
    Aircraft_1[5].local_inertia = Vector(0.837f, 0.385, 1.206);
    Aircraft_1[5].incidence_angle = 0.0;
    Aircraft_1[5].dihedral_angle = 0.0;
    Aircraft_1[5].element_area = 10.8;
    Aircraft_1[5].flap_incidence = 0.0;

    Aircraft_1[6].mass = 2.93;
    Aircraft_1[6].coordinates_from_tail = Vector(2.25, 0.0, 5.0);
    Aircraft_1[6].local_inertia = Vector(1.262, 1.942, 0.718);
    Aircraft_1[6].incidence_angle = 0.0;
    Aircraft_1[6].dihedral_angle = 90.0;
    Aircraft_1[6].element_area = 12.0;
    Aircraft_1[6].flap_incidence = 0.0;

    Aircraft_1[7].mass = 31.8;
    Aircraft_1[7].coordinates_from_tail = Vector(15.25, 0.0, 1.5);
    Aircraft_1[7].local_inertia = Vector(66.30, 861.9, 861.9);
    Aircraft_1[7].incidence_angle = 0.0;
    Aircraft_1[7].dihedral_angle = 0.0;
    Aircraft_1[7].element_area = 84.0;
    Aircraft_1[7].flap_incidence = 0.0;
}