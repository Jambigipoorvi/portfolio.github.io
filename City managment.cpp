#include<iostream>
#include<windows.h>
using namespace std;

// Function prototypes for each section
void infrastructureFunction();
void residentsFunction();
void servicesFunction();
void transportFunction();
void color(int color_value)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,color_value);
}

#include<iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <limits>
using namespace std;

// Structure to store city information
struct City
{
    string name;
    string state;
    string country;
    float total_acres;
    long population;
    int rank_in_state;
};

// Structure to store infrastructure information
struct Infrastructure
 {
    string type;
    string name;
    string location;
    int year_built;
    //string google_map_link;
    float acres;
    int rating;  // Rating from 1 to 5
    string maintenance_status;
    string nearest_place;
};

// Structure to store road information
struct Road
 {
    string name;
    string start_location;
    string end_location;
    float length;  // in kilometers
    string road_condition;  // e.g., "Good", "Under construction", "Damaged"
};

// Class to manage city info, infrastructure, and roads
class CityManagementSystem
{
private:
    City city;
    vector<Infrastructure> infrastructures;
    vector<Road> roads;

public:
    // Method to set basic city info
    void setCityInfo(string city_name, string state_name, string country_name, float acres, long pop, int rank) {
        city.name = city_name;
        city.state = state_name;
        city.country = country_name;
        city.total_acres = acres;
        city.population = pop;
        city.rank_in_state = rank;
    }

    // Method to display city info
void displayCityInfo()
{
    City city;

    // Taking inputs for city details
    color(10);
    cout << "Enter City Name: ";
    cin>>city.name;

    cout << "\nEnter State Name: ";
    cin>>city.state;

    cout << "Enter Country Name: ";
    cin>>city.country;

    cout << "Enter Total Acres (in decimal format): ";
    cin >> city.total_acres;

    cout << "Enter Population: ";
    cin >> city.population;

    cout << "Enter Rank in State: ";
    cin >> city.rank_in_state;

    cin.ignore(); // Clear newline from the input buffer
    color(7);


    // Displaying city details
    color(14);
    cout << "\n--- City Information ---" << endl;
    color(11);
    cout << "City Name: " << city.name << endl;

    cout << "State: " << city.state << endl;

    cout << "Country: " << city.country << endl;

    cout << "Total Acres: " << city.total_acres << endl;

    cout << "Population: " << city.population << endl;

    cout << "Rank (in State): " << city.rank_in_state << endl;


    // Welcome message
    color(12);
    cout << "\nWelcome to " << city.name << "'City's Infrastructure!" << endl;
    color(11);

    cout << "Explore our well-designed infrastructure, modern amenities, and vibrant community." << endl;
}


    // Infrastructure Management
    void addInfrastructure(string type, string name, string location, int year_built, float acres, int rating, string maintenance, string nearest) {
        Infrastructure inf = {type, name, location, year_built, acres, rating, maintenance, nearest};
        infrastructures.push_back(inf);
    }

    void deleteInfrastructure(string name)
    {
    if (infrastructures.empty())
        {
            color(12);
        cout << "The infrastructure list is empty.\n";
        color(7);

        return;
    }

    cout << "\nCurrent Infrastructures:\n";
    displayInfrastructures();

    for (auto it = infrastructures.begin(); it != infrastructures.end(); ++it)
    {
        if (it->name == name)
        {
            // Confirm deletion from the user
            char confirm;
            color(12);
            cout << "Are you sure you want to delete " << name << "? (y/n): ";
            color(7);
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y')
            {
                infrastructures.erase(it);
                cout << "sure Infrastructure " << name << " has been deleted.\n";
            } else
            {
                cout << "sure!! Deletion canceled.\n";
            }
            return;
        }
    }
    cout << "Infrastructure " << name << " not found.\n";
}

  void updateInfrastructure(string name)
  {

    for (auto &inf : infrastructures)
     {
        if (inf.name == name)
            {
            int choice;
            cout << "What would you like to update?\n";

            cout<<"`~~~~~~~~~~~~~~~~~~~"<<endl;
            //1cout << "What would you like to update?\n";

    cout << "1. Name\n";
    cout << "2. Location\n";
    cout << "3. Year Built\n";
    cout << "4. Acres\n";
    cout << "5. Rating\n";
    cout << "6. Maintenance Status\n";
    cout << "7. Nearest Place\n";
            cout<<"enter the choice you would like to change :"<<endl;
            cin >> choice;

            switch (choice)
            {
                case 1:
                    {
                    cout << "Enter new name: ";
                    cin >> inf.name;
                    break;

                   }
                case 2:
                     {
                    cout << "Enter new location: ";
                    cin >> inf.location;
                    break;

                }
                case 3:
                    {
                    cout << "Enter new year built: ";
                    cin >> inf.year_built;
                    break;

                }
                case 4:
                     {
                    cout << "Enter new acres: ";
                    cin >> inf.acres;
                    break;

                }
                case 5: 
                    {
                    cout << "Enter new rating (1-5): ";
                    cin >> inf.rating;
                    break;
                }
                case 6: 
                    {
                    cout << "Enter new maintenance status: ";
                    cin >> inf.maintenance_status;
                    break;

                }
                case 7: 
                    {
                    cout << "Enter new nearest place: ";
                    cin >> inf.nearest_place;
                    break;

                }
                default:
                    cout << "Invalid choice!\n";
                    return;

            }

            cout << "Infrastructure " << name << " has been updated.\n";
            return;

        }
    }
    cout << "Infrastructure " << name << " not found.\n";

 }

    void displayInfrastructures()
    {
        for (auto &inf : infrastructures)
            {
            cout << "Infrastructure: " << inf.name << endl;
            cout << "Type: " << inf.type << endl;
            cout << "Location: " << inf.location << endl;
            cout << "Year Built: " << inf.year_built << endl;
            //cout << "Google Maps Link: " << inf.google_map_link << endl;
            cout << "Acres: " << inf.acres << endl;
            cout << "Rating: " << inf.rating << endl;
            cout << "Maintenance Status: " << inf.maintenance_status << endl;
            cout << "Nearest Place: " << inf.nearest_place << endl << endl;
        }
    }

    // Road Management
     void addRoad(string name, string start, string end, float length, string condition) {
        roads.push_back({name, start, end, length, condition});
    }

    void deleteRoad(string name)
    {
        for (auto it = roads.begin(); it != roads.end(); ++it)
            {
            if (it->name == name)
            {
                roads.erase(it);
                cout << "Road " << name << " has been deleted.\n";
                return;
            }
        }
        cout << "Road " << name << " not found.\n";
    }

    void updateRoad(string old_name, string new_name)
    {
        for (auto &road : roads)
            {
            if (road.name == old_name)
            {
                road.name = new_name;
                cout << "Road updated to " << new_name << ".\n";
                return;
            }
        }
        cout << "Road " << old_name << " not found.\n";
    }

    void displayRoads()
    {
        for (auto &road : roads)
            {
            cout << "Road: " << road.name << endl;
            cout << "Start: " << road.start_location << endl;
            cout << "End: " << road.end_location << endl;
            cout << "Length (km): " << road.length << endl;
            cout << "Condition: " << road.road_condition << endl << endl;
        }
    }

    // Sorting Functions
    void sortInfrastructuresByRating()
    {
        sort(infrastructures.begin(), infrastructures.end(), [](const Infrastructure &a, const Infrastructure &b) {
            return a.rating > b.rating;
        });
        cout << "Infrastructures sorted by rating.\n";
    }

    void sortRoadsByLength()
   {
        sort(roads.begin(), roads.end(), [](const Road &a, const Road &b)
       {
            return a.length > b.length;
        });
        cout << "Roads sorted by length.\n";
    }

