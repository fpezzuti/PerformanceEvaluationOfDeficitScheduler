#include "Ricevitore.h"
#include "Job_m.h"

using namespace std;

Define_Module(Ricevitore);

void Ricevitore::initialize()
{
    EV << "CIAO" << endl;
}

void Ricevitore::handleMessage(cMessage *msg)
{
    Job *roba = check_and_cast<Job*>(msg);
    EV << roba->getName() << endl;
    std::vector<simtime_t> prova;
    prova.push_back(SimTime::parse(roba->getService_time()));
    EV << "PROVA: " << prova[0] << endl;
    delete(msg);
}
