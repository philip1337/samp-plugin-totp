/**
 * - SA-MP TOTP Plugin
 * - Author: ProMetheus (Sphinxila@Github)
 * - Description: TOTP Google Authenticator
 */

#include "Config.hpp"

// SAMP SDK & Totp handler
#include "plugin.h"
#include "Logprintf.hpp"

// Natives
#include "Natives.hpp"
#include <csignal>

// SA-MP Stuff
void **ppPluginData;
extern void *pAMXFunctions;

// @PluginLoad
PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData) {
	// AMX Stuff
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];

	// Show loading message
	logprintf(" ----------------------------------------------");
	logprintf("  Initializing samp-plugin-totp");
	logprintf("  https://github.com/Sphinxila/samp-plugin-totp");
	logprintf("  Author: ProMetheus(Sphinxila)");
	logprintf(" ----------------------------------------------");	
	return 1;
}

// @PluginUnload
PLUGIN_EXPORT void PLUGIN_CALL Unload() {
	// Unload message
	logprintf("Plugin samp-plugin-totp unloaded.");
}

// @Natives
const AMX_NATIVE_INFO natives[] = {
	AMX_DEFINE_NATIVE(Totp)
	AMX_DEFINE_NATIVE(TotpEx)
	{NULL, NULL}
};

// @AmxLoad
PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx) {
	return amx_Register(amx, natives, -1);
}

// @AmxUnload
PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx) {
	return AMX_ERR_NONE;
}

// @PluginSupports
PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
   return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}