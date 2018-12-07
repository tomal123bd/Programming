#python3
#without exception handling
#using ip-api.com
import requests
from requests import get
import socket
import xml.etree.ElementTree as ET
inp=None
print ("Input a web address or for finding network info input 'host' without quotes")
inp=input()
if inp=="host":
    ip_address=get("http://ipapi.co/ip")
    ip_address=ip_address.text
else:
    ip_address=socket.gethostbyname(inp)
get_info=requests.request("GET","http://ip-api.com/xml/"+ip_address)
tags=ET.fromstring(get_info.text)
for i in tags:
    print (i.tag,i.text)
