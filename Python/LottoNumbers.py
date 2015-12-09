isCovered=99*[False]
endOfInput=False
while not endOfInput:
	s=raw_input("Please enter a line of numbers separated by spaces:")
	items=s.split()
	lst=[eval(x) for x in items]
	for number in lst:
		if number==0:
			endOfInput=True
		else:
			isCovered[number-1]=True
allCovered=True
for i in range(99):
	if not isCovered[i]:
		allCovered=False
		break
if allCovered:
	print("The tickets cover all numbers")
else:
	print("The tickets don't cover all numbers")
