#include<iostream>
#include"Carbon_footprint_calculation.h"

using namespace std;

class Household
{

private:
    int members;
    int LPG;
    int Electricity;
    int Trash;

public:

    //SETTING VALUES

    void setMembers()
    {
        cout << "Enter number of family members: ";
        cin >> members;
    }
    void setLpg()
    {
        cout << "Enter amount of LPG used PER MONTH in SCM (Standard Cubic Meters): ";
        cin >> LPG;
    }
    void setElectricity()
    {
        cout << "Enter amount of Electricity consumed PER MONTH in Units: ";
        cin >> Electricity;
    }
    void setTrash()
    {
        cout << "Enter amount of Trash thrown out DAILY in kg: ";
        cin >> Trash;
    }

    //DISPLAYING VALUES

    void displayMembers()
    {
        cout << "Number of Family Members: " << members << endl;
    }
    int getMembers()
    {
        return members;
    }
    void displayLpg()
    {
        cout << "Amount of LPG consumed in a Month in SCM: " << LPG << endl;
    }
    void displayElectricity()
    {
        cout << "Amount of Electricity consumed in a Month in Units: " << Electricity << endl;
    }
    void displayTrash()
    {
        cout << "Amount of Trash thrown out in a Day in Kg: " << Trash << endl;
    }

    //CALCULATING CARBON FOOTPRINT FOR HOUSEHOLD
    double getCo2Lpg()
    {
        return (lpg(LPG));
    }
    double getCo2Electricity()
    {
        return electricity(Electricity);
    }
    double getCo2Trash()
    {
        return trash(Trash);
    }
    double getHousehold()
    {
        return ((lpg(LPG)+electricity(Electricity)+trash(Trash))/4.0);
    }
    // double co2lpg;
    // co2lpg = lpg(LPG);

};
class Personal
{
private:
    char name[20];
    int vehicle;
    int Bus;
    int Train;
    int Plane;
    int Hotel;
public:

    //SETTING VALUES

    void setName()
    {
        cout << "Enter your name: ";
        cin >> name;
    }
    void setVehicle()
    {
        cout << "Enter distance travelled in Private Vehicle MONTHLY in km: ";
        cin >> vehicle;
    }
    void setBus()
    {
        cout << "Enter distance travelled in Bus MONTHLY in km: ";
        cin >> Bus;
    }
    void setTrain()
    {
        cout << "Enter distance travelled in Train MONTHLY in km: ";
        cin >> Train;
    }
    void setPlane()
    {
        cout << "Enter distance travelled in Plane ANNUALLY in km: ";
        cin >> Plane;
    }
    void setHotel()
    {
        cout << "Enter number of nights stayed in hotel Annually: ";
        cin >> Hotel;
    }

    //DISPLAYING VALUES

    void displayName()
    {
        cout << "Entered Name is: " << name << endl;
    }
    void displayVehicle()
    {
        cout << "Distance Travelled by Personal Vehicle Monthly is: " << vehicle << endl;
    }
    void displayBus()
    {
        cout << "Distance Travelled by Bus Monthly is: " << Bus << endl;
    }
    void displayTrain()
    {
        cout << "Distance Travelled by Train Monthly is: " << Train << endl;
    }
    void displayPlane()
    {
        cout << "Distance Travelled by Plane Monthly is: " << Plane << endl;
    }
    void displayHotel()
    {
        cout << "Nights stayed in Hotel Annually: " << Hotel << endl;
    }

    //CALCULATING PERSONAL CARBON FOOTPRINT