    // Algorithm Example: Dijkstra's Algorithm (for finding the shortest road path)
     // Dijkstra's Algorithm for shortest path
    void dijkstraAlgorithm()
        {
        if (roads.empty())
        {
            cout << "No roads available to calculate shortest paths.\n";
            return;
        }

        // Create an adjacency list for the road network
        map<string, vector<pair<string, float>>> adjList;
        for (const auto& road : roads)
        {
            adjList[road.start_location].emplace_back(road.end_location, road.length);
            adjList[road.end_location].emplace_back(road.start_location, road.length);
        }

        string startLocation, endLocation;
        cout << "Enter the start location: ";
        cin >> startLocation;
        cout << "Enter the end location: ";
        cin >> endLocation;

        // Validate if locations exist in the road network
        if (adjList.find(startLocation) == adjList.end() || adjList.find(endLocation) == adjList.end())
        {
            cout << "Either the start or end location does not exist in the road network.\n";
            return;
        }

        // Distance map to store shortest distances, initialized to infinity
        map<string, float> distances;
        for (const auto& node : adjList)
        {
            distances[node.first] = numeric_limits<float>::max();
        }
        distances[startLocation] = 0;

        // Priority queue to select the node with the smallest distance
        priority_queue<pair<float, string>, vector<pair<float, string>>, greater<>> pq;
        pq.push({0, startLocation});

        // Map to track the previous node for path reconstruction
        map<string, string> previous;

        while (!pq.empty())
            {
            auto [currentDistance, currentNode] = pq.top();
            pq.pop();

            // Relax edges
            for (const auto& [neighbor, length] : adjList[currentNode])
                {
                float newDistance = currentDistance + length;
                if (newDistance < distances[neighbor])
                {
                    distances[neighbor] = newDistance;
                    previous[neighbor] = currentNode;
                    pq.push({newDistance, neighbor});
                }
            }
        }

        // Output the shortest path and distance
        if (distances[endLocation] == numeric_limits<float>::max())
        {
            cout << "No path found from " << startLocation << " to " << endLocation << ".\n";
        } else {
            cout << "Shortest path distance: " << distances[endLocation] << " km\nPath: ";
            string path = endLocation;
            vector<string> fullPath;
            while (path != startLocation)
            {
                fullPath.push_back(path);
                path = previous[path];
            }
            fullPath.push_back(startLocation);
            reverse(fullPath.begin(), fullPath.end());
            for (const string& location : fullPath)
            {
                cout << location;
                if (location != endLocation) cout << " -> ";
            }
            cout << endl;
        }
    }

    // Additional Functions
    void generateReport()
    {
        cout << "Generating a report of all infrastructures and roads...\n";
        displayInfrastructures();
        displayRoads();
    }

    void cityRanking()
    {
        cout << "City Rank in State: " << city.rank_in_state << endl;
    }

