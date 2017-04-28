#ifndef SAMPLOG_LOGPRINTF_HPP
#define SAMPLOG_LOGPRINTF_HPP

#include <cstdarg>

typedef void (*logprintf_t)(const char *format, ...);
extern logprintf_t logprintf;

SAMPTOTP_BEGIN_NS

void vlogprintf(const char *format, std::va_list va);

SAMPTOTP_END_NS
#endif