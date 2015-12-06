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
    bool list = false;
    double timespan=0;//time in minutes
    WebCrawler crawler;
    for (int i =0; i<argc; i++) {
        if( argv[i]== "-k")
        {
            kwds.push_back(argv[i+1]);
        }
        else if(argv[i] == "-s")
        {
            sites.push_back(argv[i+1]);
        }
        else if(argv[i] == "-th")
        {
            timespan = atoi(argv[i+1])*60;
        }
        else if(argv[i] == "-tm")
        {
            timespan = atoi(argv[i+1]);
        }
        else if(argv[i] == "-ls")
        {
            list = true;
        }
        else if(argv[i] == "--help")
        {
            cout<< "Valid Arguments:"<<endl;
            cout<<"'-k' can be used multiple times to specify keywords to search for."<<endl;
            cout<<"'-s' can be used multiple times to specify seed sites."<<endl;
            cout<<"'-th' can be used once to specify the number hours to crawl for."<<endl;
            cout<<"'-tm' can be used to specify the number of minutes to crawl for."<<endl;
            cout<<"-ls' can be used to specify that you want to list the sites being crawled. No following argument is required. Do not specify this argument if you do not wish sites being crawled to be listed."<<endl;
            cout<<"'--help' can be used to find what each argument does."<<endl;
        }
        else{
            
        }
    }

    if(timespan != 0)
    {
        crawler = WebCrawler(kwds, sites);
        if(list)
        {
            crawler.setListSites(true);
        }
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
        if(list)
        {
            crawler.setListSites(true);
        }
        crawler.crawl();
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
