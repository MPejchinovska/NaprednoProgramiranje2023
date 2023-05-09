//Marijana Pejchinovska INKI1003
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>


struct Profile {
    int ID;
    std::string username;
    float level;

    static bool sortByUsername(const Profile &a, const Profile &b) {
        return a.username < b.username;
    }
};


std::vector<Profile> loadProfiles(const std::string &filename) {
    std::vector<Profile> profiles;
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            Profile p;
            char comma;
            if (iss >> p.ID >> comma >> p.username >> comma >> p.level) {
                profiles.push_back(p);
            }
        }
        file.close();
    } else {
        std::cerr << "Error: Fajlot ne postoi.!" << std::endl;
    }

    return profiles;
}


int main() {
    std::vector<Profile> profiles = loadProfiles("INKI1003.Marijana");

    if (!profiles.empty()) {
        std::cout << "Sortirani po ID:" << std::endl;
        for (const auto &profile : profiles) {
            std::cout << profile.ID << " " << profile.username << " " << profile.level << std::endl;
        }

        std::sort(profiles.begin(), profiles.end(), Profile::sortByUsername);

        std::cout << "Sortirani po azbuchen red(a-z):" << std::endl;
        for (const auto &profile : profiles) {
            std::cout << profile.ID << " " << profile.username << " " << profile.level << std::endl;
        }
    } else {
        std::cout << "Ne se pronajdeni nikakvi profili vo fajlot." << std::endl;
    }

    return 0;
}
