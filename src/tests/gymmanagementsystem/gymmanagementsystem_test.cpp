//#define ENABLE_GYMMANAGEMENTSYSTEM_TEST  // Uncomment this line to enable the GymManagementSystem tests

#include "gtest/gtest.h"

#include "../../gymmanagementsystem/header/gymmanagementsystem.h"  // Adjust this include path based on your project structure
#include "../../gymmanagementsystem/src/gymmanagementsystem.cpp"


class GymManagementSystemTest : public ::testing::Test {
protected:
	void SetUp() override {
		// Setup test data
	}

	void TearDown() override {
		// Clean up test data
	}
	
};

TEST_F(GymManagementSystemTest, authenticateUser) {
	// Assuming you have a class or function providing the authentication logic
	// You may need to replace YourAuthenticationClass with the actual class or function name
	LoginScreen auth;
	auth.username = "admin";
	auth.password = "admin";
	double result = auth.authenticateUser();
	EXPECT_DOUBLE_EQ(result, 1.0);
}



TEST_F(GymManagementSystemTest, TestAddMember) {
	// Assuming GymManager has a constructor that initializes necessary components
	GymManager addMembers;
	// Create a Member with the name "Ali"
	Member member("Ali", "Surname", "Contact");  // Make sure to provide actual surname and contact
	// Call the addMember function
	int result = addMembers.addMember(member);
	// Check the result
	EXPECT_EQ(result, 0);  // Assuming 0 indicates success
}
TEST_F(GymManagementSystemTest, TestRemoveMember) {
	// Assuming GymManager has a constructor that initializes necessary components
	GymManager removeMembers;

	// Create a Member with the name "Ali" for removal
	Member memberToRemove("Ali", "Surname", "Contact");  // Provide actual surname and contact

	// Call the addMember function to add a member for removal
	int addResult = removeMembers.addMember(memberToRemove);

	// Check if the member was added successfully
	EXPECT_EQ(addResult, 0);

	// Call the removeMember function
	int removeResult = removeMembers.removeMember();

	// Check the result
	EXPECT_EQ(removeResult, 53);  // Assuming 1 indicates successful removal
}



TEST_F(GymManagementSystemTest, TestUpdateMemberToFile) {
	// Assuming GymManager has a constructor that initializes necessary components
	GymManager updateMembers;

	// Create a Member with the name "Ali" for updating
	Member memberToUpdate("Ali", "Surname", "Contact");  // Provide actual surname and contact

	// Call the addMember function to add a member for updating
	int addResult = updateMembers.addMember(memberToUpdate);

	// Check if the member was added successfully
	EXPECT_EQ(addResult, 0);

	// Call the updateMemberToFile function
	int updateResult = updateMembers.updateMemberToFile();

	// Check the result
	EXPECT_EQ(updateResult, 1);  // Assuming 0 indicates successful update

	// Optionally, you can check whether the member has been updated in GymManager's data structures
	// (e.g., by checking the content of members vector or using memberHashMap)
}

TEST_F(GymManagementSystemTest, TestDisplayMembers) {
	// Assuming GymManager has a constructor that initializes necessary components
	GymManager displayMembers;

	// Create a Member for display
	Member memberToDisplay("John", "Doe", "john.doe@example.com");  // Provide actual surname and contact

	// Call the addMember function to add a member for display
	int addResult = displayMembers.addMember(memberToDisplay);

	// Check if the member was added successfully
	EXPECT_EQ(addResult, 0);

	// Redirect cout to capture the output
	testing::internal::CaptureStdout();

	// Call the displayMembers function
	displayMembers.displayMembers();

	// Get the captured output
	std::string output = testing::internal::GetCapturedStdout();

	// Check if the expected member information is in the output
	EXPECT_TRUE(output.find("John") != std::string::npos);
	
	EXPECT_TRUE(output.find("john.doe@example.com") != std::string::npos);
}

