

#include "Vehicle.h"

int main()
{
    Vehicle* vPtr[] = { new Car(125.368,"BMW"), new MotorCycle(46.879,"Kawasagi") };
    int which_vehicle;
    char inputVehicle;

    do {
        fflush(stdin);
        cout << "Enter vehicle and input:" << endl;
        cin >> which_vehicle >> inputVehicle;

        switch (inputVehicle) {
        case 'S':
            vPtr[which_vehicle]->startEngine();
            vPtr[which_vehicle]->displayInformation();
            break;

        case'C':
            vPtr[which_vehicle]->stopEngine();
            vPtr[which_vehicle]->displayInformation();
            break;

        case 'U':
            vPtr[which_vehicle]->increaseSpeed();
            vPtr[which_vehicle]->displayInformation();
            break;

        case 'D':
            vPtr[which_vehicle]->decreaseSpeed();
            vPtr[which_vehicle]->displayInformation();
        }

    } while (which_vehicle != -1);
}
