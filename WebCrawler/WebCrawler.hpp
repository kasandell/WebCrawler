//
//  WebCrawler.hpp
//  WebCrawler
//
//  Created by Kyle Sandell on 12/2/15.
//  Copyright © 2015 Kyle Sandell. All rights reserved.
//

#ifndef WebCrawler_hpp
#define WebCrawler_hpp
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <thread>
#include <map>
#include <queue>
#include <curl/curl.h>
#include <set>
#include <regex>
#include <sstream>
using namespace std;

class WebCrawler{
public:
    WebCrawler();
    WebCrawler(vector<string>kwds, vector<string> websites);
    void crawl();
    void parse(pair<string, string> websiteAndURL);
    void addKeywords(vector<string> keywords);
    set<string> getStrings(istream& is, regex pat);
    string readWebsite(string url);
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
    void addURLsToQueue(set<string> list);
    double findKeywords(pair<string, string> websiteAndURL);
    void setKill(bool val);
private:
    string websiteData;
    vector<string> keywords;
    queue<string> URLs;
    vector<string> pastURLs;
    bool kill;
};



#endif /* WebCrawler_hpp */