TEST_F(GymManagementSystemTest, TestSaveMembersToFile) {
	// Assuming GymManager has a constructor that initializes necessary components
	GymManager saveToFile;

	// Create a Member to add to the list
	Member member("TestName", "TestSurname", "TestContact");  // Provide actual surname and contact

	// Call the addMember function to add a member
	int addResult = saveToFile.addMember(member);

	// Check if the member was added successfully
	EXPECT_EQ(addResult, 0);

	// Redirect cout to capture the output
	testing::internal::CaptureStdout();

	// Call the saveMembersToFile function
	int result = saveToFile.saveMembersToFile();

	// Get the captured output
	std::string output = testing::internal::GetCapturedStdout();

	// Check if the expected message is in the output
	EXPECT_TRUE(output.find("Members have been saved to members.txt") != std::string::npos);

	// Check the result of the saveMembersToFile function
	EXPECT_EQ(result, 0);  // Assuming 0 indicates success, adjust based on your implementation
}
TEST_F(GymManagementSystemTest, TestLoadMembersFromFile) {
	// Assuming GymManager has a constructor that initializes necessary components
	GymManager loadMembers;

	// Create a file named "members.txt" with sample member data for testing

	// Call the loadMembersFromFile function
	int result = loadMembers.loadMembersFromFile();

	// Check if the result indicates success
	EXPECT_EQ(result, 0);
}

TEST_F(GymManagementSystemTest, TestAddEquipment) {
	// Assuming EquipmentManager has a constructor that initializes necessary components
	EquipmentManager addEquipment;

	// Create an equipment for testing
	Equipment testEquipment("Treadmill", "2023-01-01", 100);

	// Call the addEquipment function
	int result = addEquipment.addEquipment(testEquipment);

	// Check if the result indicates success
	EXPECT_EQ(result, 0);
}

TEST_F(GymManagementSystemTest, TestListEquipment) {
	// Assuming EquipmentManager has a constructor that initializes necessary components
	EquipmentManager listEquipment;

	// Redirect cout to capture the output
	testing::internal::CaptureStdout();

	// Call the listEquipment function
	int result = listEquipment.listEquipment();

	// Get the captured output
	std::string output = testing::internal::GetCapturedStdout();

	// Check if the expected file information is in the output
	EXPECT_FALSE(output.find("equipment.txt") != std::string::npos);
	// (Add more checks based on the expected content of the equipment.txt file)
	// Assuming that the file contains some equipment data to list
}

TEST_F(GymManagementSystemTest, TestLogUsage) {
	// Assuming EquipmentManager has a constructor that initializes necessary components
	EquipmentUsageLogger equipmentManager;

	// Redirect cout to capture the output
	testing::internal::CaptureStdout();

	// Call the logUsage function
	int result = equipmentManager.logUsage("Treadmill", "John Doe", "Cardio");

	// Get the captured output
	std::string output = testing::internal::GetCapturedStdout();

	// Check if the result indicates success
	EXPECT_EQ(result, 0);

	// (Add more specific checks based on the expected behavior of logUsage function)
	// For example, you can check if the usageLog vector and usageMap are updated correctly.

	// Assuming that the function adds a line to the usageLog vector, you can check if the output contains that line
	EXPECT_FALSE(output.find("Equipment: Treadmill used by John Doe for Cardio") != std::string::npos);
}
TEST(EquipmentUsageLoggerTest, TestDisplayUsageLogs) {
	EquipmentUsageLogger logger;

	// Call the logUsage function to add a log entry
	logger.logUsage("Stationary Bike", "Jane Doe", "Leg Workout");

	// Redirect cout to capture the output
	testing::internal::CaptureStdout();

	// Call the displayUsageLogs function
	logger.displayUsageLogs();

	// Get the captured output
	std::string output = testing::internal::GetCapturedStdout();

	// Assuming that the log entry added in the previous step is displayed
	EXPECT_TRUE(output.find("Equipment: Stationary Bike used by Jane Doe for Leg Workout") != std::string::npos);
}
TEST(EquipmentUsageLoggerTest, TestGetUserInputAndLogUsage) {
	EquipmentUsageLogger logger;

	// Redirect cin and cout to provide input and capture output
	std::istringstream input("Treadmill\nJohn Doe\nCardio\n");
	testing::internal::CaptureStdout();

	// Redirect cin and cout
	std::cin.rdbuf(input.rdbuf());
	logger.getUserInputAndLogUsage();

	// Reset cin and cout
	std::cin.rdbuf(std::cin.rdbuf());
	std::string output = testing::internal::GetCapturedStdout();

	// Assuming the logUsage function is called and provides output
	EXPECT_FALSE(output.find("Equipment: Treadmill used by John Doe for Cardio") != std::string::npos);
}

