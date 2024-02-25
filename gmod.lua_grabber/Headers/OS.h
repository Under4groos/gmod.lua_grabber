#pragma once
#ifndef OS_H
#define OS_H

// OS
#if (defined(_WIN32) || defined(_WIN64))
#define OS_WINDOWS
#elif (defined(__linux__))
#define OS_LINUX
#elif (defined(__APPLE__) || defined(__MACH__))
#define OS_MAC
#else
#error "Operating system not found!"
#endif

#if ((defined(OS_WINDOWS) && (defined(OS_LINUX) || defined(OS_MAC))) || (defined(OS_LINUX) && (defined(OS_WINDOWS) || defined(OS_MAC))) || (defined(OS_MAC) && (defined(OS_WINDOWS) || defined(OS_LINUX))))
#error "Multiple OSes found!"
#endif

// Architecture
#if ((defined(_WIN32) && !defined(_WIN64)) || defined(_M_IX86) || defined(__i386__) || defined(i386) || defined(__i386))
#define ARCH_32BIT
#elif (defined(_WIN64) || defined(__ia64__) || defined(_IA64) || defined(__IA64__) || defined(_M_IA64) || defined(__x86_64__))
#define ARCH_64BIT
#endif

#if (defined(ARCH_32BIT) && defined(ARCH_64BIT))
#error "Multiple architectures found!"
#endif

#if (!defined(ARCH_32BIT) && !defined(ARCH_64BIT))
#error "No architecture found!"
#endif

// Calling conventions
#if (defined(__GNUC__))
#define __FASTCALL__ __attribute__((fastcall))
#define __THISCALL__ __attribute__((thiscall))
#define __CDECL__ __attribute__((cdecl))
#define __STDCALL__ __attribute__((stdcall))
#elif defined(_MSC_VER)
#define __FASTCALL__ __fastcall
#define __THISCALL__ __thiscall
#define __CDECL__ __cdecl
#define __STDCALL__ __stdcall
#endif


#endif