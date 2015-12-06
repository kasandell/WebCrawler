# WebCrawler
A C++ program built to crawl the web endlessly looking for websites that contain the keywords the user is looking for.

#Usage

An example usage of the program is
'''
./crawl -s http://stackoverflow.com/ -k C++ -th 5 -ls
'''
This will crawl the web for five hours, looking for sites containing the keyword C++/ The program starts at http://stackoverflow.com/ and crawls from there. It also lists every site it is crawling. 

