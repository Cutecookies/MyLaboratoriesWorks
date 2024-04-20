# include "libs/data_structures/string_/tasks/tasks.c"
# include "libs/data_structures/string_/string_.h"
# include "stdio.h"
# include "stdlib.h"
# include "assert.h"

# define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

void assertString(const char *expected, char *got,

                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp(expected, got) != 0) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

// Task 1

// нет пробелов
void test_removeNonLetters_onlyLetters() {
    char s[] = "hello\0";
    char exp[] = "hello\0";
    removeNonLetters(s);
    ASSERT_STRING(exp, s);
}

// один пробел
void test_removeNonLetters_oneSpace() {
    char s[] = "ab 1\0";
    char exp[] = "ab1\0";
    removeNonLetters(s);
    ASSERT_STRING(exp, s);
}

// много пробелов
void test_removeNonLetters_manySpaces() {
    char s[] = "ab 1c2 3 fe f 4h6 j\0";
    char exp[] = "ab1c23fef4h6j\0";
    removeNonLetters(s);
    ASSERT_STRING(exp, s);
}

// Task 2

// пустая строка
void test_removeAdjacentEqualLetters_emptyString() {
    char s[] = "\0";
    char exp[] = "\0";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(exp, s);
}

// один символ
void test_removeAdjacentEqualLetters_oneSymbol() {
    char s[] = "a\0";
    char exp[] = "a\0";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(exp, s);
}

// 2 одинаковых символа
void test_removeAdjacentEqualLetters_2SameSymbols() {
    char s[] = "aa\0";
    char exp[] = "a\0";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(exp, s);
}

// 3 одинаковых символа
void test_removeAdjacentEqualLetters_3SameSymbols() {
    char s[] = "aaa\0";
    char exp[] = "a\0";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(exp, s);
}

// 2 пары одинаковых символов
void test_removeAdjacentEqualLetters_2PairsSameSymbols() {
    char s[] = "aabb\0";
    char exp[] = "ab\0";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(exp, s);
}

// разые символы и пробелы
void test_removeAdjacentEqualLetters_differentSymbolsAndSpaces() {
    char s[] = "aaa bb c\0";
    char exp[] = "a b c\0";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(exp, s);
}

// task 3

// пустая строка
void test_transformWord_emptyString() {
    char s[] = "\0";
    char res[] = "\0";
    transformWord(s);
    ASSERT_STRING(res, s);
}

// 2 символа
void test_transformWord_2Symbols() {
    char s[] = "a1\0";
    char res[] = "1a\0";
    transformWord(s);
    ASSERT_STRING(res, s);
}

// 1 слово
void test_transformWord_1Word() {
    char s[] = "a1b2c3\0";
    char res[] = "123abc\0";
    transformWord(s);
    ASSERT_STRING(res, s);
}

// 2 слова
void test_transformWord_2Words() {
    char s[] = "a1b2c3 d5hj78 \0";
    char res[] = "123abc 578dhj \0";
    transformWord(s);
    ASSERT_STRING(res, s);
}

// Task 4

// пустая строка
void test_everyNumberBecomeSpaces_emptyString() {
    char s[5] = "";
    char res[] = "";
    everyNumberBecomeSpaces(s);
    ASSERT_STRING(res, s);
}

// 1 цифра
void test_everyNumberBecomeSpaces_oneNumber() {
    char s[5] = "3a";
    char res[] = "   a";
    everyNumberBecomeSpaces(s);
    ASSERT_STRING(res, s);
}

// 2 цифры
void test_everyNumberBecomeSpaces_2Numbers() {
    char s[6] = "3a2";
    char res[] = "   a  ";
    everyNumberBecomeSpaces(s);
    ASSERT_STRING(res, s);
}

// цифры и пробелы
void test_everyNumberBecomeSpaces_numbersAndSpaces() {
    char s[10] = "3a 2";
    char res[] = "   a   ";
    everyNumberBecomeSpaces(s);
    ASSERT_STRING(res, s);
}

// без цифр
void test_everyNumberBecomeSpaces_noNumbers() {
    char s[6] = "a b c";
    char res[] = "a b c";
    everyNumberBecomeSpaces(s);
    ASSERT_STRING(res, s);
}

// Task 5

// пустая строка
void test_replace_emptyString() {
    char s[20] = "";
    char exp[] = "";
    replace(s, "bc", "bbc");
    ASSERT_STRING(exp, s);
}

// w1 < w2
void test_replace_w1Lessw2() {
    char s[20] = "ab bc cc";
    char exp[] = "ab bbc cc";
    replace(s, "bc", "bbc");
    ASSERT_STRING(exp, s);
}

// w1 > w2
void test_replace_w1Morew2() {
    char s[20] = "ab bc cc";
    char exp[] = "ab c cc";
    replace(s, "bc", "c");
    ASSERT_STRING(exp, s);
}

