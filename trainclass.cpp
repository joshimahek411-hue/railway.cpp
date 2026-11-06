#include <iostream>
#include <cstring>
using namespace std;

class Train
{
private:

    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:

    Train()
    {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
    }

    Train(int no, char name[], char src[], char dest[], char time[])
    {
        trainNumber = no;

        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);

        trainCount++;
    }

    ~Train()
    {
        if (trainNumber != 0)
        {
            trainCount--;
        }
    }

    void setTrainNumber(int no)
    {
        trainNumber = no;
    }

    void setTrainName(char name[])
    {
        strcpy(trainName, name);
    }

    void setSource(char src[])
    {
        strcpy(source, src);
    }

    void setDestination(char dest[])
    {
        strcpy(destination, dest);
    }

    void setTrainTime(char time[])
    {
        strcpy(trainTime, time);
    }

    int getTrainNumber()
    {
        return trainNumber;
    }

    char* getTrainName()
    {
        return trainName;
    }

    char* getSource()
    {
        return source;
    }

    char* getDestination()
    {
        return destination;
    }

    char* getTrainTime()
    {
        return trainTime;
    }

    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;

        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);

        trainCount++;
    }

    void displayTrainDetails()
    {
        cout << "\nTrain Number: " << trainNumber;
        cout << "\nTrain Name: " << trainName;
        cout << "\nSource: " << source;
        cout << "\nDestination: " << destination;
        cout << "\nTrain Time: " << trainTime;
        cout << "\n";
    }

    static int getTrainCount()
    {
        return trainCount;
    }
};

int Train::trainCount = 0;

class RailwaySystem
{
private:

    Train trains[100];
    int totalTrains;

public:

   
    RailwaySystem()
    {
        totalTrains = 0;
    }

    
    void addTrain()
    {
        if (totalTrains < 100)
        {
            trains[totalTrains].inputTrainDetails();

            totalTrains++;

            cout << "\nTrain Added Successfully!\n";
        }
        else
        {
            cout << "\nTrain List is Full!\n";
        }
    }

    
    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "\nNo Train Records Found!\n";
        }
        else
        {
            for (int i = 0; i < totalTrains; i++)
            {
                cout << "\nTrain " << i + 1 << " Details:";
                trains[i].displayTrainDetails();
            }
        }
    }

    
    void searchTrainByNumber(int number)
    {
        int found = 0;

        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "\nTrain Found!";
                trains[i].displayTrainDetails();

                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            cout << "\nTrain with number "
                 << number << " not found!\n";
        }
    }
};



int main()
{
    RailwaySystem railway;

    int choice;
    int number;

    do
    {
        cout << "\n\n--- Railway Reservation System ---\n";

        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:

                railway.addTrain();

                break;

            case 2:

                railway.displayAllTrains();

                break;

            case 3:

                cout << "\nEnter Train Number to search: ";
                cin >> number;

                railway.searchTrainByNumber(number);

                break;

            case 4:

                cout << "\nExiting the system. Goodbye!\n";

                break;

            default:

                cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while (choice != 4);

    return 0;
}