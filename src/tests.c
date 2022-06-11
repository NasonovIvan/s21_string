#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

#define BUFF_SIZE 512

START_TEST(memcpy_1) {
#line 7
  char str_1[20] = "i am proger";
  char str_2[20] = " \0";
  char str_3[12] = "i am\nproger";
  char str_4[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  char str_7[10] = "\0";
  ck_assert_str_eq(memcpy(str_1, str_2, 8), s21_memcpy(str_1, str_2, 8));
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 2));
  ck_assert_str_eq(memcpy(str_3, str_4, 9), s21_memcpy(str_3, str_4, 9));
  ck_assert_str_eq(memcpy(str_3, str_4, 0), s21_memcpy(str_3, str_4, 0));
  ck_assert_str_eq(memcpy(str_2, str_5, 2), s21_memcpy(str_2, str_5, 2));
  ck_assert_str_eq(memcpy(str_6, str_7, 2), s21_memcpy(str_6, str_7, 2));
}
END_TEST

START_TEST(memmove_2) {
#line 22
  char str_1[11] = "1234567890";
  char str_2[11] = "";
  char str_3[12] = "i am\nproger";
  char str_4[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  char str_7[10] = "\0";
  ck_assert_str_eq(memmove(str_1 + 4, str_1 + 3, 3),
                   s21_memmove(str_1 + 4, str_1 + 3, 3));
  ck_assert_str_eq(memmove(str_2 + 4, str_2 + 3, 0),
                   s21_memmove(str_2 + 4, str_2 + 3, 0));
  ck_assert_str_eq(memmove(str_3, str_4, 10), s21_memmove(str_3, str_4, 10));
  ck_assert_str_eq(memmove(str_3, str_4, 0), s21_memmove(str_3, str_4, 0));
  ck_assert_str_eq(memmove(str_2, str_5, 2), s21_memmove(str_2, str_5, 2));
  ck_assert_str_eq(memmove(str_6, str_7, 2), s21_memmove(str_6, str_7, 2));
}
END_TEST

START_TEST(memset_3) {
#line 37
  char str_1[10] = "123456789";
  char str_2[11] = "";
  char str_3[12] = "i am\nproger";
  char str_4[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  char str_7[10] = "\0";
  ck_assert_str_eq(memset(str_1, 'k', 3), s21_memset(str_1, 'k', 3));
  ck_assert_str_eq(memset(str_2, '0', 3), s21_memset(str_2, '0', 3));
  ck_assert_str_eq(memset(str_3, '\0', 3), s21_memset(str_3, '\0', 3));
  ck_assert_str_eq(memset(str_4, 'q', 16), s21_memset(str_4, 'q', 16));
  ck_assert_str_eq(memset(str_5, 's', 20), s21_memset(str_5, 's', 20));
  ck_assert_str_eq(memset(str_7, 'b', 5), s21_memset(str_7, 'b', 5));
  ck_assert_str_eq(memset(str_4, 'q', 0), s21_memset(str_4, 'q', 0));
}
END_TEST

START_TEST(strcpy_4) {
#line 53
  char str_1[50] = "\0";
  char str_2[50] = "i progeeer";
  char str_3[50] = "Я программист\n";
  char str_4[50] = "i am\nproger";
  char str_5[50] = " \n\0\0";
  char str_6[50] = " a\n\0";
  char str_7[50] = "\0";
  char str_8[50] = "jhwrbnvrw\0";
  char str_9[50] = "3875bnvrw\0";
  ck_assert_str_eq(strcpy(str_1, str_7), s21_strcpy(str_1, str_7));
  ck_assert_str_eq(strcpy(str_3, str_4), s21_strcpy(str_3, str_4));
  ck_assert_str_eq(strcpy(str_4, str_2), s21_strcpy(str_4, str_2));
  ck_assert_str_eq(strcpy(str_5, str_6), s21_strcpy(str_5, str_6));
  ck_assert_str_eq(strcpy(str_7, str_3), s21_strcpy(str_7, str_3));
  ck_assert_str_eq(strcpy(str_9, str_8), s21_strcpy(str_9, str_8));
}
END_TEST

START_TEST(strncpy_5) {
  char str_7[50] = "Per aspera ad astra";
  char str_8[50] = "i am\nproger";
  char str_3[12] = "i am\nproger";
  char str_4[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  char str_1[10] = "\0";
  ck_assert_str_eq(strncpy(str_8, str_7, 8), s21_strncpy(str_8, str_7, 8));
  ck_assert_str_eq(strncpy(str_3, str_4, 3), s21_strncpy(str_3, str_4, 3));
  ck_assert_str_eq(strncpy(str_1, str_3, 6), s21_strncpy(str_1, str_3, 6));
  ck_assert_str_eq(strncpy(str_5, str_6, 2), s21_strncpy(str_5, str_6, 2));
  ck_assert_str_eq(strncpy(str_6, str_7, 0), s21_strncpy(str_6, str_7, 0));
  ck_assert_str_eq(strncpy(str_7, str_3, 40), s21_strncpy(str_7, str_3, 40));
  ck_assert_str_eq(strncpy(str_3, str_6, 12), s21_strncpy(str_3, str_6, 12));
}
END_TEST

START_TEST(memchr_6) {
#line 85
  char str_7[50] = "Per aspera ad astra";
  char str_8[50] = "i am\nproger";
  char str_3[12] = "i am\nproger";
  char str_4[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  char str_1[10] = "\0";
  char str_9[40] = "Hello world";
  ck_assert_ptr_eq(memchr(str_1, '\n', 6), s21_memchr(str_1, '\n', 6));
  ck_assert_str_eq(memchr(str_9, 'w', strlen(str_9)),
                   s21_memchr(str_9, 'w', s21_strlen(str_9)));
  ck_assert_str_eq(memchr(str_3, '\n', 6), s21_memchr(str_3, '\n', 6));
  ck_assert_ptr_eq(memchr(str_3, 'p', 2), s21_memchr(str_3, 'p', 2));
  ck_assert_str_eq(memchr(str_5, '\0', 4), s21_memchr(str_5, '\0', 4));
}
END_TEST

START_TEST(strchr_7) {
#line 100
  char str_1[10] = "\0";
  char str_7[50] = "Per aspera ad astra";
  char str_8[50] = "i am\nproger";
  char str_3[12] = "i am\nproger";
  char str_4[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  char str_10[] = "Hello";
  ck_assert_str_eq(strchr(str_10, 'o'), s21_strchr(str_10, 'o'));
  ck_assert_str_eq(strchr(str_1, '\0'), s21_strchr(str_1, '\0'));
  ck_assert_str_eq(strchr(str_3, '\n'), s21_strchr(str_3, '\n'));
  ck_assert_str_eq(strchr(str_5, ' '), s21_strchr(str_5, ' '));
  ck_assert_str_eq(strchr(str_6, 'a'), s21_strchr(str_6, 'a'));
  ck_assert_ptr_eq(strchr(str_7, '7'), s21_strchr(str_7, '7'));
}
END_TEST

START_TEST(strpbrk_8) {
#line 116
  char str_1[10] = "\0";
  char str_7[50] = "Per aspera ad astra";
  char str_8[50] = "i am\nproger";
  char str_3[12] = "i am\nproger";
  char str_4[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  char str_11[] = "Hello";
  char str_12[] = "lo";
  ck_assert_ptr_eq(strpbrk(str_1, str_7), s21_strpbrk(str_1, str_7));
  ck_assert_str_eq(strpbrk(str_11, str_12), s21_strpbrk(str_11, str_12));
  ck_assert_ptr_eq(strpbrk(str_8, str_6), s21_strpbrk(str_8, str_6));
  ck_assert_ptr_eq(strpbrk(str_4, str_8), s21_strpbrk(str_4, str_8));
  ck_assert_str_eq(strpbrk(str_5, str_6), s21_strpbrk(str_5, str_6));
  ck_assert_str_eq(strpbrk(str_3, str_6), s21_strpbrk(str_3, str_6));
}
END_TEST

START_TEST(strrchr_9) {
#line 133
  char str_1[10] = "\0";
  char str_7[50] = "Per aspera ad astra";
  char str_8[50] = "i am\nproger";
  char str_3[12] = "i am\nproger";
  char str_4[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  char str_13[150] = "Techie Delight – Ace the Technical Interviews";
  ck_assert_str_eq(strrchr(str_13, 'D'), s21_strrchr(str_13, 'D'));
  ck_assert_ptr_eq(strrchr(str_1, 'D'), s21_strrchr(str_1, 'D'));
  ck_assert_str_eq(strrchr(str_1, '\0'), s21_strrchr(str_1, '\0'));
  ck_assert_ptr_eq(strrchr(str_8, 'D'), s21_strrchr(str_8, 'D'));
  ck_assert_str_eq(strrchr(str_6, '\n'), s21_strrchr(str_6, '\n'));
  ck_assert_str_eq(strrchr(str_5, ' '), s21_strrchr(str_5, ' '));
}
END_TEST

START_TEST(strstr_10) {
#line 149
  char str_1[10] = "\0";
  char str_7[50] = "Per aspera ad astra";
  char str_8[50] = "i am\nproger";
  char str_3[12] = "i am\nproger";
  char str_4[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  char str_14[150] = "Techie Delight – Ace the Technical Interviews";
  char str_15[40] = "Ace";
  ck_assert_str_eq(strstr(str_14, str_15), s21_strstr(str_14, str_15));
  ck_assert_ptr_eq(strstr(str_1, str_4), s21_strstr(str_1, str_4));
  ck_assert_str_eq(strstr(str_7, "asp"), s21_strstr(str_7, "asp"));
  ck_assert_ptr_eq(strstr(str_7, "asq"), s21_strstr(str_7, "asq"));
  ck_assert_ptr_eq(strstr(str_5, str_6), s21_strstr(str_5, str_6));
  ck_assert_ptr_eq(strstr(str_3, str_6), s21_strstr(str_3, str_6));
  ck_assert_ptr_eq(strstr(str_3, str_1), s21_strstr(str_3, str_1));
}
END_TEST

START_TEST(memcmp_11) {
#line 167
  char str_1[10] = "\0";
  char str_7[50] = "Per aspera ad astra";
  char str_8[50] = "i am\nproger";
  char str_3[12] = "i am\nproger";
  char str_4[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  char str_16[40] = "abc";
  char str_17[40] = "bca";
  char str_36[40] = "Hello";
  char str_37[40] = "Hello";
  ck_assert_int_eq(memcmp(str_17, str_16, 2), s21_memcmp(str_17, str_16, 2));
  ck_assert_int_eq(memcmp(str_36, str_37, 3), s21_memcmp(str_36, str_37, 3));
  ck_assert_int_eq(memcmp(str_1, str_3, 3), s21_memcmp(str_1, str_3, 3));
  ck_assert_int_eq(memcmp(str_5, str_6, 10), s21_memcmp(str_5, str_6, 10));
  ck_assert_int_eq(memcmp(str_16, str_8, 3), s21_memcmp(str_16, str_8, 3));
  ck_assert_int_eq(memcmp(str_7, str_3, 3), s21_memcmp(str_7, str_3, 3));
  ck_assert_int_eq(memcmp(str_7, str_3, 0), s21_memcmp(str_7, str_3, 0));
}
END_TEST

START_TEST(strcmp_12) {
#line 187
  char str_1[10] = "\0";
  char str_7[50] = "Per aspera ad astra";
  char str_8[50] = "i am\nproger";
  char str_3[12] = "i am\nproger";
  char str_4[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  char str_18[40] = "Techie Delight – ";
  char str_19[40] = "Ace the Technical Interviews";
  char str_34[40] = "Techie";
  char str_35[40] = "Techie";
  ck_assert_int_eq(strcmp(str_8, str_3), s21_strcmp(str_8, str_3));
  ck_assert_int_eq(strcmp(str_18, str_8), s21_strcmp(str_18, str_8));
  ck_assert_int_eq(strcmp(str_8, str_18), s21_strcmp(str_8, str_18));
  ck_assert_int_eq(strcmp(str_18, str_19), s21_strcmp(str_18, str_19));
  ck_assert_int_eq(strcmp(str_34, str_35), s21_strcmp(str_34, str_35));
  ck_assert_int_eq(strcmp(str_1, str_3), s21_strcmp(str_1, str_3));
  ck_assert_int_eq(strcmp(str_5, str_6), s21_strcmp(str_5, str_6));
  ck_assert_int_eq(strcmp(str_7, str_3), s21_strcmp(str_7, str_3));
}
END_TEST

START_TEST(strncmp_13) {
#line 207
  char str_1[10] = "\0";
  char str_7[50] = "Per aspera ad astra";
  char str_8[50] = "i am\nproger";
  char str_3[12] = "i am\nproger";
  char str_4[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  char str_20[15] = "9234567890";
  char str_21[15] = "1234975654";
  char str_22[15] = "1234567890";
  char str_23[15] = "1234567890";
  char str_24[15] = "12345";
  char str_25[15] = "12345";
  ck_assert_int_eq(strncmp(str_20, str_21, 5), s21_strncmp(str_20, str_21, 5));
  ck_assert_int_eq(strncmp(str_24, str_25, 6), s21_strncmp(str_24, str_25, 6));
  ck_assert_int_eq(strncmp(str_22, str_23, 5), s21_strncmp(str_22, str_23, 5));
  ck_assert_int_eq(strncmp(str_1, str_3, 3), s21_strncmp(str_1, str_3, 3));
  ck_assert_int_eq(strncmp(str_5, str_6, 10), s21_strncmp(str_5, str_6, 10));
  ck_assert_int_eq(strncmp(str_6, str_8, 3), s21_strncmp(str_6, str_8, 3));
  ck_assert_int_eq(strncmp(str_7, str_3, 3), s21_strncmp(str_7, str_3, 3));
  ck_assert_int_eq(strncmp(str_7, str_3, 0), s21_strncmp(str_7, str_3, 0));
}
END_TEST

START_TEST(strerror_15) {
#line 251
  int num_1 = 0;
  int num_2 = 105;
  int num_4 = 254734;
  int num_3 = -2147483648;
  int num_5 = -21474;
  ck_assert_str_eq(strerror(num_1), s21_strerror(num_1));
  ck_assert_str_eq(strerror(num_2), s21_strerror(num_2));
  ck_assert_str_eq(strerror(num_3), s21_strerror(num_3));
  ck_assert_str_eq(strerror(num_4), s21_strerror(num_4));
  ck_assert_str_eq(strerror(num_5), s21_strerror(num_5));
}
END_TEST

START_TEST(strcat_16) {
#line 263
  char str_1[50] = "Hello";
  char str_2[50] = "Hello World";
  char str_3[50] = "\n\0";
  char str_4[50] = " \0";
  char str_5[50] = "\0";
  char str_6[50] = "a\n\0";
  char str_7[50] = " \n\0";
  char str_8[50] = "Hello world\0";
  char str_9[50] = "Hello world\n\0";
  ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
  ck_assert_str_eq(strcat(str_3, str_4), s21_strcat(str_3, str_4));
  ck_assert_str_eq(strcat(str_5, str_6), s21_strcat(str_5, str_6));
  ck_assert_str_eq(strcat(str_7, str_8), s21_strcat(str_7, str_8));
  ck_assert_str_eq(strcat(str_8, str_9), s21_strcat(str_8, str_9));
}
END_TEST

START_TEST(strncat_17) {
#line 279
  char str_30[100] = "Hello";
  char str_31[100] = " World";
  char str_1[10] = "\0";
  char str_7[50] = "Per aspera ad astra";
  char str_8[50] = "i am\nproger";
  char str_3[12] = "i am\nproger";
  char str_4[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  ck_assert_str_eq(strncat(str_30, str_31, 3), s21_strncat(str_30, str_31, 3));
  ck_assert_str_eq(strncat(str_1, str_3, 3), s21_strncat(str_1, str_3, 3));
  ck_assert_str_eq(strncat(str_5, str_6, 10), s21_strncat(str_5, str_6, 10));
  ck_assert_str_eq(strncat(str_6, str_8, 3), s21_strncat(str_6, str_8, 3));
  ck_assert_str_eq(strncat(str_7, str_3, 3), s21_strncat(str_7, str_3, 3));
  ck_assert_str_eq(strncat(str_7, str_3, 0), s21_strncat(str_7, str_3, 0));
}
END_TEST

START_TEST(strlen_18) {
#line 296
  char str_1[10] = "\0";
  char str_7[50] = "Per aspera ad astra";
  char str_8[50] = "i am\nproger";
  char str_3[12] = "i am\nproger";
  char str_4[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  char s1[] = "helo world";
  ck_assert_int_eq(strlen(str_1), s21_strlen(str_1));
  ck_assert_int_eq(strlen(s1), s21_strlen(s1));
  ck_assert_int_eq(strlen(str_7), s21_strlen(str_7));
  ck_assert_int_eq(strlen(str_8), s21_strlen(str_8));
  ck_assert_int_eq(strlen(str_5), s21_strlen(str_5));
  ck_assert_int_eq(strlen(str_6), s21_strlen(str_6));
  ck_assert_int_eq(strlen(str_3), s21_strlen(str_3));
}
END_TEST

START_TEST(strspn_19) {
#line 313
  char str_1[10] = "\0";
  char str_7[50] = "Per aspera ad astra";
  char str_8[50] = "i am\nproger";
  char str_3[12] = "i am\nproger";
  char str_4[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  char str_32[] = "23476";
  char str_33[] = "2345676780";
  ck_assert_int_eq(strspn(str_32, str_33), s21_strspn(str_32, str_33));
  ck_assert_int_eq(strspn(str_7, "ad"), s21_strspn(str_7, "ad"));
  ck_assert_int_eq(strspn(str_7, "Per"), s21_strspn(str_7, "Per"));
  ck_assert_int_eq(strspn(str_8, str_3), s21_strspn(str_8, str_3));
  ck_assert_int_eq(strspn(str_6, "\n"), s21_strspn(str_6, "\n"));
  ck_assert_int_eq(strspn(str_5, " \n"), s21_strspn(str_5, " \n"));
  ck_assert_int_eq(strspn(str_6, " a"), s21_strspn(str_6, " a"));
  ck_assert_int_eq(strspn(str_33, str_32), s21_strspn(str_33, str_32));
}
END_TEST

START_TEST(strcspn_20) {
#line 332
  char str_1[10] = "\0";
  char str_7[50] = "Per aspera ad astra";
  char str_8[50] = "i am\nproger";
  char str_3[12] = "i am\nproger";
  char str_4[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  char s2[] = "1sixtynine";
  char s3[] = "t";
  ck_assert_int_eq(strcspn(s2, s3), s21_strcspn(s2, s3));
  ck_assert_int_eq(strcspn(str_7, "ad"), s21_strcspn(str_7, "ad"));
  ck_assert_int_eq(strcspn(str_7, "Per"), s21_strcspn(str_7, "Per"));
  ck_assert_int_eq(strcspn(str_8, str_3), s21_strcspn(str_8, str_3));
  ck_assert_int_eq(strcspn(str_6, "\0"), s21_strcspn(str_6, "\0"));
  ck_assert_int_eq(strcspn(str_5, "\n\0"), s21_strcspn(str_5, "\n\0"));
  ck_assert_int_eq(strcspn(str_6, " a"), s21_strcspn(str_6, " a"));
  ck_assert_int_eq(strcspn(str_6, "\0"), s21_strcspn(str_6, "\0"));
  ck_assert_int_eq(strcspn(str_6, str_8), s21_strcspn(str_6, str_8));
}
END_TEST

START_TEST(sprintf_0) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%c", 'a');
  sprintf(str1, "%c", 'a');
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_1) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-c", 'a');
  sprintf(str1, "%-c", 'a');
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_2) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10c", 'a');
  sprintf(str1, "%10c", 'a');
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_3) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-2c", 'a');
  sprintf(str1, "%-2c", 'a');
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_4) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%c", '\0');
  sprintf(str1, "%c", '\0');
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_5) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-c", '\0');
  sprintf(str1, "%-c", '\0');
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_6) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10c", '\0');
  sprintf(str1, "%10c", '\0');
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_7) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-2c", '\0');
  sprintf(str1, "%-2c", '\0');
  ck_assert_str_eq(str, str1);
  // ПРОВЕРКА d
}
END_TEST

START_TEST(sprintf_8) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%d", 0);
  sprintf(str1, "%d", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_9) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.d", 0);
  sprintf(str1, "%.d", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_10) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10.d", 0);
  sprintf(str1, "%10.d", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_11) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10.2d", 0);
  sprintf(str1, "%10.2d", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_12) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-10.2d", 0);
  sprintf(str1, "%-10.2d", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_13) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-.2d", 0);
  sprintf(str1, "%-.2d", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_14) {
  char str[200];
  char str1[200];
  s21_sprintf(str, "%ld", 100000000000000000);
  sprintf(str1, "%ld", 100000000000000000);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_15) {
  char str[100];
  char str1[100];
  short int x = 400;
  s21_sprintf(str, "%hd", x);
  sprintf(str1, "%hd", x);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_16) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-5d", 0);
  sprintf(str1, "%-5d", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_17) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%5.d", 0);
  sprintf(str1, "%5.d", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_18) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-d", 0);
  sprintf(str1, "%-d", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_19) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%+d", 0);
  sprintf(str1, "%+d", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_22) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%3.5d", 20);
  sprintf(str1, "%3.5d", 20);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_23) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%3.5ld", -100000000000000000);
  sprintf(str1, "%3.5ld", -100000000000000000);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_24) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "% 3.7d", -666);
  sprintf(str1, "% 3.7d", -666);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_25) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%d", -1);
  sprintf(str1, "%d", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_26) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.d", -1);
  sprintf(str1, "%.d", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_27) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10.d", -1);
  sprintf(str1, "%10.d", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_28) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10.2d", -1);
  sprintf(str1, "%10.2d", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_29) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-10.2d", -1);
  sprintf(str1, "%-10.2d", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_30) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-.2d", -1);
  sprintf(str1, "%-.2d", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_31) {
  char str[200];
  char str1[200];
  s21_sprintf(str, "%ld", -1234852342345245);
  sprintf(str1, "%ld", -1234852342345245);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_32) {
  char str[100];
  char str1[100];
  short int x = -400;
  s21_sprintf(str, "%hd", x);
  sprintf(str1, "%hd", x);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_33) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-5d", -1);
  sprintf(str1, "%-5d", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_34) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%5d", -1);
  sprintf(str1, "%5d", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_35) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-d", -1);
  sprintf(str1, "%-d", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_36) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%+d", -1);
  sprintf(str1, "%+d", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_37) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%u", 0);
  sprintf(str1, "%u", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_38) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.u", 0);
  sprintf(str1, "%.u", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_39) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10.u", 0);
  sprintf(str1, "%10.u", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_40) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10.2u", 0);
  sprintf(str1, "%10.2u", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_41) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-10.2u", 0);
  sprintf(str1, "%-10.2u", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_42) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-.2u", 0);
  sprintf(str1, "%-.2u", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_43) {
  char str[200];
  char str1[200];
  s21_sprintf(str, "%lu", 100000000000000000);
  sprintf(str1, "%lu", 100000000000000000);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_44) {
  char str[100];
  char str1[100];
  short int x = 400;
  s21_sprintf(str, "%hu", x);
  sprintf(str1, "%hu", x);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_45) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-5u", 0);
  sprintf(str1, "%-5u", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_46) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%5u", 0);
  sprintf(str1, "%5u", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_47) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-u", 0);
  sprintf(str1, "%-u", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_50) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%3.5u", 20);
  sprintf(str1, "%3.5u", 20);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_51) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%3.5lu", -100000000000000000);
  sprintf(str1, "%3.5lu", -100000000000000000);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_52) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%u", -1);
  sprintf(str1, "%u", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_53) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.u", -1);
  sprintf(str1, "%.u", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_54) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10.u", -1);
  sprintf(str1, "%10.u", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_55) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10.2u", -1);
  sprintf(str1, "%10.2u", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_56) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-10.2u", -1);
  sprintf(str1, "%-10.2u", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_57) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-.2u", -1);
  sprintf(str1, "%-.2u", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_58) {
  char str[200];
  char str1[200];
  s21_sprintf(str, "%lu", -12348523423452);
  sprintf(str1, "%lu", -12348523423452);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_59) {
  char str[100];
  char str1[100];
  short int x = -400;
  s21_sprintf(str, "%hu", x);
  sprintf(str1, "%hu", x);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_60) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-5u", -1);
  sprintf(str1, "%-5u", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_61) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%5u", -1);
  sprintf(str1, "%5u", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_62) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-u", -1);
  sprintf(str1, "%-u", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_63) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%i", 0);
  sprintf(str1, "%i", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_64) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.i", 0);
  sprintf(str1, "%.i", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_65) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10.i", 0);
  sprintf(str1, "%10.i", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_66) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10.2i", 0);
  sprintf(str1, "%10.2i", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_67) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-10.2i", 0);
  sprintf(str1, "%-10.2i", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_68) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-.2i", 0);
  sprintf(str1, "%-.2i", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_69) {
  char str[200];
  char str1[200];
  s21_sprintf(str, "%li", 100000000000000000);
  sprintf(str1, "%li", 100000000000000000);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_70) {
  char str[100];
  char str1[100];
  short int x = 400;
  s21_sprintf(str, "%hi", x);
  sprintf(str1, "%hi", x);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_71) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-5i", 0);
  sprintf(str1, "%-5i", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_72) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%5i", 0);
  sprintf(str1, "%5i", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_73) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-i", 0);
  sprintf(str1, "%-i", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_74) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%+i", 0);
  sprintf(str1, "%+i", 0);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_77) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%3.5i", 20);
  sprintf(str1, "%3.5i", 20);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_78) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%3.5li", -100000000000000000);
  sprintf(str1, "%3.5li", -100000000000000000);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_79) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "% 3.7i", -666);
  sprintf(str1, "% 3.7i", -666);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_80) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%i", -1);
  sprintf(str1, "%i", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_81) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.i", -1);
  sprintf(str1, "%.i", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_82) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10.i", -1);
  sprintf(str1, "%10.i", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_83) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10.2i", -1);
  sprintf(str1, "%10.2i", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_84) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-10.2i", -1);
  sprintf(str1, "%-10.2i", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_85) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-.2i", -1);
  sprintf(str1, "%-.2i", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_86) {
  char str[200];
  char str1[200];
  s21_sprintf(str, "%li", -1234852342345245);
  sprintf(str1, "%li", -1234852342345245);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_87) {
  char str[100];
  char str1[100];
  short int x = -400;
  s21_sprintf(str, "%hi", x);
  sprintf(str1, "%hi", x);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_88) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-5i", -1);
  sprintf(str1, "%-5i", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_89) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%5i", -1);
  sprintf(str1, "%5i", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_90) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-i", -1);
  sprintf(str1, "%-i", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_91) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%+i", -1);
  sprintf(str1, "%+i", -1);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_92) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%f", 1337.228);
  sprintf(str1, "%f", 1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_93) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10f", 1337.228);
  sprintf(str1, "%10f", 1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_94) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10.2f", 1337.228);
  sprintf(str1, "%10.2f", 1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_95) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10.12f", 1337.228);
  sprintf(str1, "%10.12f", 1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_96) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-1.12f", 1337.228);
  sprintf(str1, "%-1.12f", 1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_97) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.12f", 1337.228);
  sprintf(str1, "%.12f", 1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_98) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "% 12f", 1337.228);
  sprintf(str1, "% 12f", 1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_99) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%+12f", 1337.228);
  sprintf(str1, "%+12f", 1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_100) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.0f", 1337.228);
  sprintf(str1, "%.0f", 1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_101) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.5f", 1337.228);
  sprintf(str1, "%.5f", 1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_102) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%3.5f", 1337.228);
  sprintf(str1, "%3.5f", 1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_103) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%30.12f", 1337.228);
  sprintf(str1, "%30.12f", 1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_104) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-30.12f", 1337.228);
  sprintf(str1, "%-30.12f", 1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_105) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "% 02.12f", 1337.228);
  sprintf(str1, "% 02.12f", 1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_106) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%f", -1337.228);
  sprintf(str1, "%f", -1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_107) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10f", -1337.228);
  sprintf(str1, "%10f", -1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_108) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10.2f", -1337.228);
  sprintf(str1, "%10.2f", -1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_109) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%10.12f", -1337.228);
  sprintf(str1, "%10.12f", -1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_110) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-1.12f", -1337.228);
  sprintf(str1, "%-1.12f", -1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_111) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.12f", -1337.228);
  sprintf(str1, "%.12f", -1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_112) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "% 20f", -1337.228);
  sprintf(str1, "% 20f", -1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_113) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%+20f", -1337.228);
  sprintf(str1, "%+20f", -1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_114) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.0f", -1337.228);
  sprintf(str1, "%.0f", -1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_115) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.5f", -1337.228);
  sprintf(str1, "%.5f", -1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_116) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%3.5f", -1337.228);
  sprintf(str1, "%3.5f", -1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_117) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%30.12f", -1337.228);
  sprintf(str1, "%30.12f", -1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_118) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-30.12f", -1337.228);
  sprintf(str1, "%-30.12f", -1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_119) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "% 02.12f", -1337.228);
  sprintf(str1, "% 02.12f", -1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_120) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%s", "ABOBA");
  sprintf(str1, "%s", "ABOBA");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_121) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-s", "ABOBA");
  sprintf(str1, "%-s", "ABOBA");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_122) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%20s", "ABOBA");
  sprintf(str1, "%20s", "ABOBA");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_123) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%20s", "123456789");
  sprintf(str1, "%20s", "123456789");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_124) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%3s", "A B O B A");
  sprintf(str1, "%3s", "A B O B A");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_125) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-3s", "A B O B A");
  sprintf(str1, "%-3s", "A B O B A");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_126) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.5s", "A B O B A");
  sprintf(str1, "%.5s", "A B O B A");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_127) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.25s", "A B O B A");
  sprintf(str1, "%.25s", "A B O B A");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_128) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.s", "A B O B A");
  sprintf(str1, "%.s", "A B O B A");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_129) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-.5s", "SampleText");
  sprintf(str1, "%-.5s", "SampleText");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_130) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%5.10s", "SampleText");
  sprintf(str1, "%5.10s", "SampleText");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_131) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%5.1s", "SampleText");
  sprintf(str1, "%5.1s", "SampleText");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_132) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-5.1s", "SampleText");
  sprintf(str1, "%-5.1s", "SampleText");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_133) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-5.0s", "SampleText");
  sprintf(str1, "%-5.0s", "SampleText");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_134) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%s", "\0\0\0\0\0\0");
  sprintf(str1, "%s", "\0\0\0\0\0\0");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_135) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-s", "\0\0\0\0\0\0");
  sprintf(str1, "%-s", "\0\0\0\0\0\0");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_136) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%20s", "\0\0\0\0\0\0");
  sprintf(str1, "%20s", "\0\0\0\0\0\0");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_137) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%20s", "\0\0\0\0\0\0");
  sprintf(str1, "%20s", "\0\0\0\0\0\0");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_138) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%3s", "\0\0\0\0\0\0");
  sprintf(str1, "%3s", "\0\0\0\0\0\0");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_139) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-3s", "\0\0\0\0\0\0");
  sprintf(str1, "%-3s", "\0\0\0\0\0\0");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_140) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.5s", "\0\0\0\0\0\0");
  sprintf(str1, "%.5s", "\0\0\0\0\0\0");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_141) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.25s", "\0\0\0\0\0\0");
  sprintf(str1, "%.25s", "\0\0\0\0\0\0");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_142) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.s", "\0\0\0\0\0\0");
  sprintf(str1, "%.s", "\0\0\0\0\0\0");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_143) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-.5s", "\0\0\0\0\0\0\0");
  sprintf(str1, "%-.5s", "\0\0\0\0\0\0\0");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_144) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%5.10s", "\0\0\0\0\0\0\0");
  sprintf(str1, "%5.10s", "\0\0\0\0\0\0\0");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_145) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%5.1s", "\0\0\0\0\0\0\0");
  sprintf(str1, "%5.1s", "\0\0\0\0\0\0\0");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_146) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-5.1s", "\0\0\0\0\0\0\0");
  sprintf(str1, "%-5.1s", "\0\0\0\0\0\0\0");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_147) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-5.0s", "\0\0\0\0\0\0\0");
  sprintf(str1, "%-5.0s", "\0\0\0\0\0\0\0");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_148) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%s", "");
  sprintf(str1, "%s", "");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_149) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-s", "");
  sprintf(str1, "%-s", "");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_150) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%20s", "");
  sprintf(str1, "%20s", "");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_151) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%20s", "");
  sprintf(str1, "%20s", "");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_152) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%3s", "");
  sprintf(str1, "%3s", "");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_153) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-3s", "");
  sprintf(str1, "%-3s", "");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_154) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.5s", "");
  sprintf(str1, "%.5s", "");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_155) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.25s", "");
  sprintf(str1, "%.25s", "");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_156) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.s", "");
  sprintf(str1, "%.s", "");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_157) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-.5s", "");
  sprintf(str1, "%-.5s", "");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_158) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%5.10s", "");
  sprintf(str1, "%5.10s", "");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_159) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%5.1s", "");
  sprintf(str1, "%5.1s", "");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_160) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-5.1s", "");
  sprintf(str1, "%-5.1s", "");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_161) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%-5.0s", "");
  sprintf(str1, "%-5.0s", "");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_162) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%%");
  sprintf(str1, "%%");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_163) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%%");
  sprintf(str1, "%%");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_164) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%%%+.d%.1u%+.i%+.f%.4s", 21, -42, 0xF1AC, -2313.1313,
              "it will go");
  sprintf(str1, "%%%+.d%.1u%+.i%+.f%.4s", 21, -42, 0xF1AC, -2313.1313,
          "it will go");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_165) {
  char str[100];
  char str1[100];
  for (int i = -101; i <= 101;) {
    s21_sprintf(str1, "% -i % -d % -5d", i, i + 1, 143646235);
    sprintf(str, "% -i % -d % -5d", i, i + 1, 143646235);
    i += 7;
    ck_assert_str_eq(str, str1);
  }
}
END_TEST

