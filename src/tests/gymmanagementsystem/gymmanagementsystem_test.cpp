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

class EquipmentUsageLoggerTest : public ::testing::Test {
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
	
	GymManager addMembers;
	Member member("Ali", "Surname", "Contact"); 
	int result = addMembers.addMember(member);
	EXPECT_EQ(result, 0); 
}
TEST_F(GymManagementSystemTest, TestRemoveMember) {
	
	GymManager removeMembers;
	Member memberToRemove("Ali", "Surname", "Contact");
	int addResult = removeMembers.addMember(memberToRemove);
	EXPECT_EQ(addResult, 0);
	int removeResult = removeMembers.removeMember();
	EXPECT_EQ(removeResult, 53); 
}
TEST_F(GymManagementSystemTest, TestUpdateMemberToFile) {
	
	GymManager updateMembers;
	Member memberToUpdate("Ali", "Surname", "Contact");
	int addResult = updateMembers.addMember(memberToUpdate);
	EXPECT_EQ(addResult, 0);
	int updateResult = updateMembers.updateMemberToFile();
	EXPECT_EQ(updateResult, 1); 
}
TEST_F(GymManagementSystemTest, TestDisplayMembers) {
	
	GymManager displayMembers;
	Member memberToDisplay("John", "Doe", "john.doe@example.com");  
	int addResult = displayMembers.addMember(memberToDisplay);
	EXPECT_EQ(addResult, 0);
	testing::internal::CaptureStdout();
	displayMembers.displayMembers();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_TRUE(output.find("John") != std::string::npos);
	EXPECT_TRUE(output.find("john.doe@example.com") != std::string::npos);
}

TEST_F(GymManagementSystemTest, TestSaveMembersToFile) {

	GymManager saveToFile;
	Member member("TestName", "TestSurname", "TestContact"); 
	int addResult = saveToFile.addMember(member);
	EXPECT_EQ(addResult, 0);
	testing::internal::CaptureStdout();
	int result = saveToFile.saveMembersToFile();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_TRUE(output.find("Members have been saved to members.txt") != std::string::npos);
	EXPECT_EQ(result, 0);  
}

TEST_F(GymManagementSystemTest, TestLoadMembersFromFile) {
	
	GymManager loadMembers;
	int result = loadMembers.loadMembersFromFile();
	EXPECT_EQ(result, 0);
}

TEST_F(GymManagementSystemTest, TestAddEquipment) {
	
	EquipmentManager addEquipment;
	Equipment testEquipment("Treadmill", "2023-01-01", 100);
	int result = addEquipment.addEquipment(testEquipment);
	EXPECT_EQ(result, 0);
}
TEST_F(GymManagementSystemTest, TestListEquipment) {

	EquipmentManager listEquipment;
	testing::internal::CaptureStdout();
	int result = listEquipment.listEquipment();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_FALSE(output.find("equipment.txt") != std::string::npos);
}
TEST_F(GymManagementSystemTest, TestLogUsage) {
	
	EquipmentUsageLogger equipmentManager;
	testing::internal::CaptureStdout();
	int result = equipmentManager.logUsage("Treadmill", "John Doe", "Cardio");
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(result, 0);
	EXPECT_FALSE(output.find("Equipment: Treadmill used by John Doe for Cardio") != std::string::npos);
}
TEST(EquipmentUsageLoggerTest, TestDisplayUsageLogs) {
	EquipmentUsageLogger logger;
	logger.logUsage("Stationary Bike", "Jane Doe", "Leg Workout");
	testing::internal::CaptureStdout();
	logger.displayUsageLogs();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_TRUE(output.find("Equipment: Stationary Bike used by Jane Doe for Leg Workout") != std::string::npos);
}
TEST(EquipmentUsageLoggerTest, TestGetUserInputAndLogUsage) {
	EquipmentUsageLogger logger;
	std::istringstream input("Treadmill\nJohn Doe\nCardio\n");
	testing::internal::CaptureStdout();
	std::cin.rdbuf(input.rdbuf());
	logger.getUserInputAndLogUsage();
	std::cin.rdbuf(std::cin.rdbuf());
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_FALSE(output.find("Equipment: Treadmill used by John Doe for Cardio") != std::string::npos);
}

