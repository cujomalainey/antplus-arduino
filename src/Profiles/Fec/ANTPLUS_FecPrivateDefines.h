#ifndef ANTPLUS_FECPROFILEPRIVATEDEFINES_h
#define ANTPLUS_FECPROFILEPRIVATEDEFINES_h

#include <Profiles/Fec/ANTPLUS_FecDefines.h>

/* Channel Config */
#define ANTPLUS_FEC_DISPLAY_CHANNELTYPE CHANNEL_TYPE_BIDIRECTIONAL_RECEIVE
#define ANTPLUS_FEC_MONITOR_CHANNELTYPE CHANNEL_TYPE_BIDIRECTIONAL_TRANSMIT
#define ANTPLUS_FEC_CHANNELPERIOD 8192
// 30 / 2.5 = 12
#define ANTPLUS_FEC_SEARCHTIMEOUT 12

/* DataPages number */
#define ANTPLUS_FEC_MANUFACTURERINFORMATION_NUMBER 80
#define ANTPLUS_FEC_PRODUCT_INFORMATION_NUMBER 81
#define ANTPLUS_FEC_DATAPAGE_TRAINER_DATA_NUMBER 25
#define ANTPLUS_FEC_GENERAL_INFORMATION_NUMBER 16
#define ANTPLUS_FEC_GENERAL_SETTINGS_NUMBER 17
#define ANTPLUS_FEC_BASIC_RESISTANCE_NUMBER 48
#define ANTPLUS_FEC_TARGET_POWER_NUMBER 49
#define ANTPLUS_FEC_TRACK_RESISTANCE_NUMBER 51
#define ANTPLUS_FEC_CAPABILITIES_INFORMATION_NUMBER 54
#define ANTPLUS_FEC_USER_INFORMATION_NUMBER 55

#endif // ANTPLUS_FECPROFILEPRIVATEDEFINES_h