START_TEST(sprintf_166) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.f", 56.7);
  sprintf(str1, "%.f", 56.7);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_167) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.f", 56.2);
  sprintf(str1, "%.f", 56.2);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_168) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%.f", 5634.9);
  sprintf(str1, "%.f", 5634.9);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_169) {
  char data[200];
  char data1[200];
  s21_sprintf(data, "%lc", 'c');
  sprintf(data1, "%lc", 'c');
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(sprintf_170) {
  char data[1000];
  char data1[1000];
  wchar_t buf[100] = L"hello";
  s21_sprintf(data, "%ls", buf);
  sprintf(data1, "%ls", buf);
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(sprintf_171) {
  char str[100];
  char str1[100];
  s21_sprintf(str, "%f", 1337.228);
  sprintf(str1, "%f", 1337.228);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(sprintf_172) {
  char data[1000];
  char data1[1000];
  wchar_t buf[100] = L"hello";
  s21_sprintf(data, "%-ls", buf);
  sprintf(data1, "%-ls", buf);
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(sprintf_173) {
  char data[1000];
  char data1[1000];
  wchar_t buf[100] = L"hello";
  s21_sprintf(data, "%-.5ls", buf);
  sprintf(data1, "%-.5ls", buf);
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(sprintf_174) {
  char data[1000];
  char data1[1000];
  wchar_t buf[100] = L"helloooooooooooooooooo";
  s21_sprintf(data, "%-.8ls", buf);
  sprintf(data1, "%-.8ls", buf);
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(simple_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(precise_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(star_precision_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_short_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_another_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(zero_precision_zero_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(space_flag_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0f %.lf %f %lf";
  float val = 0;
  double val1 = 0;
  // long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  // long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val3, val4),
                   sprintf(str2, format, val, val1, val3, val4));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(all_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(empty_format_and_parameters) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%li%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf12) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-11.11li%-35.5lu%-3.5ld%33.8f";
  double k = 333.33213;

  ck_assert_int_eq(
      s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
      sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf14) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf15) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf16) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf17) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf18) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf19) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf20) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf24) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                  "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf25) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf28) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int a = s21_sprintf(str1, "%d", 123);
  int b = sprintf(str2, "%d", 123);

  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf29) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf30) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %5c";
  char w = 'c';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}

