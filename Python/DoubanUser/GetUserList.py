#coding=utf-8
##从豆瓣网页中得到用户id

##网页地址类型：http://movie.douban.com/subject/25727048/collections?start=0
#http://movie.douban.com/subject/25727048/collections?start=20

from bs4 import BeautifulSoup
import codecs
import time
import urllib2

baseUrl='http://movie.douban.com/subject/25727048/collections?start='

def saveUserInfo(idList,linkList):
	if len(idList)!=len(linkList):
		print 'Error:len(idList)!=len(linkList)!'
		return
	writeFile=codecs.open('UserIdList3.txt','a','utf-8')
	size=len(idList)
	for i in range(size):
		writeFile.write(idList[i]+'\t'+linkList[i]+'\n')
	writeFile.close()

def parseHtmlUserId(html):
	idList=[]
	linkList=[]
	
	soup=BeautifulSoup(html)
	td_tags=soup.findAll('td',width='80',valign='top')
	i=0
	for td in td_tags:
		if i==20:
			break
		a=td.a
		link=a.get('href')
		i_start=link.find('people/')
		id=link[i_start+7:-1]
		idList.append(id)
		linkList.append(link)
		i+=1
	return (idList,linkList)
	
def getHtml(num):
	url=baseUrl+str(num)
	page=urllib2.urlopen(url)
	html=page.read()
	return html
	
def launch():
	ques=raw_input('Start from number(multiples of 20):')
	startNum=int(ques)
	if startNum%20!=0:
		print 'Input Error!'
		return
	for i in range(startNum,200,20):
		print 'Loading page %d/200...'%(i+1)
		html=getHtml(i)
		(curIdList,curLinkList)=parseHtmlUserId(html)
		saveUserInfo(curIdList,curLinkList)
		print 'Sleeping...'
		time.sleep(5)
if __name__=='__main__':
	launch()
