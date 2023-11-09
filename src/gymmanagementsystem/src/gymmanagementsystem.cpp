#include "../header/gymmanagementsystem.h"
#include <stdexcept>

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
        std::string filename = "C:\\Users\\aliem\\Desktop\\members.txt"; // Dosya yolunu belirt
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
        std::string filename = "C:\\Users\\aliem\\Desktop\\members.txt"; // Dosya yolunu belirt
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
        std::string filename = "C:\\Users\\aliem\\Desktop\\members.txt"; // Dosya yolunu belirt
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
                std::cout << "Name: " << name << ", Contact: " << contact << std::endl;
            }
            file.close();

        }

        else {
            std::cout << "Failed to open the file for reading." << std::endl;
        }

    }

    void saveMembersToFile() {
        std::string filename = "C:\\Users\\aliem\\Desktop\\members.txt"; // Dosya yolunu değiştirdik
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
        std::string filename = "C:\\Users\\aliem\\Desktop\\members.txt"; // Dosya yolunu belirt
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


    // Diğer işlevleri eklemek için aynı şekilde tanımlayabilirsiniz.

private:
    std::vector<Member> members;
    std::unordered_map<std::string, Member> memberHashMap; // Üyeleri adlarına göre saklamak için bir hash tablosu
};