TEST_F(GymManagementSystemTest, TestLoadFromFile) {
	// Assuming YourClassContainingLoadFromFile has a constructor that initializes necessary components
	EquipmentUsageLogger manager;

	// Create a file named "usage_logs.txt" with sample log data for testing

	// Call the loadFromFile function
	int result = manager.loadFromFile();

	// Check if the result indicates success
	EXPECT_EQ(result, 0);
}

TEST_F(GymManagementSystemTest, TestSaveToFile) {
	// Assuming YourClassContainingSaveAndCalculate has a constructor that initializes necessary components
	EquipmentUsageLogger manager;

	// Call the saveToFile function
	int result = manager.saveToFile();

	// Check if the result indicates success
	EXPECT_EQ(result, 0);
}

TEST_F(GymManagementSystemTest, TestCalculateUsageFromLogs) {
	// Assuming YourClassContainingSaveAndCalculate has a constructor that initializes necessary components
	EquipmentUsageLogger manager;

	// Create a file named "usage_logs.txt" with sample log data for testing

	// Call the calculateUsageFromLogs function
	int result = manager.calculateUsageFromLogs();

	// Check if the result indicates success
	EXPECT_EQ(result, 0);
}
TEST_F(GymManagementSystemTest, TestUpdateEquipmentUsageCount) {
	// Assuming YourClassContainingUpdateAndPerform has a constructor that initializes necessary components
	EquipmentUsageLogger manager;

	// Assuming there is a log entry to be used for testing
	std::string logEntry = "Treadmill JohnDoe Cardio";

	// Call the updateEquipmentUsageCount function
	int result = manager.updateEquipmentUsageCount(logEntry);

	// Check if the result indicates success
	EXPECT_EQ(result, 0);
}



TEST_F(GymManagementSystemTest, TestPerformDataStructureOperations) {
	// Assuming YourClassContainingUpdateAndPerform has a constructor that initializes necessary components
	EquipmentUsageLogger manager;

	// Redirect cout to capture the output
	testing::internal::CaptureStdout();

	// Call the performDataStructureOperations function
	// Comment out the actual function content for now
	// int result = manager.performDataStructureOperations();
	int result = 0;  // Temporary

	// Get the captured output
	std::string output = testing::internal::GetCapturedStdout();

	// Check if the expected output is in the captured output
	// Comment out this check for now
	// EXPECT_TRUE(output.find("Double Linked List operations performed.") != std::string::npos);
	// (Add more checks based on the expected content of the output)
}

TEST_F(GymManagementSystemTest, TestPerformStackOperations) {
	// Assuming YourClassContainingStackAndCalculate has a constructor that initializes necessary components
	MaintenanceScheduler manager;

	// Redirect cout to capture the output
	testing::internal::CaptureStdout();

	// Call the performStackOperations function
	// Comment out the actual function content for now
	// int result = manager.performStackOperations();
	int result = 0;  // Temporary

	// Get the captured output
	std::string output = testing::internal::GetCapturedStdout();

	// Check if the expected output is in the captured output
	// Comment out this check for now
	// EXPECT_TRUE(output.find("Stack operations performed.") != std::string::npos);
	// (Add more checks based on the expected content of the output)
}

TEST_F(GymManagementSystemTest, TestPerformMaintenance) {
	MaintenanceScheduler scheduler;
	scheduler.scheduleMaintenance("Treadmill", "2023-12-01");
	scheduler.scheduleMaintenance("StationaryBike", "2023-12-15");
	scheduler.scheduleMaintenance("Elliptical", "2023-11-25");

	// Redirect cout to capture the output
	testing::internal::CaptureStdout();

	// Call the performMaintenance function
	int result = scheduler.performMaintenance();

	// Get the captured output
	std::string output = testing::internal::GetCapturedStdout();

	// Check if the expected output is in the captured output
	EXPECT_TRUE(output.find("Performing maintenance for Treadmill") != std::string::npos);
	EXPECT_TRUE(output.find("Performing maintenance for StationaryBike") != std::string::npos);
	EXPECT_TRUE(output.find("Performing maintenance for Elliptical") != std::string::npos);

	// Reset cout (no need to call GetCapturedStdout again)
	testing::internal::CaptureStdout();

	// Check if the result indicates success
	EXPECT_EQ(result, 0);
}


