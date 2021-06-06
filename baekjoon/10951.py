arr = []
while True:
	try:
		inputStr = input('')
	except:
		break;
	arr.append(inputStr)
print(''.join(arr))