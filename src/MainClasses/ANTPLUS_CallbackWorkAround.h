#ifndef ANTPLUS_CALLBACKWORKAROUND_h
#define ANTPLUS_CALLBACKWORKAROUND_h
#include "ANT.h"

/* This file is a workaround for the function pointers, I apologize for it, its not pretty */

void onPacketErrorCallback(uint8_t error, uintptr_t data);
void onAcknowledgedDataCallback(AcknowledgedData& msg, uintptr_t data);
void onAdvancedBurstDataCallback(AdvancedBurstData& msg, uintptr_t data);
void onBroadcastDataCallback(BroadcastData& msg, uintptr_t data);
void onBurstTransferDataCallback(BurstTransferData& msg, uintptr_t data);
void onAdvancedBurstCapabilitiesConfigurationCallback(AdvancedBurstCapabilitiesConfiguration& msg, uintptr_t data);
void onAntVersionCallback(AntVersion& msg, uintptr_t data);
void onCapabilitiesCallback(Capabilities& msg, uintptr_t data);
void onChannelEventResponseCallback(ChannelEventResponse& msg, uintptr_t data);
void onChannelIdResponseCallback(ChannelIdResponse& msg, uintptr_t data);
void onChannelStatusCallback(ChannelStatus& msg, uintptr_t data);
void onEncryptionModeParametersCallback(EncryptionModeParameters& msg, uintptr_t data);
void onEventFilterCallback(EventFilter& msg, uintptr_t data);
void onSelectiveDataUpdateMaskSettingCallback(SelectiveDataUpdateMaskSetting& msg, uintptr_t data);
void onStartUpMessageCallback(StartUpMessage& msg, uintptr_t data);

#endif // ANTPLUS_CALLBACKWORKAROUND_h