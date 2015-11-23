from Domain import*

def appendString(string):
	stringArray = []
	stringArray.append(string)
	return stringArray

def extractChars(stringArray):
	charSet = set()
	for word in stringArray:
		for letter in word:
			charSet.add(letter)
	return charSet 

def extractSep(wordList):
	lastChars = set()
	charSet = set()
	for word in wordList[:-1]:
		for letter in word:
			charSet.add(letter)
			#add carries here

	for letter in wordList[-1]:
		lastChars.add(letter)

	return lastChars, charSet

def setConstDict(wordList):
	constDict = {}
	lastWord = wordList[-1][::-1]
	carryNum = getMaxWordLength(wordList)
	rWordList = reverseWordList(wordList)

	for column in range(0, len(lastWord)):
		constDict[lastWord[column]] = getColumn(column, rWordList)
	for i in range(0,getMaxWordLength(wordList)):
		constDict['x' + str(i)] = [1,0]
	return constDict

def reverseWordList(wordList):
	for indx, word in enumerate(wordList):
		wordList[indx] = word[::-1]
		
	return wordList

def getMaxWordLength(wordList):
	lengthList = []
	for word in wordList:
		lengthList.append(len(word))
	return max(lengthList)

def getColumn(columnNum, wordList):
	columnArray  = []
	for word in wordList[:-1]:
		if columnNum <len(word):
			columnArray.append(word[columnNum])
	return columnArray

def setDomainTable(letters):
    domainTable = {}
    for name in letters:
        domainTable[name] = Variable(name,1)
    return domainTable


