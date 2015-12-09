import zlib
inAddr=raw_input("Please enter the source file address:")
desAddr=raw_input("Please enter the destinated file address:")
infile=open(inAddr,'rb')
dst=open(desAddr,'wb')
decomp=zlib.decompressobj()
data=infile.read(1024)
while data:
	dst.write(decomp.decompress(data));
	data=infile.read(1024)
dst.write(decomp.flush())