TEST_F(GymManagementSystemTest, TestLoadFromFile) {
	
	EquipmentUsageLogger manager;
	int result = manager.loadFromFile();
	EXPECT_EQ(result, 0);
}

TEST_F(GymManagementSystemTest, TestSaveToFile) {
	
	EquipmentUsageLogger manager;
	int result = manager.saveToFile();
	EXPECT_EQ(result, 0);
}

TEST_F(GymManagementSystemTest, TestCalculateUsageFromLogs) {
	
	EquipmentUsageLogger manager;
	int result = manager.calculateUsageFromLogs();
	EXPECT_EQ(result, 0);
}

TEST_F(GymManagementSystemTest, TestUpdateEquipmentUsageCount) {
	
	EquipmentUsageLogger manager;
	std::string logEntry = "Treadmill JohnDoe Cardio";
	int result = manager.updateEquipmentUsageCount(logEntry);
	EXPECT_EQ(result, 0);
}


TEST_F(GymManagementSystemTest, TestPerformDataStructureOperations) {
	
	EquipmentUsageLogger manager;
	testing::internal::CaptureStdout();
	int result = 0;
	std::string output = testing::internal::GetCapturedStdout();
}

TEST_F(GymManagementSystemTest, TestPerformStackOperations) {

	MaintenanceScheduler manager;
	testing::internal::CaptureStdout();
	int result = 0; 
	std::string output = testing::internal::GetCapturedStdout();

}

TEST_F(GymManagementSystemTest, TestPerformMaintenance) {
    MaintenanceScheduler scheduler;
    scheduler.scheduleMaintenance("Treadmill", "2023-12-01");
    scheduler.scheduleMaintenance("StationaryBike", "2023-12-15");
    scheduler.scheduleMaintenance("Elliptical", "2023-11-25");
    testing::internal::CaptureStdout();
    int result = scheduler.performMaintenance();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Performing maintenance for Treadmill") != std::string::npos);
    EXPECT_TRUE(output.find("Performing maintenance for StationaryBike") != std::string::npos);
    EXPECT_TRUE(output.find("Performing maintenance for Elliptical") != std::string::npos);
    EXPECT_EQ(result, 0);
}

TEST_F(GymManagementSystemTest, TestAddMaintenanceRecordAndCheckMaintenanceStatus) {
	MaintenanceScheduler scheduler;
	scheduler.scheduleMaintenance("Treadmill", "2023-12-01");
}

TEST_F(GymManagementSystemTest, TestCreateSampleDataAndListStudentsAndPrograms) {
	ClassScheduling scheduler;
	int createSampleDataResult = scheduler.createSampleData();
	EXPECT_EQ(createSampleDataResult, 0);
	int listStudentsAndProgramsResult = scheduler.listStudentsAndPrograms();
	EXPECT_EQ(listStudentsAndProgramsResult, 0);
}

