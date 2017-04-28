/** 
 *  SA-MP TOTP Functions
 *
 *  (c) Copyright 2017-2018, ProMetheus
 */

#if defined HEADER_A_TOTP_INC
	#endinput
#endif
#define HEADER_A_TOTP_INC

/**
 * Totp
 * @param string secret
 * @param int step
 */
native Totp(const secret[], step = 30);


/**
 * TotpEx
 * @param string secret
 * @param int current time
 * @param int step
 */
native TotpEx(const secret[], time, step = 30);