// START_TEST(wide_string2) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %120ls ABOBA";
//   wchar_t w[] = L"森我爱菠萝";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST

START_TEST(sprintf_simple_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_precise_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_minus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_plus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_short_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_zero_precision_zero_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_space_flag_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_all_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_empty_format_and_parameters) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_char_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%li%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf12) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-11.11li%-35.5lu%-3.5ld%33.12lf";
  double k = 333.33213;

  ck_assert_int_eq(
      s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
      sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf16) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf17) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf18) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf19) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf20) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf24) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                  "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf25) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf26) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%%";

  ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf27) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%%%%%%%%";

  ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf29) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf30) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_wide_string2) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %120ls ABOBA";
//   wchar_t w[] = L"森我爱菠萝";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(sprintf_wide_string4) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %43ls";
//   wchar_t w[] = L"森我爱菠萝";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(sprintf_wide_char2) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %43lc";
//   unsigned long w = L'森';
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_int_eq(a, b);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(to_lower_21) {
  const char *str_1 = "ADF";
  const char *str_2 = "adf";
  const char *str_3 = s21_NULL;
  const char *str_4 = "ломай меня полностью";
  char *res = s21_to_lower(str_1);
  char *res1 = s21_to_lower(str_4);
  char *res2 = s21_to_lower(str_3);
  ck_assert_str_eq(str_2, res);
  ck_assert_ptr_eq(str_3, res1);
  ck_assert_ptr_eq(str_3, res2);
  free(res);
}
END_TEST

