//
//  WebCrawler.cpp
//  WebCrawler
//
//  Created by Kyle Sandell on 12/2/15.
//  Copyright © 2015 Kyle Sandell. All rights reserved.
//

#include "WebCrawler.hpp"

WebCrawler::WebCrawler()
{
    
}
WebCrawler::WebCrawler(vector<string>kwds, vector<string> websites)
{
    for(auto kwd:kwds)
    {
        keywords.push_back(kwd);
    }
    for(auto site:websites)
    {
        URLs.push(site);
    }
}
void WebCrawler::crawl()
{
     regex pat{ R"((http://)?www([./#\+-]\w*)+)" };
}
set<string> WebCrawler::getStrings(istream& is, regex pat)
{
    set<string> res;
    smatch m;
    for (string s; getline(is, s);)  // read a line
        if (regex_search(s, m, pat))
            res.insert(m[0]);              // save match in set
    return res;
}
void WebCrawler::parse()
{
    
}
void WebCrawler::addURLsToQueue(vector<string> urlList)
{
    
}
void WebCrawler::addKeywords(vector<string> keywords)
{
    
}