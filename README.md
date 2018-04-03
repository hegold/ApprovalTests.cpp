CppApprovals
============

[![Build Status](https://api.travis-ci.org/approvals/ApprovalTests.cpp.svg?branch=master)](https://travis-ci.org/approvals/ApprovalTests.cpp)

Native ApprovalTests for C++

![Intro Graphic](doc/images/ApprovalTests.cpp.IntroGraphic.gif?raw=true)

Currently working in Mac/Linux/Windows with
* [Catch1](https://github.com/catchorg/Catch2/tree/Catch1.x)  
* [Catch2](https://github.com/catchorg/Catch2)   
* [Okra](https://github.com/JayBazuzi/Okra) & C++ 11  
* [GoogleTest](https://github.com/google/googletest)



## Getting Started

I Highly suggest you clone [The Approval.cpp Starter Project](https://github.com/approvals/ApprovalTests.Cpp.StarterProject)

## Main File

you need to include 2 lines for your main file to work.

``` cpp
#define APPROVALS_CATCH
#include "ApprovalTests.hpp"
```

For all other files, you only need
``` cpp
#include "ApprovalTests.hpp"
```

## Examples
ApprovalTests uses ApprovalTests to test ApprovalTests (it's turtles all the way down)  
[Checkout our own tests](https://github.com/approvals/ApprovalTests.cpp/tree/master/ApprovalTests_Catch2_Tests) to see how we do it:  
### Suggested:  
[ApprovalTests](https://github.com/approvals/ApprovalTests.cpp/blob/master/ApprovalTests_Catch2_Tests/ApprovalsTests.cpp)  
[VectorTests](https://github.com/approvals/ApprovalTests.cpp/blob/master/ApprovalTests_Catch2_Tests/VectorTests.cpp)  
[CombinationTests](https://github.com/approvals/ApprovalTests.cpp/blob/master/ApprovalTests_Catch2_Tests/CombinationTests.cpp)  