    double getCo2Vehicle()
    {
        return privateVehicle(vehicle);
    }
    double getCo2Bus()
    {
        return bus(Bus);
    }
    double getCo2Train()
    {
        return train(Train);
    }
    double getCo2Plane()
    {
        return plane(Plane);
    }
    double getCo2Hotel()
    {
        return hotel(Hotel);
    }
    double getPersonal()
    {
        return (privateVehicle(vehicle) + bus(Bus) + train(Train) + plane(Plane) + hotel(Hotel));
    }

};
class Total
{
public:
    double getTotal(Household H, Personal P)
    {
        return ( double(H.getHousehold()) + double(P.getPersonal()) );
    }
};
int main()
{
    Household H;
    Personal P;
    Total T;
    cout<< "WELCOME TO OUR CARBON FOOTPRINT CALCULATOR" <<endl;
    P.setName();

    cout<< "WELCOME! " << endl;

    cout << "\n\nLet's start with Household Emissions\n\n" << endl;

    H.setMembers();
    H.setElectricity();
    H.setLpg();
    H.setTrash();

    cout << "\n\nNow heading to Travel Emissions\n\n" << endl;

    P.setVehicle();
    P.setBus();
    P.setTrain();
    P.setPlane();
    P.setHotel();

    cout << "\n\nYour Entered Details are\n\n" << endl;

    P.displayName();
    H.displayMembers();
    H.displayElectricity();
    H.displayLpg();
    H.displayTrash();
    P.displayVehicle();
    P.displayBus();
    P.displayTrain();
    P.displayPlane();
    P.displayHotel();

    cout << "\n\nYour CO2 Emissions for Individual Factors are\n\n" << endl;

    cout << "For Electricity: " << H.getCo2Electricity()/double(H.getMembers()) << " kg/yr" << endl;
    cout << "For LPG: " << H.getCo2Lpg()/double(H.getMembers()) << " kg/yr" << endl;
    cout << "For Trash: " << H.getCo2Trash()/double(H.getMembers()) << " kg/yr" << endl;
    cout << "For Personal Vehicle: " << P.getCo2Vehicle() << " kg/yr" << endl;
    cout << "For Bus: " << P.getCo2Bus() << " kg/yr" << endl;
    cout << "For Train: " << P.getCo2Train() << " kg/yr" << endl;
    cout << "For Plane: " << P.getCo2Plane() << " kg/yr" << endl;
    cout << "For Hotel: " << P.getCo2Hotel() << " kg/yr" << endl;

    cout << "\n\nFinally...\n\n" << endl;
    cout << "Total Carbon Footprint is: " << T.getTotal(H, P)/1000.0 << " Tons of CO2" << endl;

    return 0;
   /* int live;
    cout<<"I live in\n1.Detached single family home\n2.Attached single family home\n3.Apartment Building(2 to 4 units)\n4.Apartment Building (5+ units)\n5.Mobile home"<<endl;
    cin>>live;


    int size_house;
    cout<<"Enter the size of housing\n1.Under 500 sq ft\n2.500-900\n3.1,000-1,499\n4.1,500-1,999\n5.2000-2,499\n6.2500-2999\n7.3000-3,999\n8.Over 4000"<<endl;
    cin>>size_house;



    int solar;
    cout<<"Do you purchase clean energy such as wind or solar\n1.Yes,some\n2.Yes,most\n3.Yes,all\n4.No\n5.I don't know"<<endl;
    cin>>solar;

    int recycle;
    cout<<"Do recycle items such as metal,plastic,glass or plates?\n1. YES\n2. No"<<endl;
    cin>>recycle;

    int diet;
    cout<<"My diet is mostly\n1.Meat lover\n2. Average omnivore\n3.No beef\n4. Vegetarian\n5. Vegan"<<endl;
    cin>>diet;

    int decide;
    cout<<"Do you make a conscious effort to save energy?\n1.I have a programmable thermostat\n2.I use ENERGY STAR appliances\n3. I use energy efficient lightbulbs\n4.I line dry my laundry"<<endl;
    cin>>decide;

    int travel;
    cout<<"Select the way you frequently get around\n1.Intercity/Commuter Rail\n2.Bus/Subway/Metro\n3.Car\n4.Walk/Bike"<<endl;
    cin>>travel;

    int no_rlt;
    cout<<"Number of long round flight trips(2500+ miles).I make in a year\n1.0\n2.1\n3. 2\n4. 4\n5. 5-9\n6. 10-14\n7.15-19\n8.20+"<<endl;
    cin>>no_rlt;

    int no_rmt;
    cout<<"Number of medium round-trip flights (300-2500 miles one way) I make in a year\n1.0\n2.1\n3. 2\n4. 4\n5. 5-9\n6. 10-14\n7.15-19\n8.20+"<<endl;
    cin>>no_rmt;

    int no_rst;
    cout<<"Number of short round-trip flights (<300 miles one way) I make in a year\n1.0\n2.1\n3. 2\n4. 4\n5. 5-9\n6. 10-14\n7.15-19\n8.20+"<<endl;
    cin>>no_rst;

    int hotel;
    cout<<"Average number of nights spent in a hotel per year\n1.0\n2.1-2 Nights\n3. 3-4 Nights\n4. 5-6 Nights\n5.  1-2 Weeks\n6. 3-4 Weeks\n7.1-2 Months"<<endl;
    cin>>hotel;




     int total;
        total=no_m+live+size_house+solar+recycle+diet+decide+travel+no_rlt+no_rmt+no_rst+hotel;
        cout<<"TOTAL= "<<total<<" Tons"<<endl;

    */
}