#include <iostream>
#include <vector>


class CeilingFan
{
public:
    const static int HIGH = 3;
    const static int MEDIUM = 2;
    const static int LOW = 1;
    const static int OFF = 0;
    int speed;
    CeilingFan() {
        speed = OFF;
    }
    void high() {
        speed = HIGH;
        std::cout << "ceiling fan is on high\n";
    }
    void medium() {
        speed = MEDIUM;
        std::cout << "ceiling fan is on medium\n";
    }
    void low() {
        speed = LOW;
        std::cout << "ceiling fan is on low\n";
    }
    void off() {
        speed = OFF;
        std::cout << "ceiling fan is off\n";
    }
    int getSpeed() {
        return speed;
    }
};

class Command
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};


class noCommand : public Command
{
public:
    void execute() {};
    void undo() {};
};

class CeilingFanHighCommand : public Command
{
public:
    CeilingFan* ceilingFan;
    int prevSpeed;

    CeilingFanHighCommand(CeilingFan* _ceilingFan) {
        this -> ceilingFan = _ceilingFan;
    }
    void execute() {
        prevSpeed = ceilingFan -> getSpeed();
        ceilingFan -> high();
    }
    void undo() {
        if (prevSpeed == CeilingFan::HIGH) {
            ceilingFan -> high();
        }
        else if (prevSpeed == CeilingFan::MEDIUM) {
            ceilingFan -> medium();
        }
        else if (prevSpeed == CeilingFan::LOW) {
            ceilingFan -> low();
        }
        else if (prevSpeed == CeilingFan::OFF) {
            ceilingFan -> off();
        }
    }
};

class CeilingFanMediumCommand : public Command
{
public:
    CeilingFan* ceilingFan;
    int prevSpeed;

    CeilingFanMediumCommand(CeilingFan* _ceilingFan) {
        this -> ceilingFan = _ceilingFan;
    }
    void execute() {
        prevSpeed = ceilingFan -> getSpeed();
        ceilingFan -> medium();
    }
    void undo() {
        if (prevSpeed == CeilingFan::HIGH) {
            ceilingFan -> high();
        }
        else if (prevSpeed == CeilingFan::MEDIUM) {
            ceilingFan -> medium();
        }
        else if (prevSpeed == CeilingFan::LOW) {
            ceilingFan -> low();
        }
        else if (prevSpeed == CeilingFan::OFF) {
            ceilingFan -> off();
        }
    }
};

class CeilingFanLowCommand : public Command
{
public:
    CeilingFan* ceilingFan;
    int prevSpeed;

    CeilingFanLowCommand(CeilingFan* _ceilingFan) {
        this -> ceilingFan = _ceilingFan;
    }
    void execute() {
        prevSpeed = ceilingFan -> getSpeed();
        ceilingFan -> low();
    }
    void undo() {
        if (prevSpeed == CeilingFan::HIGH) {
            ceilingFan -> high();
        }
        else if (prevSpeed == CeilingFan::MEDIUM) {
            ceilingFan -> medium();
        }
        else if (prevSpeed == CeilingFan::LOW) {
            ceilingFan -> low();
        }
        else if (prevSpeed == CeilingFan::OFF) {
            ceilingFan -> off();
        }
    }
};

class CeilingFanOffCommand : public Command
{
public:
    CeilingFan* ceilingFan;
    int prevSpeed;

    CeilingFanOffCommand(CeilingFan* _ceilingFan) {
        this -> ceilingFan = _ceilingFan;
    }
    void execute() {
        prevSpeed = ceilingFan -> getSpeed();
        ceilingFan -> off();
    }
    void undo() {
        if (prevSpeed == CeilingFan::HIGH) {
            ceilingFan -> high();
        }
        else if (prevSpeed == CeilingFan::MEDIUM) {
            ceilingFan -> medium();
        }
        else if (prevSpeed == CeilingFan::LOW) {
            ceilingFan -> low();
        }
        else if (prevSpeed == CeilingFan::OFF) {
            ceilingFan -> off();
        }
    }
};

class RemoteControlWithUndo
{
public:
    std::vector<Command*> onCommands;
    std::vector<Command*> offCommands;
    Command* undoCommand;
    RemoteControlWithUndo() {
        noCommand* nocommand = new noCommand;
        for (int i = 0; i < 7; i++) {
            onCommands.push_back(nocommand);
            offCommands.push_back(nocommand);
        }
        undoCommand = nocommand;
    }
    void setCommand(int slot, Command* onCommand, Command* offCommand) {
        onCommands[slot] = onCommand;
        offCommands[slot] = offCommand;
    }
    void onButtonWasPushed(int slot) {
        onCommands[slot] -> execute();
        undoCommand = onCommands[slot];
    }
    void offButtonWasPushed(int slot) {
        offCommands[slot] -> execute();
        undoCommand = offCommands[slot];
    }
    void undoButtonWasPushed() {
        undoCommand -> undo();
    }
};


int main()
{
    RemoteControlWithUndo* remoteControl = new RemoteControlWithUndo; 

    CeilingFan* ceilingFan = new CeilingFan;
    CeilingFanMediumCommand* ceilingFanMedium = new CeilingFanMediumCommand(ceilingFan);
    CeilingFanHighCommand* ceilingFanHigh = new CeilingFanHighCommand(ceilingFan);
    CeilingFanLowCommand* ceilingFanLow = new CeilingFanLowCommand(ceilingFan);
    CeilingFanOffCommand* ceilingFanOff = new CeilingFanOffCommand(ceilingFan);


    remoteControl -> setCommand(0, ceilingFanMedium, ceilingFanOff);
    remoteControl -> setCommand(1, ceilingFanHigh, ceilingFanLow);

    remoteControl -> onButtonWasPushed(0);
    remoteControl -> offButtonWasPushed(0);
    remoteControl -> undoButtonWasPushed();
    remoteControl -> onButtonWasPushed(1);
    remoteControl -> undoButtonWasPushed();
}
