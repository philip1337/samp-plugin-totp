#include "Config.hpp"
#include "Logprintf.hpp"

#include "Natives.hpp"

#include <ctime>
#include <iostream>

#include <libcppotp\bytes.h>
#include <libcppotp\otp.h>

SAMPTOTP_BEGIN_NS

using namespace CppTotp;

/**
 * GetString
 * - Helper function
 */
const std::string GetString(AMX *amx, cell param)
{
	char *tmp;
	amx_StrParam(amx, param, tmp);
	return (tmp != NULL) ? tmp : std::string();
}

/**
 * native Totp(const secret[], step)
 */
AMX_NATIVE(Totp, 2)
	// Get params
	auto secret = GetString(amx, params[1]);
	
	// Addr
	cell *pAddr = nullptr;
	amx_GetAddr(amx, params[2], &pAddr);

	// Get number from ptr
	auto step = static_cast<int>(*pAddr);

	// Base32
	Bytes::ByteString qui = Bytes::fromUnpaddedBase32(secret);

	// Calculate TOTP
	auto code = CppTotp::totp(qui, std::time(nullptr), 0, step, 6);

	// Invalid
	return code;
AMX_NATIVE_END

/**
* native TotpEx(const secret[], time, step)
*/
AMX_NATIVE(TotpEx, 3)
	// Get params
	auto secret = GetString(amx, params[1]);

	// Addr
	cell *pAddr = nullptr;
	amx_GetAddr(amx, params[2], &pAddr);

	// Get number from ptr
	auto time = static_cast<int>(*pAddr);

	// Addr
	pAddr = nullptr;
	amx_GetAddr(amx, params[3], &pAddr);

	// Get number from ptr
	auto step = static_cast<int>(*pAddr);

	// Base32
	Bytes::ByteString qui = Bytes::fromUnpaddedBase32(secret);

	// Calculate TOTP
	auto code = CppTotp::totp(qui, time, 0, step, 6);

	// Invalid
	return code;
AMX_NATIVE_END

SAMPTOTP_END_NS