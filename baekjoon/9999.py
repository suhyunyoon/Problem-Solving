str9 = ''
try:
	while True:
		inputStr = input('')
		cnt9 = 0
		for i in inputStr:
			if i == '구':
				cnt9 += 1
			else:
				if cnt9 > 0:
					str9 += chr(64 + cnt9)
				str9 += i
				cnt9 = 0
		str9 += '\n'
except:
	pass
print(str9)
# chr(아스키코드)