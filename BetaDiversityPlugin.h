#ifndef BETADIVERSITYPLUGIN_H
#define BETADIVERSITYPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class BetaDiversityPlugin : public Plugin
{
public: 
 std::string toString() {return "BetaDiversity";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;
 std::vector<std::string> metrics;
};

#endif
