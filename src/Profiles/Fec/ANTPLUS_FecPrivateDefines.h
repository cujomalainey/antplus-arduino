#ifndef ANTPLUS_FECPROFILEPRIVATEDEFINES_h
#define ANTPLUS_FECPROFILEPRIVATEDEFINES_h

#include <Profiles/Fec/ANTPLUS_FecDefines.h>

/* Channel Config */
#define ANTPLUS_FEC_MONITOR_CHANNELTYPE CHANNEL_TYPE_BIDIRECTIONAL_TRANSMIT
#define ANTPLUS_FEC_CHANNELPERIOD 8192
// 30 / 2.5 = 12
#define ANTPLUS_FEC_SEARCHTIMEOUT 12

// Field common to some base messages
#define FESTATE_BYTE        7
#define FESTATE_MASK        0x70
#define FESTATE_SHIFT       4
#define LAPTOGGLEBIT_BYTE   7
#define LAPTOGGLEBIT_MASK   0x80
#define LAPTOGGLEBIT_SHIFT  7

#endif // ANTPLUS_FECPROFILEPRIVATEDEFINES_h