START_TEST(to_upper_22) {
  const char *str_1 = "ADF";
  const char *str_2 = "adf";
  const char *str_3 = s21_NULL;
  const char *str_4 = "ломай меня полностью";
  char *res = s21_to_upper(str_2);
  char *res1 = s21_to_upper(str_4);
  char *res2 = s21_to_upper(str_3);
  ck_assert_str_eq(str_1, res);
  ck_assert_ptr_eq(str_3, res1);
  ck_assert_ptr_eq(str_3, res2);
  free(res);
}
END_TEST

START_TEST(insert_23) {
  const char *str_1 = "ADF";
  const char *str_2 = "adf";
  const char *str_3 = "ADadfF";
  s21_size_t index_1 = 2;
  const char *str_666 = s21_NULL;
  char *res = s21_insert(str_1, str_2, index_1);
  char *res1 = s21_insert(str_666, str_2, index_1);
  ck_assert_str_eq(str_3, res);
  ck_assert_ptr_eq(str_666, s21_insert(str_666, str_2, index_1));
  free(res);
}
END_TEST

START_TEST(trim_24) {
  const char *str_1 = "adf";
  const char *str_2 = "af";
  const char *str_3 = "d";
  const char *str_666 = s21_NULL;
  char *res = s21_trim(str_1, str_2);
  char *res1 = s21_trim(str_666, str_2);
  ck_assert_str_eq(str_3, res);
  ck_assert_ptr_eq(str_666, res1);
  free(res);
}
END_TEST

