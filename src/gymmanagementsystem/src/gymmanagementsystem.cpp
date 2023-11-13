#include "../header/gymmanagementsystem.h"
#include <stdexcept>#include <fstream>
#include <list>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map> 
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include <unordered_set>


class LoginScreen {
public:
    void authenticateUser() {



        std::string username, password;

        while (true) {
            std::cout << "Username: ";
            std::cin >> username;

            std::cout << "Password: ";
            std::cin >> password;

            if (isValidCredentials(username, password)) {
                std::cout << "Authentication successful. Welcome, " << username << "!" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                system("cls");
                break;
            }
            else {
                std::cout << "Invalid credentials. Please try again." << std::endl;
            }
        }
    }

private:
    bool isValidCredentials(const std::string& username, const std::string& password) {
        // Burada kullanıcı adı ve şifreyi kontrol edin (örneğin, sabit bir kullanıcı adı ve şifre ile karşılaştırabilirsiniz)
        // Gerçek bir uygulamada, genellikle bir kullanıcı veritabanından kontrol edilir.
        return (username == "admin" && password == "admin");
    }
};

class Member {
public:
    Member() : name(""), surname(""), contact("") {}

    Member(const std::string& name, const std::string& surname, const std::string& contact) : name(name), surname(surname), contact(contact) {}


    std::string getName() const {
        return name;
    }
    std::string getSurName() const {
        return surname;
    }

    std::string getContact() const {
        return contact;
    }

private:
    std::string name;
    std::string surname;
    std::string contact;
};
class GymManager {
public:
    void addMember(const Member& member) {
        members.push_back(member);
        memberHashMap[member.getName()] = member;  // Hash tablosuna üyeyi ekle
    }

    void removeMember() {
        std::string filename = "members.txt"; // Dosya yolunu belirt
        std::ifstream file(filename);

        if (file.is_open()) {
            std::string line;
            std::vector<Member> loadedMembers;

            while (std::getline(file, line)) {
                std::istringstream ss(line);
                std::string name, surname, contact;
                std::getline(ss, name, ',');
                std::getline(ss, surname, ',');
                std::getline(ss, contact, ',');
                Member member(name, surname, contact);
                loadedMembers.push_back(member);
            }

            file.close();

            std::cout << "Members from file:" << std::endl;

            

            std::cout << "1. Update a Member" << std::endl;
            std::cout << "2. Remove a Member" << std::endl;
            std::cout << "3. Back to Main Menu" << std::endl;

            int choice;
            std::cin >> choice;

            if (choice == 1) {
                // ... (update logic)
            }
            else if (choice == 2) {
                // Remove logic
                listMembers();  // Show members after removal
                std::cout << "Enter the name of the member you want to remove: ";
                std::string name;
                std::cin >> name;

                auto it = std::remove_if(loadedMembers.begin(), loadedMembers.end(),
                    [name](const Member& member) { return member.getName() == name; });

                if (it != loadedMembers.end()) {
                    loadedMembers.erase(it, loadedMembers.end());

                    // Güncellenmiş üyeyi dosyaya kaydet
                    std::ofstream updatedFile(filename);
                    std::cout << "Member informations removed!: ";
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                    system("cls");

                    if (updatedFile.is_open()) {
                        for (const Member& member : loadedMembers) {
                            updatedFile << member.getName() << "," << member.getSurName() << "," << member.getContact() << "\n";
                        }
                        updatedFile.close();
                        std::cout << "Member with name " << name << " has been removed." << std::endl;
                    }
                    else {
                        std::cout << "Failed to open the file for saving." << std::endl;
                    }
                }
                else {
                    std::cout << "Member with name " << name << " not found." << std::endl;
                }
            }
            // ... (back to main menu logic)
        }
        else {
            std::cout << "Failed to open the file for reading." << std::endl;
        }

        // Kullanıcıdan bir tuşa basılmasını bekleyin.
        std::cout << "Press any key to clear the screen...";
        std::cin.get(); // Kullanıcının herhangi bir tuşa basmasını bekleyin.
        system("cls");  // Ekranı temizle
    }