    void findInfrastructureByType(string type) {
        bool found = false;
        for (auto &inf : infrastructures) {
            if (inf.type == type) {
                cout << "Infrastructure Name: " << inf.name << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No infrastructures found of type: " << type << endl;
        }
    }

    void findRoadByCondition(string condition)
    {
        bool found = false;
        for (auto &road : roads)
            {
            if (road.road_condition == condition)
            {
                cout << "Road Name: " << road.name << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No roads found with condition: " << condition << endl;
        }
    }

    void updateCityInfo(string name, string state, string country)
    {
        city.name = name;
        city.state = state;
        city.country = country;
        cout << "City Info Updated!\n";
    }

    // Algorithm for searching roads by name (Linear Search)
    void searchRoadByName(string road_name)
    {
        bool found = false;
        for (auto &road : roads)
            {
            if (road.name == road_name)
            {
                cout << "Road Found: " << road.name << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "Road not found.\n";
        }
    }
};


#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

// Resident Class
class Resident
{
    std::string name;
    int age;


    std::string occupation;
    double income;
    int propertyID;
    std::string aadhar_id;

public:

    Resident(std::string n, int a, std::string o, double inc, int pID,std::string aid)
        : name(n), age(a), occupation(o), income(inc), propertyID(pID), aadhar_id(aid){}

    void display()
    {
        std::cout << "Name: " << name << ", Age: " << age
                  << ", Occupation: " << occupation
                  << ", Income: " << income
                  << ", Property ID: " << propertyID
                  <<", Aadhar id:" <<aadhar_id<< "\n";
    }

    std::string getName() { return name; }

    int getAge() { return age; }

    double getIncome() { return income; }

    int getPropertyID() { return propertyID; }

     std:: string  getAadharID() { return aadhar_id; }

    void setName(std::string n) { name = n; }

    void setAge(int a) { age = a; }

    void setOccupation(std::string o) { occupation = o; }

    void setIncome(double inc) { income = inc; }

    void setaadhar_id(std::string aid) {aadhar_id=aid;}
};

// Property Class
class Property
 {
    int id;

    std::string address;

    std::string type;

    int ownerID;

public:

    Property(int i, std::string addr, std::string t, int oID)
        : id(i), address(addr), type(t), ownerID(oID) {}

    void display()
     {
        std::cout << "Property ID: " << id
                  << ", Address: " << address
                  << ", Type: " << type
                  << ", Owner ID: " << ownerID << "\n";
    }

    int getID() { return id; }
};

// Zone Class
class Zone
{
    std::string name;

    int zoneID;

    std::vector<Resident> residents;

public:

    Zone(std::string n, int id) : name(n), zoneID(id) {}

    void addResidentToZone(Resident& resident)
    {
        residents.push_back(resident);
    }

    void displayZoneDetails()
    {
        std::cout << "Zone Name: " << name << ", Zone ID: " << zoneID << "\n";
        std::cout << "Residents in this Zone:\n";
        for (auto& resident : residents) {
            resident.display();
        }
    }

    std::string getZoneName() { return name; }

    int getZoneID() { return zoneID; }

    void displayResidents()
     {
        for (auto& resident : residents)
            {
            resident.display();
        }
    }

    int getPopulation()
     {
        return residents.size();
    }
};

// CityManagement Class
class CityManagement
{
    std::vector<Resident> residents;

    std::vector<Zone> zones;

public:
    // Resident-related methods

    void addResident()
    {
        std::string name, occupation,aadhar_id;

        int age, propertyID;
        double income;

        std::cout << "Enter Resident Name: ";

        std::cin >> name;

        std::cout << "Enter Age: ";

        std::cin >> age;


        std::cout << "Enter Occupation: ";

        std::cin >> occupation;


        std::cout << "Enter Income: ";

        std::cin >> income;

        std::cout << "Enter Property ID: ";

        std::cin >> propertyID;

        std::cout << "Enter Aadhar id: ";
        std::cin >> aadhar_id;


        residents.emplace_back(name, age, occupation, income, propertyID,aadhar_id);

        std::cout << "Resident added successfully!\n";
    }

    void displayAllResidents()

     {
        std::cout << "Residents:\n";

        for (auto& resident : residents)

            resident.display();
    }

    void searchResident()

     {
        std::string name;

        std::cout << "Enter Resident Name to Search: ";

        std::cin >> name;

        bool found = false;

        for (auto& resident : residents)
            {

            if (resident.getName() == name)
             {
                resident.display();
                found = true;
            }
        }

        if (!found) std::cout << "Resident not found!\n";
    }

    void sortResidentsByIncome() {
        for (size_t i = 0; i < residents.size(); i++)
            {
            for (size_t j = 0; j < residents.size() - i - 1; j++)
            {
                if (residents[j].getIncome() < residents[j + 1].getIncome())
                {
                    std::swap(residents[j], residents[j + 1]);
                }
            }
        }
        std::cout << "Residents sorted by income!\n";
    };

    void updateResident()
    {

        std::string name;

        std::cout << "Enter Resident Name to Update: ";

        std::cin >> name;

        for (auto& resident : residents)
            {
            if (resident.getName() == name)
             {
                int choice;

                std::cout << "What do you want to update?\n";
                std::cout << "1. Name\n2. Age\n3. Occupation\n4. Income\n";
                std::cin >> choice;

                switch (choice)
                 {
                    case 1:
                        {
                        std::string newName;

                        std::cout << "Enter New Name: ";

                        std::cin >> newName;
                        resident.setName(newName);
                        break;
                    }
                    case 2:
                        {
                        int newAge;

                        std::cout << "Enter New Age: ";

                        std::cin >> newAge;

                        resident.setAge(newAge);
                        break;
                    }
                    case 3:
                         {
                        std::string newOccupation;

                        std::cout << "Enter New Occupation: ";

                        std::cin >> newOccupation;

                        resident.setOccupation(newOccupation);

                        break;
                    }

                    case 4:
                        {
                        double newIncome;

                        std::cout << "Enter New Income: ";

                        std::cin >> newIncome;

                        resident.setIncome(newIncome);
                        break;
                    }

                    default:
                        std::cout << "Invalid choice!\n";
                }

                std::cout << "Resident updated successfully!\n";
                return;
            }
        }

        std::cout << "Resident not found!\n";
    }

    void calculateTax()
    {

        std::string name;

        std::cout << "Enter Resident Name to Calculate Tax: ";

        std::cin >> name;

        for (auto& resident : residents)
            {
            if (resident.getName() == name)
            {
                double income = resident.getIncome();

                double tax = 0;


                // Simple Tax Slabs
                if (income <= 50000)
                    tax = income * 0.05;

                else if (income <= 100000)
                    tax = income * 0.10;

                else
                    tax = income * 0.20;

                std::cout << "Tax for " << name << ": " << tax << "\n";

                return;
            }
        }

        std::cout << "Resident not found!\n";
    }

    // Zone-related methods
    void addZone()
     {
        std::string zoneName;

        int zoneID;

        std::cout << "Enter Zone Name: ";

        std::cin >> zoneName;

        std::cout << "Enter Zone ID: ";

        std::cin >> zoneID;

        zones.emplace_back(zoneName, zoneID);
        std::cout << "Zone added successfully!\n";
    }

    void assignResidentToZone()
    {
        std::string name;
        int zoneID;

        std::cout << "Enter Resident Name to Assign: ";

        std::cin >> name;

        std::cout << "Enter Zone ID: ";

        std::cin >> zoneID;

        for (auto& resident : residents)
            {
            if (resident.getName() == name)
            {
                for (auto& zone : zones)
                {
                    if (zone.getZoneID() == zoneID)
                     {
                        zone.addResidentToZone(resident);
                        std::cout << "Resident assigned to Zone successfully!\n";
                        return;

                    }
                }

                std::cout << "Zone ID not found!\n";
                return;
            }
        }
        std::cout << "Resident not found!\n";
    }

void searchResidentByAadharID()
{
        std::string aadharID;

        std::cout << "Enter Aadhar ID to Search: ";

        std::cin >> aadharID;

        bool found = false;

        for (auto& resident : residents)
            {
            if (resident.getAadharID() == aadharID)
            {
                std::cout << "Resident found:\n";
                resident.display();
                found = true;
                break;
            }
        }

        if (!found)
            {
            std::cout << "No resident found with Aadhar ID: " << aadharID << "\n";
        }
    }

    void displayZones()
     {
        std::cout << "Zones:\n";
        for (auto& zone : zones)
            {
            zone.displayZoneDetails();
        }
    }

    void calculateTotalPopulation()
     {
        int totalPopulation = 0;

        for (auto& zone : zones)

            {
            totalPopulation += zone.getPopulation();
        }

        std::cout << "Total Population of the City: " << totalPopulation << "\n";
    }
};

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

// Garbage Collection System
class GarbageCollection {
private:
    map<string, int> garbageBins; // Area -> Garbage Amount (kg)
    vector<string> truckRoutes;
    int garbageLevels[5]; // Array for garbage levels in a single area (max 5 bins per area)

public:
    void addGarbageBin(const string &area, int initialGarbage) 
    {
        garbageBins[area] = initialGarbage;
    }

    void updateGarbageLevels(const int levels[], int size)
    {
        for (int i = 0; i < size && i < 5; ++i)
            {
            garbageLevels[i] = levels[i];
        }
        cout << "Garbage levels updated.\n";
    }

    void displayGarbageLevels()
     {
        cout << "Garbage Levels: ";
        for (int i = 0; i < 5; ++i)
            {
            cout << garbageLevels[i] << " ";
        }
        cout << endl;
    }

    void collectGarbage(const string &area)
     {
        if (garbageBins.count(area))
            {
            cout << "Collecting garbage from " << area << ".\n";
            garbageBins[area] = 0;
        }
         else
        {
            cout << "No garbage bin found in " << area << ".\n";
        }
    }

    void optimizeRoute()
     {
        truckRoutes.clear();
        for (const auto &entry : garbageBins)
         {
            if (entry.second > 0)
                {
                truckRoutes.push_back(entry.first);
            }
        }
        cout << "Optimized route: ";
        for (const string &area : truckRoutes)
            {
            cout << area << " -> ";
        }
        cout << "END\n";
    }
};

// Health Care Services
class HealthCare {
private:
    vector<string> hospitals;
    map<string, vector<string>> appointments; // Hospital -> Patients
    string appointmentSlots[7]; // Array for daily appointment slots (max 7 days)

public:
    void addHospital(const string &name)
     {
        hospitals.push_back(name);
    }

    void scheduleAppointment(const string &hospital, const string &patient)
     {
        if (find(hospitals.begin(), hospitals.end(), hospital) != hospitals.end())
            {
            appointments[hospital].push_back(patient);
            cout << "Appointment scheduled for " << patient << " at " << hospital << ".\n";
        }
        else
        {
            cout << "Hospital not found: " << hospital << ".\n";
        }
    }

    void setAppointmentSlots(const string slots[], int size)
     {
        for (int i = 0; i < size && i < 7; ++i)
            {
            appointmentSlots[i] = slots[i];
        }
        cout << "Appointment slots updated.\n";
    }

    void displayAppointments() const
     {
        for (const auto &entry : appointments)
            {
            cout << "Hospital: " << entry.first << endl;
            for (const string &patient : entry.second)
                {
                cout << "  Patient: " << patient << endl;
            }
        }
    }

    void displayAppointmentSlots()
     {
        cout << "Appointment Slots: ";
        for (int i = 0; i < 7; ++i)
            {
            cout << appointmentSlots[i] << " ";
        }
        cout << endl;
    }
};

// Water Management
class WaterManagement {
private:
    int dailyConsumption[7]; // Array for tracking consumption over a week
    int quantity;

public:
    WaterManagement(int qty) : quantity(qty) {}

    void recordDailyConsumption(const int consumption[], int size)
     {
        for (int i = 0; i < size && i < 7; ++i)
            {
            dailyConsumption[i] = consumption[i];
        }
        cout << "Daily consumption recorded.\n";
    }

    void displayWeeklyConsumption()
    {
        cout << "Weekly Water Consumption: ";
        for (int i = 0; i < 7; ++i) {
            cout << dailyConsumption[i] << " ";
        }
        cout << endl;
    }

    void distributeWater(int amount)
     {
        if (amount <= quantity)
            {
            quantity -= amount;
            cout << amount << " units of water distributed.\n";
        } else {
            cout << "Insufficient water resources!\n";
        }
    }

    int getQuantity() const
    {
        return quantity;
    }
};

// Workforce Management
class Workforce {
private:
    map<string, int> workers; // Department -> Worker Count
    int performanceRatings[5]; // Array for performance ratings (max 5 departments)

public:
    void addDepartment(const string &department, int count)
    {
        workers[department] = count;
        cout << "Department added: " << department << " with " << count << " workers.\n";
    }

    void allocateWorkers(const string &department, int count)
     {
        if (workers[department] >= count)
            {
            workers[department] -= count;
            cout << count << " workers allocated to " << department << ".\n";
        }
         else
        {
            cout << "Not enough workers in " << department << ".\n";
        }
    }

    void recordPerformanceRatings(const int ratings[], int size)
     {
        for (int i = 0; i < size && i < 5; ++i)
            {
            performanceRatings[i] = ratings[i];
        }
        cout << "Performance ratings recorded.\n";
    }

    void displayPerformanceRatings()
    {
        cout << "Performance Ratings: ";
        for (int i = 0; i < 5; ++i) {
            cout << performanceRatings[i] << " ";
        }
        cout << endl;
    }

    void display() const
     {
        for (const auto &entry : workers)
            {
            cout << "Department: " << entry.first << ", Workers Available: " << entry.second << endl;
        }
    }
};

// Urban Planning
class UrbanPlanning {
private:
    vector<string> projects;
    string milestones[5]; // Array for project milestones (max 5 projects)

public:
    void addProject(const string &project)
    {
        projects.push_back(project);
    }

    void setMilestones(const string milestoneList[], int size)
    {
        for (int i = 0; i < size && i < 5; ++i)
            {
            milestones[i] = milestoneList[i];
        }
        cout << "Milestones updated.\n";
    }

    void displayMilestones()
    {
        cout << "Project Milestones: ";
        for (int i = 0; i < 5; ++i)
            {
            cout << milestones[i] << " ";
        }
        cout << endl;
    }

    void displayProjects()
     {
        cout << "Urban Development Projects: \n";
        for (const string &project : projects)
            {
            cout << "  - " << project << endl;
        }
    }
};

// Emergency Services Coordination
class EmergencyServices {
private:
    vector<string> services;
    map<string, string> incidents;  // Incident -> Service
    string incidentLog[10];         // Array for tracking incidents (max 10)

public:
    void addService(const string &service)
    {
        services.push_back(service);
    }

    void logIncident(const string &incident, int index)
     {
        if (index >= 0 && index < 10)
            {
            incidentLog[index] = incident;
            cout << "Incident logged: " << incident << endl;
        }
         else
         {
            cout << "Invalid incident log index!\n";
        }
    }

    void displayIncidentLog()
     {
        cout << "Incident Log: \n";
        for (const string &incident : incidentLog)
            {
            if (!incident.empty()) cout << " - " << incident << endl;
        }
    }

    void assignIncident(const string &incident, const string &service)
     {
        if (find(services.begin(), services.end(), service) != services.end())
            {
            incidents[incident] = service;
            cout << "Incident: " << incident << " assigned to " << service << ".\n";
        }
        else
         {
            cout << "Service not available: " << service << ".\n";
        }
    }

    void displayIncidents() const
    {
        for (const auto &entry : incidents)
            {
            cout << "Incident: " << entry.first << " -> Service: " << entry.second << endl;
        }
    }
};

// Security and Surveillance
class SecuritySurveillance {
private:
    map<string, string> cameras; // Location -> Status
    string surveillanceLogs[10]; // Array for surveillance logs (max 10)

public:
    void installCamera(const string &location, const string &status)
     {
        cameras[location] = status;
        cout << "Camera installed at " << location << " with status: " << status << ".\n";
    }

    void logSurveillance(const string &log, int index)
    {
        if (index >= 0 && index < 10)
            {
            surveillanceLogs[index] = log;
            cout << "Surveillance log added: " << log << endl;
        }
        else
         {
            cout << "Invalid log index!\n";
        }
    }

    void displayLogs()
     {
        cout << "Surveillance Logs: \n";
        for (const string &log : surveillanceLogs)
            {
            if (!log.empty()) cout << " - " << log << endl;
        }
    }

    void updateCameraStatus(const string &location, const string &status)
     {
        if (cameras.count(location))
            {
            cameras[location] = status;
            cout << "Updated camera at " << location << " to status: " << status << ".\n";
        } else
        {
            cout << "No camera found at " << location << ".\n";
        }
    }

    void displayCameras() const
     {
        for (const auto &entry : cameras)
            {
            cout << "Location: " << entry.first << " -> Status: " << entry.second << endl;
        }
    }
};

// Real-Time Notifications
class RealTimeNotifications {
private:
    queue<string> notifications;
    string notificationHistory[10]; // Array for past notifications (max 10)

public:
    void addNotification(const string &message)
    {
        notifications.push(message);
        cout << "Notification added: " << message << endl;
    }

    void recordNotification(const string &message, int index)
     {
        if (index >= 0 && index < 10)
            {
            notificationHistory[index] = message;
            cout << "Notification recorded: " << message << endl;
        } else {
            cout << "Invalid index for notification history!\n";
        }
    }

    void displayHistory()
    {
        cout << "Notification History: \n";
        for (const string &notification : notificationHistory)
            {
            if (!notification.empty()) cout << " - " << notification << endl;
        }
    }

    void displayNotifications()
    {
        cout << "Real-Time Notifications:\n";
        while (!notifications.empty())
            {
            cout << notifications.front() << endl;
            notifications.pop();
        }
    }
};

// Class for Energy and Renewable Resources
class EnergyRenewableResources {
private:
    vector<string> energySources;
    int resourceLevels[5]; // Resource levels for 5 energy sources

public:
    void addEnergySource(const string &source, int level)
     {
        if (energySources.size() < 5)
            {
            energySources.push_back(source);
            resourceLevels[energySources.size() - 1] = level;
            cout << "Energy source added: " << source << " with level " << level << "\n";
        }
        else
         {
            cout << "Maximum energy sources reached.\n";
        }
    }

    void displayEnergySources()
    {
        cout << "Energy Sources and Levels:\n";
        for (size_t i = 0; i < energySources.size(); ++i)
            {
            cout << "- " << energySources[i] << ": " << resourceLevels[i] << "\n";
        }
    }
};

// Class for Cultural and Recreational Services
class CulturalRecreationalServices {
private:
    vector<string> events;
    string feedback[5]; // Feedback for 5 events

public:
    void addEvent(const string &event)
     {
        events.push_back(event);
        cout << "Event added: " << event << "\n";
    }

    void recordFeedback(const string &eventFeedback, int index)
     {
        if (index >= 0 && index < 5)
            {
            feedback[index] = eventFeedback;
            cout << "Feedback recorded for event index " << index << ": " << eventFeedback << "\n";
        }
        else
        {
            cout << "Invalid feedback index.\n";
        }
    }

    void displayEvents()
    {
        cout << "Events:\n";
        for (const auto &event : events)
            {
            cout << "- " << event << "\n";
        }
    }

    void displayFeedback() {
        cout << "Feedback for Events:\n";
        for (int i = 0; i < 5; ++i) {
            if (!feedback[i].empty())
                cout << "- Feedback for event " << i + 1 << ": " << feedback[i] << "\n";
        }
    }
};

// Class for Environmental Sustainability
class EnvironmentalSustainability {
private:
    map<string, int> sustainabilityProjects; // Project name -> Progress percentage

public:
    void addProject(const string &project, int progress)
    {
        sustainabilityProjects[project] = progress;
        cout << "Sustainability project added: " << project << " with progress " << progress << "%\n";
    }

    void updateProgress(const string &project, int progress)
    {
        if (sustainabilityProjects.find(project) != sustainabilityProjects.end())
            {
            sustainabilityProjects[project] = progress;
            cout << "Progress updated for project " << project << " to " << progress << "%\n";
        }
        else
         {
            cout << "Project not found.\n";
        }
    }

    void displayProjects() {
        cout << "Sustainability Projects:\n";
        for (const auto &entry : sustainabilityProjects)
            {
            cout << "- " << entry.first << ": " << entry.second << "%\n";
        }
    }
};

// Class for Public Health and Sanitation
class PublicHealthSanitation {
private:
    vector<string> sanitationTasks;

public:
    void addTask(const string &task)
     {
        sanitationTasks.push_back(task);
        cout << "Sanitation task added: " << task << "\n";
    }

    void displayTasks()
     {
        cout << "Sanitation Tasks:\n";
        for (const auto &task : sanitationTasks)
            {
            cout << "- " << task << "\n";
        }
    }
};

// Class for Tourism and Visitor Management
class TourismVisitorManagement
{
private:
    struct Visitor
    {
        string name;
        int age;
        string nationality;
    };

    struct Tour {
        string name;
        string destination;
        vector<Visitor> visitors;
    };

    vector<Tour> tours;

public:
    void addTour(const string &name, const string &destination)
     {
        tours.push_back({name, destination});
        cout << "Tour added: " << name << " to " << destination << "\n";
    }

    void addVisitorToTour(const string &tourName, const string &visitorName, int age, const string &nationality)
     {
        for (auto &tour : tours)
        {
            if (tour.name == tourName)
                {
                tour.visitors.push_back({visitorName, age, nationality});
                cout << "Visitor " << visitorName << " added to tour " << tourName << "\n";
                return;
            }
        }
        cout << "Tour not found.\n";
    }

    void displayTours()
     {
        cout << "Tours:\n";
        for (const auto &tour : tours)
            {
            cout << "- " << tour.name << " to " << tour.destination << "\n";
        }
    }

    void displayVisitorsForTour(const string &tourName)
    {
        for (const auto &tour : tours)
         {
            if (tour.name == tourName)
                {
                cout << "Visitors for " << tourName << ":\n";
                for (const auto &visitor : tour.visitors) {
                    cout << "- " << visitor.name << " (Age: " << visitor.age << ", Nationality: " << visitor.nationality << ")\n";
                }
                return;
            }
        }
        cout << "Tour not found.\n";
    }
};



#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;


struct Route {
    int id;
    string source;
    string destination;
    int duration;
    double cost;
    int distance;
    string type; // "flight", "train", "bus"
};


class TransportNetwork {
private:
    map<string, vector<Route>> routes;
    map<int, Route> routeDetails;
    stack<pair<string, pair<int, int>>> history;
    map<string, set<string>> stationTypes; // Maps locations to available transport types

public:
    void addRoute(int id, const string& source, const string& destination,
                 int duration, double cost, int distance, const string& type)
                  {
        Route route = {id, source, destination, duration, cost, distance, type};
        routes[source].push_back(route);
        routeDetails[id] = route;
        history.push({"addRoute", {id, -1}});
        stationTypes[source].insert(type);
        stationTypes[destination].insert(type);
    }


    void displayRoutes(const string& type = "")
     {
        for (auto& entry : routes)
            {
            cout << "From: " << entry.first << "\n";
            for (auto& route : entry.second)
             {
                if (type.empty() || route.type == type)
                    {
                    cout << "  Route ID: " << route.id
                         << ", Type: " << route.type
                         << ", To: " << route.destination
                         << ", Duration: " << route.duration << " mins"
                         << ", Cost: $" << route.cost;
                    if (route.distance > 0) {
                        cout << ", Distance: " << route.distance << " km";
                    }
                    cout << "\n";
                }
            }
        }
    }


    void bfsTraversal(const string& startLocation, const string& type = "")
     {
        set<string> visited;
        queue<string> q;
        q.push(startLocation);

        cout << "Locations visited in order: ";
        while (!q.empty())
            {
            string current = q.front();
            q.pop();

            if (visited.count(current)) continue;

            cout << current << " ";
            visited.insert(current);

            for (auto& route : routes[current])
                {
                if (type.empty() || route.type == type)
                 {
                    if (!visited.count(route.destination))
                        {
                        q.push(route.destination);
                    }
                }
            }
        }
        cout << endl;
    }


    void dijkstra(const string& startLocation, const string& endLocation,
                 bool useCost = true, const string& type = "")
                  {
        map<string, double> costs;
        map<string, string> previous;
        set<string> processed;

        for (auto& entry : routes)
            {
            costs[entry.first] = INT_MAX;
            previous[entry.first] = "";
        }
        costs[startLocation] = 0;

        priority_queue<pair<double, string>, vector<pair<double, string>>, greater<>> pq;
        pq.push({0, startLocation});

        while (!pq.empty())
            {
            string current = pq.top().second;
            pq.pop();

            if (processed.count(current)) continue;
            processed.insert(current);

            for (auto& route : routes[current])
                {
                if (!type.empty() && route.type != type) continue;

                double newCost = costs[current] + (useCost ? route.cost : route.duration);
                if (newCost < costs[route.destination])
                    {
                    costs[route.destination] = newCost;
                    previous[route.destination] = current;
                    pq.push({newCost, route.destination});
                }
            }
        }

        if (costs[endLocation] == INT_MAX)
            {
            cout << "No route found from " << startLocation << " to " << endLocation << ".\n";
            return;
        }

        cout << (useCost ? "Cheapest" : "Fastest") << " route "
             << (type.empty() ? "" : "(" + type + ") ")
             << "found: Total " << (useCost ? "cost: $" : "duration: ")
             << costs[endLocation] << (useCost ? "" : " mins") << "\nPath: ";

        vector<string> path;
        string current = endLocation;
        while (!current.empty()) {
            path.push_back(current);
            current = previous[current];
        }
        reverse(path.begin(), path.end());
        for (const string& location : path)
            {
            cout << location << " ";
        }
        cout << endl;
    }


    void analyzeNetwork()
     {
        map<string, int> typeCount;
        set<string> locations;

        for (auto& entry : routes)
            {
            locations.insert(entry.first);
            for (auto& route : entry.second)
                {
                typeCount[route.type]++;
                locations.insert(route.destination);
            }
        }

        cout << "\nNetwork Analysis:\n";
        cout << "Total Locations: " << locations.size() << endl;
        cout << "Routes by type:\n";
        for (auto& type : typeCount) {
            cout << "- " << type.first << ": " << type.second << " routes\n";
        }

        cout << "\nMulti-modal stations:\n";
        for (auto& station : stationTypes)
        {
            if (station.second.size() > 1)
                {
                cout << "- " << station.first << ": ";
                for (auto& type : station.second)
                    {
                    cout << type << " ";
                }
                cout << endl;
            }
        }
    }


    void findRoutesWithinTime(const string& startLocation, int timeLimit, const string& type = "")
     {
        cout << "Locations reachable within " << timeLimit << " minutes"
             << (type.empty() ? "" : " by " + type) << " from " << startLocation << ":\n";

        for (auto& route : routes[startLocation])
         {
            if (type.empty() || route.type == type)
                {
                if (route.duration <= timeLimit)
                 {
                    cout << "- " << route.destination
                         << " (" << route.duration << " mins, "
                         << route.type << ")\n";
                }
            }
        }
    }


    void updateRouteCost(int id, double newCost)
    {
    if (routeDetails.find(id) == routeDetails.end())
        {
        cout << "Route ID " << id << " not found.\n";
        return;
    }
    routeDetails[id].cost = newCost;
    for (auto& route : routes[routeDetails[id].source])
        {
        if (route.id == id) {
            route.cost = newCost;
            break;
        }
    }
    history.push({"updateRouteCost", {id, static_cast<int>(newCost)}});
    cout << "Route ID " << id << " cost updated to $" << newCost << ".\n";
}


void removeRoute(int id)
 {
    if (routeDetails.find(id) == routeDetails.end())
        {
        cout << "Route ID " << id << " not found.\n";
        return;
    }
    Route route = routeDetails[id];
    auto& sourceRoutes = routes[route.source];
    sourceRoutes.erase(
        remove_if(sourceRoutes.begin(), sourceRoutes.end(),
                  [id](const Route& r) { return r.id == id; }),
        sourceRoutes.end());
    routeDetails.erase(id);
    history.push({"removeRoute", {id, 0}});
    cout << "Route ID " << id << " removed successfully.\n";
}


void findKNearestLocations(const string& startLocation, int k)
{
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;

    for (auto& route : routes[startLocation])
        {
        pq.push({route.distance, route.destination});
    }

    cout << "The " << k << " nearest locations from " << startLocation << " are:\n";
    for (int i = 0; i < k && !pq.empty(); i++) {
        auto nearest = pq.top();
        pq.pop();
        cout << "- " << nearest.second << " (" << nearest.first << " km)\n";
    }
}


void findLongestRouteChain(const string& startLocation, const string& type = "")
{
    map<string, int> dp;

    // Recursive lambda function for DFS
    auto dfs = [&](const string& current, const auto& dfs_ref) -> int
    {
        if (dp.count(current)) return dp[current];
        int maxLength = 0;
        for (const auto& route : routes[current])
            {
            if (type.empty() || route.type == type)
            {
                maxLength = max(maxLength, 1 + dfs_ref(route.destination, dfs_ref));
            }
        }
        return dp[current] = maxLength;
    };

    int maxLength = dfs(startLocation, dfs);
    cout << "Longest route chain starting from " << startLocation << ": " << maxLength << " stops.\n";
}

void bookTicket(const string& source, const string& destination, const string& type)
{
    for (auto& route : routes[source])
     {
        if (route.destination == destination && (type.empty() || route.type == type))
            {
            cout << "Booking confirmed for Route ID: " << route.id << "\n"
                 << "  From: " << route.source
                 << ", To: " << route.destination
                 << ", Type: " << route.type
                 << ", Cost: $" << route.cost << "\n";
            history.push({"bookTicket", {route.id, -1}});
            return;
        }
    }
    cout << "No available routes from " << source << " to " << destination
         << (type.empty() ? "" : " by " + type) << ".\n";
}

void cancelTicket(int routeId)
 {
    if (routeDetails.find(routeId) == routeDetails.end())
        {
        cout << "Route ID " << routeId << " not found.\n";
        return;
    }
    cout << "Ticket for Route ID " << routeId << " canceled successfully.\n";
    history.push({"cancelTicket", {routeId, -1}});
}
void viewPopularTransportType()
{
    map<string, int> typeUsage;
    for (const auto& entry : routes)
     {
        for (const auto& route : entry.second)
            {
            typeUsage[route.type]++;
        }
    }

    string popularType;
    int maxUsage = 0;
    for (const auto& type : typeUsage)
     {
        if (type.second > maxUsage)
            {
            maxUsage = type.second;
            popularType = type.first;
        }
    }

    cout << "Most popular transport type: " << popularType
         << " with " << maxUsage << " routes.\n";
}



void viewBookedTickets()
{
    if (history.empty())
        {
        cout << "No tickets have been booked.\n";
        return;
    }

    cout << "Booked Tickets:\n";
    stack<pair<string, pair<int, int>>> temp = history;
    while (!temp.empty())
        {
        auto action = temp.top();
        temp.pop();
        if (action.first == "bookTicket") {
            int routeId = action.second.first;
            if (routeDetails.find(routeId) != routeDetails.end())
            {
                const auto& route = routeDetails[routeId];
                cout << "  Route ID: " << route.id
                     << ", From: " << route.source
                     << ", To: " << route.destination
                     << ", Type: " << route.type
                     << ", Cost: $" << route.cost << "\n";
            }
        }
    }
}

void undoLastAction()
 {
        if (history.empty())
            {
            cout << "No actions to undo.\n";
            return;
        }

        auto lastAction = history.top();
        history.pop();

        if (lastAction.first == "addRoute")
            {
            int routeId = lastAction.second.first;
            Route route = routeDetails[routeId];

            auto& sourceRoutes = routes[route.source];
            sourceRoutes.erase(
                remove_if(sourceRoutes.begin(), sourceRoutes.end(),
                    [routeId](const Route& r) { return r.id == routeId; }),
                sourceRoutes.end());

            routeDetails.erase(routeId);
            cout << "Undid addition of route " << routeId << endl;
        }
    }
    void resetNetwork()
    {
        routes.clear();
        routeDetails.clear();
        history = stack<pair<string, pair<int, int>>>(); // Clear history stack
        stationTypes.clear();
        cout << "Network has been reset.\n";
    }

};


void showMenu()
 {
    cout << "\nTransportation Management System\n"
         << "1. Add a new route\n"
         << "2. Display routes\n"
         << "3. Find reachable locations (BFS)\n"
         << "4. Find cheapest route\n"
         << "5. Find fastest route\n"
         << "6. Analyze network\n"
         << "7. Find routes within time limit\n"
         <<"8.Update route cost\n"
         <<"9.Remove a route\n"
         <<"10.Find Nearest Locations\n"
         <<"11.Find the longest route chain\n"
         <<"12.Ticket Booking\n"
         <<"13.Cancel ticket\n"
         <<"14.View Popular Transport Type\n"
         <<"15.View Booked Tickets\n"
         << "17. Undo last action\n"
         <<"16.Reset network\n"
         << "18. Exit\n"
         << "Enter your choice: ";
}


int main() {
    int choice;

    // Main menu with a loop to allow continuous selection
    while(true) {
        cout << "City Management System" << endl;
        cout << "1. Infrastructure" << endl;
        cout << "2. Residents" << endl;
        cout << "3. Services" << endl;
        cout << "4. Transport" << endl;
        cout << "5. Exit" << endl;  // Option to exit the program
        cout << "Enter your choice: ";
        cin >> choice;

        // Switch-case to call the respective function based on user input
        switch(choice) {
            case 1:
                infrastructureFunction();
                break;
            case 2:
                residentsFunction();
                break;
            case 3:
                servicesFunction();
                break;
            case 4:
                transportFunction();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                return 0;  // Exit the program
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}

// Definitions for the functions corresponding to each section

void infrastructureFunction()
{
    cout << "Managing Infrastructure..." << endl;
    {
    CityManagementSystem cms;
    int choice;

    // Set city info
    cms.setCityInfo("Belgaum", "Karnataka", "India", 500.0, 1000000, 5);

    do {
        cout << "\nCity Management System\n";
        cout << "1. City Basic Info\n";
        cout << "2. Infrastructure Management\n";
        cout << "3. Road Management\n";
        cout << "4. Sorting & Algorithms\n";
        cout << "5. Additional Features\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                cms.displayCityInfo();
                break;
            }
            case 2: {
                int infraChoice;
                do {
                    cout << "\n1. Add Infrastructure\n";
                    cout << "2. View Infrastructure\n";
                    cout << "3. Delete Infrastructure\n";
                    cout << "4. Update Infrastructure\n";
                    cout << "5. Find Infrastructure by Type\n";
                    cout << "6. Exit\n";
                    cout << "Enter your choice: ";
                    cin >> infraChoice;

                    switch (infraChoice) {
                        case 1: {
                            string type, name, location,  maintenance, nearest;
                            int year_built, rating;
                            float acres;
                            cout << "Enter Infrastructure Type (e.g., School, Hospital): ";
                            cin >> type;
                            cout << "Enter Name: ";
                            cin >> name;
                            cout << "Enter Location: ";
                            cin >> location;
                            cout << "Enter Year Built: ";
                            cin >> year_built;
                            //cout << "Enter Google Maps Link: ";
                            //cin >> map_link;
                            cout << "Enter Acres: ";
                            cin >> acres;
                            cout << "Enter Rating (1-5): ";
                            cin >> rating;
                            cout << "Enter Maintenance Status: ";
                            cin >> maintenance;
                            cout << "Enter Nearest Place: ";
                            cin >> nearest;

                            cms.addInfrastructure(type, name, location, year_built, acres, rating, maintenance, nearest);
                            break;
                        }
                        case 2:
                             {
                            cms.displayInfrastructures();
                            break;
                        }
                        case 3:
                            {
                            string name;
                            cout << "Enter Infrastructure Name to Delete: ";
                            cin >> name;
                            cms.deleteInfrastructure(name);
                            break;
                        }
                        case 4:
                             {
                            string name;
                            cms.updateInfrastructure(name);
                            break;
                        }
                        case 5:
                            {
                            string type;
                            cout << "Enter Infrastructure Type to Find: ";
                            cin >> type;
                            cms.findInfrastructureByType(type);
                            break;
                        }
                    }
                } while (infraChoice != 6);
                break;
            }
            case 3:
                 {
                int roadChoice;
                do {
                    cout << "\n1. Add Road\n";
                    cout << "2. View Roads\n";
                    cout << "3. Delete Road\n";
                    cout << "4. Update Road\n";
                    cout << "5. Find Road by Condition\n";
                    cout << "6. Search Road by Name\n";
                    cout << "7. Exit\n";
                    cout << "Enter your choice: ";
                    cin >> roadChoice;

                    switch (roadChoice) {
                        case 1:
                             {
                            string name, start, end, condition;
                            float length;
                            cout << "Enter Road Name: ";
                            cin >> name;
                            cout << "Enter Start Location: ";
                            cin >> start;
                            cout << "Enter End Location: ";
                            cin >> end;
                            cout << "Enter Road Length (in km): ";
                            cin >> length;
                            cout << "Enter Road Condition (e.g., Good, Damaged): ";
                            cin >> condition;
                            cms.addRoad(name, start, end, length, condition);
                            break;
                        }
                        case 2:
                            {
                            cms.displayRoads();
                            break;
                        }
                        case 3:
                            {
                            string name;
                            cout << "Enter Road Name to Delete: ";
                            cin >> name;
                            cms.deleteRoad(name);
                            break;
                        }
                        case 4:
                             {
                            string old_name, new_name;
                            cout << "Enter Old Road Name: ";
                            cin >> old_name;
                            cout << "Enter New Road Name: ";
                            cin >> new_name;
                            cms.updateRoad(old_name, new_name);
                            break;
                        }
                        case 5:
                             {
                            string condition;
                            cout << "Enter Road Condition to Find: ";
                            cin >> condition;
                            cms.findRoadByCondition(condition);
                            break;
                        }
                        case 6:
                             {
                            string road_name;
                            cout << "Enter Road Name to Search: ";
                            cin >> road_name;
                            cms.searchRoadByName(road_name);
                            break;
                        }
                    }
                } while (roadChoice != 7);
                break;
            }
            case 4:
                 {
                int algorithmChoice;
                do {
                    cout << "\n1. Sort Infrastructures by Rating\n";
                    cout << "2. Sort Roads by Length\n";
                    cout << "3. Run Dijkstra's Algorithm\n";
                    cout << "4. Exit\n";
                    cout << "Enter your choice: ";
                    cin >> algorithmChoice;

                    switch (algorithmChoice) {
                        case 1:
                            cms.sortInfrastructuresByRating();
                            break;
                        case 2:
                            cms.sortRoadsByLength();
                            break;
                        case 3:
                            cms.dijkstraAlgorithm();
                            break;
                    }
                } while (algorithmChoice != 4);
                break;
            }
            case 5:
                 {
                int featureChoice;
                do {
                    cout << "\n1. Generate Report\n";
                    cout << "2. Display City Ranking\n";
                    cout << "3. Exit\n";
                    cout << "Enter your choice: ";
                    cin >> featureChoice;

                    switch (featureChoice) {
                        case 1:
                            cms.generateReport();
                            break;
                        case 2:
                            cms.cityRanking();
                            break;
                    }
                } while (featureChoice != 3);
                break;
            }
        }
    } while (choice != 6);


}
    // Code related to infrastructure
}

void residentsFunction()
{
    cout << "Managing Residents..." << endl;
    {
    CityManagement city;

    int choice;

    do {

        std::cout << "\n--- City Residential Management System ---\n";

        std::cout << "1. Add Resident\n";

        std::cout << "2. Display All Residents\n";

        std::cout << "3. Search Resident\n";

        std::cout << "4. Sort Residents by Income\n";

        std::cout << "5. search resident by aadharid\n";

        std::cout << "6. Update Resident\n";

        std::cout << "7. Calculate Tax\n";

        std::cout << "8. Add Zone\n";

        std::cout << "9. Assign Resident to Zone\n";

        std::cout << "10. Display Zones\n";

        std::cout << "11. Calculate Total Population\n";

        std::cout << "12. Exit\n";

        std::cout << "Enter your choice: ";

        std::cin >> choice;


        switch (choice) {

            case 1:
                city.addResident();
                break;

            case 2:
                city.displayAllResidents();
                break;

            case 3:
                city.searchResident();
                break;

            case 4:
                city.sortResidentsByIncome();
                break;

            case 5:
                city.searchResidentByAadharID();
                break;

            case 6:
                city.updateResident();
                break;

            case 7:
                city.calculateTax();
                break;

            case 8:
                city.addZone();
                break;

            case 9:
                city.assignResidentToZone();
                break;

            case 10:
                city.displayZones();
                break;

            case 11:
                city.calculateTotalPopulation();
                break;

            case 12:
                std::cout << "Exiting system. Goodbye!\n";
                break;

            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    }

    while (choice != 11);
}

    // Code related to residents
}

void servicesFunction()
{
    cout << "Managing Services..." << endl;
    {
    GarbageCollection garbageSystem;
    HealthCare healthSystem;
    WaterManagement waterSystem(10000);
    Workforce workforceSystem;
    UrbanPlanning urbanSystem;
    EmergencyServices emergencySystem;
    SecuritySurveillance securitySystem;
    RealTimeNotifications notificationSystem;
    EnergyRenewableResources energySystem;
    CulturalRecreationalServices culturalSystem;
    EnvironmentalSustainability sustainabilitySystem;
    PublicHealthSanitation sanitationSystem;
    TourismVisitorManagement tourismSystem;

    int mainChoice;

    do {
        cout << "\n--- City Management System ---\n";
        cout << "1. Garbage Collection\n";
        cout << "2. Health Care\n";
        cout << "3. Water Management\n";
        cout << "4. Workforce Management\n";
        cout << "5. Urban Planning\n";
        cout << "6. Emergency Services\n";
        cout << "7. Security and Surveillance\n";
        cout << "8. Real-Time Notifications\n";
        cout << "9. Energy and Renewable Resources\n";
        cout << "10. Cultural and Recreational Services\n";
        cout << "11. Environmental Sustainability\n";
        cout << "12. Public Health and Sanitation\n";
        cout << "13. Tourism and Visitor Management\n";
        cout << "14. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;


        switch (mainChoice)
         {
        case 1:
            {
            int subChoice;
            cout << "\n--- Garbage Collection ---\n";
            cout << "1. Update Garbage Levels\n";
            cout << "2. Display Garbage Levels\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1)
                {
                int levels[5];
                cout << "Enter garbage levels for 5 bins: ";
                for (int i = 0; i < 5; ++i) cin >> levels[i];
                garbageSystem.updateGarbageLevels(levels, 5);
            }
            else if (subChoice == 2)
             {
                garbageSystem.displayGarbageLevels();
            }
            else
             {
                cout << "Invalid choice.\n";
            }
            break;
        }
        case 2:
             {
            int subChoice;
            cout << "\n--- Health Care ---\n";
            cout << "1. Set Appointment Slots\n";
            cout << "2. Display Appointment Slots\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1) {
                string slots[7];
                cout << "Enter appointment slots for 7 days: ";
                for (int i = 0; i < 7; ++i) cin >> slots[i];
                healthSystem.setAppointmentSlots(slots, 7);
            }
            else if (subChoice == 2)
            {
                healthSystem.displayAppointmentSlots();
            }
            else
             {
                cout << "Invalid choice.\n";
            }
            break;
        }
        case 3:
            {
            int subChoice;
            cout << "\n--- Water Management ---\n";
            cout << "1. Record Weekly Consumption\n";
            cout << "2. Display Weekly Consumption\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1)
                {
                int consumption[7];
                cout << "Enter daily water consumption for 7 days: ";
                for (int i = 0; i < 7; ++i) cin >> consumption[i];
                waterSystem.recordDailyConsumption(consumption, 7);
            }
             else if (subChoice == 2)
             {
                waterSystem.displayWeeklyConsumption();
            }
            else
             {
                cout << "Invalid choice.\n";
            }
            break;
        }
        case 4:
            {
            int subChoice;
            cout << "\n--- Workforce Management ---\n";
            cout << "1. Record Performance Ratings\n";
            cout << "2. Display Performance Ratings\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1)
                {
                int ratings[5];
                cout << "Enter performance ratings for 5 departments: ";
                for (int i = 0; i < 5; ++i) cin >> ratings[i];
                workforceSystem.recordPerformanceRatings(ratings, 5);
            }
             else if (subChoice == 2)
             {
                workforceSystem.displayPerformanceRatings();
            }
             else
                {
                cout << "Invalid choice.\n";
            }
            break;
        }
        case 5:
             {
            int subChoice;
            cout << "\n--- Urban Planning ---\n";
            cout << "1. Set Project Milestones\n";
            cout << "2. Display Project Milestones\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1)
                {
                string milestones[5];
                cout << "Enter milestones for 5 projects: ";
                for (int i = 0; i < 5; ++i) cin >> milestones[i];
                urbanSystem.setMilestones(milestones, 5);
            }
             else if (subChoice == 2)
             {
                urbanSystem.displayMilestones();
            }
            else
             {
                cout << "Invalid choice.\n";
            }
            break;
        }
        case 6: {
            int subChoice;
            cout << "\n--- Emergency Services ---\n";
            cout << "1. Log Incident\n";
            cout << "2. Display Incident Log\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1)
                {
                string incident;
                int index;
                cout << "Enter incident description: ";
                cin.ignore();
                getline(cin, incident);
                cout << "Enter index (0-9): ";
                cin >> index;
                emergencySystem.logIncident(incident, index);
            }
            else if (subChoice == 2)
             {
                emergencySystem.displayIncidentLog();
            }
            else
             {
                cout << "Invalid choice.\n";
            }
            break;
        }
        case 7:
             {
            int subChoice;
            cout << "\n--- Security and Surveillance ---\n";
            cout << "1. Log Surveillance Activity\n";
            cout << "2. Display Surveillance Logs\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1)
                {
                string log;
                int index;
                cout << "Enter surveillance activity: ";
                cin.ignore();
                getline(cin, log);
                cout << "Enter index (0-9): ";
                cin >> index;
                securitySystem.logSurveillance(log, index);
            } else if (subChoice == 2) {
                securitySystem.displayLogs();
            } else {
                cout << "Invalid choice.\n";
            }
            break;
        }
        case 8:
            {
            int subChoice;
            cout << "\n--- Real-Time Notifications ---\n";
            cout << "1. Record Notification\n";
            cout << "2. Display Notification History\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1)
                {
                string message;
                int index;
                cout << "Enter notification message: ";
                cin.ignore();
                getline(cin, message);
                cout << "Enter index (0-9): ";
                cin >> index;
                notificationSystem.recordNotification(message, index);
            } else if (subChoice == 2) {
                notificationSystem.displayHistory();
            } else
             {
                cout << "Invalid choice.\n";
            }
            break;
        }
        case 9:
            {
            int subChoice;
            cout << "\n--- Energy and Renewable Resources ---\n";
            cout << "1. Add Energy Source\n";
            cout << "2. Display Energy Sources\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1)
                {
                string source;
                int level;
                cout << "Enter energy source: ";
                cin >> source;
                cout << "Enter resource level: ";
                cin >> level;
                energySystem.addEnergySource(source, level);
            }
            else if (subChoice == 2)
                {
                energySystem.displayEnergySources();
            }
             else
             {
                cout << "Invalid choice.\n";
            }
            break;
        }
        case 10:
             {
            int subChoice;
            cout << "\n--- Cultural and Recreational Services ---\n";
            cout << "1. Add Event\n";
            cout << "2. Record Feedback\n";
            cout << "3. Display Events\n";
            cout << "4. Display Feedback\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1)
                {
                string event;
                cout << "Enter event name: ";
                cin.ignore();
                getline(cin, event);
                culturalSystem.addEvent(event);
            }
            else if (subChoice == 2)
             {
                string feedback;
                int index;
                cout << "Enter feedback: ";
                cin.ignore();
                getline(cin, feedback);
                cout << "Enter event index (0-4): ";
                cin >> index;
                culturalSystem.recordFeedback(feedback, index);
            }
             else if (subChoice == 3)
             {
                culturalSystem.displayEvents();
            }
             else if (subChoice == 4) {
                culturalSystem.displayFeedback();
            }
            else
             {
                cout << "Invalid choice.\n";
            }
            break;
        }
        case 11:
            {
            int subChoice;
            cout << "\n--- Environmental Sustainability ---\n";
            cout << "1. Add Project\n";
            cout << "2. Update Progress\n";
            cout << "3. Display Projects\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1)
                {
                string project;
                int progress;
                cout << "Enter project name: ";
                cin.ignore();
                getline(cin, project);
                cout << "Enter progress percentage: ";
                cin >> progress;
                sustainabilitySystem.addProject(project, progress);
            }
            else if (subChoice == 2)
             {
                string project;
                int progress;
                cout << "Enter project name: ";
                cin.ignore();
                getline(cin, project);
                cout << "Enter new progress percentage: ";
                cin >> progress;
                sustainabilitySystem.updateProgress(project, progress);
            }
             else if (subChoice == 3)
                {
                sustainabilitySystem.displayProjects();
            }
            else
             {
                cout << "Invalid choice.\n";
            }
            break;
        }
        case 12: {
            int subChoice;
            cout << "\n--- Public Health and Sanitation ---\n";
            cout << "1. Add Task\n";
            cout << "2. Display Tasks\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1)
                {
                string task;
                cout << "Enter sanitation task: ";
                cin.ignore();
                getline(cin, task);
                sanitationSystem.addTask(task);
            }
            else if (subChoice == 2)
             {
                sanitationSystem.displayTasks();
            }
            else
            {
                cout << "Invalid choice.\n";
            }
            break;
        }
        case 13:
            {
            int subChoice;
            cout << "\n--- Tourism and Visitor Management ---\n";
            cout << "1. Add Tour\n";
            cout << "2. Add Visitor to Tour\n";
            cout << "3. Display Tours\n";
            cout << "4. Display Visitors for a Tour\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1)
                {
                string name, destination;
                cout << "Enter tour name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter destination: ";
                getline(cin, destination);
                tourismSystem.addTour(name, destination);
            }
             else if (subChoice == 2)
                {
                string tourName, visitorName, nationality;
                int age;
                cout << "Enter tour name: ";
                cin.ignore();
                getline(cin, tourName);
                cout << "Enter visitor name: ";
                getline(cin, visitorName);
                cout << "Enter age: ";
                cin >> age;
                cin.ignore();
                cout << "Enter nationality: ";
                getline(cin, nationality);
                tourismSystem.addVisitorToTour(tourName, visitorName, age, nationality);
            } else if (subChoice == 3)
            {
                tourismSystem.displayTours();
            } else if (subChoice == 4)
            {
                string tourName;
                cout << "Enter tour name: ";
                cin.ignore();
                getline(cin, tourName);
                tourismSystem.displayVisitorsForTour(tourName);
            } else {
                cout << "Invalid choice.\n";
            }
            break;
        }
        case 14:
            cout << "Exiting the system...\n";
            break;


        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (mainChoice != 14);


}

    // Code related to services
}

void transportFunction() {
    cout << "Managing Transport..." << endl;
    {
    TransportNetwork network;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, duration, distance;
                double cost;
                string source, destination, type;
                cout << "Enter route ID: ";
                cin >> id;
                cout << "Enter source location: ";
                cin >> source;
                cout << "Enter destination location: ";
                cin >> destination;
                cout << "Enter duration (mins): ";
                cin >> duration;
                cout << "Enter cost: ";
                cin >> cost;
                cout << "Enter distance (km): ";
                cin >> distance;
                cout << "Enter type (flight/train/bus): ";
                cin >> type;
                network.addRoute(id, source, destination, duration, cost, distance, type);
                break;
            }

            case 2: {
                string type;
                cout << "Enter type to filter (or empty for all): ";
                cin.ignore();
                getline(cin, type);
                network.displayRoutes(type);
                break;
            }

            case 3: {
                string start, type;
                cout << "Enter starting location: ";
                cin >> start;
                cout << "Enter type to filter (or empty for all): ";
                cin.ignore();
                getline(cin, type);
                network.bfsTraversal(start, type);
                break;
            }

            case 4: {
                string start, end, type;
                cout << "Enter starting location: ";
                cin >> start;
                cout << "Enter destination location: ";
                cin >> end;
                cout << "Enter type to filter (or empty for all): ";
                cin.ignore();
                getline(cin, type);
                network.dijkstra(start, end, true, type);
                break;
            }

            case 5: {
                string start, end, type;
                cout << "Enter starting location: ";
                cin >> start;
                cout << "Enter destination location: ";
                cin >> end;
                cout << "Enter type to filter (or empty for all): ";
                cin.ignore();
                getline(cin, type);
                network.dijkstra(start, end, false, type);
                break;
            }

            case 6:
                network.analyzeNetwork();
                break;

            case 7: {
                string start, type;
                int timeLimit;
                cout << "Enter starting location: ";
                cin >> start;
                cout << "Enter time limit (mins): ";
                cin >> timeLimit;
                cout << "Enter type to filter (or empty for all): ";
                cin.ignore();
                getline(cin, type);
                network.findRoutesWithinTime(start, timeLimit, type);
                break;
            }

            case 8: {
            int id;
            double newCost;
            cout << "Enter route ID to update cost: ";
            cin >> id;
            cout << "Enter new cost: ";
            cin >> newCost;
            network.updateRouteCost(id, newCost);
            break;
            }

        case 9: {
            int id;
            cout << "Enter route ID to remove: ";
            cin >> id;
            network.removeRoute(id);
            break;
            }

        case 10: {
            string start;
            int k;
            cout << "Enter starting location: ";
            cin >> start;
            cout << "Enter the number of nearest locations to find: ";
            cin >> k;
            network.findKNearestLocations(start, k);
            break;
            }

            case 11:  {  // This case is for finding the longest route chain
            string startLocation, type;
            cout << "Enter starting location: ";
            cin >> startLocation;
            cout << "Enter type to filter (or press Enter for all): ";
            cin.ignore(); // To clear any leftover newline character from previous input
            getline(cin, type);

            // Call the function to find the longest route chain
            network.findLongestRouteChain(startLocation, type);
            break;
            }
            case 12: {
            string source, destination, type;
            cout << "Enter source location: ";
            cin >> source;
            cout << "Enter destination location: ";
            cin >> destination;
            cout << "Enter transport type (or press Enter for any): ";
            cin.ignore();
            getline(cin, type);

            network.bookTicket(source, destination, type);
            break;
            }
            case 13: {
            int routeId;
            cout << "Enter the Route ID for the ticket to cancel: ";
            cin >> routeId;

            network.cancelTicket(routeId);
            break;
            }
        case 14: {
        network.viewPopularTransportType();
        break;
        }

            case 15: {  // View booked tickets
            network.viewBookedTickets();
            break;
            }

            case 16: { // Reset network
            char confirm;
            cout << "Are you sure you want to reset the entire network? This action cannot be undone. (y/n): ";
            cin >> confirm;
            if (tolower(confirm) == 'y') {
            network.resetNetwork();
            } else {
            cout << "Reset operation canceled.\n";
            }
            break;
            }

            case 17:
                network.undoLastAction();
                break;
            case 18:
                cout << "Thank you for using the system. Goodbye!\n";

            default:
                cout << "Invalid option. Please choose a valid number.\n";

        }
    }
}

    // Code related to transport
}
