/***************************************************************************
* Copyright (c) 2017, Ullrich Koethe                                       *
*                                                                          *
* Distributed under the terms of the BSD 3-Clause License.                 *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/

#ifndef XTENSOR_ENABLE_ASSERT
#define XTENSOR_ENABLE_ASSERT
#endif

#include "xtensor/xexception.hpp"

#include <string>

#include "gtest/gtest.h"
#include "test_common_macros.hpp"

namespace xt
{
    TEST(xexception, macros)
    {
        XT_EXPECT_THROW(XTENSOR_ASSERT_MSG(false, "Intentional error"), std::runtime_error);
        XT_EXPECT_THROW(XTENSOR_PRECONDITION(false, "Intentional error"), std::runtime_error);
    }

#if !defined(XTENSOR_NO_EXCEPTIONS)

    TEST(xexception, exceptions)
    {
        try
        {
            XTENSOR_ASSERT_MSG(false, "Intentional error");
            FAIL() << "No exception thrown.";
        }
        catch (std::runtime_error& e)
        {
            std::string expected("Assertion error!\nIntentional error");
            std::string message(e.what());
            EXPECT_TRUE(0 == expected.compare(message.substr(0, expected.size())));
        }
        try
        {
            XTENSOR_PRECONDITION(false, "Intentional error");
            FAIL() << "No exception thrown.";
        }
        catch (std::runtime_error& e)
        {
            std::string expected("Precondition violation!\nIntentional error");
            std::string message(e.what());
            EXPECT_TRUE(0 == expected.compare(message.substr(0, expected.size())));
        }
    }
#endif

}  // namespace xt
