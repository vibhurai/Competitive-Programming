from urllib.request import urlopen
import xml.etree.ElementTree as ET
import ssl

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

html = urlopen('http://py4e-data.dr-chuck.net/comments_734558.xml', context=ctx).read()
sum=0

tree = ET.fromstring(html)
counts = tree.findall('.//count')
for tag in counts: 
    x=tag.text
    x= int(x)
    sum+=x
print(sum)    

    