START_TEST(str_tok_1) {
  char str_1[250] = "adf awe";
  char *str_2 = " ";
  char str_3[250] = "adf awe";
  char *str_666 = s21_NULL;
  char *res1 = strtok(str_1, str_2);
  char *res2 = s21_strtok(str_3, str_2);
  ck_assert_pstr_eq(res1, res2);
  while (res1 != str_666) {
    res1 = strtok(str_666, str_2);
    res2 = s21_strtok(str_666, str_2);
    ck_assert_pstr_eq(res1, res2);
  }
}
END_TEST

START_TEST(str_tok_2) {
  char str_1[250] = "   ";
  char *str_2 = " ";
  char str_3[250] = "   ";
  char *res1 = strtok(str_1, str_2);
  char *res2 = s21_strtok(str_3, str_2);
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_test_sprint_666) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-5.10u";

  s21_sprintf(str1, format, 111);
  sprintf(str2, format, 111);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_667) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-5.10lu";

  s21_sprintf(str1, format, 111);
  sprintf(str2, format, 111);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_671) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 2.5d";

  s21_sprintf(str1, format, 11);
  sprintf(str2, format, 11);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_672) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%lu";

  s21_sprintf(str1, format, ULONG_MAX);
  sprintf(str2, format, ULONG_MAX);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_673) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%ld";

  s21_sprintf(str1, format, LONG_MIN);
  sprintf(str2, format, LONG_MIN);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_674) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%ld";

  s21_sprintf(str1, format, LONG_MAX);
  sprintf(str2, format, LONG_MAX);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_675) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%d";

  s21_sprintf(str1, format, INT_MIN);
  sprintf(str2, format, INT_MIN);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_676) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%d";

  s21_sprintf(str1, format, INT_MAX);
  sprintf(str2, format, INT_MAX);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_677) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%d";
  int min = -2147483648;

  s21_sprintf(str1, format, min);
  sprintf(str2, format, min);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_678) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.4ld";

  s21_sprintf(str1, format, 1);
  sprintf(str2, format, 1);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_679) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7ld";

  s21_sprintf(str1, format, 1);
  sprintf(str2, format, 1);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_680) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.4lu";

  s21_sprintf(str1, format, 1);
  sprintf(str2, format, 1);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_681) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7lu";

  s21_sprintf(str1, format, 1);
  sprintf(str2, format, 1);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_682) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.4ld";
  long long int min_i = -1;

  s21_sprintf(str1, format, min_i);
  sprintf(str2, format, min_i);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_683) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-7.4ld";
  long long int min_i = -1;

  s21_sprintf(str1, format, min_i);
  sprintf(str2, format, min_i);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_684) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%10f";

  s21_sprintf(str1, format, 43.123);
  sprintf(str2, format, 43.123);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_685) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.-2f";

  s21_sprintf(str1, format, 43.123);
  sprintf(str2, format, 43.123);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_687) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  wchar_t w[] = L"森我爱菠";
  char format[] = "%.0ls";

  s21_sprintf(str1, format, w);
  sprintf(str2, format, w);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_688) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char format[] = "%-24.0f";

  s21_sprintf(str1, format, 43.12);
  sprintf(str2, format, 43.12);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_689) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  wchar_t w[] = L"森我爱菠";
  char format[] = "%25.0ls";

  s21_sprintf(str1, format, w);
  sprintf(str2, format, w);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_690) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  wchar_t w[] = L"森我爱菠";
  char format[] = "%-25.0ls";

  s21_sprintf(str1, format, w);
  sprintf(str2, format, w);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_691) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  wchar_t w[] = L"森我爱菠";
  char format[] = "%-25.ls";

  s21_sprintf(str1, format, w);
  sprintf(str2, format, w);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprint_692) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  wchar_t w[] = L"森我爱菠";
  char format[] = "%25.ls";

  s21_sprintf(str1, format, w);
  sprintf(str2, format, w);

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_test_sprint_693) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   wchar_t w[] = L"森我爱菠";
//   char format[] = "%25ls";