    void updateMembertoFile() {
        std::string filename = "members.txt"; // Dosya yolunu belirt
        std::ifstream file(filename);

        if (file.is_open()) {
            std::string line;
            std::vector<Member> loadedMembers;

            while (std::getline(file, line)) {
                std::istringstream ss(line);
                std::string name, surname, contact;
                std::getline(ss, name, ',');
                std::getline(ss, surname, ',');
                std::getline(ss, contact, ',');
                Member member(name, surname, contact);
                loadedMembers.push_back(member);
            }

            file.close();

            std::cout << "Members from file:" << std::endl;

            for (const Member& member : loadedMembers) {
                std::cout << "Name: " << member.getName() << ", Contact: " << member.getContact() << std::endl;
            }

            std::cout << "Enter the name of the member you want to update: ";
            std::string name;
            std::cin >> name;

            auto it = std::find_if(loadedMembers.begin(), loadedMembers.end(),
                [name](const Member& member) { return member.getName() == name; });

            if (it != loadedMembers.end()) {
                std::string updatedName, updatedSurname, updatedContact;

                std::cout << "Enter updated name: ";
                std::cin >> updatedName;
                std::cout << "Enter updated surname: ";
                std::cin >> updatedSurname;
                std::cout << "Enter updated contact: ";
                std::cin >> updatedContact;

                Member updatedMember(updatedName, updatedSurname, updatedContact);
                *it = updatedMember;

                // Güncellenmiş üyeyi dosyaya kaydet
                std::ofstream updatedFile(filename);
                std::cout << "Member information updated!: ";
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("cls");

                if (updatedFile.is_open()) {
                    for (const Member& member : loadedMembers) {
                        updatedFile << member.getName() << "," << member.getSurName() << "," << member.getContact() << "\n";
                    }
                    updatedFile.close();
                    std::cout << "Member with name " << updatedName << " has been updated." << std::endl;
                }
                else {
                    std::cout << "Failed to open the file for saving." << std::endl;
                }
            }
            else {
                std::cout << "Member with name " << name << " not found. Update failed." << std::endl;
            }
        }
        else {
            std::cout << "Failed to open the file for reading." << std::endl;
        }

        // Kullanıcıdan bir tuşa basılmasını bekleyin.
        std::cout << "Press any key to clear the screen...";
        std::cin.get(); // Kullanıcının herhangi bir tuşa basmasını bekleyin.
        system("cls");  // Ekranı temizle
    }




    void displayMembers() {
        std::cout << "Gym Members:" << std::endl;
        for (const Member& member : members) {
            std::cout << "Name: " << member.getName() << ", Contact: " << member.getContact() << std::endl;
        }
    }
    void listMembers() {
        system("cls"); // Ekranı temizle
        std::string filename = "members.txt"; // Dosya yolunu belirt
        std::ifstream file(filename);

        std::string line;
        std::cout << "Members from file:" << std::endl;

        while (std::getline(file, line)) {
            std::istringstream ss(line);
            std::string name, surname, contact;
            std::getline(ss, name, ',');
            std::getline(ss, surname, ',');
            std::getline(ss, contact, ',');
            std::cout << "\nName: " << name << ", \nSurname:" << surname << ", \nContact: " << contact << std::endl;
        }

        file.close();

        std::cout << "\nPress enter to continue";
        std::cin.ignore(); // Enter tuşunu beklemek için gereklidir.
        std::cin.get(); // Kullanıcının herhangi bir tuşa basmasını bekleyin.
    }


    void saveMembersToFile() {
        std::string filename = "members.txt"; // Dosya yolunu değiştirdik
        std::ofstream file(filename);
        system("cls");

        if (file.is_open()) {
            for (const Member& member : members) {
                file << member.getName() << "," << member.getSurName() << "," << member.getContact() << "\n";
            }
            file.close();
            std::cout << "Members have been saved to " << filename << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            system("cls");

        }
        else {
            std::cout << "Failed to open the file for saving." << std::endl;
        }
    }

    void loadMembersFromFile() {
        std::string filename = "members.txt"; // Dosya yolunu belirt
        std::ifstream file(filename);

        if (file.is_open()) {
            members.clear(); // Mevcut üyeleri temizle
            std::string line;

            while (std::getline(file, line)) {
                std::istringstream ss(line);
                std::string name, surname, contact;
                std::getline(ss, name, ',');
                std::getline(ss, surname, ',');
                std::getline(ss, contact, ',');
                Member member(name, surname, contact);
                members.push_back(member);
                memberHashMap[name] = member; // Hash tablosuna ekle
            }

            file.close();
            std::cout << "Members have been loaded from " << filename << std::endl;
        }
        else {
            std::cout << "Failed to open the file for loading." << std::endl;
        }
    }

