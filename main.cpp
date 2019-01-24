//
// Disk Simulator Project.
// Project 2
// Created By Spencer Greco
//
#include <iostream>
#include <fstream>
#include "Request.hpp"
#include "FCFS/FCFSQueue.hpp"
#include "SameTrack/SameTrackQueue.hpp"
#include "PickUp/PickUpQueue.hpp"
#include "LookUp/LookUpQueue.hpp"
#include "CLookUp/CLookUpQueue.hpp"
#include "EventQueue.hpp"
#include "Disk.hpp"
#include "Queue.hpp"
#include "DiskDoneEvent.hpp"
#include <vector>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
    // These are all of the Output Files that output will be written to.
    fstream FCFSFile;
    FCFSFile.open("FCFS_TextFile.txt", ios::out);
    FCFSFile << "track" << setw(10)<< "sector" << setw(10) << "Entr"<< setw(10)<<"InIt" << setw(10) << "Comp"<< setw(10) << "Wait" << setw(10)<< "Serv" << setw(10) << "TimInSys" <<endl;
    FCFSFile.close();

    fstream STRACKFile;
    STRACKFile.open("STRACK_TextFile.txt", ios::out);
    STRACKFile << "track" << setw(10) << "sector" << setw(10) << "Entr" << setw(10) << "InIt" << setw(10) << "Comp" << setw(10)<< "Wait" << setw(10)<< "Serv" << setw(10) << "TimInSys" <<endl;
    STRACKFile.close();

    fstream PICKUPFile;
    PICKUPFile.open("PICKUP_TextFile.txt", ios::out);
    PICKUPFile << "track" << setw(10) << "sector" << setw(10) << "Entr"<<  setw(10) <<"InIt" << setw(10) << "Comp" << setw(10)<< "Wait" << setw(10)<< "Serv" << setw(10)<< "TimInSys" <<endl;
    PICKUPFile.close();

    fstream LOOKFile;
    LOOKFile.open("LOOK_TextFile.txt", fstream::out);
    LOOKFile << "track" << setw(10) << "sector" << setw(10) << "Entr"<< setw(10) << "InIt" << setw(10) << "Comp" << setw(10) << "Wait" << setw(10) << "Serv" << setw(10)<< "TimInSys" <<endl;
    LOOKFile.close();

    fstream CLOOKFile;
    CLOOKFile.open("CLOOK_TextFile.txt", fstream::out);
    CLOOKFile << "track" << setw(10) << "sector" << setw(10) << "Entr" << setw(10) << "InIt" << setw(10) << "Comp" << setw(10) << "Wait" << setw(10) << "Serv" << setw(10)<< "TimInSys" <<endl;
    CLOOKFile.close();

    fstream TimerReport;
    TimerReport.open("TimerReport.txt", ios::out);
    TimerReport << "Time" << setw(10) << "FCFS" << setw(10) << "SAME TRACK" << setw(10) <<"PICKUP" << setw(10) << "C-LOOKUP"<< setw(10)<<"LOOKUP" << endl;
    TimerReport.close();

    fstream SummaryReport;
    SummaryReport.open("SummaryReport.txt", ios::out);
    SummaryReport << "Name" << setw(15) << "TimeInSystem" << setw(15) << "WaitTime"<< setw(15) << "ServiceTime" << setw(15) << "NumINQueue" << endl;
    SummaryReport << setw(10) << "Min" << setw(10) << "Max" << setw(10) << "Avg" << setw(10) << "Min" << setw(10) << "Max" << setw(10) << "Avg" << setw(10) << "Min" << setw(10) <<
    "Max" << setw(10) << "Avg" << setw(10)<< "Max" << setw(10) << "Avg" << endl;
    SummaryReport.close();



