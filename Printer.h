#pragma once
#include "LeakedObjectDetector.h"
#include "PrintJob.h"

struct Printer
{
    int paperLevel, maxRes;
    float inkLevel, electrictyConsumption;
    std::string brandName;
    Printer();
    ~Printer();

    void printDocument();
    void printDocument2();
    void loadJobs(int queueNumber);
    void scanDocument(int resolution = 300);
    void scanDocument2(int resolution = 300);
    void printCopies(int noCopies);
    void printCopies2(int noCopies);

    PrintJob printJob;
    
    JUCE_LEAK_DETECTOR(Printer)
};
