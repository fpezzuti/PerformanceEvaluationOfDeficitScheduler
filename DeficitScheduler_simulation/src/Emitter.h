#ifndef __DEFICITSCHEDULER_EMITTER_H_
#define __DEFICITSCHEDULER_EMITTER_H_

#include <omnetpp.h>

using namespace omnetpp;

class Emitter : public cSimpleModule
{
    private:
        bool constant;
        simtime_t arrival_time;
        simtime_t service_time;
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *job);
};

#endif