    void registration() {
        std::string name, contact, surname;
        std::cout << "Enter Name: ";
        std::cin >> name;
        std::cout << "Enter SurName: ";
        std::cin >> surname;
        std::cout << "Enter Contact: ";
        std::cin >> contact;
        Member newMember(name, surname, contact);
        addMember(newMember);
    }

private:
    std::vector<Member> members;
    std::unordered_map<std::string, Member> memberHashMap; // Üyeleri adlarına göre saklamak için bir hash tablosu
};
class Equipment {
public:
    Equipment() : name(""), lastMaintenance(""), usageLogs(0) {}

    Equipment(const std::string& name, const std::string& lastMaintenance, int usageLogs)
        : name(name), lastMaintenance(lastMaintenance), usageLogs(usageLogs) {}

    std::string getName() const {
        return name;
    }

    std::string getLastMaintenance() const {
        return lastMaintenance;
    }

    int getUsageLogs() const {
        return usageLogs;
    }

private:
    std::string name;
    std::string lastMaintenance;
    int usageLogs;
};
class EquipmentManager {
public:
    void addEquipment(const Equipment& equipment) {
        equipments.push_back(equipment);
        equipmentHashMap[equipment.getName()] = equipment;
    }

    void displayEquipment() {
        std::cout << "Gym Equipment:" << std::endl;
        for (const Equipment& equipment : equipments) {
            std::cout << "Name: " << equipment.getName() << ", Last Maintenance: " << equipment.getLastMaintenance() << ", Usage Logs: " << equipment.getUsageLogs() << std::endl;
        }
    }

    void listEquipment() {
        std::string filename = "equipment.txt";
        std::ifstream file(filename);

        if (file.is_open()) {
            std::string line;
            std::cout << "Equipment from file:" << std::endl;
            while (std::getline(file, line)) {
                std::istringstream ss(line);
                std::string name, lastMaintenance;
                int usageLogs;
                ss >> name >> lastMaintenance >> usageLogs;
                Equipment equipment(name, lastMaintenance, usageLogs);
                std::cout << "Name: " << equipment.getName() << ", Last Maintenance: " << equipment.getLastMaintenance() << ", Usage Logs: " << equipment.getUsageLogs() << std::endl;
            }
            file.close();
        }
        else {
            std::cout << "Failed to open the file for reading." << std::endl;
        }
    }

    // Other methods for updating, removing, saving, loading equipment data

private:
    std::vector<Equipment> equipments;
    std::unordered_map<std::string, Equipment> equipmentHashMap;
};
class EquipmentUsageLogger {
public:
    void logUsage(const std::string& equipmentName, const std::string& user, const std::string& purpose) {
        usageLog.push_back("Equipment: " + equipmentName + " used by " + user + " for " + purpose);
       usageMap[equipmentName]++;
        saveToFile();  // Her yeni kullanımı dosyaya kaydet
    }

    void displayUsageLogs() {
        std::cout << "Usage Logs:" << std::endl;
        for (const auto& log : usageLog) {
            std::cout << log << std::endl;
        }
    }

    void displayEquipmentUsageCount() {
        std::cout << "Equipment Usage Counts:" << std::endl;
        for (const auto& pair : usageMap) {
            std::cout << pair.first << " used " << pair.second << " times." << std::endl;
        }
    }

    void getUserInputAndLogUsage() {
        std::string equipmentName, user, purpose;
        std::cout << "Enter equipment Number: ";
        std::getline(std::cin >> std::ws, equipmentName);

        std::cout << "Enter user name: ";
        std::getline(std::cin >> std::ws, user);

        std::cout << "Enter purpose of use: ";
        std::getline(std::cin >> std::ws, purpose);

        logUsage(equipmentName, user, purpose);
    }

    void getUserInputForMultipleEquipments() {
        int numEquipments;
        std::cout << "How much equipment did you use: ";
        std::cin >> numEquipments;
        std::cin.ignore();  // Clear input buffer

        for (int i = 0; i < numEquipments; ++i) {
            std::cout << "Enter details for equipment " << i + 1 << ":" << std::endl;
            getUserInputAndLogUsage();
        }
    }

