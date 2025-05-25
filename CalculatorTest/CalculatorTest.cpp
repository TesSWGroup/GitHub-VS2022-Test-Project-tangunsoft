#include <gtest/gtest.h>
#include "../Calculator.h"

// 테스트 케이스를 그룹화하는 테스트 스위트
class CalculatorTest : public testing::Test {
protected:
    Calculator calc;  // 각 테스트에서 사용할 계산기 객체
};

// 덧셈 테스트
TEST_F(CalculatorTest, AdditionWorks) {
    // EXPECT_EQ는 두 값이 같은지 검사합니다
    EXPECT_EQ(calc.Add(2, 3), 5);    // 2 + 3 = 5
    EXPECT_EQ(calc.Add(-1, 1), 0);   // -1 + 1 = 0
    EXPECT_EQ(calc.Add(0, 0), 0);    // 0 + 0 = 0
}

// 뺄셈 테스트
TEST_F(CalculatorTest, SubtractionWorks) {
    EXPECT_EQ(calc.Subtract(5, 3), 2);    // 5 - 3 = 2
    EXPECT_EQ(calc.Subtract(1, 1), 0);    // 1 - 1 = 0
    EXPECT_EQ(calc.Subtract(0, 5), -5);   // 0 - 5 = -5
}

// 곱셈 테스트
TEST_F(CalculatorTest, MultiplicationWorks) {
    EXPECT_EQ(calc.Multiply(2, 3), 6);    // 2 * 3 = 6
    EXPECT_EQ(calc.Multiply(-2, 3), -6);  // -2 * 3 = -6
    EXPECT_EQ(calc.Multiply(0, 5), 0);    // 0 * 5 = 0
}

// 나눗셈 테스트
TEST_F(CalculatorTest, DivisionWorks) {
    EXPECT_DOUBLE_EQ(calc.Divide(6, 2), 3.0);     // 6 / 2 = 3.0
    EXPECT_DOUBLE_EQ(calc.Divide(5, 2), 2.5);     // 5 / 2 = 2.5
    EXPECT_DOUBLE_EQ(calc.Divide(0, 5), 0.0);     // 0 / 5 = 0.0
    
    // 0으로 나누기 예외 테스트
    EXPECT_THROW(calc.Divide(5, 0), const char*);  // 5 / 0은 예외를 발생시켜야 함
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 