#!/usr/bin/env python
# coding: utf-8
from contextlib import closing
from urllib import urlopen
from urlparse import urlsplit

def download_file(url):
    filename = urlsplit(url).path.rsplit('/', 1)[1]
    with closing(urlopen(url, 'rb')) as web_file:
        with open(filename, 'wb') as local_file:
            local_file.write(web_file.read())


if __name__ == '__main__':
    url = 'http://hsa-embedded.googlecode.com/files/download.pn'
    download_file(url)