    void loadFromFile() {
    
        std::ifstream file("usage_logs.txt");
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                usageLog.push_back(line);
                updateEquipmentUsageCount(line); // Her girdide ekipman kullanım sayısını güncelle
            }
            file.close();
        }
    }

    void saveToFile() {
        std::ofstream file("usage_logs.txt");
        if (file.is_open()) {
            for (const auto& log : usageLog) {
                file << log << "\n";
            }
            file.close();
        }
        else {
            std::cout << "Unable to save to file." << std::endl;
        }
    }

    void calculateUsageFromLogs() {
        std::ifstream file("usage_logs.txt");
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                usageLog.push_back(line);
                updateEquipmentUsageCount(line); // Her girdide ekipman kullanım sayısını güncelle
            }
            file.close();
        }
    }

    void updateEquipmentUsageCount(const std::string& log) {
        std::istringstream ss(log);
        std::string equipmentName, user, purpose;
        ss >> equipmentName >> user >> purpose;
        usageMap[equipmentName]++;
    }

    // Yeni eklenen işlevler
    void performDataStructureOperations() {
        std::cout << "Performing operations on various data structures and algorithms:" << std::endl;
        // Örnek olarak bir Double Linked List ve Stack kullanılıyor:
        performDoubleLinkedListOperations();
        performStackOperations();
    }

    void performDoubleLinkedListOperations() {
        std::list<std::string> doubleLinkedList;
        doubleLinkedList.push_back("Item 1");

        std::cout << "Double Linked List operations performed." << std::endl;
        for (const auto& item : doubleLinkedList) {
            std::cout << "Item: " << item << std::endl;
        }
    }

    void performStackOperations() {
        std::stack<std::string> stackData;
        stackData.push("Data 1");

        std::cout << "Stack operations performed." << std::endl;
        while (!stackData.empty()) {
            std::cout << "Stack Top: " << stackData.top() << std::endl;
            stackData.pop();
        }
    }


private:
    std::vector<std::string> usageLog;
    std::unordered_map<std::string, int> usageMap;
};
class MaintenanceScheduler {
public:
public:
    void scheduleMaintenance(const std::string& equipmentName, const std::string& maintenanceDate) {
        maintenanceSchedule[equipmentName] = maintenanceDate;
        std::cout << "Maintenance scheduled for " << equipmentName << " on " << maintenanceDate << std::endl;
    }

    void performMaintenance() {
        std::stack<std::string> maintenanceStack;

        for (const auto& schedule : maintenanceSchedule) {
            maintenanceStack.push(schedule.first);
        }

        while (!maintenanceStack.empty()) {
            std::string equipment = maintenanceStack.top();
            maintenanceStack.pop();

            std::cout << "Performing maintenance for " << equipment << std::endl;
            // Perform maintenance operations here

            std::cout << "Maintenance completed for " << equipment << std::endl;
        }
    }

    void addMaintenanceRecord(const std::string& equipmentName, const std::string& maintenanceDate) {
        maintenanceRecords[equipmentName] = maintenanceDate;
        std::cout << "Maintenance record added for " << equipmentName << " on " << maintenanceDate << std::endl;
    }

    void checkMaintenanceStatus(const std::string& equipmentName, const std::string& currentDate) {
        if (maintenanceSchedule.find(equipmentName) != maintenanceSchedule.end()) {
            if (currentDate > maintenanceSchedule[equipmentName]) {
                std::cout << equipmentName << " is due for maintenance!" << std::endl;
            }
            else {
                std::cout << equipmentName << " is up to date with maintenance." << std::endl;
            }
        }
        else {
            std::cout << "No maintenance schedule found for " << equipmentName << std::endl;
        }
    }

    void displayMaintenanceSchedule() {
        std::cout << "Maintenance Schedule:" << std::endl;
        for (const auto& record : maintenanceSchedule) {
            std::cout << record.first << " - " << record.second << std::endl;
        }
    }

private:
    std::unordered_map<std::string, std::string> maintenanceSchedule;
    std::unordered_map<std::string, std::string> maintenanceRecords;

};
class ClassScheduling {
public:
    // Öğrenci yapıları
    struct Student {
        std::string name;
        std::vector<int> workoutPrograms; // Öğrencinin katıldığı antrenman programlarının indeksleri
    };

    // Antrenman programı yapıları
    struct WorkoutProgram {
        std::string name;
        std::vector<int> participants; // Antrenmana katılan öğrenci indeksleri
    };
    // Antrenman programları listesi
    std::vector<WorkoutProgram> programs;

