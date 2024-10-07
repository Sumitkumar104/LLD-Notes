#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Elevator
{
    enum Direction
    {
        UP,
        DOWN
    };

    vector<int> requests;
    int minFloor;
    int maxFloor;
    int currentFloor;
    int currentCapacity;
    int maxCapacity;
    Direction direction;

    void handleInitialRequests();
    void handleAdditionalRequests();
    bool isValidRequest(int floor) const;
    void updateDirection();
    void processRequests();
    void displayElevatorStatus() const;
    void removeCompletedRequests(int floor);
     
    public:
    Elevator(int minFloor, int maxFloor, int maxCapacity)
        : minFloor(minFloor), maxFloor(maxFloor), maxCapacity(maxCapacity), currentFloor(0), currentCapacity(0), direction(UP) {}

    ~Elevator() = default;

    void start();
};



// Adds the initial set of requests from users
void Elevator::handleInitialRequests()
{
     int numRequests;
    int destinationFloor;

     cout << "Enter number of requests: ";
     cin >> numRequests;

     cout << "Enter destination floor(s): ";
    for ( int i = 0; i < numRequests; ++i)
    {
         cin >> destinationFloor;
        if (isValidRequest(destinationFloor))
        {
            requests.emplace_back(destinationFloor);
            currentCapacity++;
        }

        if (currentCapacity == maxCapacity)
        {
             cout << "Elevator is full! No more requests can be accepted.\n";
            break;
        }
    }

    updateDirection();
}

// Adds additional requests during the elevator trip
void Elevator::handleAdditionalRequests()
{
     int numRequests;
    int destinationFloor;

     cout << "Enter number of additional requests: ";
     cin >> numRequests;

     cout << "Enter destination floor(s): ";
    for ( int i = 0; i < numRequests; ++i)
    {
         cin >> destinationFloor;
        if (isValidRequest(destinationFloor))
        {
            requests.emplace_back(destinationFloor);
            currentCapacity++;
        }

        if (currentCapacity == maxCapacity)
        {
             cout << "Elevator is full! No more requests can be accepted.\n";
            break;
        }
    }
}

// Validates if the request is allowed based on current direction and capacity
bool Elevator::isValidRequest(int floor) const
{
    if (currentCapacity >= maxCapacity)
    {
         cout << "Elevator is full!\n";
        return false;
    }
    if (direction == UP && floor < currentFloor)
    {
         cout << "Elevator is going UP. Invalid request.\n";
        return false;
    }
    if (direction == DOWN && floor > currentFloor)
    {
         cout << "Elevator is going DOWN. Invalid request.\n";
        return false;
    }
    if (floor > maxFloor || floor < minFloor)
    {
         cout << "Invalid floor number.\n";
        return false;
    }

    return true;
}

// Updates the direction of the elevator based on the first request
void Elevator::updateDirection()
{
    if (!requests.empty())
    {
        if (requests.front() > currentFloor)
        {
            direction = UP;
        }
        else if (requests.front() < currentFloor)
        {
            direction = DOWN;
        }
    }
}

// Processes the requests one by one
void Elevator::processRequests()
{
     sort(requests.begin(), requests.end());

    while (!requests.empty())
    {
        // Move the elevator to the next floor
        if (direction == UP)
        {
            currentFloor = *requests.begin();
        }
        else
        {
            currentFloor = *requests.rbegin();
        }

        displayElevatorStatus();

        // Remove requests for the current floor
        removeCompletedRequests(currentFloor);

        if (currentFloor == maxFloor)
        {
            direction = DOWN;
        }
        else if (currentFloor == minFloor)
        {
            direction = UP;
        }

        if (currentCapacity == 0)
        {
            handleInitialRequests();
        }
        else
        {
            handleAdditionalRequests();
        }

         sort(requests.begin(), requests.end());
    }
}

// Displays the current status of the elevator
void Elevator::displayElevatorStatus() const
{
     string dir = (direction == UP) ? "UP" : "DOWN";

     cout << "\n=======================================================\n";
     cout << "Current floor: " << currentFloor << "\n";
     cout << "Current capacity: " << currentCapacity << "/" << maxCapacity << "\n";
     cout << "Direction: " << dir << "\n";
     cout << "Min floor: " << minFloor << " | Max floor: " << maxFloor << "\n";
     cout << "=======================================================\n";
}

// Removes the requests corresponding to the current floor
void Elevator::removeCompletedRequests(int floor)
{
    requests.erase( remove(requests.begin(), requests.end(), floor), requests.end());
    currentCapacity--;
}

// Starts the elevator operation
void Elevator::start()
{
     cout << "Starting the elevator...\n";
    handleInitialRequests();
    processRequests();
}



int main()
{
    int minFloor, maxFloor;
     int maxCapacity;

     cout << "Enter minimum and maximum floor numbers: ";
     cin >> minFloor >> maxFloor;

     cout << "Enter elevator maximum capacity: ";
     cin >> maxCapacity;

    Elevator elevator(minFloor, maxFloor, maxCapacity);
    elevator.start();

    return 0;
}
