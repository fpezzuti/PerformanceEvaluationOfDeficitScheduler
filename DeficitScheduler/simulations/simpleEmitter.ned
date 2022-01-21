package deficitscheduler.simulations;

import deficitscheduler.Emitter;
import deficitscheduler.Server;

network simpleEmitter
{
    @display("bgb=327,154");
    submodules:

        emitter: Emitter {
            constant = false;
        }
        server: Server {
            constant = false;
            turn_time = emitter.requested_service_time;
        }
    connections:
        emitter.out --> server.in;
}