    // Öğrencilerin listesi
    std::vector<Student> students;

    void createSampleData() {
        system("cls");
        // Antrenman programları oluştur
        WorkoutProgram chestProgram = { "Chest Workout", {} };
        WorkoutProgram backProgram = { "Back Workout", {} };
        WorkoutProgram bicepsProgram = { "Biceps Workout", {} };

        // Öğrenciler oluştur
        Student student1 = { "Samet", {0, 1} }; 
        Student student2 = { "Ali", {1, 2} };   
        Student student3 = { "Hüseyin", {1, 2} };
        // Programlara katılan öğrencileri güncelle
        chestProgram.participants = { 0, 1 };
        backProgram.participants = { 0, 2 };
        bicepsProgram.participants = { 1 };

        // Programları ve öğrencileri vektörlere ekle
        programs = { chestProgram, backProgram, bicepsProgram };
        students = { student1, student2,student3 };
    } 
    void listStudentsAndPrograms() {
        std::cout << "Ogrenciler ve Katildiklari Programlar:\n";
        for (size_t i = 0; i < students.size(); ++i) {
            std::cout << students[i].name << " - Katildigi Programlar: ";
            for (int programIndex : students[i].workoutPrograms) {
                std::cout << programs[programIndex].name << " ";
            }
            std::cout << std::endl;
        }
    }
    // SCC için kullanılan yardımcı fonksiyonlar
    void performSCC() {
        std::unordered_set<int> visited;
        std::vector<std::vector<int>> adjList(programs.size() + students.size());

        // Creating adjacency list based on the relationships between students and workout programs
        for (size_t i = 0; i < programs.size(); ++i) {
            for (int participant : programs[i].participants) {
                adjList[i].push_back(participant + programs.size());
                adjList[participant + programs.size()].push_back(i);
            }
        }

        std::vector<int> order; // For storing the finishing order
        for (size_t i = 0; i < adjList.size(); ++i) {
            if (visited.find(i) == visited.end()) {
                dfs(i, adjList, visited, order);
            }
        }

        // Reversing the graph
        std::vector<std::vector<int>> reversed(adjList.size());
        for (size_t i = 0; i < adjList.size(); ++i) {
            for (int j : adjList[i]) {
                reversed[j].push_back(i);
            }
        }

        visited.clear();

        // Printing SCC components
        std::vector<std::vector<int>> sccComponents;
        for (int i = order.size() - 1; i >= 0; --i) {
            int node = order[i];
            if (visited.find(node) == visited.end()) {
                std::vector<int> component;
                dfs(node, reversed, visited, component);
                sccComponents.push_back(component);
            }
        }

        // Printing SCC components
        std::cout << "Strongly Connected Components:\n";
        for (const auto& component : sccComponents) {
            std::cout << "Component: ";
            for (int node : component) {
                std::cout << node << " ";
            }
            std::cout << std::endl;
        }

    }

    void dfs(int node, const std::vector<std::vector<int>>& adjList, std::unordered_set<int>& visited, std::vector<int>& order) {
        visited.insert(node);
        for (int neighbor : adjList[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, adjList, visited, order);
            }
        }
        order.push_back(node);
    }
   
};
class ParticipationTracking {
public:
    std::unordered_map<std::string, std::vector<std::string>> participantPrograms;

    void addParticipation(const std::string& participant, const std::string& program) {
        participantPrograms[participant].push_back(program);
    }

    void listParticipations(const std::string& participant) {
        system("cls");
        if (participantPrograms.find(participant) != participantPrograms.end()) {
            std::cout << participant << " participated in: ";
            for (const std::string& program : participantPrograms[participant]) {
                std::cout << program << " ";
            }
            std::cout << std::endl;

        }
        else {
            std::cout << participant << " didn't participate in any program." << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
       
        
    }

    void readMembersFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string name;
                iss >> name;
                std::string program;
                while (iss >> program) {
                    participantPrograms[name].push_back(program);
                }
            }
            file.close();
        }
    }
};
class InstructorAssignments {
public:
    std::unordered_map<std::string, std::vector<std::string>> instructorToCourses;

    void assignCourseToInstructor(const std::string& instructor, const std::string& course) {
        instructorToCourses[instructor].push_back(course);
    }

