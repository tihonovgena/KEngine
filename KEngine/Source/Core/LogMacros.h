#pragma once

#include "Log.h"

constexpr KEngine::LogVerbosity Trace = KEngine::LogVerbosity::Trace;
constexpr KEngine::LogVerbosity Info = KEngine::LogVerbosity::Info;
constexpr KEngine::LogVerbosity Warning = KEngine::LogVerbosity::Warning;
constexpr KEngine::LogVerbosity Error = KEngine::LogVerbosity::Error;
constexpr KEngine::LogVerbosity Critical = KEngine::LogVerbosity::Critical;

#define KE_CORE_LOG(Level, ...) KEngine::Log::LogMessage(KEngine::Log::GetEngineLogger(), Level, __VA_ARGS__)
#define KE_LOG(Level, ...)	    KEngine::Log::LogMessage(KEngine::Log::GetApplicationLogger(), Level, __VA_ARGS__)