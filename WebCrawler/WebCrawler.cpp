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
    
    while (!URLs.empty()) {
        string url=URLs.front();
        URLs.pop();
        string dat = readWebsite(url);
        parse(pair<string, string>(url, dat));
    }
    
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

void WebCrawler::parse(pair<string, string> websiteAndURL)
{
    string site=websiteAndURL.first;
    string dat=websiteAndURL.second;
    regex pat{ R"((http://)?www([./#\+-]\w*)+)" };
    istringstream iss(dat);
    set<string> sites=getStrings(iss, pat);
    for(auto u:sites)
    {
        URLs.push(u);
    }
}


void WebCrawler::addKeywords(vector<string> keywords)
{
    
}

string WebCrawler::readWebsite(string url)
{
    websiteData.clear();
    CURL *curl;
    CURLcode res;
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &WebCrawler::WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &websiteData);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, true);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return websiteData;
}

size_t WebCrawler::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}