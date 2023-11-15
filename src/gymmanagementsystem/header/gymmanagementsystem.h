/**
 * @file gymmanagementsystem.h
 * 
 * @brief Provides functions for math. utilities
 */

#ifndef GYMMANAGEMENTSYSTEM_H
#define GYMMANAGEMENTSYSTEM_H

#include "../../utility/header/commonTypes.h"

namespace Coruh
{
    namespace GymManagementSystem
    {
        /**
            @class GymManagementSystem
            @brief Provides Basic functions for various operations.
        */
        struct
            
            GymManagementSystem
        {
        public:
           
            int authenticateUser();
            int addMember();
            int removeMember();
            int updateMemberToFile();
            int listMembers();
            int displayMembers();
            int aveMembersToFile();
            int registration();
            int loadMembersFromFile();

            int addEquipment();
            int displayEquipment();
            int logUsage();
            int displayUsageLogs();
            int getUserInputAndLogUsage();
            int getUserInputForMultipleEquipments();
            int loadFromFile();
            int performDataStructureOperations();
            int performDoubleLinkedListOperations();
            int performStackOperations();
            int scheduleMaintenance();
            int performMaintenance();
            int addMaintenanceRecord();
            int checkMaintenanceStatus();
            int displayMaintenanceSchedule();
            int createSampleData();
            int listStudentsAndPrograms();
            int performSCC();
            int dfs();
            int updateSparseMatrix();
            int listParticipations();
            int developerInfo();
            int getUserInput();
            int saveToFeedbackFile();
            int listFeedbacks();
            int addProduct();
            int purchaseProduct();
            int printPriceList();
            int getPrice();
            int addParticipation();
           

            int assignCourseToInstructor();
            int listCoursesForInstructor();
            int loadPriceList();
            int displayPurchaseOptions();
            int displayPriceList();
            int getAndSaveUserInfo();
            int displayMembershipFeeList();
          
        };
    }
}

#endif // GYMMANAGEMENTSYSTEM_H