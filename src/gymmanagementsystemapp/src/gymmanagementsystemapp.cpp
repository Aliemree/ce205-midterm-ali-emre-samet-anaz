﻿#include <iostream>
#include <vector>
#include <string>
#include <unordered_map> 
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include "..\..\..\..\ce205-midterm-ali-emre-samet-anaz\src\gymmanagementsystem\src\gymmanagementsystem.cpp"




void PrintCentered(const std::string& text) {
    // Ekrandaki karakter genişliğini al
    int screenWidth = 125;  // Örnek olarak 80 karakter genişliği

    // Metni ortalamak için kullanılacak boşluk sayısını hesapla
    int padding = (screenWidth - text.length()) / 2;

    // Boşlukları metnin etrafına yerleştirerek metni ortala ve yazdır
    std::cout << std::string(padding, ' ') << text << std::string(padding, ' ') << std::endl;
}

int main() {

    EquipmentUsageLogger usageLogger;
    usageLogger.loadFromFile();
    MaintenanceScheduler scheduler;
    Purchase purchaseSystem;
    MembershipFeeTracking membershipTracker;
    DiscountOffers discountTracker;
    StockManagement stockManager;



    /*SchedulingManager schedulingManager;*/
    GymManager gym;
    std::vector<std::vector<int>> sparseMatrix;
    std::stack<int> stackData;
    std::queue<int> queueData;
    while (true) {

        PrintCentered("Gym Management System Menu");
        PrintCentered("1. Member Management");
        PrintCentered("2. Schedule");
        PrintCentered("3. Equipment Control");
        PrintCentered("4. Financials");
        PrintCentered("5. Give Feedback");
        PrintCentered("6. Exit");


        int choice;
        std::cin >> choice;
        system("cls");


        switch (choice) {
        case 1: {
            while (true) {
                PrintCentered("  Member Management ");
                PrintCentered("1. Registration");
                PrintCentered("2. Update ");
                PrintCentered("3. Delete");
                PrintCentered("4. List Members");
                PrintCentered("5. Back to Main Menu");

                int subChoice;
                std::cin >> subChoice;
                system("cls");

                switch (subChoice) {
                case 1:
                    gym.registration();
                    gym.saveMembersToFile();
                   
                    break;
                case 2:
                 
                    gym.updateMembertoFile();
                    system("cls");
                    break;

                case 3:

                    gym.listMembers();
                    gym.removeMember();
                    system("cls");

                    break;
                case 4:

                    gym.listMembers();
                    system("cls");

                    break;

                case 5:
                    system("cls");
                    break;

                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                }

                if (subChoice == 5) {
                    break;
                }
            }
            system("cls");

            break;
        }


        case 2: {
            while (true) {
                system("cls");
                PrintCentered("  Scheduling ");
                PrintCentered("1. Workout Programs");
                PrintCentered("2. Class Scheduling ");
                PrintCentered("3. Participation Tracking");
                PrintCentered("4. Instructor Assignments");
                PrintCentered("5. Back to Main Menu");
               

                int subsubChoice;
                std::cin >> subsubChoice;

                switch (subsubChoice) {
                case 1:
                    while (true) {
                      
                        PrintCentered("  Workout Programs ");
                        PrintCentered("1. CHEST WORKOUT");
                        PrintCentered("2.  BACK WORKOUT ");
                        PrintCentered("3. BICEPS WORKOUT");
                        PrintCentered("4. TRICEPS WORKOUT");
                        PrintCentered("5. ABS WORKOUT");
                        PrintCentered("6. SHOULDER WORKOUT");
                        PrintCentered("7. LEGS ");
                        PrintCentered("8. BACK TO MAIN MENU");
                       
                       


                        int sub1Choice;
                        std::cin >> sub1Choice;
                      

                        switch (sub1Choice) {
                        case 1:
                           
                            std::cout << "\n\n\n\n";
                            std::cout << "\t PUSH UP:                 3 SETS;       15,12,10 REPS\n\n";
                            std::cout << "\t INCLINED BENCH-PRESS:    3 SETS;       15,12,10 REPS\n\n";
                            std::cout << "\t FLAT BENCH-PRESS:        3 SETS;       15,12,10 REPS\n\n";
                            std::cout << "\t DECLINED BENCH-PRESS:    3 SETS;       15,12,10 REPS\n\n";
                            std::cout << "\t INCLINE DUMBBELL-PRESS:  3 SETS;       15,12,10 REPS\n\n";
                            std::cout << "\t FLAT DUMBBELL-PRESS:      3 SETS;       15,12,10 REPS\n\n";
                            std::cout << "\t DECLINED DUMBBELL-PRESS:  3 SETS;       15,12,10 REPS\n\n";
                            std::cout << "\t CABLE CROSS:             3 SETS;       15,12,10 REPS\n\n";
                            std::cout << "\t SEATED MACHINE FLY:      3 SETS;       15,12,10 REPS\n\n";
                            std::cout << "\t PLEASE DON'T LIFT OVER-WEIGHT\n\n\n\n\n";



                            break;
                        case 2:

                            std::cout << "\n\n\n\n";
                            std::cout << "\t WIDE GRIP PULL-UP:       3 SETS;        15,12,10 REPS\n\n";
                            std::cout << "\t LAT PULL DOWN BACK:      3 SETS;        15,12,10 REPS\n\n";
                            std::cout << "\t T-BAR:                   3 SETS;        15,12,10 REPS\n\n";
                            std::cout << "\t SEATED RAW:              3 SETS;        15,12,10 REPS\n\n";
                            std::cout << "\t PULL DOWN ROW:           3 SETS;        15,12,10 REPS\n\n";
                            std::cout << "\t ONR ARM DUMBBELL ROWS:   3 SETS;        15,12,10 REPS\n\n";
                            std::cout << "\t BARBELL BENT OVER:       3 SETS;        15,12,10 REPS\n\n";
                            std::cout << "\t DEAD LIFT:               3 SETS;        15,12,10 REPS\n\n";
                            std::cout << "\t PLEASE DON'T LIFT OVER-WEIGHT\n\n\n";
                            // Durum 2break;
                            break;
                        case 3:

                            std::cout << "\n\n\n\n";
                            std::cout << "\t SMALL GRIP PULL-UP:       3 SETS;        15,12,10 REPS\n\n";
                            std::cout << "\t PREACHER CURLS:           3 SETS;        15,12,10 REPS\n\n";
                            std::cout << "\t BARBELL CURLS:            3 SETS;        15,12,10 REPS\n\n";
                            std::cout << "\t ONE BY ONE DUMBELL CURL:  3 SETS;        15,12,10 REPS\n\n";
                            std::cout << "\t CONCENTRATION CURLS:      3 SETS;        15,12,10 REPS\n\n";
                            std::cout << "\t CABLE BICEPS CURLS:       3 SETS;        15,12,10 REPS\n\n";
                            std::cout << "\t INCLINED DUMBELL CURLS:   3 SETS;        15,12,10 REPS\n\n";
                            std::cout << "\t REVERSE CURLS:            3 SETS;        15,12,10 REPS\n\n";
                            std::cout << "\t HAMMER CURLS:             3 SETS;        15,12,10 REPS\n\n";
                            std::cout << "\t PLEASE DON'T LIFT OVER-WEIGHT\n\n\n";
                            // Durum 3
                            break;
                        case 4:


                            std::cout << "\n\n\n\n";
                            std::cout << "\t DIAMOND PUSH-UP:               3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t FLAT BAR TRICEPS EXTENSION:    3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t BAR TRICEPS EXTENSION:         3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t ONE ARM DUMBELL PRESS:         3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t BOTH ARM DUMBELL PRESS:        3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t KICKBACK:                      3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t CABLE PUSH DOWN:               3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t CABLE PUSH OVERHEAD:           3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t TRICEPS DIPS:                  3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t PLEASE DON'T LIFT OVER-WEIGHT\n\n\n";
                            // Durum 4
                            break;
                        case 5:


                            std::cout << "\n\n\n\n";
                            std::cout << "\t HANGING LEG RAISE:                             3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t MACHINE CRUNCH:                                3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t CABLE PALLOF PRESS:                            3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t KNEELING CABLE CRUNCH:                         3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t DECLINE-BENCH CRUNCH WITH MEDICINE BALL:       3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t EXERCISE BALL PIKE:                            3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t PLANK:                                         7,5,3 MINUTES\n\n";
                            std::cout << "\t PLEASE DON'T LIFT OVER-WEIGHT\n\n\n";
                            // Durum 5
                            break;
                        case 6:
                            std::cout << "\n\n\n\n";
                            std::cout << "\t BAREBELL FRONT PRESS:           3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t DUMBELL PRESS:                  3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t LATERAL RAISES:                 3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t FRONT PRESS:                    3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t DUMBELL BENT OVER:              3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t UPRIGHT ROW:                    3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t SHRUG:                          3 SETS;     15,12,10 REPS\n\n";
                            std::cout << "\t PLEASE DON'T LIFT OVER-WEIGHT\n\n";
                            // Durum 6
                            break;
                        case 7:
                            std::cout << "\n\n";
                            std::cout << "\t SET-UPS:                      3 SETS;      15,12,10 REPS\n\n";
                            std::cout << "\t SUMO DUMBELL SQUATS:          3 SETS;      15,12,10 REPS\n\n";
                            std::cout << "\t LUNGES DUMBELLS:              3 SETS;      15,12,10 REPS\n\n";
                            std::cout << "\t SEATED LEGS CRULS:            3 SETS;      15,12,10 REPS\n\n";
                            std::cout << "\t SEATED MACHINE EXTENSIONS:    3 SETS;      15,12,10 REPS\n\n";
                            std::cout << "\t STANDING DUMBELL CALF:        3 SETS;      15,12,10 REPS\n\n";
                            std::cout << "\t REVERSE LEGS CRULS:           3 SETS;      15,12,10 REPS\n\n";
                            std::cout << "\t HEAVY LEG PRESS:              3 SETS;      15,12,10 REPS\n\n";
                            std::cout << "\t PLEASE DON'T LIFT OVER-WEIGHT\n\n";
                            // Durum 7
                            break;
                        case 8:
                            system("cls");
                            main();
                            break;
                        default:
                            std::cout << "Invalid choice. Please try again." << std::endl;
                            break;
                        }
                    }

                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                }

                if (subsubChoice == 5) {

                    break;
                }
            }
            // Programınıza uygun olarak programları, sınıf saatlerini ve diğer programları yönetmek için işlevleri ekleyebilirsiniz.
            system("cls");
            break;
        }

        case 3: {
            while (true) {

                PrintCentered("  Equipment control ");
                PrintCentered("1. Usage Logs");
                PrintCentered("2. Maintenance Schedules ");
                PrintCentered("3. Purchase");
                PrintCentered("4. Rules And Regulayions");
                PrintCentered("5. Back to Main Menu");


                int subChoice;
                std::cin >> subChoice;
                system("cls");
                switch (subChoice) {
                case 1:
                    

                    PrintCentered("  Equipment List ");
                    PrintCentered("1. Mountain bike");
                    PrintCentered("2. Elliptical training ");
                    PrintCentered("3. Railway Power ");
                    PrintCentered("4. Dumbbell");
                    PrintCentered("5. Shuttle Stand");
                    PrintCentered("6. Punching ball");
                    PrintCentered("7. Back to Main Menu");

                    usageLogger.loadFromFile();
                    usageLogger.getUserInputForMultipleEquipments();
                    usageLogger.performDataStructureOperations();
                    usageLogger.calculateUsageFromLogs();


                    std::cout << "Displaying Usage Logs Once:" << std::endl;
                    usageLogger.displayUsageLogs(); // Tek seferde kullanım günlüklerini listele
                    usageLogger.displayEquipmentUsageCount();
                    std::cout << "Press Enter to exit...";
                    std::cin.get();

                    system("cls");
                    break;

                case 2:

                    // Bakım planı oluşturma
                    scheduler.scheduleMaintenance("Treadmill", "2023-11-15");
                    scheduler.scheduleMaintenance("Dumbbells", "2023-11-20");
                    scheduler.scheduleMaintenance("Mountain bike", "2023-11-15");
                    scheduler.scheduleMaintenance("Elliptical training", "2023-11-20");
                    scheduler.scheduleMaintenance("Shuttle Stand", "2023-11-27");
                    scheduler.scheduleMaintenance("Punching ball", "2023-11-14");

                    // Bakım planını görüntüleme
                    scheduler.displayMaintenanceSchedule();

                    // Bakım durumunu kontrol etme
                    scheduler.checkMaintenanceStatus("Treadmill", "2023-11-16");
                    scheduler.checkMaintenanceStatus("Mountain bike", "2023-11-15");
                    scheduler.checkMaintenanceStatus("Punching ball", "2023 - 11 - 14");
                    main();
                    break;

                case 3:

                    purchaseSystem.displayPurchaseOptions();
                    char option;
                    std::cout << "Select an option to buy (A to I): ";
                    std::cin >> option;

                    if (purchaseSystem.buyItem(option)) {
                        std::cout << "Thank you for your purchase!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                        system("cls");
                    }
                    else {
                        std::cout << "Purchase failed. Please try again." << std::endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                        system("cls");
                    }
                    break;

                    main();
                case 4:

                    PrintCentered("  Rules And Regulayions ");
                    PrintCentered("\n\t1.Do not bring your gym bag or other personal belongings onto the fitness floor.\n");
                    PrintCentered("\t2.Refrain from yelling, using profanity, banging weights and making loud sounds\n");
                    PrintCentered("\t3.Do not sit on machines between sets\n");
                    PrintCentered("\t4.Re-rack weights and return all other equipment and accessories to their proper locations\n");
                    PrintCentered("\t5.Ask staff to show you how to operate equipment properly so that others are not waiting as you figure it out.\n");
                    PrintCentered("\t6.Wipe down all equipment after use.\n");
                    PrintCentered("\t7.Stick to posted time limits on all cardiovascular machines.\n");
                    PrintCentered("\t8.Do not bring children onto the gym floor. Children must remain in the childcare area.\n");
                    PrintCentered("\t9.Do not disturb others. Focus on your own workout and allow others to do the same.\n");
                    PrintCentered("\t10.Before beginning your workout, wash your hands and wipe off any cologne or perfume.\n\n");
                    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                    system("cls");

                    break;
                case 5:
                    system("cls");
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                    system("cls");
                }

                if (subChoice == 5) {

                    break;
                }
            }

            break;

        }

        case 4: {
            while (true) {


                PrintCentered("  Financials ");
                PrintCentered("1. Membership Fee Tracking");
                PrintCentered("2. Discount Offers ");
                PrintCentered("3. Point-Of-Sale For Merchandise");
                PrintCentered("4. Back to Main Menu");

                int subChoice;
                std::cin >> subChoice;
                system("cls");
                switch (subChoice) {
                case 1:
                    


                    membershipTracker.displayMembershipFeeList();
                    char typeOption;
                    std::cout << "Enter the membership type (A - I): ";
                    std::cin >> typeOption;
                    
                    membershipTracker.getAndSaveUserInfo();
                    membershipTracker.setMembershipType(typeOption);
                    break;
                case 2:
                    discountTracker.displayDiscountOptions();

                    char userDiscount;
                    std::cout << "Enter the discount code: ";
                    std::cin >> userDiscount;
                    discountTracker.evaluateDiscountRequest(userDiscount);
                   
                    break;
                case 3:
                    stockManager.displayStock();
                    PrintCentered("STOK HARAMDIR");
                   
                    break;
                case 4:
                    system("cls");
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                }

                if (subChoice == 4) {
                    break;
                }
                // Finansal işlevleri ekleyebilirsiniz.
            }
            system("cls");
            break;

        }


        case 5:
            while (true) {


                PrintCentered("  FEEDBACK ");
                PrintCentered("1. ");
                PrintCentered("2.  ");
                PrintCentered("3. ");
                PrintCentered("4. Back to Main Menu");

                int subChoice;
                std::cin >> subChoice;
                system("cls");
                switch (subChoice) {
                case 1:
                    //kullanıcının nickname ini iste
                    //ismi feedback.txt ye kaydet
                    break;
                case 2:
                    //kullanıcının yorumunu iste
                    // yorumu feedback.txt ye kaydet
                    break;
                case 3:
                    //kullanıcıdan 0 ile 10 arasından bir puan iste
                    //puanı feedback.txt ye kaydet
                    break;

                case 4:
                    // sırayla ekrana yazdırma zımbırtısı alisko sen o is gobusunu kıtlarım

                    system("cls");
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                }

                if (subChoice == 4) {
                    break;
                }
                // Finansal işlevleri ekleyebilirsiniz.
            }
        
        system("cls");
        break;

        case 6:

            return 0;


        default:
            std::cout << "Invalid choice. Please try again." << std::endl;

        }


    }

}
