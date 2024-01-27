#include <string>
#include <boost/process.hpp>

bool isServiceRunning() {
    std::string serviceName = "./service/service";
    boost::process::ipstream pipeStream;
    boost::process::child childProcess(serviceName, boost::process::std_out > pipeStream);

    std::string line;
    while (pipeStream && std::getline(pipeStream, line) && !line.empty()) {
        childProcess.wait();
        return true; 
    }

    childProcess.wait();
    return false;
}

void startService() {
    std::string serviceCommand = "service/service";
    boost::process::spawn(serviceCommand);
}

void startCLI() {
    std::string cliCommand = "interface/interface";
    boost::process::spawn(cliCommand);
}

int main() {
    if (!isServiceRunning()) {
        startService();
    }
    startCLI();
    return 0;
}