// w1 = w2
void test_replace_w1Equalw2() {
    char s[20] = "ab bc cc";
    char exp[] = "ab cd cc";
    replace(s, "bc", "cd");
    ASSERT_STRING(exp, s);
}

// Task 6

// пустая строка
void test_isWordsOrdered_emptyString() {
    char s[] = "";
    assert(isWordsOrdered(s));
}

// 1 слово
void test_isWordsOrdered_1Word() {
    char s[] = "a";
    assert(isWordsOrdered(s));
}

// 2 слова по порядку
void test_isWordsOrdered_2WordsTrue() {
    char s[] = "a b";
    assert(isWordsOrdered(s));
}

// 2 слова не по порядку
void test_isWordsOrdered_2WordsFalse() {
    char s[] = "b a";
    assert(!isWordsOrdered(s));
}

// 2 слова равны
void test_isWordsOrdered_2WordsEqual() {
    char s[] = "a a";
    assert(isWordsOrdered(s));
}

// слова по порядку и равные слова
void test_isWordsOrdered_wordsTrueAndEqualWords() {
    char s[] = "a b c c d";
    assert(isWordsOrdered(s));
}

// слова не по порядку и равные слова
void test_isWordsOrdered_wordsFalseAndEqualWords() {
    char s[] = "a b d c d";
    assert(!isWordsOrdered(s));
}

// Task 7

// пустая строка
void test_printWordsFromEnd_emptyString() {
    char s[] = "ab cd";
    printWordsFromEnd(s);
}

// 2 слова
void test_printWordsFromEnd_2Words() {
    char s[] = "ab cd";
    printWordsFromEnd(s);
}

// Task 8

// пустая строка
void test_countWordsPalindromes_emptyString() {
    char s[] = "";
    assert(countWordsPalindromes(s) == 0);
}

// нечетный палиндром
void test_countWordsPalindromes_oddPalindrome() {
    char s[] = "ab cd abcba";
    assert(countWordsPalindromes(s) == 1);
}

// четный палиндром
void test_countWordsPalindromes_evenPalindrome() {
    char s[] = "ab cd abba";
    assert(countWordsPalindromes(s) == 1);
}

// несколько палиндромов
void test_countWordsPalindromes_somePalindromes() {
    char s[] = "ab cd abba cd aba";
    assert(countWordsPalindromes(s) == 2);
}

// Task 9

// пустые строки
void test_uniteStrings_emptyStrings() {
    char s1[] = "";
    char s2[] = "";
    char s3[2] = "";
    char exp[] = "";
    uniteStrings(s1, s2, s3);
    ASSERT_STRING(exp, s3);
}

// одна строка
void test_uniteStrings_1String() {
    char s1[] = "ab";
    char s2[] = "";
    char s3[10] = "";
    char exp[] = "ab";
    uniteStrings(s1, s2, s3);
    ASSERT_STRING(exp, s3);
}

// равные строки
void test_uniteStrings_equalStrings() {
    char s1[] = "ab";
    char s2[] = "bc";
    char s3[10] = "";
    char exp[] = "ab bc";
    uniteStrings(s1, s2, s3);
    ASSERT_STRING(exp, s3);
}

// не равные строки
void test_uniteStrings_notEqualStrings() {
    char s1[] = "ab dc";
    char s2[] = "bc h j y";
    char s3[40] = "";
    char exp[] = "ab bc dc h j y";
    uniteStrings(s1, s2, s3);
    ASSERT_STRING(exp, s3);
}

// Task 10

// пустая строка
void test_makeStringWordReverse_emptyString() {
    char s[] = "";
    char exp[] = "";
    makeStringWordReverse(s);
    ASSERT_STRING(exp, s);
}

// 1 слово
void test_makeStringWordReverse_1Word() {
    char s[] = "ab";
    char exp[] = "ab";
    makeStringWordReverse(s);
    ASSERT_STRING(exp, s);
}

// 3 слова
void test_makeStringWordReverse_3Words() {
    char s[] = "ab b a";
    char exp[] = "a b ab";
    makeStringWordReverse(s);
    ASSERT_STRING(exp, s);
}

// Task 11

void testAll_getWordBeforeFirstWordWithA() {
    WordDescriptor word;
    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &word)
           == EMPTY_STRING);
    char s2[] = "ABC";

    assert(getWordBeforeFirstWordWithA(s2, &word)
           == FIRST_WORD_WITH_A);
    char s3[] = "BC A";
    assert(getWordBeforeFirstWordWithA(s3, &word)
           == WORD_FOUND);
    char got[MAX_WORD_SIZE];
    copy(word.begin, word.end, got);
    got[word.end - word.begin] = '\0';
    ASSERT_STRING("BC", got);
    char s4[] = "B Q WE YR OW IUWR";
    assert(getWordBeforeFirstWordWithA(s4, &word)
           == NOT_FOUND_A_WORD_WITH_A);
}

