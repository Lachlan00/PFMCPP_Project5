#pragma once
#include "LeakedObjectDetector.h"

struct PrintJob 
{
    int numCopies, numPages, resolution;
    std::string documentFilename, paperType;
    PrintJob();
    ~PrintJob();

    void cancelJob(std::string jobID);
    std::string checkJobStatus(std::string jobID);
    void addToQueue(std::string printerID, std::string proity = "low");
    
    JUCE_LEAK_DETECTOR(PrintJob)
};