//   s21_sprintf(str1, format, w);
//   sprintf(str2, format, w);

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(sprintf_test_sprint_694) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  wchar_t w[] = L"森我爱菠";
  char format[] = "%-25ls";

  s21_sprintf(str1, format, w);
  sprintf(str2, format, w);

  ck_assert_str_eq(str1, str2);
}
END_TEST

int main(void) {
  Suite *s25;
  TCase *tc;
  s25 = suite_create("s21_SPRINTF");
  tc = tcase_create("case_sprintf");
  SRunner *sr = srunner_create(s25);
  int nf;

  suite_add_tcase(s25, tc);

  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memmove_2);
  tcase_add_test(tc, memset_3);
  tcase_add_test(tc, strcpy_4);
  tcase_add_test(tc, strncpy_5);
  tcase_add_test(tc, memchr_6);
  tcase_add_test(tc, strchr_7);
  tcase_add_test(tc, strpbrk_8);
  tcase_add_test(tc, strrchr_9);
  tcase_add_test(tc, strstr_10);
  tcase_add_test(tc, memcmp_11);
  tcase_add_test(tc, strcmp_12);
  tcase_add_test(tc, strncmp_13);
  tcase_add_test(tc, strerror_15);
  tcase_add_test(tc, strcat_16);
  tcase_add_test(tc, strncat_17);
  tcase_add_test(tc, strlen_18);
  tcase_add_test(tc, strspn_19);
  tcase_add_test(tc, strcspn_20);

  tcase_add_test(tc, sprintf_0);
  tcase_add_test(tc, sprintf_1);
  tcase_add_test(tc, sprintf_2);
  tcase_add_test(tc, sprintf_3);
  tcase_add_test(tc, sprintf_4);
  tcase_add_test(tc, sprintf_5);
  tcase_add_test(tc, sprintf_6);
  tcase_add_test(tc, sprintf_7);
  tcase_add_test(tc, sprintf_8);
  tcase_add_test(tc, sprintf_9);
  tcase_add_test(tc, sprintf_10);
  tcase_add_test(tc, sprintf_11);
  tcase_add_test(tc, sprintf_12);
  tcase_add_test(tc, sprintf_13);
  tcase_add_test(tc, sprintf_14);
  tcase_add_test(tc, sprintf_15);
  tcase_add_test(tc, sprintf_16);
  tcase_add_test(tc, sprintf_17);
  tcase_add_test(tc, sprintf_18);
  tcase_add_test(tc, sprintf_19);
  tcase_add_test(tc, sprintf_22);
  tcase_add_test(tc, sprintf_23);
  tcase_add_test(tc, sprintf_24);
  tcase_add_test(tc, sprintf_25);
  tcase_add_test(tc, sprintf_26);
  tcase_add_test(tc, sprintf_27);
  tcase_add_test(tc, sprintf_28);
  tcase_add_test(tc, sprintf_29);
  tcase_add_test(tc, sprintf_30);
  tcase_add_test(tc, sprintf_31);
  tcase_add_test(tc, sprintf_32);
  tcase_add_test(tc, sprintf_33);
  tcase_add_test(tc, sprintf_34);
  tcase_add_test(tc, sprintf_35);
  tcase_add_test(tc, sprintf_36);
  tcase_add_test(tc, sprintf_37);
  tcase_add_test(tc, sprintf_38);
  tcase_add_test(tc, sprintf_39);
  tcase_add_test(tc, sprintf_40);
  tcase_add_test(tc, sprintf_41);
  tcase_add_test(tc, sprintf_42);
  tcase_add_test(tc, sprintf_43);
  tcase_add_test(tc, sprintf_44);
  tcase_add_test(tc, sprintf_45);
  tcase_add_test(tc, sprintf_46);
  tcase_add_test(tc, sprintf_47);
  tcase_add_test(tc, sprintf_50);
  tcase_add_test(tc, sprintf_51);
  tcase_add_test(tc, sprintf_52);
  tcase_add_test(tc, sprintf_53);
  tcase_add_test(tc, sprintf_54);
  tcase_add_test(tc, sprintf_55);
  tcase_add_test(tc, sprintf_56);
  tcase_add_test(tc, sprintf_57);
  tcase_add_test(tc, sprintf_58);
  tcase_add_test(tc, sprintf_59);
  tcase_add_test(tc, sprintf_60);
  tcase_add_test(tc, sprintf_61);
  tcase_add_test(tc, sprintf_62);
  tcase_add_test(tc, sprintf_63);
  tcase_add_test(tc, sprintf_64);
  tcase_add_test(tc, sprintf_65);
  tcase_add_test(tc, sprintf_66);
  tcase_add_test(tc, sprintf_67);
  tcase_add_test(tc, sprintf_68);
  tcase_add_test(tc, sprintf_69);
  tcase_add_test(tc, sprintf_70);
  tcase_add_test(tc, sprintf_71);
  tcase_add_test(tc, sprintf_72);
  tcase_add_test(tc, sprintf_73);
  tcase_add_test(tc, sprintf_74);
  tcase_add_test(tc, sprintf_77);
  tcase_add_test(tc, sprintf_78);
  tcase_add_test(tc, sprintf_79);
  tcase_add_test(tc, sprintf_80);
  tcase_add_test(tc, sprintf_81);
  tcase_add_test(tc, sprintf_82);
  tcase_add_test(tc, sprintf_83);
  tcase_add_test(tc, sprintf_84);
  tcase_add_test(tc, sprintf_85);
  tcase_add_test(tc, sprintf_86);
  tcase_add_test(tc, sprintf_87);
  tcase_add_test(tc, sprintf_88);
  tcase_add_test(tc, sprintf_89);
  tcase_add_test(tc, sprintf_90);
  tcase_add_test(tc, sprintf_91);
  tcase_add_test(tc, sprintf_92);
  tcase_add_test(tc, sprintf_93);
  tcase_add_test(tc, sprintf_94);
  tcase_add_test(tc, sprintf_95);
  tcase_add_test(tc, sprintf_96);
  tcase_add_test(tc, sprintf_97);
  tcase_add_test(tc, sprintf_98);
  tcase_add_test(tc, sprintf_99);
  tcase_add_test(tc, sprintf_100);
  tcase_add_test(tc, sprintf_101);
  tcase_add_test(tc, sprintf_102);
  tcase_add_test(tc, sprintf_103);
  tcase_add_test(tc, sprintf_104);
  tcase_add_test(tc, sprintf_105);
  tcase_add_test(tc, sprintf_106);
  tcase_add_test(tc, sprintf_107);
  tcase_add_test(tc, sprintf_108);
  tcase_add_test(tc, sprintf_109);
  tcase_add_test(tc, sprintf_110);
  tcase_add_test(tc, sprintf_111);
  tcase_add_test(tc, sprintf_112);
  tcase_add_test(tc, sprintf_113);
  tcase_add_test(tc, sprintf_114);
  tcase_add_test(tc, sprintf_115);
  tcase_add_test(tc, sprintf_116);
  tcase_add_test(tc, sprintf_117);
  tcase_add_test(tc, sprintf_118);
  tcase_add_test(tc, sprintf_119);
  tcase_add_test(tc, sprintf_120);
  tcase_add_test(tc, sprintf_121);
  tcase_add_test(tc, sprintf_122);
  tcase_add_test(tc, sprintf_123);
  tcase_add_test(tc, sprintf_124);
  tcase_add_test(tc, sprintf_125);
  tcase_add_test(tc, sprintf_126);
  tcase_add_test(tc, sprintf_127);
  tcase_add_test(tc, sprintf_128);
  tcase_add_test(tc, sprintf_129);
  tcase_add_test(tc, sprintf_130);
  tcase_add_test(tc, sprintf_131);
  tcase_add_test(tc, sprintf_132);
  tcase_add_test(tc, sprintf_133);
  tcase_add_test(tc, sprintf_134);
  tcase_add_test(tc, sprintf_135);
  tcase_add_test(tc, sprintf_136);
  tcase_add_test(tc, sprintf_137);
  tcase_add_test(tc, sprintf_138);
  tcase_add_test(tc, sprintf_139);
  tcase_add_test(tc, sprintf_140);
  tcase_add_test(tc, sprintf_141);
  tcase_add_test(tc, sprintf_142);
  tcase_add_test(tc, sprintf_143);
  tcase_add_test(tc, sprintf_144);
  tcase_add_test(tc, sprintf_145);
  tcase_add_test(tc, sprintf_146);
  tcase_add_test(tc, sprintf_147);
  tcase_add_test(tc, sprintf_148);
  tcase_add_test(tc, sprintf_149);
  tcase_add_test(tc, sprintf_150);
  tcase_add_test(tc, sprintf_151);
  tcase_add_test(tc, sprintf_152);
  tcase_add_test(tc, sprintf_153);
  tcase_add_test(tc, sprintf_154);
  tcase_add_test(tc, sprintf_155);
  tcase_add_test(tc, sprintf_156);
  tcase_add_test(tc, sprintf_157);
  tcase_add_test(tc, sprintf_158);
  tcase_add_test(tc, sprintf_159);
  tcase_add_test(tc, sprintf_160);
  tcase_add_test(tc, sprintf_161);
  tcase_add_test(tc, sprintf_162);
  tcase_add_test(tc, sprintf_163);
  tcase_add_test(tc, sprintf_164);
  tcase_add_test(tc, sprintf_165);
  tcase_add_test(tc, sprintf_166);
  tcase_add_test(tc, sprintf_167);
  tcase_add_test(tc, sprintf_168);
  tcase_add_test(tc, sprintf_169);
  tcase_add_test(tc, sprintf_170);
  tcase_add_test(tc, sprintf_171);
  tcase_add_test(tc, sprintf_172);
  tcase_add_test(tc, sprintf_173);
  tcase_add_test(tc, sprintf_174);

  tcase_add_test(tc, sprintf_simple_int);
  tcase_add_test(tc, sprintf_precise_int);
  tcase_add_test(tc, sprintf_width_int);
  tcase_add_test(tc, sprintf_minus_width_int);
  tcase_add_test(tc, sprintf_plus_width_int);
  tcase_add_test(tc, sprintf_flags_short_int);
  tcase_add_test(tc, sprintf_zero_precision_zero_int);
  tcase_add_test(tc, sprintf_space_flag_int);
  tcase_add_test(tc, sprintf_unsigned_val);
  tcase_add_test(tc, sprintf_unsigned_val_width);
  tcase_add_test(tc, sprintf_unsigned_val_flags);
  tcase_add_test(tc, sprintf_unsigned_val_precision);
  tcase_add_test(tc, sprintf_unsigned_val_many_flags);
  tcase_add_test(tc, sprintf_unsigned_val_short);
  tcase_add_test(tc, sprintf_unsigned_val_long);
  tcase_add_test(tc, sprintf_unsigned_val_many);

  tcase_add_test(tc, sprintf_octal_short);
  tcase_add_test(tc, sprintf_unsigned_zero);
  tcase_add_test(tc, sprintf_one_char);
  tcase_add_test(tc, sprintf_one_precision);
  tcase_add_test(tc, sprintf_one_flags);
  tcase_add_test(tc, sprintf_one_width);
  tcase_add_test(tc, sprintf_one_many);
  tcase_add_test(tc, sprintf_one_many_flags);
  tcase_add_test(tc, sprintf_string);
  tcase_add_test(tc, sprintf_string_precision);
  tcase_add_test(tc, sprintf_string_width);
  tcase_add_test(tc, sprintf_string_flags);
  tcase_add_test(tc, sprintf_string_long);
  tcase_add_test(tc, sprintf_string_many);
  tcase_add_test(tc, sprintf_string_width_huge);
  tcase_add_test(tc, sprintf_float_flags);
  tcase_add_test(tc, sprintf_all_empty);
  tcase_add_test(tc, sprintf_empty_format_and_parameters);
  tcase_add_test(tc, sprintf_test_one_char);
  tcase_add_test(tc, sprintf_test_many_char);
  tcase_add_test(tc, sprintf_test_one_string);
  tcase_add_test(tc, sprintf_test_many_string);
  tcase_add_test(tc, sprintf_test_one_dec);
  tcase_add_test(tc, sprintf_test_many_dec);
  tcase_add_test(tc, sprintf_test_one_int);
  tcase_add_test(tc, sprintf_test_many_int);
  tcase_add_test(tc, sprintf_test_one_float);
  tcase_add_test(tc, sprintf_test_many_float);
  tcase_add_test(tc, sprintf_test_one_unsigned_dec);
  tcase_add_test(tc, sprintf_test_many_unsigned_dec);
  tcase_add_test(tc, sprintf_test_one_char_with_alignment_left);
  tcase_add_test(tc, sprintf_test_one_char_with_alignment_right);
  tcase_add_test(tc, sprintf_test_many_char_with_alignment);
  tcase_add_test(tc, sprintf_test_sprintf1);
  tcase_add_test(tc, sprintf_test_sprintf2);
  tcase_add_test(tc, sprintf_test_sprintf3);
  tcase_add_test(tc, sprintf_test_sprintf4);
  tcase_add_test(tc, sprintf_test_sprintf6);
  tcase_add_test(tc, sprintf_test_sprintf7);
  tcase_add_test(tc, sprintf_test_sprintf8);
  tcase_add_test(tc, sprintf_test_sprintf9);
  tcase_add_test(tc, sprintf_test_sprintf10);
  tcase_add_test(tc, sprintf_test_sprintf11);
  tcase_add_test(tc, sprintf_test_sprintf12);
  tcase_add_test(tc, sprintf_test_sprintf16);
  tcase_add_test(tc, sprintf_test_sprintf17);
  tcase_add_test(tc, sprintf_test_sprintf18);
  tcase_add_test(tc, sprintf_test_sprintf19);
  tcase_add_test(tc, sprintf_test_sprintf20);
  tcase_add_test(tc, sprintf_test_sprintf24);
  tcase_add_test(tc, sprintf_test_sprintf25);
  tcase_add_test(tc, sprintf_test_sprintf29);
  tcase_add_test(tc, sprintf_test_sprintf30);
  tcase_add_test(tc, sprintf_test_sprintf26);
  tcase_add_test(tc, sprintf_test_sprintf27);
  // tcase_add_test(tc, sprintf_wide_string2);
  // tcase_add_test(tc, sprintf_wide_string4);
  // tcase_add_test(tc, sprintf_wide_char2);
  tcase_add_test(tc, sprintf_flags_long_int);

  tcase_add_test(tc, simple_int);
  tcase_add_test(tc, precise_int);
  tcase_add_test(tc, width_int);
  tcase_add_test(tc, minus_width_int);
  tcase_add_test(tc, plus_width_int);
  tcase_add_test(tc, star_precision_int);
  tcase_add_test(tc, flags_long_int);
  tcase_add_test(tc, flags_short_int);
  tcase_add_test(tc, flags_another_long_int);
  tcase_add_test(tc, zero_precision_zero_int);
  tcase_add_test(tc, space_flag_int);
  tcase_add_test(tc, unsigned_val);
  tcase_add_test(tc, unsigned_val_width);
  tcase_add_test(tc, unsigned_val_flags);
  tcase_add_test(tc, unsigned_val_precision);
  tcase_add_test(tc, unsigned_val_many_flags);
  tcase_add_test(tc, unsigned_val_short);
  tcase_add_test(tc, unsigned_val_long);
  tcase_add_test(tc, unsigned_val_many);
  tcase_add_test(tc, unsigned_zero);
  tcase_add_test(tc, one_char);
  tcase_add_test(tc, one_precision);
  tcase_add_test(tc, one_flags);
  tcase_add_test(tc, one_width);
  tcase_add_test(tc, one_many);
  tcase_add_test(tc, one_many_flags);
  tcase_add_test(tc, string);
  tcase_add_test(tc, string_precision);
  tcase_add_test(tc, string_width);
  tcase_add_test(tc, string_flags);
  tcase_add_test(tc, string_long);
  tcase_add_test(tc, string_many);
  tcase_add_test(tc, string_width_huge);
  tcase_add_test(tc, float_flags);
  tcase_add_test(tc, float_many);
  tcase_add_test(tc, all_empty);
  tcase_add_test(tc, empty_format_and_parameters);
  tcase_add_test(tc, test_one_char);
  tcase_add_test(tc, test_many_char);
  tcase_add_test(tc, test_one_string);
  tcase_add_test(tc, test_many_string);
  tcase_add_test(tc, test_one_dec);
  tcase_add_test(tc, test_many_dec);
  tcase_add_test(tc, test_one_int);
  tcase_add_test(tc, test_many_int);
  tcase_add_test(tc, test_one_float);
  tcase_add_test(tc, test_many_float);
  tcase_add_test(tc, test_one_unsigned_dec);
  tcase_add_test(tc, test_many_unsigned_dec);
  tcase_add_test(tc, test_one_char_with_alignment_left);
  tcase_add_test(tc, test_one_char_with_alignment_right);
  tcase_add_test(tc, test_many_char_with_alignment);
  tcase_add_test(tc, test_sprintf1);
  tcase_add_test(tc, test_sprintf2);
  tcase_add_test(tc, test_sprintf3);
  tcase_add_test(tc, test_sprintf4);
  tcase_add_test(tc, test_sprintf6);
  tcase_add_test(tc, test_sprintf7);
  tcase_add_test(tc, test_sprintf8);
  tcase_add_test(tc, test_sprintf9);
  tcase_add_test(tc, test_sprintf10);
  tcase_add_test(tc, test_sprintf11);
  tcase_add_test(tc, test_sprintf12);
  tcase_add_test(tc, test_sprintf14);
  tcase_add_test(tc, test_sprintf15);
  tcase_add_test(tc, test_sprintf16);
  tcase_add_test(tc, test_sprintf17);
  tcase_add_test(tc, test_sprintf18);
  tcase_add_test(tc, test_sprintf19);
  tcase_add_test(tc, test_sprintf20);
  tcase_add_test(tc, test_sprintf24);
  tcase_add_test(tc, test_sprintf25);
  tcase_add_test(tc, test_sprintf28);
  tcase_add_test(tc, test_sprintf29);
  tcase_add_test(tc, test_sprintf30);
  tcase_add_test(tc, width_char);
  // tcase_add_test(tc, wide_string2);

  tcase_add_test(tc, to_lower_21);
  tcase_add_test(tc, to_upper_22);
  tcase_add_test(tc, insert_23);
  tcase_add_test(tc, trim_24);

  tcase_add_test(tc, str_tok_1);
  tcase_add_test(tc, str_tok_2);
  tcase_add_test(tc, sprintf_test_sprint_666);
  tcase_add_test(tc, sprintf_test_sprint_667);
  tcase_add_test(tc, sprintf_test_sprint_671);
  tcase_add_test(tc, sprintf_test_sprint_672);
  tcase_add_test(tc, sprintf_test_sprint_673);
  tcase_add_test(tc, sprintf_test_sprint_674);
  tcase_add_test(tc, sprintf_test_sprint_675);
  tcase_add_test(tc, sprintf_test_sprint_676);
  tcase_add_test(tc, sprintf_test_sprint_677);
  tcase_add_test(tc, sprintf_test_sprint_678);
  tcase_add_test(tc, sprintf_test_sprint_679);
  tcase_add_test(tc, sprintf_test_sprint_680);
  tcase_add_test(tc, sprintf_test_sprint_681);
  tcase_add_test(tc, sprintf_test_sprint_682);
  tcase_add_test(tc, sprintf_test_sprint_683);
  tcase_add_test(tc, sprintf_test_sprint_684);
  tcase_add_test(tc, sprintf_test_sprint_685);
  tcase_add_test(tc, sprintf_test_sprint_687);
  tcase_add_test(tc, sprintf_test_sprint_688);
  tcase_add_test(tc, sprintf_test_sprint_689);
  tcase_add_test(tc, sprintf_test_sprint_690);
  tcase_add_test(tc, sprintf_test_sprint_691);
  tcase_add_test(tc, sprintf_test_sprint_692);
  // tcase_add_test(tc, sprintf_test_sprint_693);
  tcase_add_test(tc, sprintf_test_sprint_694);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
