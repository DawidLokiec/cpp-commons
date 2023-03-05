#include <gtest/gtest.h>
#include "language.h"

TEST(LanguageTest, IsInstanceOfTest) {
	class A {
		public:
			virtual ~A() = default;
	};

	class B : public A {

	};

	class C {

	};

	A *a = new B();
	{
		const bool isCorrectSubtype = commons::isInstanceOf<A, B>(a);
		EXPECT_TRUE(isCorrectSubtype);
	}
	{
		const bool isCorrectSubtype = commons::isInstanceOf<A, C>(a);
		EXPECT_FALSE(isCorrectSubtype);
	}

	delete a;
}
