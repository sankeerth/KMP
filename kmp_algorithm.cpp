#include "log.h"
#include <string.h>

int compute_kmp_table(char *word, int *table, int word_length)
{
	int pos = 2; // position in the table
	int cur = 0; // position in the array which contains the word to match

	table[0] = -1, table[1] = 0; // pre-initialize starting values in the table

	while (pos < word_length) {
		if (word[pos-1] == word[cur]) {
		   	cur = cur + 1;
            		table[pos] = cur;
		    	pos++;
		} else if (cur > 0) {
		    	cur = table[cur];
		} else {
            	    	table[pos] = 0;
		    	pos++;
		}
	}
}

int perform_kmp(char *text, char *word)
{
	int match = 0; // position in text array where prospective match is found
	int index = 0; // position of iterative index in word array

	int text_length = strlen(text);
	int word_length = strlen(word);

	int *table = new int [word_length];
	compute_kmp_table(word, table, word_length);

	while ((match+index) < text_length) {
		if (text[match+index] == word[index]) {
			if (index == (word_length-1)) {
				return match;
			} else {
			    	index++;
			}
		} else {
            if (table[index] > -1) {
                match = match + index - table[index];
                index = table[index];
			} else {
                match = match + 1;
				index = 0;
			}
		}
	}
	return -1;
}

