# x 혹은 a/b 튜플을 저장
calcStack = []
notSolution = []
# (a/b x + c/b) / (e/f x + g/h) = 0
a = 0
b = 1
c = 0
d = 1
e = 0
f = 1
g = 1
h = 1

def gcd(x,y):
	while y != 0:
		(x, y) = (y, x%y)
	return x

def printFormula():
	print("(%d/%d)x + (%d/%d)" % (a,b,c,d))
	print("(%d/%d)x + (%d/%d)" % (e,f,g,h))
	print('')
	return 0

def reduction(lhs, rhs):
	lSign = 1 if lhs > 0 else -1
	rSign = 1 if rhs > 0 else -1
	lhs *= lSign
	rhs *= rSign
	if rSign == -1:
		lSign *= rSign
		rSign = 1
	tempGCD = gcd(lhs, rhs)
	lhs /= tempGCD
	rhs /= tempGCD
	return (lhs * lSign, rhs * rSign)

def addTuple(lhs, rhs):
	#firstTuple = lhs[0]*rhs[1] + rhs[0]*lhs[1]
	#secTuple = lhs[1] * rhs[1]
	calcTuple = (lhs[0]*rhs[1] + rhs[0]*lhs[1], lhs[1] * rhs[1])
	return calcTuple;

def calcSolution():
	global a,b,c,d,e,f,g,h
	if(d == 0 or a == 0):
		return (0, 1)
	temp = reduction(a,b)
	a = temp[0]
	b = temp[1]
	temp = reduction(c,d)
	c = temp[0]
	d = temp[1]
	temp = reduction(e,f)
	e = temp[0]
	f = temp[1]
	temp = reduction(g,h)
	g = temp[0]
	h = temp[1]
	temp = reduction(-1 * c * b, d * a)
	return temp

def calculate(lhs, rhs, op):
	global a,b,c,d,e,f,g,h
	# add & subtraction
	if op == '+' or op == '-':
		if op == '-' and rhs != 'X':
			rhs = (rhs[0] * -1, rhs[1])
		if lhs == 'X' or rhs == 'X':
			if lhs == 'X':
				num = rhs
			else:
				num = lhs
				if op == '-':
					a *= -1
					c *= -1
			temp = addTuple((a,b), (e * num[0],f * num[1]))
			a = temp[0]
			b = temp[1]
			temp = addTuple((c,d), (g * num[0],h * num[1]))
			c = temp[0]
			d = temp[1]
			calcStack.append('X')
		else:
			calcStack.append(addTuple(lhs, rhs))
			
	# multiply and divide
	elif op == '*' or op == '/':
		if op == '/' and rhs != 'X':
			if rhs[0] != 0:
				rhs = (rhs[1], rhs[0])
			# divide by 0
			else:
				return True
		if lhs == 'X' or rhs == 'X':
			if lhs == 'X':
				num = rhs
			else:
				num = lhs
				if op == '/':
					if a != 0:
						temp = calcSolution()
						notSolution.append(temp)
					a,e = e,a
					b,f = f,b
					c,g = g,c
					d,h = h,d
					
			a *= num[0]
			c *= num[0]
			b *= num[1]
			d *= num[1]
			calcStack.append('X')
		else:
			calcStack.append((lhs[0] * rhs[0], lhs[1] * rhs[1]))
	return False

def equation(inputStr):
	# Init
	global a,b,c,d,e,f,g,h
	a = 0
	b = 1
	c = 0
	d = 1
	e = 0
	f = 1
	g = 1
	h = 1
	calcStack.clear()
	notSolution.clear()
	
	if inputStr == '':
		inputStr = input('')
	eqArr = inputStr.split()
	flag = False
	for tok in eqArr:
		if tok == 'X':
			a = 1
			calcStack.append(tok)
		elif tok == '+' or tok == '-' or tok == '*' or tok == '/':
			rhs = calcStack.pop()
			lhs = calcStack.pop()
			#print(tok)
			#print(lhs,rhs)
			flag = calculate(lhs, rhs, tok)
			#printFormula()
			# end
			if flag:
				break;
		else:
			calcStack.append((int(tok), 1))
	
	if not flag:
		temp = calcStack.pop()
		if temp != 'X':
			c = temp[0]
			d = temp[1]

	if a == 0:
		if c == 0:
			print('MULTIPLE')
		else :
			print('NONE')
	else : 
		temp = calcSolution()
		if notSolution.count(temp) > 0:
			print('NONE')
		else :
			print("X = %d/%d" % (temp[0], temp[1]))
	
equation('')