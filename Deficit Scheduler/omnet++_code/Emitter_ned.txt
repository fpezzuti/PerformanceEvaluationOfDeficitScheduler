package deficitscheduler;

simple Emitter {
    
    parameters:
        bool constant;
    	double interarrival_time @unit(s) = default(10ms);
    	double requested_service_time @unit(s) = default(2ms);
   	gates:
   	    output out;
    	
}
