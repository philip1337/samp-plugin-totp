#ifndef SAMPLOG_NATIVES_HPP
#define SAMPLOG_NATIVES_HPP

#include "plugin.h"

SAMPTOTP_BEGIN_NS

#define AMX_NATIVE(native, argc) \
	cell AMX_NATIVE_CALL Natives::native(AMX *amx, cell *params) { \
		AMX_CHECK_PARAMS(argc, native)

#define AMX_NATIVE_END }

#define AMX_DECLARE_NATIVE(native) \
	cell AMX_NATIVE_CALL native(AMX *amx, cell *params)

#define AMX_DEFINE_NATIVE(native) \
	{#native, SAMPTOTP_NS::Natives::native},

#define AMX_CHECK_PARAMS(count, fname) \
	if (params[0] < (count * sizeof(cell))) \
	{ \
		logprintf("[TOTP] Fatal Error calling '%s': expecting >= %d parameter(s), but found < %d", #fname, count, params[0] / sizeof(cell)); \
		return 0; \
	}

namespace Natives
{
	AMX_DECLARE_NATIVE(Totp);
	AMX_DECLARE_NATIVE(TotpEx);
};

SAMPTOTP_END_NS
#endif