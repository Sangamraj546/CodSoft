#include <iostream>
#include <vector>

class Seat {
public:
    Seat() : isBooked(false) {}

    bool isBooked;
};

class Theater {
public:
    Theater(int numRows, int numCols) : numRows(numRows), numCols(numCols) {
        seats.resize(numRows, std::vector<Seat>(numCols));
    }

    bool bookSeat(int row, int col) {
        if (row < 1 || row > numRows || col < 1 || col > numCols) {
            std::cout << "Invalid row or column. Please try again." << std::endl;
            return false;
        }

        if (seats[row - 1][col - 1].isBooked) {
            std::cout << "Seat is already booked. Please choose another seat." << std::endl;
            return false;
        }

        seats[row - 1][col - 1].isBooked = true;
        std::cout << "Seat booked successfully!" << std::endl;
        return true;
    }

    double calculateTotalCost() const {
        double totalCost = 0.0;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (seats[i][j].isBooked) {
                    totalCost += TICKET_PRICE;
                }
            }
        }
        return totalCost;
    }

    void displaySeatingChart() const {
        std::cout << "Seating Chart:" << std::endl;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                char status = seats[i][j].isBooked ? 'X' : '-';
                std::cout << status << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    const double TICKET_PRICE = 10.0;
    int numRows;
    int numCols;
    std::vector<std::vector<Seat>> seats;
};

int main() {
    int numRows = 5;
    int numCols = 10;
    Theater theater(numRows, numCols);

    while (true) {
        theater.displaySeatingChart();

        // User menu
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Book a seat" << std::endl;
        std::cout << "2. Calculate total cost" << std::endl;
        std::cout << "3. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int row, col;
            std::cout << "Enter row and column (e.g., 1 2) to book a seat: ";
            std::cin >> row >> col;
            theater.bookSeat(row, col);
        } else if (choice == 2) {
            double totalCost = theater.calculateTotalCost();
            std::cout << "Total cost for booked seats: $" << totalCost << std::endl;
        } else if (choice == 3) {
            std::cout << "Thank you for using the booking system. Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    }

    return 0;
}
