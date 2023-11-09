//#define ENABLE_GYMMANAGEMENTSYSTEM_TEST  // Uncomment this line to enable the GymManagementSystem tests

#include "gtest/gtest.h"
#include "../../gymmanagementsystem/header/gymmanagementsystem.h"  // Adjust this include path based on your project structure

using namespace Coruh::GymManagementSystem;

class GymManagementSystemTest : public ::testing::Test {
protected:
	void SetUp() override {
		// Setup test data
	}

	void TearDown() override {
		// Clean up test data
	}
};

TEST_F(GymManagementSystemTest, TestAdd) {
	double result = GymManagementSystem::add(5.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 8.0);
}

TEST_F(GymManagementSystemTest, TestSubtract) {
	double result = GymManagementSystem::subtract(5.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 2.0);
}

TEST_F(GymManagementSystemTest, TestMultiply) {
	double result = GymManagementSystem::multiply(5.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 15.0);
}

TEST_F(GymManagementSystemTest, TestDivide) {
	double result = GymManagementSystem::divide(6.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 2.0);
}

TEST_F(GymManagementSystemTest, TestDivideByZero) {
	EXPECT_THROW(GymManagementSystem::divide(5.0, 0.0), std::invalid_argument);
}

/**
 * @brief The main function of the test program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return int The exit status of the program.
 */
int main(int argc, char** argv) {
#ifdef ENABLE_GYMMANAGEMENTSYSTEM_TEST
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
#else
	return 0;
#endif
}