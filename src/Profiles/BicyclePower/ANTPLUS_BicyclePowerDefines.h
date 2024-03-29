#ifndef ANTPLUS_BICYCLEPOWERPROFILEDEFINES_h
#define ANTPLUS_BICYCLEPOWERPROFILEDEFINES_h

#define ANTPLUS_BICYCLEPOWER_DEVICETYPE 11

/* Sensor Types */
#define ANTPLUS_BICYCLEPOWER_FLAGS_SENSORTYPE_POWERONLY       0
#define ANTPLUS_BICYCLEPOWER_FLAGS_SENSORTYPE_TORQUEWHEEL 		1
#define ANTPLUS_BICYCLEPOWER_FLAGS_SENSORTYPE_TORQUECRANK 		2
#define ANTPLUS_BICYCLEPOWER_FLAGS_SENSORTYPE_CTF          		3

/* DataPage Defines */
#define ANTPLUS_BICYCLEPOWER_DATAPAGES_GENERALCALIBRATION_NUMBER 		0x01


/* Standard Power Only */
#define ANTPLUS_BICYCLEPOWER_DATAPAGES_STANDARDPOWERONLY_NUMBER 		0x10

#define ANTPLUS_BICYCLEPOWER_DATAPAGES_STANDARDPOWERONLY_PEDALDIFFERENTIATION_RIGHT 1
#define ANTPLUS_BICYCLEPOWER_DATAPAGES_STANDARDPOWERONLY_PEDALPOWER_NOTUSED 0x7F
#define ANTPLUS_BICYCLEPOWER_DATAPAGES_STANDARDPOWERONLY_INSTANTANEOUSCADENCE_INVALID 0xFF


/* Standard Wheel Torque */
#define ANTPLUS_BICYCLEPOWER_DATAPAGES_STANDARDWHEELTORQUE_NUMBER 										0x11

#define ANTPLUS_BICYCLEPOWER_DATAPAGES_STANDARDWHEELTORQUE_INSTANTANEOUSCADENCE_INVALID 0xFF


/* Standard Crank Torque */
#define ANTPLUS_BICYCLEPOWER_DATAPAGES_STANDARDCRANKTORQUE_NUMBER 										0x12

#define ANTPLUS_BICYCLEPOWER_DATAPAGES_STANDARDCRANKTORQUE_INSTANTANEOUSCADENCE_INVALID 0xFF


/* Torqyue and Pedal Smoothness */
#define ANTPLUS_BICYCLEPOWER_DATAPAGES_TORQUEEFFECTIVENESSANDPEDALSMOOTHNESS_NUMBER 	0x13

#define ANTPLUS_BICYCLEPOWER_DATAPAGES_TORQUEEFFECTIVENESSANDPEDALSMOOTHNESS_TORQUEEFFECTIVENESS_INVALID 0xFF

#define ANTPLUS_BICYCLEPOWER_DATAPAGES_TORQUEEFFECTIVENESSANDPEDALSMOOTHNESS_PEDALSMOOTHNESS_INVALID 0xFF
#define ANTPLUS_BICYCLEPOWER_DATAPAGES_TORQUEEFFECTIVENESSANDPEDALSMOOTHNESS_RIGHTPEDALSMOOTHNESS_COMBINED 0xFE

/* Crank Torque Frequency */
#define ANTPLUS_BICYCLEPOWER_DATAPAGES_CRANKTORQUEFREQUENCY_NUMBER 									0x20


#endif // ANTPLUS_BICYCLEPOWERPROFILEDEFINES_h
