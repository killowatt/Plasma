//#pragma once
//
//#include "Engine.h"
//
//class String
//{
//	// not designed to be a "faster" container
//	// just a more useful one (For unicode/loading localization/preventing leaks)
//	// general purpose string container without too much concern for performance (immediately)
//	// no feature creep please
//
//	// NOT IN USE, just trying stuff out
//
//	char* const source = new char[1];
//	uint32 length = 0; // TODO: please use
//	uint32 size = 15;
//
//public:
//	uint32 Length();
//	uint32 Size() { return size; }
//
//	const char* GetRawString() { return source; }
//
//private:
//	bool isvalidutf8() = delete;
//	bool isutf8() = delete;
//
//	String& operator=(const String&) = delete;
//
//	String(const String&) = delete;
//
//
//public:
//	String();
//
//#ifdef PLASMA_DEBUG
//	String& operator=(const char* target);
//#elif
//	String& operator=(const char* target) = delete;
//#endif
//	//String(const char* string)
//};