    void listCoursesForInstructor(const std::string& instructor) {
        if (instructorToCourses.find(instructor) != instructorToCourses.end()) {
            std::cout << "Courses assigned to " << instructor << ": ";
            for (const std::string& course : instructorToCourses[instructor]) {
                std::cout << course << " ";
            }
            std::cout << std::endl;
        }
        else {
            std::cout << instructor << " is not assigned to any course." << std::endl;
        }
    }
};
class Purchase {
public:
    Purchase() {
        loadPriceList();
    }

    void displayPurchaseOptions() {
        std::cout << "\n\n\t\tPAYMENT METHODS AND DISCOUNTS\n\n";
        for (const auto& entry : priceList) {
            std::cout << "\n\t" << entry.first << "- " << entry.second.first << " : " << entry.second.second << "$";
        }
        std::cout << std::endl;
    }

    bool buyItem(char option) {
        if (priceList.find(option) != priceList.end()) {
            std::cout << "You've purchased " << priceList[option].first << " for " << priceList[option].second << "$." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            system("cls");
            return true;
        }
        else {
            std::cout << "Invalid option! Please select a valid item." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            system("cls");
            return false;
        }
    }

private:

    std::unordered_map<char, std::pair<std::string, int>> priceList;
    std::vector<std::string> usageLog;

    void loadPriceList() {
        priceList['A'] = { "Supplement / Whey Protein 30gr", 2 };
        priceList['B'] = { "Supplement / Isolate Protein 30gr)", 2 };
        priceList['C'] = { "Supplement / Creatine Monohydrate 5mg)", 1 };
        priceList['D'] = { "Supplement / Pre-Workout 10gr (200mg cafein)", 2 };
        priceList['E'] = { "Supplement / Cafein 1pill-200mg", 1 };
        priceList['F'] = { "Supplement / Glutamine 25gr", 2 };
        priceList['G'] = { "Supplement / BCAA 20gr ", 2 };
        priceList['H'] = { "Supplement / Arginine 12.5 gr", 1 };
        priceList['I'] = { "Vitamines / Multivitamines ", 5 };
    }
};
class MembershipFeeTracking{
public:
    MembershipFeeTracking() {
        loadMembershipFeeTrackingList(); // Fiyat listesini yükle
    }

    void displayMembershipFeeList() {
        std::cout << "\nMembership Fee List:\n";
        for (const auto& entry : priceList) {
            std::cout << entry.first << ". " << entry.second.first << " : " << entry.second.second << "$" << std::endl;
        }
    }
    void getAndSaveUserInfo() {
        std::ifstream inFile("members.txt"); // Dosyayı okuma modunda aç
        if (inFile.is_open()) {
            std::string line;
            std::cout << "Existing Members:\n";
            while (std::getline(inFile, line)) {
                std::cout << line << std::endl;
            }
            inFile.close();
        }
        else {
            std::cerr << "Unable to open the file!" << std::endl;
        }
    }


void setMembershipType(char option) {
    if (priceList.find(option) != priceList.end()) {
        std::cout << "You've selected: " << priceList[option].first << " for " << priceList[option].second << "$." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        system("cls");
        // Üyelik türünü kullanıcının seçtiği türe ayarla veya kaydet
    }
else {
 std::cout << "Invalid option! Please select a valid item." << std::endl;
 std::this_thread::sleep_for(std::chrono::milliseconds(2000));
 system("cls");
}
}

void createHeap() {
        for (const auto& entry : priceList) {
            heap.push_back(entry.second);
        }
        std::make_heap(heap.begin(), heap.end(), compareByPrice);
    }

    void displayHeap() {
        std::cout << "\nHeap Structure:\n";
        for (const auto& entry : heap) {
            std::cout << entry.first << " : " << entry.second << "$" << std::endl;
        }
    }

private:
    std::unordered_map<char, std::pair<std::string, int>> priceList;
    std::vector<std::pair<std::string, int>> heap;

