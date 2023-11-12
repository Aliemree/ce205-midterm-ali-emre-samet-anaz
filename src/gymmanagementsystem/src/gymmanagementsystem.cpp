#include "../header/gymmanagementsystem.h"
#include <stdexcept>

#include <fstream>
#include <list>

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map> 
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>



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

            for (const Member& member : loadedMembers) {
                std::cout << "Name: " << member.getName() << ", Contact: " << member.getContact() << std::endl;
            }

            std::cout << "1. Update a Member" << std::endl;
            std::cout << "2. Remove a Member" << std::endl;
            std::cout << "3. Back to Main Menu" << std::endl;

            int choice;
            std::cin >> choice;

            if (choice == 1) {
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
            else if (choice == 2) {
                listMembers();
                std::cout << "Enter the name of the member you want to remove: ";
                std::string name;
                std::cin >> name;

                auto it = std::remove_if(loadedMembers.begin(), loadedMembers.end(),
                    [name](const Member& member) { return member.getName() == name; });

                if (it != loadedMembers.end()) {
                    loadedMembers.erase(it, loadedMembers.end());

                    // Güncellenmiş üyeyi dosyaya kaydet
                    std::ofstream updatedFile(filename);

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
        std::string filename = "members.txt"; // Dosya yolunu belirt
        std::ifstream file(filename);

        if (file.is_open()) {
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

        }

        else {
            std::cout << "Failed to open the file for reading." << std::endl;
        }

    }

    void saveMembersToFile() {
        std::string filename = "members.txt"; // Dosya yolunu değiştirdik
        std::ofstream file(filename);

        if (file.is_open()) {
            for (const Member& member : members) {
                file << member.getName() << "," << member.getSurName() << "," << member.getContact() << "\n";
            }
            file.close();
            std::cout << "Members have been saved to " << filename << std::endl;
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
            return true;
        }
        else {
            std::cout << "Invalid option! Please select a valid item." << std::endl;
            return false;
        }
    }

private:
    std::unordered_map<char, std::pair<std::string, int>> priceList;
    std::vector<std::string> usageLog;

    void loadPriceList() {
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
};








