#ifndef __DEFICITSCHEDULER_SERVER_H_
#define __DEFICITSCHEDULER_SERVER_H_

#include <omnetpp.h>

using namespace omnetpp;

struct info_holder {
    simtime_t arrival_instant;
    simtime_t service_time;
};

class Server : public cSimpleModule {
    private:
        bool constant;
        simsignal_t delay_signal;
        std::vector<info_holder> queue;
        simtime_t deficit;
        simtime_t Q;
        simtime_t vacation_period;
        cMessage *end_of_vacation;
        cMessage *end_of_service;
        //bool working;
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        virtual void startService();
        virtual void startVacation();
        virtual void getResponseTime();
};

#endif
