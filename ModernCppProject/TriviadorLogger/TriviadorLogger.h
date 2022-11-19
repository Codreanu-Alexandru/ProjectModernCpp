#pragma once
#include <ostream>
#ifdef LOGGING_EXPORT
#define LOGGING_API _declspec(dllexport)
#else
#define LOGGING_API _declspec(dllimport)
#endif

class LOGGING_API TriviadorLogging {

public:
	enum class Level {
		Info,
		Warning,
		Error
	};

public:
	TriviadorLogging(std::ostream& out, Level minLevel);
	template<class T>
	void Log(T message, Level level);

	template<class ...Args>
	void Log(Level level, Args&& ...params);

private:
	std::ostream& m_out;
	Level m_minLevel;
};

template<class T>
inline void TriviadorLogging::Log(T message, Level level) {

	if (static_cast<int>(level) >= static_cast<int>(m_minLevel)) {
		if (level == Level::Info) {
			m_out << "[Info] " << message << std::endl;
		}
		else if (level == Level::Warning) {
			m_out << "[Warning] " << message << std::endl;
		}
		else {
			m_out << "[Error] " << message << std::endl;
		}
	}
}

template<class ...Args>
inline void TriviadorLogging::Log(Level level, Args && ...params) {

	if (static_cast<int>(level) >= static_cast<int>(m_minLevel)) {
		if (level == Level::Info) {
			m_out << "[Info] ";
		}
		else if (level == Level::Warning) {
			m_out << "[Warning] ";
		}
		else {
			m_out << "[Error] ";
		}
	}

	((m_out << ' ' << std::forward<Args>(params)), ...);
	m_out << std::endl;
}
