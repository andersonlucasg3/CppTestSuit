#pragma once

#include <format>
#include <iostream>

class CLogger
{
    template<typename ... TArgs>
    static std::string GetFormattedString(const char* Format, TArgs&& ... Args)
    {
        return std::vformat(Format, std::make_format_args(Args...));
    }

public:
    template<typename ... TArgs>
    static void Log(const char* Format, TArgs&& ... Args)
    {
        std::cout << GetFormattedString(Format, Args...);
    }

    template<typename ... TArgs>
    static void Warning(const char* Format, TArgs ... Args)
    {
        std::cout << ("WARNING: " + GetFormattedString(Format, Args...));
    }

    template<typename ... TArgs>
    static void Error(const char* Format, TArgs ... Args)
    {
        std::cout << ("ERROR: " + GetFormattedString(Format, Args...));
    }
};