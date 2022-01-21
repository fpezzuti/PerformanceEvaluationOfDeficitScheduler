#include "Emitter.h"
#include "Job_m.h"

Define_Module(Emitter);

void Emitter::initialize()
{
    constant = par("constant");
    if (constant) {
        arrival_time = par("interarrival_time");
        service_time = par("requested_service_time");
    }
    else {
        simtime_t mean_arrival_time = par("interarrival_time");
        simtime_t mean_service_time = par("requested_service_time");
        arrival_time = exponential(mean_arrival_time, 0);
        service_time = exponential(mean_service_time, 1);
    }
    Job *job_to_send = new Job("job_to_send");
    job_to_send->setService_time(service_time.str().c_str());
    scheduleAt(simTime() + arrival_time, job_to_send);
}

void Emitter::handleMessage(cMessage *msg){
    if(msg->isSelfMessage()) {
        send(msg, "out");
        //crea nuovo messaggio
        Job *job_to_send = new Job("job_to_send");

        if(!constant){
            simtime_t mean_arrival_time = par("interarrival_time");
            simtime_t mean_service_time = par("requested_service_time");
            arrival_time = exponential(mean_arrival_time, 0);
            service_time = exponential(mean_service_time, 1);
        }
        job_to_send->setService_time(service_time.str().c_str());

        scheduleAt(simTime() + arrival_time, job_to_send);
    }

}
