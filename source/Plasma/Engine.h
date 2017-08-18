#pragma once

typedef signed int int32;
typedef unsigned int uint32;

typedef unsigned char uint8;

struct NonCopyable 
{
	NonCopyable & operator=(const NonCopyable&) = delete;
	NonCopyable(const NonCopyable&) = delete;
	NonCopyable() = default;
};

namespace PlasmaMath
{
	// TODO: move math somewhere, or use lib?
	template<class T>
	static inline T Max(const T A, const T B) { return (A >= B) ? A : B; }

	template<class T>
	static inline T Min(const T A, const T B) { return (A <= B) ? A : B; }
}