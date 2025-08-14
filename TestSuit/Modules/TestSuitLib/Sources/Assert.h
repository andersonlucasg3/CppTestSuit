#pragma once

#include <type_traits>
#include <string>
#include <vector>

class CTestBase;

struct CTestAssertInfo
{
    const std::string FileName;
    const std::string FunctionName;
    const int LineNumber;

    const std::string Expression;

    CTestAssertInfo(
        const std::string& InFileName, 
        const std::string& InFunctionName,
        const int InLineNumber,
        const std::string InExpression
    );
};

class CAssert
{
    bool _bHadAnyErrors;

    std::vector<CTestAssertInfo> _failedTestCases;

    template<typename TLeft, typename TRight>
    constexpr bool IsANumber()
    {
        constexpr bool IsLeftTypeANumber = std::is_floating_point_v<TLeft> || std::is_integral_v<TLeft>;
        constexpr bool IsRightTypeANumber = std::is_floating_point_v<TRight> || std::is_integral_v<TRight>;

        return IsLeftTypeANumber && IsRightTypeANumber;
    }

public:
    CAssert();
    ~CAssert() = default;

    template<typename TLeft, typename TRight>
    void Equal(TLeft InLeftValue, TRight InRightValue, const CTestAssertInfo& Info)
    {
        bool bResult = InLeftValue == InRightValue;

        if (!bResult)
        {
            _failedTestCases.push_back(Info);
        }
    }

    template<typename TLeft, typename TRight>
    void Greater(TLeft InLeftValue, TRight InRightValue, bool bAndEqual, const CTestAssertInfo& Info)
    {
        static_assert(IsANumber<TLeft, TRight>());

        bool bResult;

        if (bAndEqual)
        {
            bResult = InLeftValue >= InRightValue;
        }
        else
        {
            bResult = InLeftValue > InRightValue;
        }

        if (!bResult)
        {
            _failedTestCases.push_back(Info);
        }
    }

    template<typename TLeft, typename TRight>
    bool Lesser(TLeft InLeftValue, TRight InRightValue, bool bAndEqual, const CTestAssertInfo& Info)
    {
        static_assert(IsANumber<TLeft, TRight>());
        
        bool bResult;

        if (bAndEqual)
        {
            bResult = InLeftValue <= InRightValue;
        }
        else
        {
            bResult = InLeftValue < InRightValue;
        }

        if (!bResult)
        {
            _failedTestCases.push_back(Info);
        }
    }

    friend class CTestCoordinator;
};

#define ASSERT_CONTEXT(expr) CTestAssertInfo(this, __FILE__, __FUNCTION__, __LINE__, ##expr)

#define ASSERT_EQUAL(l, r)                  _assert->Equal(l, r, ASSERT_CONTEXT(##l == ##r))
#define ASSERT_GREATER(l, r)                _assert->Greater(l, r, false, ASSERT_CONTEXT(##l > ##r))
#define ASSERT_GREATER_EQUAL(l, r)          _assert->Greater(l, r, true, ASSERT_CONTEXT(##l >= ##r))
#define ASSERT_LESSER(l, r)                 _assert->Lesser(l, r, false, ASSERT_CONTEXT(##l < ##r))
#define ASSERT_LESSER_EQUAL(l, r)           _assert->Lesser(l, r, true, ASSERT_CONTEXT(##l < ##r))
