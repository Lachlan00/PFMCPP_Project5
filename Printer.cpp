#include <iostream>
#include "Printer.h"

Printer::Printer() :
paperLevel(124),
maxRes(300),
inkLevel(75.f),
electrictyConsumption(140.f),
brandName("Canon")
{}

Printer::~Printer()
{
    std::cout << "Printer is gone!" << std::endl;
}

void Printer::printDocument()
{
    std::cout << "Printing " << printJob.numCopies << " Copies of document " << printJob.documentFilename << std::endl;
    std::cout << "Current ink level: " << inkLevel << std::endl;
    std::cout << "Current paper level: "  << paperLevel << std::endl;
}

void Printer::printDocument2()
{
    std::cout << "Printing " << this->printJob.numCopies << " Copies of document " << this->printJob.documentFilename << std::endl;
    std::cout << "Current ink level: " << this->inkLevel << std::endl;
    std::cout << "Current paper level: "  << this->paperLevel << std::endl;
}

void Printer::loadJobs(int queueNumber)
{
    if (queueNumber > 1)
    {
        queueNumber -= 1;
    }
}

void Printer::scanDocument(int resolution)
{
    std::cout << "Scanning document at " << resolution << " dpi." << std::endl;
    std::cout << "Max resolution is " << maxRes << " dpi." << std::endl;
}

void Printer::scanDocument2(int resolution)
{
    std::cout << "Scanning document at " << resolution << " dpi." << std::endl;
    std::cout << "Max resolution is " << this->maxRes << " dpi." << std::endl;
}

void Printer::printCopies(int noCopies)
{
    printJob.numCopies = noCopies;
    printDocument();
    
    for (int i = 0; i < noCopies; ++i)
    {
        if (paperLevel == 0)
        {
            std::cout << "Error: no paper!" << std::endl;
            break;
        }
        
        std::cout << "Printing copy " << i + 1 << ".." << std::endl;
        paperLevel -= 1;
    }
}

void Printer::printCopies2(int noCopies)
{
    this->printJob.numCopies = noCopies;
    this->printDocument();
    
    for (int i = 0; i < noCopies; ++i)
    {
        if (this->paperLevel == 0)
        {
            std::cout << "Error: no paper!" << std::endl;
            break;
        }
        
        std::cout << "Printing copy " << i + 1 << ".." << std::endl;
        this->paperLevel -= 1;
    }
}

