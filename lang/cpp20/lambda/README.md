Capture *this by value in lambdas:
You can now capture the *this object of a class by value in a lambda expression. This can be useful in cases where you need to capture the object's state and use it inside the lambda.

Default capture modes:
C++20 introduces new default capture modes for lambdas. You can now use the = sign to capture all variables by value and the & sign to capture all variables by reference. For example, you can use [=] to capture all variables by value, and [&] to capture all variables by reference.

constexpr lambdas:
C++20 allows lambda functions to be declared as constexpr. This means that the lambda function can be evaluated at compile-time if all of its arguments are compile-time constants.

Template lambdas:
C++20 introduced template lambdas, which allows lambda functions to be templated. You can use the auto and template keywords in the parameter list of a lambda function to define a templated lambda. This can be useful in cases where you need to write generic code that can work with different types of data.

Improved lambda expressions in unevaluated contexts:
C++20 improves the handling of lambda expressions in unevaluated contexts such as decltype, sizeof, and typeid. Now, when you use a lambda expression in an unevaluated context, the compiler generates a unique type for the lambda expression.

