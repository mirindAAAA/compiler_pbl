#include <fstream>
#include <iostream>

void generateReport()
{
    std::ofstream report("report.html");

    report << "<html><head><title>Security Report</title></head><body>";
    report << "<h1>Secure Code Analyzer Report</h1>";

    report << "<h2>Detected Vulnerabilities</h2>";
    report << "<ul>";
    report << "<li><b>Unsafe Function:</b> gets() - Buffer overflow risk</li>";
    report << "<li><b>Infinite Loop:</b> while(1)</li>";
    report << "<li><b>Null Pointer:</b> Possible dereference</li>";
    report << "</ul>";

    report << "<h2>Suggested Fixes</h2>";
    report << "<ul>";
    report << "<li>Replace gets() with fgets()</li>";
    report << "<li>Add termination condition for loops</li>";
    report << "<li>Check pointers before dereferencing</li>";
    report << "</ul>";

    report << "</body></html>";

    report.close();

    std::cout << "\nReport generated: report.html\n";
}