// Task 12

// 1 слово из 1-ой строки во 2-ой
void test_lastWordInFirstStringInSecondString_1Word() {
    char s1[] = "a";
    char s2[] = "a bc";
    char exp[] = "a";
    char string[MAX_N_WORDS_IN_STRING];
    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);
    wordDescriptorToString(word, string);
    ASSERT_STRING(exp, string);
}

// 2 слова из 1-ой строки во 2-ой
void test_lastWordInFirstStringInSecondString_2Words() {
    char s1[] = "a b c";
    char s2[] = "a bc b d";
    char exp[] = "b";
    char string[MAX_N_WORDS_IN_STRING];
    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);
    wordDescriptorToString(word, string);
    ASSERT_STRING(exp, string);
}

// Task 13

// пустая строка
void test_areThereSameWords_emptyString() {
    char s[] = "";
    assert(!areThereSameWords(s));
}

// нет одинаковых слов
void test_areThereSameWords_noSameWords() {
    char s[] = "a b c";
    assert(!areThereSameWords(s));
}

// есть одинаковые слова
void test_areThereSameWords_areSameWords() {
    char s[] = "a b c a";
    assert(areThereSameWords(s));
}

// есть несколько одинаковых слов
void test_areThereSameWords_areSomeSameWords() {
    char s[] = "a b c d c b";
    assert(areThereSameWords(s));
}

// Task 14

// пустая строка
void test_areWordsWithSameLetters_emptyString() {
    char s[] = "";
    assert(!areWordsWithSameLetters(s));
}

// есть слова с одинаковыми элементами
void test_areWordsWithSameLetters_areSameElements() {
    char s[] = "ab ba c";
    assert(areWordsWithSameLetters(s));
}

// нет слов с одинаковыми элементами
void test_areWordsWithSameLetters_noSameElements() {
    char s[] = "ab baс c";
    assert(!areWordsWithSameLetters(s));
}

void test() {
    test_removeNonLetters_onlyLetters();
    test_removeNonLetters_oneSpace();
    test_removeNonLetters_manySpaces();
    test_removeAdjacentEqualLetters_emptyString();
    test_removeAdjacentEqualLetters_oneSymbol();
    test_removeAdjacentEqualLetters_2SameSymbols();
    test_removeAdjacentEqualLetters_3SameSymbols();
    test_removeAdjacentEqualLetters_2PairsSameSymbols();
    test_removeAdjacentEqualLetters_differentSymbolsAndSpaces();
    test_transformWord_emptyString();
    test_transformWord_2Symbols();
    test_transformWord_1Word();
    test_transformWord_2Words();
    test_everyNumberBecomeSpaces_emptyString();
    test_everyNumberBecomeSpaces_oneNumber();
    test_everyNumberBecomeSpaces_2Numbers();
    test_everyNumberBecomeSpaces_numbersAndSpaces();
    test_everyNumberBecomeSpaces_noNumbers();
    test_replace_emptyString();
    test_replace_w1Lessw2();
    test_replace_w1Morew2();
    test_replace_w1Equalw2();
    test_isWordsOrdered_emptyString();
    test_isWordsOrdered_1Word();
    test_isWordsOrdered_2WordsTrue();
    test_isWordsOrdered_2WordsFalse();
    test_isWordsOrdered_2WordsEqual();
    test_isWordsOrdered_wordsTrueAndEqualWords();
    test_isWordsOrdered_wordsFalseAndEqualWords();
    test_printWordsFromEnd_emptyString();
    test_printWordsFromEnd_2Words();
    test_countWordsPalindromes_emptyString();
    test_countWordsPalindromes_oddPalindrome();
    test_countWordsPalindromes_evenPalindrome();
    test_countWordsPalindromes_somePalindromes();
    test_uniteStrings_emptyStrings();
    test_uniteStrings_1String();
    test_uniteStrings_equalStrings();
    test_uniteStrings_notEqualStrings();
    test_makeStringWordReverse_emptyString();
    test_makeStringWordReverse_1Word();
    test_makeStringWordReverse_3Words();
    testAll_getWordBeforeFirstWordWithA();
    test_lastWordInFirstStringInSecondString_1Word();
    test_lastWordInFirstStringInSecondString_2Words();
    test_areThereSameWords_emptyString();
    test_areThereSameWords_noSameWords();
    test_areThereSameWords_areSameWords();
    test_areThereSameWords_areSomeSameWords();
    test_areWordsWithSameLetters_emptyString();
    test_areWordsWithSameLetters_areSameElements();
    test_areWordsWithSameLetters_noSameElements();
}

int main() {
    test();

    return 0;
}