package deficitscheduler;

simple Server
{
    parameters:
        bool constant;
        double vacation_time @unit(s) = default(0ms);
        double turn_time @unit(s) = default(0ms);
        @signal[delay];
        @statistic[response_time](source="delay"; record=vector, mean;);
    gates:
        input in;
}