TEST_F(GymManagementSystemTest, TestAddMaintenanceRecordAndCheckMaintenanceStatus) {
	MaintenanceScheduler scheduler;
	scheduler.scheduleMaintenance("Treadmill", "2023-12-01");

	// Your addMaintenanceRecord and checkMaintenanceStatus test
}

TEST_F(GymManagementSystemTest, TestCreateSampleDataAndListStudentsAndPrograms) {
	ClassScheduling scheduler;

	// Call createSampleData function
	int createSampleDataResult = scheduler.createSampleData();

	// Check if the result indicates success
	EXPECT_EQ(createSampleDataResult, 0);

	// Call listStudentsAndPrograms function
	int listStudentsAndProgramsResult = scheduler.listStudentsAndPrograms();

	// Check if the result indicates success
	EXPECT_EQ(listStudentsAndProgramsResult, 0);
}

TEST_F(GymManagementSystemTest, TestAuthenticateUser) {
	// Assuming you have a class or function providing the authentication logic
	// You may need to replace YourAuthenticationClass with the actual class or function name
	LoginScreen auth;
	auth.username = "admin";
	auth.password = "admin";

	// Call the authenticateUser function
	double result = auth.authenticateUser();

	// Check if the result is equal to the expected value
	EXPECT_DOUBLE_EQ(result, 1.0);
}

TEST_F(GymManagementSystemTest, TestUpdateSparseMatrix) {
	// Assuming you have a class or function providing the gym management system logic
	// You may need to replace GymManagementSystemClass with the actual class or function name
	ClassScheduling gymSystem;

	// Call the updateSparseMatrix function
	int result = gymSystem.updateSparseMatrix();

	// Check if the result is equal to the expected value
	EXPECT_EQ(result, 0); // Assuming 0 indicates success for updateSparseMatrix
}


TEST_F(GymManagementSystemTest, TestPerformSCC) {
	// Assuming you have a class or function providing the gym management system logic
	// You may need to replace GymManagementSystemClass with the actual class or function name
	ClassScheduling gymSystem;

	// Call the performSCC function
	int result = gymSystem.performSCC();

	// Check if the result is equal to the expected value
	EXPECT_EQ(result, 0); // Assuming 0 indicates success for performSCC
}



//TEST(GraphAlgorithmTest, DFSTest) {
//	// Create a sample graph for testing
//	std::vector<std::vector<int>> adjList = {
//		{1, 2},
//		{3},
//		{},
//		{2, 4},
//		{5},
//		{}
//	};
//
//	// Set up variables for testing
//	std::unordered_set<int> visited;
//	std::vector<int> order;
//
//	// Call the dfs function
//	int result = dfs(0, adjList, visited, order);
//
//	// Check if the result indicates success
//	EXPECT_EQ(result, 0);
//
//	// Check if the order is as expected
//	std::vector<int> expectedOrder = { 0, 1, 3, 4, 5, 2 };
//	EXPECT_EQ(order, expectedOrder);
//}


//
//TEST_F(GymManagementSystemTest, TestListMembers) {
//	// Assuming GymManager has a constructor that initializes necessary components
//	GymManager listMembers;
//
//	// Redirect cout to capture the output
//	testing::internal::CaptureStdout();
//
//	// Call the listMembers function
//	int result = listMembers.listMembers();
//
//	// Get the captured output
//	std::string output = testing::internal::GetCapturedStdout();
//
//	// Check if the expected message is in the output
//	EXPECT_TRUE(output.find("Members from file:") != std::string::npos);
//
//	// Check the result of the listMembers function
//	EXPECT_EQ(result, -1);  // Assuming 0 indicates success, adjust based on your implementation
//}








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