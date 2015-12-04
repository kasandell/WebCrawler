//
//  main.cpp
//  WebCrawler
//
//  Created by Kyle Sandell on 12/2/15.
//  Copyright © 2015 Kyle Sandell. All rights reserved.
//
#include "WebCrawler.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    vector<string> kwds;
    vector<string> sites;
    double timespan=0;//time in minutes
    WebCrawler crawler;
    for (int i =0; i<argc; i++) {
        if( argv[i]== "-k")
        {
            kwds.push_back(argv[i+1]);
        }
        if(argv[i] == "-s")
        {
            sites.push_back(argv[i+1]);
        }
        if(argv[i] == "-th")
        {
            timespan = atoi(argv[i+1])*60;
        }
        if(argv[i] == "-tm")
        {
            timespan = atoi(argv[i+1]);
        }
    }
    
    if(timespan != 0)
    {
        crawler = WebCrawler(kwds, sites);
        time_t start = time(NULL);
        crawler.crawl();
        while (std::chrono::minutes(time(NULL)-start).count() < timespan) {
            
        }
        crawler.setKill(true);
        sleep(1000);
        
    }
    else{
        string q="";
        crawler=WebCrawler(kwds, sites);
        cin>>q;
        while (q != "q") {
            cin>>q;
            if(q == "q")
            {
                crawler.setKill(true);
                sleep(1000);
                break;
            }
        }
    }
    return 0;
}
