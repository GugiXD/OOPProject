#pragma once

class Ticket {
protected:
    int row = 0;
    int place = 0;

public:

    virtual void printInfo() = 0;
    Ticket() {}

};

