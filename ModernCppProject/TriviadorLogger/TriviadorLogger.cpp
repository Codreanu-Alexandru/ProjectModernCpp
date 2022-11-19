#include "TriviadorLogger.h"

TriviadorLogging::TriviadorLogging(std::ostream& out, Level minLevel)
	:m_out(out),
	m_minLevel(minLevel) {
}