    void loadMembershipFeeTrackingList() {
        priceList['A'] = { "Fitness / Normal Membership : 1 Month (5 days a week)", 20 };
        priceList['B'] = { "Fitness / Normal Membership : 1 Month (3 days a week)", 15 };
        priceList['C'] = { "Fitness / Student Discount : 1 Month (3 days a week)", 10 };
        priceList['D'] = { "Swimming / Normal Membership : 1 Month (5 days a week)", 25 };
        priceList['E'] = { "Swimming / Normal Membership : 1 Month (3 days a week)", 20 };
        priceList['F'] = { "Swimming / Student Discount : 1 Month (3 days a week)", 15 };
        priceList['G'] = { "Fitness and Swimming / Normal Membership : 1 Month (5 days a week)", 40 };
        priceList['H'] = { "Fitness and Swimming / Normal Membership : 1 Month (3 days a week)", 30 };
        priceList['I'] = { "Fitness and Swimming / Student Discount : 1 Month (3 days a week)", 20 };
    }

    static bool compareByPrice(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        return a.second < b.second;
    }
};
class DiscountOffer {
public:
    std::unordered_map<char, std::pair<std::string, int>> priceList;

    DiscountOffer() {
        priceList['A'] = { "Fitness / Normal Membership: 1 Month (5 days a week)", 20 };
        priceList['B'] = { "Fitness / Normal Membership: 1 Month (3 days a week)", 15 };
        priceList['C'] = { "Fitness / Student Discount: 1 Month (3 days a week)", 10 };
        priceList['D'] = { "Swimming / Normal Membership: 1 Month (5 days a week)", 25 };
        priceList['E'] = { "Swimming / Normal Membership: 1 Month (3 days a week)", 20 };
        priceList['F'] = { "Swimming / Student Discount: 1 Month (3 days a week)", 15 };
        priceList['G'] = { "Fitness and Swimming / Normal Membership: 1 Month (5 days a week)", 40 };
        priceList['H'] = { "Fitness and Swimming / Normal Membership: 1 Month (3 days a week)", 30 };
        priceList['I'] = { "Fitness and Swimming / Student Discount: 1 Month (3 days a week)", 20 };
    }

    int getPrice(char code) {
        if (priceList.find(code) != priceList.end()) {
            return priceList[code].second;
        }
        return -2;  // Eğer kod bulunamazsa -2 döndürür
    }
    void printPriceList() {
        for (const auto& entry : priceList) {
            std::cout << "Code: " << entry.first << " - " << entry.second.first << " - Price: " << entry.second.second << std::endl;
        }
    }
};
class OtherClass {
public:
    void displayPriceList() {
        DiscountOffer discountOffer;
        discountOffer.printPriceList();
    }
};
class GymPOS {
public:
    // Ürün listesi ve fiyatları için hash table
    std::unordered_map<std::string, double> productPrices;

    // Ürün eklemek için
    void addProduct(const std::string& productName, double price) {
        productPrices[productName] = price;
    }

    // Ürünü satın al
    void purchaseProduct(const std::string& productName) {
        if (productPrices.find(productName) != productPrices.end()) {
            std::cout << "You purchased " << productName << " for $" << productPrices[productName] << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            system("cls");

            // Burada, ürünü stoktan düşebilirsiniz.
        }
        else {
            
        }
    }
};
    class Feedback {
    public:
        void getUserInput() {
            std::cout << "Enter your nickname: ";
            std::cin >> nickname_;

            std::cout << "Enter your comment: ";
            std::cin.ignore(); // Ignore the newline character left in the buffer
            std::getline(std::cin, comment_);

            std::cout << "Enter your rating (1-10): ";
            std::cin >> rating_;
        }

        void saveToFeedbackFile() {
            std::ofstream file("feedback.txt", std::ios::app);
            if (file.is_open()) {
                file << "Nickname: " << nickname_ << std::endl;
                file << "Comment: " << comment_ << std::endl;
                file << "Rating: " << rating_ << std::endl;
                file << "-------------------------" << std::endl; // Separate entries in the file
                file.close();
                std::cout << "Your feedback has been saved!" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("cls");

            }
            else {
                std::cout << "Error! Your feedback couldn't be saved." << std::endl;
            }
        }
        void listFeedbacks() {
            std::ifstream file("feedback.txt");
            std::string line;
            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }
            file.close();
        }

        void developerInfo() {

            std::cout << "Our Github Links:" << std::endl;
            std::cout << "----------------------------" << std::endl; 
            std::cout << "https://github.com/Aliemree" << std::endl;
            std::cout << "https://github.com/SametAnaz" << std::endl;
            std::cout << "----------------------------" << std::endl;
            std::cout << "Press enter for exit." << std::endl;

        }

    private:
        std::string nickname_;
        std::string comment_;
        int rating_;
    };
















