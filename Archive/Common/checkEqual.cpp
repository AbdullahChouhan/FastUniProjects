int stringLength(char* word) {
	int length = -1;
	while (word[++length] != '\0');
	return length - 1;
}

bool checkEqual(char* word1, char* delim, int start = 0) {
	int i = start;
	for (; word1[start] != '\0' && delim[start - i] != '\0';start++) {
		if (word1[start] != delim[start - i])
			return false;
	}
	return stringLength(word1) == stringLength(delim);
}