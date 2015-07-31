#include "kmp_algorithm.cpp"

int main()
{
	char *text = "ABC ABCDAB ABCDABCDABDE";
	char *word = "ABCDABD";

	LOG(perform_kmp(text, word));

	char *txt = "ABABDABACDABABCABAB";
   	char *pat = "ABABCABAB";

   	LOG(perform_kmp(txt, pat));
	return 0;
}