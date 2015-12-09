#!/usr/bin/python
import Image
def createImage():
	img=Image.open("img.jpg")
	pix=img.load()
	file=open("misc100.txt")
	for h in range(0,256):
		for w in range(0,256):
			rgb=file.readline()
			rc=rgb.replace("\n","").split(",")
			for x in range(0,3):
				rc[x]=int(rc[x])
			rcp=tuple(rc)
			pix[h,w]=rcp
			c+=1
			if c == 61336:
				img.save("out.jpg","JPEG")
				file.close()
				return
if __name__ == "__main__":
	createImage()