// These are all of the variables I used to calculate The summary Output, Timer event, and DiskDone Requests.
// In this code you will see a lot of 1, 2, 3, 4, and 5 next to variables.
// The purpose for these is to keep track of all of the queuetypes.
// 1 corresponds to  FCFS Queue.
// 2 corresponds to Same Track Queue.
// 3 corresponds to Pick-Up Queue.
// 4 corresponds to Look up Queue.
// 5 corresponds to C-Look up Queue.
// This may sound silly but I found it to be a less confusing manor then naming each one each time.
// Especially because of the summary output which holds a ton of variables with the queue names.
// So if you see these numbers next to variables this is what they mean.


    // These Variables hold the running total for queues.
    double Comp1 = 0;
    double Comp2 = 0;
    double Comp3 = 0;
    double Comp4 = 0;
    double Comp5 = 0;

    //This Variable holds the time at which the timer event will execute.
    double timerEvent = 50;

    // These Variables are what calculate the queue lengths on execuation of a timer event.
    // They get incremented each time a request takes place and decremented each time a Disk Done event executes.
    int TimerEvent1 = 0;
    int TimerEvent2 = 0;
    int TimerEvent3 = 0;
    int TimerEvent4 = 0;
    int TimerEvent5 = 0;

    // All of these variables hold the data for the Summary. There is 55 of them one for each data point in
    // the summary output file.
    float FCFSAVG = 0, FCFSMAX = 0;
    float STRACKAVG = 0, STRACKMAX = 0;
    float PICKUPAVG = 0, PICKUPMAX = 0;
    float LOOKAVG = 0, LOOKMAX = 0;
    float CLOOKAVG = 0, CLOOKMAX = 0;
    float FCFSminTIS = 0, FCFSmaxTIS = 0, FCFSavgTIS=0;
    float STRACKminTIS = 0, STRACKmaxTIS = 0, STRACKavgTIS=0;
    float PICKUPminTIS = 0, PICKUPmaxTIS = 0, PICKUPavgTIS=0;
    float LOOKUPminTIS = 0, LOOKUPmaxTIS = 0, LOOKUPavgTIS=0;
    float CLOOKUPminTIS = 0, CLOOKUPmaxTIS = 0, CLOOKUPavgTIS=0;
    float FCFSminWT = 0, FCFSmaxWT = 0, FCFSavgWT=0;
    float STRACKminWT = 0, STRACKmaxWT = 0, STRACKavgWT=0;
    float PICKUPminWT = 0, PICKUPmaxWT = 0, PICKUPavgWT=0;
    float LOOKUPminWT = 0, LOOKUPmaxWT = 0, LOOKUPavgWT=0;
    float CLOOKUPminWT = 0, CLOOKUPmaxWT = 0, CLOOKUPavgWT=0;
    float FCFSminST = 0, FCFSmaxST = 0, FCFSavgST=0;
    float STRACKminST = 0, STRACKmaxST = 0, STRACKavgST=0;
    float PICKUPminST = 0, PICKUPmaxST = 0, PICKUPavgST=0;
    float LOOKUPminST = 0, LOOKUPmaxST = 0, LOOKUPavgST=0;
    float CLOOKUPminST = 0, CLOOKUPmaxST = 0, CLOOKUPavgST=0;

    // This variable calculate the amount of iterations the TimerEvent happens.
    // It is needed to calculate the averages for Timer Event.
    int iterations = 0;

    // This variable calculate the amount of request events put into the event queue.
    // It is needed to calculate the averages for Summary OutPut.
    int iterations2 = 0;

    // This variable counts the running total of requests.
    int totalEvents = 0;

    // This variable counts the running total of Disk Done Events.
    // When totalEvents == totalEvetnsCompleted all requests have been comppleted.
    int totalEventsCompleted = 0;
        if( argc != 2) {
        std::cout << "usage: " << argv[0] << " nameOfAnInputFile\n";
        exit(1);
    }

    std::ifstream inputStream;

    inputStream.open(argv[1], std::ios::in);
    if( ! inputStream.is_open()) {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        perror("Error when attempting to open the input file.");
        exit(1);
    }

    vector <Queue *> queues;

  // My queues and Disks
    FCFSQueue *fcfsQueue = new FCFSQueue();
    SameTrackQueue *sameTrackQueue = new SameTrackQueue();
    PickUpQueue *pickUpQueue = new PickUpQueue();
    LookUpQueue *lookUpQueue = new LookUpQueue();
    CLookUpQueue *cLookUpQueue = new CLookUpQueue();
    Disk fcfsDisk;
    Disk sameTrackDisk;
    Disk pickUpDisk;
    Disk lookUpDisk;
    Disk  cLookUpDisk;


    EventQueue eventQueue;
    float time;
    int track, sector;
    while(inputStream >> time && inputStream >> track && inputStream >> sector) {
        Request *request = new Request(time/10 , track, sector);
        eventQueue.addRequest(request,0);
        fcfsQueue->addRequest(request);
        sameTrackQueue->addRequest(request);
        pickUpQueue->addRequest(request);
        lookUpQueue->addRequest(request);
        cLookUpQueue->addRequest(request);
        iterations2++;
    }

    Request *timerRequest = new Request(timerEvent);
    eventQueue.addRequest(timerRequest, 6);


    while( ! eventQueue.isEmpty() ) {

        Request *TopOfeventQueue;
        TopOfeventQueue = eventQueue.getRequest();
        // My decrements of TimerEvents
        if(TopOfeventQueue->isDDevent()){
            // Find which type of request is which.
           if(TopOfeventQueue->isFCFS()) {
               TimerEvent1--;
               totalEventsCompleted++;
           }
           else if(TopOfeventQueue->isStrack()) {
               TimerEvent2--;
               totalEventsCompleted++;
           }
           else if(TopOfeventQueue->isPickUp()) {
               TimerEvent3--;
               totalEventsCompleted++;
           }
           else if(TopOfeventQueue->isLookUp()) {
               TimerEvent4--;
               totalEventsCompleted++;
           }
           else if(TopOfeventQueue->isCLookUp()) {
               TimerEvent5--;
               totalEventsCompleted++;
           }
            delete TopOfeventQueue;
        }



        else if (TopOfeventQueue->isRequest()) {

            //FCFS queue proccess and Calcualtions.
            Request *request1 = fcfsQueue->getRequest();
            DiskDoneEvent *diskDoneEvent1 = new DiskDoneEvent(request1->time(), request1->track(), request1->sector());
            float accessTime1 = fcfsDisk.getAccessTime(diskDoneEvent1->track(), diskDoneEvent1->sector(),
                                                       diskDoneEvent1->time());
            diskDoneEvent1->saveTime();
            diskDoneEvent1->setTime(accessTime1);
            diskDoneEvent1->calculations(Comp1);
            Comp1 = (diskDoneEvent1->getIniT() + diskDoneEvent1->getServ());
            diskDoneEvent1->print(1);


            // Calculations for summary.

            float a1 = diskDoneEvent1->getTimeInSys();
            float b1 = diskDoneEvent1->getWaitTime();
            float c1 = diskDoneEvent1->getServ();

            if (FCFSminTIS > a1)
                FCFSminTIS = a1;

            if(FCFSminTIS == 0)
                FCFSminTIS = a1;

            if (FCFSmaxTIS < a1)
                FCFSmaxTIS = a1;
            FCFSavgTIS += a1;

            if (FCFSminWT > b1)
                FCFSminWT = b1;

            if (FCFSmaxWT < b1)
                FCFSmaxWT = b1;
            FCFSavgWT += b1;

            if (FCFSminST > c1)
                FCFSminST = c1;

            if(FCFSminST == 0)
                FCFSminST = c1;

            if (FCFSmaxST < c1)
                FCFSmaxST = c1;
            FCFSavgST += c1;



            //FCFS DDone Event
            Request *DDrequest1 = new Request(diskDoneEvent1->getComp());
            DDrequest1->setDDevent(true);
            eventQueue.addRequest(DDrequest1,1);
            TimerEvent1++;
            if (TimerEvent1 > FCFSMAX)
                FCFSMAX = TimerEvent1;
            totalEvents++;


            // The proccess is repeaeted below for each queue.

            //SameTrack
            Request *request2 = sameTrackQueue->getRequest();
            DiskDoneEvent *diskDoneEvent2 = new DiskDoneEvent(request2->time(), request2->track(), request2->sector());
            float accessTime2 = sameTrackDisk.getAccessTime(diskDoneEvent2->track(), diskDoneEvent2->sector(),
                                                            diskDoneEvent2->time());
            diskDoneEvent2->saveTime();
            diskDoneEvent2->setTime(accessTime2);
            diskDoneEvent2->calculations(Comp2);
            Comp2 = (diskDoneEvent2->getIniT() + diskDoneEvent2->getServ());
            diskDoneEvent2->print(2);


            float a2 = diskDoneEvent2->getTimeInSys();
            float b2 = diskDoneEvent2->getWaitTime();
            float c2 = diskDoneEvent2->getServ();

            if (STRACKminTIS > a2)
                STRACKminTIS = a2;

            if(STRACKminTIS == 0)
                STRACKminTIS = a2;

            if (STRACKmaxTIS < a2)
                STRACKmaxTIS = a2;
            STRACKavgTIS +=a2;

            if (STRACKminWT > b2)
                STRACKminWT = b2;

            if (STRACKmaxWT < b2)
                STRACKmaxWT = b2;
            STRACKavgWT +=b2;

            if (STRACKminST > c2)
                STRACKminST = c2;

            if(STRACKminST == 0)
                STRACKminST = c2;

            if (STRACKmaxST < c2)
                STRACKmaxST = c2;
            STRACKavgST +=c2;


            //SameTrack DDone Event
            Request *DDrequest2 = new Request(diskDoneEvent2->getComp());
            DDrequest2->setDDevent(true);
            eventQueue.addRequest(DDrequest2,2);
            TimerEvent2++;
            if (TimerEvent2 > STRACKMAX)
                STRACKMAX = TimerEvent2;
            totalEvents++;



            //PickUP
            Request *request3 = pickUpQueue->getRequest();
            DiskDoneEvent *diskDoneEvent3 = new DiskDoneEvent(request3->time(), request3->track(), request3->sector());
            float accessTime3 = pickUpDisk.getAccessTime(diskDoneEvent3->track(), diskDoneEvent3->sector(),
                                                         diskDoneEvent3->time());
            diskDoneEvent3->saveTime();
            diskDoneEvent3->setTime(accessTime3);
            diskDoneEvent3->calculations(Comp3);
            Comp3 = (diskDoneEvent3->getIniT() + diskDoneEvent3->getServ());
            diskDoneEvent3->print(3);

            float a3 = diskDoneEvent3->getTimeInSys();
            float b3 = diskDoneEvent3->getWaitTime();
            float c3 = diskDoneEvent3->getServ();

            if (PICKUPminTIS > a3)
                PICKUPminTIS = a3;

            if(PICKUPminTIS == 0)
                PICKUPminTIS = a3;

            if (PICKUPmaxTIS < a3)
                PICKUPmaxTIS = a3;
            PICKUPavgTIS +=a3;

            if (PICKUPminWT > b3)
                PICKUPminWT = b3;

            if (PICKUPmaxWT < b3)
                PICKUPmaxWT = b3;
            PICKUPavgWT +=b3;

            if (PICKUPminST > c3)
                PICKUPminST = c3;

            if(PICKUPminST == 0)
                PICKUPminST = c3;

            if (PICKUPmaxST < c3)
                PICKUPmaxST = c3;
            PICKUPavgST +=c3;



            //PickUP DDone Event
            Request *DDrequest3 = new Request(diskDoneEvent3->getComp());
            DDrequest3->setDDevent(true);
            eventQueue.addRequest(DDrequest3,3);
            TimerEvent3++;
            if (TimerEvent3 > PICKUPMAX)
                PICKUPMAX = TimerEvent3;
            totalEvents++;



            //LookUp
            Request *request4 = lookUpQueue->getRequest();
            DiskDoneEvent *diskDoneEvent4 = new DiskDoneEvent(request4->time(), request4->track(), request4->sector());
            float accessTime4 = lookUpDisk.getAccessTime(diskDoneEvent4->track(), diskDoneEvent4->sector(),
                                                         diskDoneEvent4->time());
            diskDoneEvent4->saveTime();
            diskDoneEvent4->setTime(accessTime4);
            diskDoneEvent4->calculations(Comp4);
            Comp4 = (diskDoneEvent4->getIniT() + diskDoneEvent4->getServ());
            diskDoneEvent4->print(4);

            float a4 = diskDoneEvent4->getTimeInSys();
            float b4 = diskDoneEvent4->getWaitTime();
            float c4 = diskDoneEvent4->getServ();

            if (LOOKUPminTIS > a4)
                LOOKUPminTIS = a4;

            if(LOOKUPminTIS == 0)
                LOOKUPminTIS = a4;

            if (LOOKUPmaxTIS < a4)
                LOOKUPmaxTIS = a4;
            LOOKUPavgTIS +=a4;

            if (LOOKUPminWT > b4)
                LOOKUPminWT = b4;

            if (LOOKUPmaxWT < b4)
                LOOKUPmaxWT = b4;
            LOOKUPavgWT +=b4;


            if (LOOKUPminST > c4)
                LOOKUPminST = c4;

            if(LOOKUPminST == 0)
                LOOKUPminST = c4;

            if (LOOKUPmaxST < c4)
                LOOKUPmaxST = c4;
            LOOKUPavgST +=c4;


            //LookUp DDone Event
            Request *DDrequest4 = new Request(diskDoneEvent4->getComp());
            DDrequest4->setDDevent(true);
            eventQueue.addRequest(DDrequest4,4);
            TimerEvent4++;
            if (TimerEvent4 > LOOKMAX)
                LOOKMAX = TimerEvent4;
            totalEvents++;




            //CLookUp
            Request *request5 = cLookUpQueue->getRequest();
            DiskDoneEvent *diskDoneEvent5 = new DiskDoneEvent(request5->time(), request5->track(), request5->sector());
            float accessTime5 = cLookUpDisk.getAccessTime(diskDoneEvent5->track(), diskDoneEvent5->sector(),
                                                          diskDoneEvent5->time());
            diskDoneEvent5->saveTime();
            diskDoneEvent5->setTime(accessTime5);
            diskDoneEvent5->calculations(Comp5);
            Comp5 = (diskDoneEvent5->getIniT() + diskDoneEvent5->getServ());
            diskDoneEvent5->print(5);

            float a5 = diskDoneEvent5->getTimeInSys();
            float b5 = diskDoneEvent5->getWaitTime();
            float c5 = diskDoneEvent5->getServ();

            if (CLOOKUPminTIS > a5)
                CLOOKUPminTIS = a5;

            if(CLOOKUPminTIS == 0)
                CLOOKUPminTIS = a5;

            if (CLOOKUPmaxTIS < a5)
                CLOOKUPmaxTIS = a5;
            CLOOKUPavgTIS +=a5;


            if (CLOOKUPminWT > b5)
                CLOOKUPminWT = b5;


            if (CLOOKUPmaxWT < b5)
                CLOOKUPmaxWT = b5;
            CLOOKUPavgWT +=b5;

            if (CLOOKUPminST > c5)
                CLOOKUPminST = c5;

            if(CLOOKUPminST == 0)
                CLOOKUPminST = c5;

            if (CLOOKUPmaxST < c5)
                CLOOKUPmaxST = c5;
            CLOOKUPavgST +=c5;

            //CLookUp DDone Event
            Request *DDrequest5 = new Request(diskDoneEvent5->getComp());
            DDrequest5->setDDevent(true);
            eventQueue.addRequest(DDrequest5,5);
            TimerEvent5++;
            if (TimerEvent5 > CLOOKMAX)
                CLOOKMAX = TimerEvent5;
            totalEvents++;

        }

        else if (totalEvents == totalEventsCompleted){
            delete TopOfeventQueue;
        }

        else if (TopOfeventQueue->issTimerEvent()){

            fstream FCFSFile;
            FCFSFile.open("TimerReport.txt", ios::app);
            FCFSFile << timerEvent << setw(10)<< TimerEvent1 << setw(10) << TimerEvent2 << setw(10) << TimerEvent3 << setw(10)<< TimerEvent5 << setw(10)<< TimerEvent4 <<endl;
            FCFSFile.close();
            // More averages for Summary output
            timerEvent += 50;
            Request *timerRequest1 = new Request(timerEvent);
            eventQueue.addRequest(timerRequest1, 6);
            FCFSAVG += TimerEvent1;
            STRACKAVG += TimerEvent2;
            PICKUPAVG += TimerEvent3;
            LOOKAVG += TimerEvent4;
            CLOOKAVG +=TimerEvent5;
            iterations++;
            delete TopOfeventQueue;
        }

    }

    //Summary Output File prints statments.
    SummaryReport.open("SummaryReport.txt", ios::app);
    SummaryReport << "FCFS   "<<FCFSminTIS << setw(10) <<FCFSmaxTIS << setw(10) << FCFSavgTIS/iterations2 <<  setw(10) <<
             FCFSminWT << setw(10) <<FCFSmaxWT << setw(10) << FCFSavgWT/iterations2 << setw(10)<<
             FCFSminST << setw(10) <<FCFSmaxST << setw(10) << FCFSavgST/iterations2 << setw(10)<<
             FCFSMAX << setw(10) <<FCFSAVG/iterations << endl;



    SummaryReport << "STRACK " <<STRACKminTIS << setw(10) <<STRACKmaxTIS << setw(10) << STRACKavgTIS/iterations2 << setw(10) <<
            STRACKminWT << setw(10) <<STRACKmaxWT << setw(10) << STRACKavgWT/iterations2 << setw(10)<<
            STRACKminST << setw(10) <<STRACKmaxST << setw(10) << STRACKavgST/iterations2 << setw(10)<<
            STRACKMAX<<setw(10) << STRACKAVG/iterations << endl;



    SummaryReport << "PICKUP " <<PICKUPminTIS << setw(10) <<PICKUPmaxTIS << setw(10) << PICKUPavgTIS/iterations2 << setw(10) <<
            PICKUPminWT << setw(10) <<PICKUPmaxWT << setw(10) << PICKUPavgWT/iterations2 << setw(10) <<
            PICKUPminST << setw(10) <<PICKUPmaxST << setw(10) << PICKUPavgST/iterations2 << setw(10) <<
            PICKUPMAX << setw(10)<< PICKUPAVG/iterations << endl;



    SummaryReport << "CLOOK  " <<CLOOKUPminTIS << setw(10) <<CLOOKUPmaxTIS << setw(10) << CLOOKUPavgTIS/iterations2 << setw(10)<<
            CLOOKUPminWT << setw(10) <<CLOOKUPmaxWT << setw(10) << CLOOKUPavgWT/iterations2 <<setw(10) <<
            CLOOKUPminST << setw(10) <<CLOOKUPmaxST << setw(10) << CLOOKUPavgST/iterations2 <<setw(10) <<
            CLOOKMAX << setw(10) << CLOOKAVG/iterations << endl;



    SummaryReport << "LOOK   " <<LOOKUPminTIS << setw(10) <<LOOKUPmaxTIS << setw(10) << LOOKUPavgTIS/iterations2 << setw(10) <<
            LOOKUPminWT << setw(10) <<LOOKUPmaxWT << setw(10) << LOOKUPavgWT/iterations2 << setw(10) <<
            LOOKUPminST << setw(10) <<LOOKUPmaxST << setw(10) << LOOKUPavgST/iterations2 << setw(10) <<
            LOOKMAX << setw(10) << LOOKAVG/iterations << endl;

    SummaryReport.close();



    cout << "done" << endl;


    return 0;
}
