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
using namespace std;

class WebCrawler{
public:
    WebCrawler();
    WebCrawler(vector<string>kwds, vector<string> websites);
    void crawl();
    void parse();
    void addURLsToQueue(vector<string> urlList);
    void addKeywords(vector<string> keywords);
    set<string> getStrings(istream& is, regex pat);
private:
    vector<string> keywords;
    queue<string> URLs;
};



#endif /* WebCrawler_hpp */
