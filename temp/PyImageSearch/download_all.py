import xml.etree.ElementTree
from xml.dom import minidom
from urllib import request
import os

# tree = xml.etree.ElementTree.parse('pyimagesearch.xml')
# root = tree.getroot()
KB = 2**10
MB = 2**20

if __name__=='__main__':
    xmldoc = minidom.parse('pyimagesearch.xml')
    itemlist = xmldoc.getElementsByTagName('Key')
    sizelist = xmldoc.getElementsByTagName('Size')

    for item, sizee in zip(itemlist, sizelist):
        val = item.toxml()[5:-6]
        size = int(sizee.toxml()[6:-7])
        if '.zip' in val:
            if size>50*MB:
                print('Too Big to Download', val)
                continue
            if os.path.isfile('adrian/'+val):
                print('File Exists', val)
                continue
            link = 'https://s3-us-west-2.amazonaws.com/static.pyimagesearch.com/' + val
            val = val.split('/')[-1]
            print(link)
            try:
                request.urlretrieve(link, 'adrian/'+val)
            except Exception as e:
                raise Exception('Could not Download due to', e)
                continue
