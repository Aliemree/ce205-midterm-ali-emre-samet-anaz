﻿#include <iostream>
#include <vector>
#include <string>
#include <unordered_map> 
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include "C:\Users\aliem\Desktop\ce205-midterm-ali-emre-samet-anaz\src\gymmanagementsystem\src\gymmanagementsystem.cpp"



void PrintCentered(const std::string& text) {
    // Ekrandaki karakter genişliğini al
    int screenWidth = 125;  // Örnek olarak 80 karakter genişliği

    // Metni ortalamak için kullanılacak boşluk sayısını hesapla
    int padding = (screenWidth - text.length()) / 2;

    // Boşlukları metnin etrafına yerleştirerek metni ortala ve yazdır
    std::cout << std::string(padding, ' ') << text << std::string(padding, ' ') << std::endl;
}

int main() {
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
        PrintCentered("5. Exit");


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
                    system("cls");
                    break;
                case 2:
                    // Güncelleme işlevini ekleyebilirsiniz.

                    gym.updateMembertoFile();



                    system("cls");
                    break;
                case 3:
                    gym.listMembers();
                    // Silme işlevini ekleyebilirsiniz.
                    gym.removeMember();
                    system("cls");
                    break;
                case 4:

                    gym.listMembers();



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
                PrintCentered("  Scheduling ");
                PrintCentered("1. Workout Programs");
                PrintCentered("2. Class Scheduling ");
                PrintCentered("3. Participation Tracking");
                PrintCentered("4. Instructor Assignments");
                PrintCentered("5. Back to Main Menu");


                int subsubChoice;
                std::cin >> subsubChoice;
                system("cls");
                switch (subsubChoice) {
                case 1:
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    // Güncelleme işlevini ekleyebilirsiniz.
                    break;
                case 3:
                    // Silme işlevini ekleyebilirsiniz.
                    system("cls");
                    break;
                case 4:
                    // Geri bildirim toplama işlevini ekleyebilirsiniz.
                    system("cls");
                    break;
                case 5:
                    system("cls");
                    break;
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
                PrintCentered("4. Replacement Planning");
                PrintCentered("5. Back to Main Menu");


                int subChoice;
                std::cin >> subChoice;
                system("cls");
                switch (subChoice) {
                case 1:
                    system("cls");
                    break;
                case 2:
                    // Güncelleme işlevini ekleyebilirsiniz.
                    system("cls");
                    break;
                case 3:
                    // Silme işlevini ekleyebilirsiniz.
                    system("cls");
                    break;
                case 4:
                    // Geri bildirim toplama işlevini ekleyebilirsiniz.
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
            // Ekipman kontrolü için işlevleri ekleyebilirsiniz.
            system("cls");
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
                    system("cls");
                    break;
                case 2:
                    // Güncelleme işlevini ekleyebilirsiniz.
                    system("cls");
                    break;
                case 3:
                    // Silme işlevini ekleyebilirsiniz.
                    system("cls");
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
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    //// Verileri dosyaya yaz
    //writeProgramToFile(schedulingManager.workoutPrograms, "WorkOutProgram.txt");

    //// Dosyadan verileri oku
    //schedulingManager.workoutPrograms = readProgramsFromFile("WorkOutProgram.txt");

    //// Ekrana yazdır
    //schedulingManager.displayWorkoutPrograms();


    //return 0;
}