TEST_F(GymManagementSystemTest, TestAuthenticateUser) {

	LoginScreen auth;
	auth.username = "admin";
	auth.password = "admin";
	double result = auth.authenticateUser();
	EXPECT_DOUBLE_EQ(result, 1.0);
}
TEST_F(GymManagementSystemTest, TestUpdateSparseMatrix) {
	ClassScheduling gymSystem;
	int result = gymSystem.updateSparseMatrix();
	EXPECT_EQ(result, 0);
}
TEST_F(GymManagementSystemTest, TestPerformSCC) {

	ClassScheduling gymSystem;
	int result = gymSystem.performSCC();
	EXPECT_EQ(result, 0);
}
TEST_F(GymManagementSystemTest, TestGetUserInput) {
	Feedback feedback;
	std::string userInput = "John";
	std::stringstream testInput(userInput);
	std::cin.rdbuf(testInput.rdbuf());
	int result = feedback.getUserInput();
	EXPECT_EQ(result, 0); 
}
TEST_F(GymManagementSystemTest, TestAddProduct) {
	GymPOS gymPos;
	int result = gymPos.addProduct("Protein Shake", 5.99);
	EXPECT_EQ(result, 0);
}
TEST_F(GymManagementSystemTest, TestPurchaseProduct) {
	GymPOS gymPos;
	gymPos.addProduct("Protein Shake", 5.99);
	int result = gymPos.purchaseProduct("Protein Shake");
	EXPECT_EQ(result, 0);
}
TEST_F(GymManagementSystemTest, TestPrintPriceList) {

	std::stringstream capturedOutput;
	std::streambuf* oldCoutBuffer = std::cout.rdbuf(); 
	std::cout.rdbuf(capturedOutput.rdbuf());
	DiscountOffer discountOffer;
	discountOffer.printPriceList();
	std::string outputString = capturedOutput.str(); 
	std::string expectedOutput = "Code: A - Fitness / Normal Membership: 1 Month (5 days a week) - Price: 20\nCode: B - Fitness / Normal Membership: 1 Month (3 days a week) - Price: 15\nCode: C - Fitness / Student Discount: 1 Month (3 days a week) - Price: 10\nCode: D - Swimming / Normal Membership: 1 Month (5 days a week) - Price: 25\nCode: E - Swimming / Normal Membership: 1 Month (3 days a week) - Price: 20\nCode: F - Swimming / Student Discount: 1 Month (3 days a week) - Price: 15\nCode: G - Fitness and Swimming / Normal Membership: 1 Month (5 days a week) - Price: 40\nCode: H - Fitness and Swimming / Normal Membership: 1 Month (3 days a week) - Price: 30\nCode: I - Fitness and Swimming / Student Discount: 1 Month (3 days a week) - Price: 20\n";
	EXPECT_EQ(outputString, expectedOutput);
	std::cout.rdbuf(oldCoutBuffer);
}
TEST_F(GymManagementSystemTest, TestGetPrice) {
	DiscountOffer discountOffer;
	discountOffer.priceList['A'] = { "Fitness / Normal Membership: 1 Month (5 days a week)", 20 };
	discountOffer.priceList['B'] = { "Fitness / Normal Membership: 1 Month (3 days a week)", 15 };
	EXPECT_EQ(discountOffer.getPrice('A'), 20); 
	EXPECT_EQ(discountOffer.getPrice('B'), 15); 
	EXPECT_EQ(discountOffer.getPrice('C'), 10); 
}
TEST_F(GymManagementSystemTest, TestDisplayUsageLogs) {
	EquipmentUsageLogger logger;
	logger.logUsage("Stationary Bike", "Jane Doe", "Leg Workout");
	testing::internal::CaptureStdout();
	try {
		logger.displayUsageLogs();
	}
	catch (const std::exception& e) {
		
		std::cerr << "Caught exception: " << e.what() << std::endl;
		FAIL();
	}
	catch (...) {
		std::cerr << "Caught an unknown exception." << std::endl;
		FAIL();
	}
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_TRUE(output.find("Equipment: Stationary Bike used by Jane Doe for Leg Workout") != std::string::npos);
}

TEST_F(GymManagementSystemTest, TestAddParticipation) {
	ParticipationTracking gymSystem;
	int result = gymSystem.addParticipation("John", "Running");
	EXPECT_EQ(result, 0); 
	EXPECT_EQ(gymSystem.participantPrograms["John"].size(), 1);
	EXPECT_EQ(gymSystem.participantPrograms["John"][0], "Running");
}
TEST_F(GymManagementSystemTest, TestBuyItem) {
	
	Purchase purchase;
	testing::internal::CaptureStdout();
	char validOption = 'A';
	bool buyResultValid = purchase.buyItem(validOption);
	EXPECT_TRUE(buyResultValid);
	char invalidOption = 'Z';
	bool buyResultInvalid = purchase.buyItem(invalidOption);
	EXPECT_FALSE(buyResultInvalid);
	testing::internal::GetCapturedStdout();
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
}
#endif