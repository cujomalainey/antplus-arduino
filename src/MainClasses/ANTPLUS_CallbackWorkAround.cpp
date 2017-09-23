#include <MainClasses/ANTPLUS_CallbackWorkAround.h>
#include <MainClasses/ANTPLUS_AntPlusRouter.h>

/**
 * The author apologies for this code.
 * If you know a better way without changing
 * the callback signature in the ant-arduino repo,
 * then please send a pull request or contact me.
 *
 * this solution allows users to use ther own
 * function callbacks while still allowing multiple
 * drivers/routers on the same system.
 */

void onPacketErrorCallback(uint8_t error, uintptr_t data) {
    AntPlusRouter* router = (AntPlusRouter*)data;
    router->onPacketError(error);
}

void onAcknowledgedDataCallback(AcknowledgedData& msg, uintptr_t data) {
    AntPlusRouter* router = (AntPlusRouter*)data;
    router->onAcknowledgedData(msg);
}

void onAdvancedBurstDataCallback(AdvancedBurstData& msg, uintptr_t data) {
    AntPlusRouter* router = (AntPlusRouter*)data;
    router->onAdvancedBurstData(msg);
}

void onBroadcastDataCallback(BroadcastData& msg, uintptr_t data) {
    AntPlusRouter* router = (AntPlusRouter*)data;
    router->onBroadcastData(msg);
}

void onBurstTransferDataCallback(BurstTransferData& msg, uintptr_t data) {
    AntPlusRouter* router = (AntPlusRouter*)data;
    router->onBurstTransferData(msg);
}

void onAdvancedBurstCapabilitiesConfigurationCallback(AdvancedBurstCapabilitiesConfiguration& msg, uintptr_t data) {
    AntPlusRouter* router = (AntPlusRouter*)data;
    router->onAdvancedBurstCapabilitiesConfiguration(msg);
}

void onAntVersionCallback(AntVersion& msg, uintptr_t data) {
    AntPlusRouter* router = (AntPlusRouter*)data;
    router->onAntVersion(msg);
}

void onCapabilitiesCallback(Capabilities& msg, uintptr_t data) {
    AntPlusRouter* router = (AntPlusRouter*)data;
    router->onCapabilities(msg);
}

void onChannelEventResponseCallback(ChannelEventResponse& msg, uintptr_t data) {
    AntPlusRouter* router = (AntPlusRouter*)data;
    router->onChannelEventResponse(msg);
}

void onChannelIdResponseCallback(ChannelIdResponse& msg, uintptr_t data) {
    AntPlusRouter* router = (AntPlusRouter*)data;
    router->onChannelIdResponse(msg);
}

void onChannelStatusCallback(ChannelStatus& msg, uintptr_t data) {
    AntPlusRouter* router = (AntPlusRouter*)data;
    router->onChannelStatus(msg);
}

void onEncryptionModeParametersCallback(EncryptionModeParameters& msg, uintptr_t data) {
    AntPlusRouter* router = (AntPlusRouter*)data;
    router->onEncryptionModeParameters(msg);
}

void onEventFilterCallback(EventFilter& msg, uintptr_t data) {
    AntPlusRouter* router = (AntPlusRouter*)data;
    router->onEventFilter(msg);
}

void onSelectiveDataUpdateMaskSettingCallback(SelectiveDataUpdateMaskSetting& msg, uintptr_t data) {
    AntPlusRouter* router = (AntPlusRouter*)data;
    router->onSelectiveDataUpdateMaskSetting(msg);
}

void onStartUpMessageCallback(StartUpMessage& msg, uintptr_t data) {
    AntPlusRouter* router = (AntPlusRouter*)data;
    router->onStartUpMessage(msg);
}
