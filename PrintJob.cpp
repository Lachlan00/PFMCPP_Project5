#include <iostream>
#include "PrintJob.h"

PrintJob::PrintJob() :
numCopies(2),
numPages(12),
resolution(300),
documentFilename("myDoc.doc"),
paperType("A4")
{}

PrintJob::~PrintJob()
{
    std::cout << "Print job over." << std::endl;
}

