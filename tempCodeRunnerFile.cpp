#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a class for a hotel room
class Room {
public:
    int roomNumber;
    bool isOccupied;
    string guestName;

    Room(int number) : roomNumber(number), isOccupied(false), guestName("") {}

    void bookRoom(string name) {
        isOccupied = true;
        guestName = name;
        cout << "Room " << roomNumber << " booked by " << guestName << endl;
    }

    void checkOut() {
        isOccupied = false;
        guestName = "";
        cout << "Guest checked out from Room " << roomNumber << endl;
    }

    void displayRoomInfo() {
        cout << "Room Number: " << roomNumber << endl;
        cout << "Occupied: " << (isOccupied ? "Yes" : "No") << endl;
        if (isOccupied)
            cout << "Guest Name: " << guestName << endl;
    }
};

// Function to display the main menu
void displayMenu() {
    cout << "Hotel Management System" << endl;
    cout << "1. Display Room Information" << endl;
    cout << "2. Book a Room" << endl;
    cout << "3. Check Out" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    vector<Room> rooms;

    // Initialize rooms
    for (int i = 1; i <= 10; i++) {
        rooms.push_back(Room(i));
    }

    int choice;
    int roomNumber;  // Moved these variable declarations outside the switch statement
    string guestName;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Room Information:" << endl;
                for (const Room& room : rooms) {
                    room.displayRoomInfo();
                }
                break;
            case 2:
                cout << "Enter Room Number to book: ";
                cin >> roomNumber;
                if (roomNumber >= 1 && roomNumber <= 10) {
                    cout << "Enter Guest Name: ";
                    cin >> guestName;
                    rooms[roomNumber - 1].bookRoom(guestName);
                } else {
                    cout << "Invalid room number!" << endl;
                }
                break;
            case 3:
                cout << "Enter Room Number to check out: ";
                cin >> roomNumber;
                if (roomNumber >= 1 && roomNumber <= 10) {
                    rooms[roomNumber - 1].checkOut();
                } else {
                    cout << "Invalid room number!" << endl;
                }
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}