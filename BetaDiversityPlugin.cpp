#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "BetaDiversityPlugin.h"

void BetaDiversityPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   if ((key != "biomfile") && (key != "tree") && (key.length() > 0)) {
      metrics.push_back(key);
   }
   else {
   ifile >> value;
   parameters[key] = value;
   }
 }
 
}

void BetaDiversityPlugin::run() {
   
}

void BetaDiversityPlugin::output(std::string file) {
//beta_diversity.py -i filtered_otu_table.biom -m euclidean,weighted_unifrac,unweighted_unifrac -t rep_set.tre -o beta_div
   std::string command = "export OLDPATH=${PYTHONPATH}; export PYTHONPATH=${PYTHON2_DIST_PACKAGES}:${PYTHON2_SITE_PACKAGES}:${PYTHONPATH}; beta_diversity.py ";
 command += "-i "+parameters["biomfile"]+" -m ";
 for (int i = 0; i < metrics.size(); i++) {
    command += metrics[i];
    if (i != metrics.size()-1){command += ",";}
    else {command += " ";}
 }
 command += "-t "+parameters["tree"]+" ";
 command += "-o "+file+"; cp "+file+"/* "+file+"/..; export PYTHONPATH=OLDPATH";
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<BetaDiversityPlugin> BetaDiversityPluginProxy = PluginProxy<BetaDiversityPlugin>("BetaDiversity", PluginManager::getInstance());
