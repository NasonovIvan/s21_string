#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  s21_size_t i = 0;

  char *char_dest = (char *)dest;
  char *char_src = (char *)src;

  for (i = 0; i < n; i++) {
    char_dest[i] = char_src[i];
  }

  return (dest);
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *tmp;

  tmp = (char *)calloc(n, sizeof(char));

  s21_memcpy(tmp, src, n);
  s21_memcpy(dest, tmp, n);

  free(tmp);

  return (dest);
}

void *s21_memset(void *str, int c, s21_size_t n) {
  s21_size_t i = 0;

  while (i < n) {
    *((char *)str + i) = c;
    i++;
  }
  return (str);
}

char *s21_strcpy(char *dest, const char *src) {
  unsigned char *Dest;
  unsigned char *Src;

  Dest = (unsigned char *)dest;
  Src = (unsigned char *)src;

  while ((*Dest = *Src) != '\0') {
    Dest++;
    Src++;
  }
  return (dest);
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  size_t i = 0;
  if (n != 0) {
    if (n > s21_strlen(src)) {
      for (; src[i] != '\0'; i++) dest[i] = src[i];
      for (size_t j = i; j < n; j++) dest[j] = '\0';
    }
    if (n <= s21_strlen(src)) {
      for (; i < n; i++) dest[i] = src[i];
    }
  }
  return dest;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *pointer = s21_NULL;
  if (n == 0 || str == s21_NULL) {
  } else {
    int len = n / sizeof(str[0]);
    for (int i = 0; i < len; i++) {
      if (*((char *)str + i) == (char)c && pointer == s21_NULL) {
        pointer = (char *)str + i;
      }
    }
  }
  return pointer;
}

char *s21_strrchr(const char *str, int c) {
  char *pointer = s21_NULL;
  int i = s21_strlen(str);
  for (; i >= 0; i--) {
    if (str[i] == c && pointer == s21_NULL) {
      pointer = (char *)str + i;
    }
  }
  return pointer;
}

char *s21_strchr(const char *str, int c) {
  char *pointer = s21_NULL;
  int i = 0;
  while (str[i] != '\0' && str[i] != c) {
    i++;
  }
  if (str[i] == c) {
    pointer = (char *)str + i;
  }
  return pointer;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) return (char *)str1 + i;
    }
  }

  return s21_NULL;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *pointer = s21_NULL;
  int index = 0, f_time = 0, j = 0;
  if (!*needle) {
    pointer = (char *)haystack;
  } else {
    for (int i = 0; i < (int)s21_strlen(haystack); ++i) {
      if (j == (int)s21_strlen(needle)) {
        pointer = (char *)haystack + (index);
      } else if ((char)*(haystack + i) == (char)*(needle + j)) {
        if (f_time == 0) {
          index = i;
          f_time++;
        }
        j++;
      } else {
        index = 0;
        j = 0;
        f_time = 0;
      }
    }
    if (j == (int)s21_strlen(needle)) {
      pointer = (char *)haystack + (index);
    }
  }
  return pointer;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;
  s21_size_t i = 0;

  char *Str1 = (char *)str1;
  char *Str2 = (char *)str2;

  while (i < n) {
    if (*(Str1 + i) != *(Str2 + i)) {
      res = *(Str1 + i) - *(Str2 + i);
      break;
    }
    i++;
  }

  return res;
}

int s21_strcmp(const char *str1, const char *str2) {
  int i = 0;
  int res = 0;
  while (str1[i] == str2[i] && str1[i] != '\0') {
    i++;
  }
  res = (int)(*(str1 + i) - *(str2 + i));

  return res;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int indx = 0;
  int result = 0;
  if (n == 0) {
    indx = 1;
    result = 0;
  }

  if (!indx) {
    s21_size_t i = 0;
    while (*(str1 + i) && *(str2 + i) && i < n - 1 &&
           *(str1 + i) == *(str2 + i))
      i++;
    if (*(str1 + i) != *(str2 + i))
      result = *(unsigned char *)(str1 + i) - *(unsigned char *)(str2 + i);
  }

  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *p = s21_NULL;
  int flag = 0;
  if (str) {
    p = str;
  }
  if (p) {
    str = p + s21_strspn(p, delim);
    p = str + s21_strcspn(str, delim);
    if (p == str) {
      p = s21_NULL;
      flag = 1;
    } else {
      p = *p ? *p = 0, p + 1 : 0;
    }
  }
  return flag == 1 ? s21_NULL : str;
}

char *s21_strerror(int errnum) {
  const char *list[] = LIST_ERRORS;

  char *err;
  static char str[300];
  for (register int i = 0; i < 300; i++) {
    str[i] = '\0';
  }

  if (errnum <= N && errnum >= 0) {
    err = (char *)list[errnum];
    return (err);
  } else {
    s21_sprintf(str, "Unknown error: %d", errnum);
  }

  return str;
}

char *s21_strcat(char *dest, const char *src) {
  s21_size_t i = 0;

  while (*(dest + i)) {
    i++;
  }

  while ((*(dest + i) = *src) != '\0') {
    i++;
    src++;
  }

  *(dest + i) = '\0';

  return (dest);
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0, j = 0;

  while (*(dest + i)) {
    i++;
  }

  while ((j < n) && ((*(dest + i) = *(src + j)) != '\0')) {
    i++;
    j++;
  }

  *(dest + i) = '\0';

  return (dest);
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t i = 0;
  for (; *str; i++) {
    str++;
  }

  return i;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0, j = 0, result = s21_strlen(str1);
  while (j < s21_strlen(str2)) {
    i = 0;
    while (i < s21_strlen(str1)) {
      if (str1[i] == str2[j]) {
        if (result > i) {
          result = i;
        }
      }
      i++;
    }
    j++;
  }
  return result;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  int check = 0, res = 0;
  for (; str1[res] != '\0'; res++) {
    check = 0;
    for (int j = 0; str2[j] != '\0'; j++) {
      if (str1[res] == str2[j]) check = 1;
    }
    if (check == 0) break;
  }
  return res;
}

void *s21_to_upper(const char *str) {
  char *result;

  if (str == s21_NULL) {
    result = s21_NULL;
  } else {
    result = calloc(s21_strlen(str) + 1, sizeof(char));
    for (s21_size_t i = 0; i < s21_strlen(str) + 1; i++) {
      if (str[i] > 96 && str[i] < 123) {
        result[i] = str[i] - 32;
      } else if (str[i] >= 0 && str[i] < 127) {
        result[i] = str[i];
      } else {
        result = s21_NULL;
        break;
      }
    }
  }
  return result;
}

void *s21_to_lower(const char *str) {
  char *result;
  if (str == s21_NULL) {
    result = s21_NULL;
  } else {
    result = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
    for (s21_size_t i = 0; i < s21_strlen(str) + 1; i++) {
      if (str[i] > 64 && str[i] < 91) {
        result[i] = str[i] + 32;
      } else if (str[i] >= 0 && str[i] < 127) {
        result[i] = str[i];
      } else {
        result = s21_NULL;
        break;
      }
    }
  }
  return result;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result;
  s21_size_t is_error;
  s21_size_t i = 0;
  if (!src || !str || (s21_strlen(src) < start_index)) {
    is_error = 1;
  } else {
    result = calloc(s21_strlen(src) + s21_strlen(str) + 1, sizeof(char));
    is_error = 0;
    for (; i < s21_strlen(src) + s21_strlen(str); i++) {
      if (i < start_index) {
        result[i] = src[i];
      }
      if (i >= start_index && i < start_index + s21_strlen(str)) {
        result[i] = str[i - start_index];
      }
      if (i >= start_index + s21_strlen(str)) {
        result[i] = src[i - s21_strlen(str)];
      }
    }
  }
  return (is_error == 0) ? result : s21_NULL;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = NULL;
  if (src && trim_chars) {
    char *ptr_str = (char *)src;
    char *end_str = (char *)src + s21_strlen(src);
    for (; *ptr_str && s21_strchr(trim_chars, *ptr_str); ptr_str++) {
    }
    for (; end_str != ptr_str && s21_strchr(trim_chars, *(end_str - 1));
         end_str--) {
    }
    res = (char *)malloc((end_str - ptr_str + 1) * sizeof(char));
    if (res) {
      s21_strncpy(res, ptr_str, end_str - ptr_str);
      *(res + (end_str - ptr_str)) = '\0';
    }
  }
  return res;
}

int len_number_double(double num) {
  int len = 0;
  int c;
  int num_int;
  double n = num;
  num_int = (int)n;

  while (num_int) {
    c = (int)fmod(n, 10.);
    n -= c;
    n /= 10.;
    n += 0.5;
    len++;
    num_int = (int)n;
  }
  return len;
}

int s21_atoi(char *str) {
  int num = 0;
  int minus = 0;
  int i = 0;
  if (str[i] == '-') {
    minus = 1;
    i++;
  }
  for (; str[i] >= '0' && str[i] <= '9'; i++) {
    num = (num * 10) + (str[i] - '0');
  }
  if (minus == 1) {
    num = -num;
  }
  return num;
}

void s21_itoa_double(char *str_dbl, double num, int accuracy) {
  double n = num;
  int len = 0;
  int i = 0;
  int j = 0;
  char c_reverse;
  int acc_copy = accuracy;

  for (; acc_copy > 0; acc_copy--) {
    n *= 10.;
  }
  n = round(n);
  n += 0.5;

  len = len_number_double(n);

  acc_copy = accuracy;
  for (; acc_copy > 0; acc_copy--) {
    j = (int)fmod(n, 10.);
    str_dbl[i] = j + '0';
    n /= 10.;
    i++;
  }
  len -= accuracy;

  if (accuracy != 0) {
    str_dbl[i] = '.';
    i++;
  }

  do {
    j = (int)fmod(n, 10.);
    str_dbl[i] = j + '0';
    n /= 10.;
    i++;
    len--;
  } while (len > 0);

  str_dbl[i] = '\0';

  i -= 1;
  j = 0;

  while (j < i) {
    c_reverse = str_dbl[j];
    str_dbl[j] = str_dbl[i];
    str_dbl[i] = c_reverse;
    j++;
    i--;
  }
}

void s21_itoa_u_int(char *str_num, unsigned int errnum) {
  unsigned int num;
  int i, j;
  char c_reverse;

  i = 0;

  if ((num = errnum) == UINT_MAX) {
    errnum = 429496729;
    str_num[i] = '5';
    i++;
  }

  do {
    str_num[i] = errnum % 10 + '0';
    i++;
  } while ((errnum /= 10) > 0);

  str_num[i] = '\0';
  j = 0;
  i -= 1;

  while (j < i) {
    c_reverse = str_num[j];
    str_num[j] = str_num[i];
    str_num[i] = c_reverse;
    j++;
    i--;
  }
}

void s21_itoa_u_long_int(char *str_num, unsigned long int errnum) {
  unsigned long int num;
  int i, j;
  char c_reverse;

  i = 0;

  if ((num = errnum) == ULONG_MAX) {
    errnum = 1844674407370955161;
    str_num[i] = '5';
    i++;
  }

  do {
    str_num[i] = errnum % 10 + '0';
    i++;
  } while ((errnum /= 10) > 0);

  str_num[i] = '\0';
  j = 0;
  i -= 1;

  while (j < i) {
    c_reverse = str_num[j];
    str_num[j] = str_num[i];
    str_num[i] = c_reverse;
    j++;
    i--;
  }
}

void s21_itoa_long_int(char *str_num, long long int errnum) {
  long long int num;
  int i, j;
  char c_reverse;

  i = 0;

  if (errnum == LONG_MIN) {
    errnum = 922337203685477580;
    str_num[i] = '8';
    i++;
  }
  if ((num = errnum) == LONG_MAX) {
    errnum = 922337203685477580;
    str_num[i] = '7';
    i++;
  }

  do {
    str_num[i] = errnum % 10 + '0';
    i++;
  } while ((errnum /= 10) > 0);

  str_num[i] = '\0';

  j = 0;
  i -= 1;

  while (j < i) {
    c_reverse = str_num[j];
    str_num[j] = str_num[i];
    str_num[i] = c_reverse;
    j++;
    i--;
  }
}

void s21_itoa_int(char *str_num, int errnum) {
  int i, j;
  char c_reverse;

  i = 0;

  if (errnum == INT_MIN) {
    errnum = -(errnum + 1);
    str_num[i] = errnum % 10 + 1 + '0';
    i++;
    errnum /= 10;
  }

  do {
    str_num[i] = errnum % 10 + '0';
    i++;
  } while ((errnum /= 10) > 0);

  str_num[i] = '\0';
  j = 0;
  i -= 1;

  while (j < i) {
    c_reverse = str_num[j];
    str_num[j] = str_num[i];
    str_num[i] = c_reverse;
    j++;
    i--;
  }
}

void proc_u_int(char *str, unsigned int num, struct flags fl) {
  unsigned int n = num;
  int copy_num = num;
  int j = 0;
  char str_num[350];
  int len;
  len = 0;
  int len_acc;
  len_acc = 0;

  while (n /= 10) {
    len++;
  }
  len++;
  if (fl.indx_point == 1 && copy_num == 0) {
    len = 0;
  }

  if (fl.zero == -1 && fl.minus == -1 && fl.width != -1) {
    if (fl.accuracy != -1) {
      len_acc = (len <= fl.accuracy) ? fl.accuracy : len;

      for (j = 0; j < fl.width - len_acc; j++) {
        *str = ' ';
        str++;
      }
    } else {
      for (j = 0; j < fl.width - len; j++) {
        *str = ' ';
        str++;
      }
    }
  }
  if (fl.indx_point == 0 || copy_num != 0) {
    s21_itoa_u_int(str_num, num);
    s21_strncat(str, str_num, s21_strlen(str_num));
  }
  if (fl.accuracy - len > 0) {
    char str_acc[1024];
    for (int k = 0; k < (fl.accuracy - len); k++) {
      str_acc[k] = '0';
    }
    str_acc[fl.accuracy - len] = '\0';
    s21_strncat(str_acc, str, s21_strlen(str));
    s21_memmove(str, str_acc, s21_strlen(str_acc));
  }

  len = s21_strlen(str);
  if (copy_num < 0) {
    len++;
  }
  if (fl.minus == 1 && fl.width != -1) {
    len = s21_strlen(str);
    str += s21_strlen(str);
    for (; j < fl.width - len; j++) {
      *str = ' ';
      str++;
    }
  }
  *(str + s21_strlen(str)) = '\0';
}

void proc_u_long_int(char *str, unsigned long int num, struct flags fl) {
  unsigned long int n = num;
  unsigned long int copy_num = num;
  int j = 0;
  char str_num[350];
  int len;
  len = 0;
  int len_acc;
  len_acc = 0;

  while (n /= 10) {
    len++;
  }
  len++;

  if (fl.zero == -1 && fl.minus == -1 && fl.width != -1) {
    if (fl.accuracy != -1) {
      len_acc = (len <= fl.accuracy) ? fl.accuracy : len;

      for (j = 0; j < fl.width - len_acc; j++) {
        *str = ' ';
        str++;
      }
    } else {
      for (j = 0; j < fl.width - len; j++) {
        *str = ' ';
        str++;
      }
    }
  }
  if (fl.indx_point == 0 || copy_num != 0) {
    s21_itoa_u_long_int(str_num, num);
    s21_strncat(str, str_num, s21_strlen(str_num));
  }
  if (fl.accuracy - len > 0) {
    char str_acc[1024];
    for (int k = 0; k < (fl.accuracy - len); k++) {
      str_acc[k] = '0';
    }
    str_acc[fl.accuracy - len] = '\0';
    s21_strncat(str_acc, str, s21_strlen(str));
    s21_memmove(str, str_acc, s21_strlen(str_acc));
  }
  if (fl.minus == 1 && fl.width != -1) {
    len = s21_strlen(str);
    str += s21_strlen(str);
    for (; j < fl.width - len; j++) {
      *str = ' ';
      str++;
    }
  }
  *(str + s21_strlen(str)) = '\0';
}

void proc_long_int(char *str, long long int num, struct flags fl) {
  long long int n = num;
  long long int copy_num = num;
  int j = 0;
  char str_num[350];
  int len;
  len = 0;
  int len_acc;
  len_acc = 0;

  if (n < 0) {
    n = -n;
  }
  while (n /= 10) {
    len++;
  }
  len++;

  if ((num < 0)) {
    len++;
  } else if (fl.plus == 1 && num > 0) {
    len++;
  } else if (fl.space == 1 && num > 0) {
    len++;
  }

  if (fl.zero == -1 && fl.minus == -1 && fl.width != -1) {
    if (fl.accuracy != -1) {
      len_acc = (len <= fl.accuracy) ? fl.accuracy : len;
      if ((num < 0) && (len <= fl.accuracy)) {
        len_acc++;
      }
      for (j = 0; j < fl.width - len_acc; j++) {
        *str = ' ';
        str++;
      }
    } else {
      for (j = 0; j < fl.width - len; j++) {
        *str = ' ';
        str++;
      }
    }
  }
  if (fl.space == 1 && num >= 0) {
    *str = ' ';
    str++;
    len--;
  }

  if (fl.plus == 1 && num > 0) {
    *str = '+';
    str++;
    len--;
  }

  if (num < 0) {
    *str = '-';
    str++;
    num = -num;
    len--;
  }

  s21_itoa_long_int(str_num, num);
  s21_strncat(str, str_num, s21_strlen(str_num));

  if (fl.accuracy - len > 0) {
    char *str_acc = (char *)calloc((fl.accuracy - len), sizeof(char));
    for (int k = 0; k < (fl.accuracy - len); k++) {
      *(str_acc + k) = '0';
    }
    *(str_acc + (fl.accuracy - len + 1)) = '\0';
    s21_strncat(str_acc, str, s21_strlen(str));
    s21_strncpy(str, str_acc, s21_strlen(str_acc));
    free(str_acc);
  }

  len = s21_strlen(str);
  if (copy_num < 0) {
    len++;
  } else if (fl.plus == 1 && num > 0) {
    len++;
  } else if (fl.space == 1 && num >= 0) {
    len++;
  }

  if (fl.minus == 1 && fl.width != -1) {
    str += s21_strlen(str);
    for (j = 0; j < fl.width - len; j++) {
      *str = ' ';
      str++;
    }
  }
  *(str + s21_strlen(str)) = '\0';
}

void proc_int(char *str, int num, struct flags fl) {
  int n = num;
  int copy_num = num;
  int j = 0;
  char str_num[350];
  int len = 0;
  int len_acc = 0;

  if (n < 0) {
    n = -n;
  }
  while (n /= 10) {
    len++;
  }
  len++;
  if (num < 0) {
    len++;
  } else if (fl.plus == 1 && num >= 0) {
    len++;
  } else if (fl.space == 1 && num >= 0) {
    len++;
  }

  if (fl.accuracy == 0 && copy_num == 0) {
    len = 0;
  }

  if (fl.zero == -1 && fl.minus == -1 && fl.width != -1) {
    if (fl.accuracy != -1) {
      len_acc = (len <= fl.accuracy) ? fl.accuracy : len;
      if ((num < 0) && (len <= fl.accuracy)) {
        len_acc++;
      } else if (fl.plus == 1 && (len <= fl.accuracy)) {
        len_acc++;
      } else if (fl.space == 1 && (len <= fl.accuracy)) {
        len_acc++;
      }
      for (j = 0; j < fl.width - len_acc; j++) {
        *str = ' ';
        str++;
      }
    } else {
      for (j = 0; j < fl.width - len; j++) {
        *str = ' ';
        str++;
      }
    }
  }

  if (fl.space == 1 && num >= 0) {
    *str = ' ';
    str++;
    len--;
  }

  if (fl.plus == 1 && num >= 0) {
    *str = '+';
    str++;
    len--;
  }

  if (num < 0) {
    *str = '-';
    str++;
    num = -num;
    len--;
  }

  if (fl.accuracy == 0 && copy_num == 0) {
  } else {  // if (fl.indx_point == 0 || copy_num != 0)
    s21_itoa_int(str_num, num);
    s21_strncat(str, str_num, s21_strlen(str_num));
  }
  if (len < 0) len = 0;

  if (fl.accuracy - len > 0) {
    // char *str_acc = (char *)calloc((fl.accuracy - len), sizeof(char));
    char str_acc[350];
    for (register int i = 0; i < 350; i++) {
      str_acc[i] = '\0';
    }
    for (int k = 0; k < (fl.accuracy - len); k++) {
      *(str_acc + k) = '0';
    }
    *(str_acc + (fl.accuracy - len + 1)) = '\0';
    s21_strncat(str_acc, str, s21_strlen(str));
    s21_strncpy(str, str_acc, s21_strlen(str_acc));
  }

  len = s21_strlen(str);
  if (copy_num < 0) {
    len++;
  } else if (fl.plus == 1 && num >= 0) {
    len++;
  } else if (fl.space == 1 && num >= 0) {
    len++;
  }
  if (fl.minus == 1 && fl.width != -1) {
    str += s21_strlen(str);
    for (j = 0; j < fl.width - len; j++) {
      *str = ' ';
      str++;
    }
  }
  *(str + s21_strlen(str)) = '\0';
}

void proc_double(char *str, double num, struct flags fl) {
  double n = num;
  int j = 0;
  char *str_num = (char *)calloc(1024, sizeof(char));
  int len_point = 0;
  int len_point2 = 0;
  int len_acc = 0;

  if (n < 0) {
    n = -n;
  }

  len_point = len_number_double(n);
  n = round(n);
  len_point2 = len_number_double(n);

  if (fl.accuracy == 0) {
    len_point = (len_point < len_point2) ? len_point2 : len_point;
  }

  if ((int)num == 0) {
    len_point++;
  }
  if ((num < 0)) {
    len_point++;
  } else if (fl.plus == 1 && num > 0) {
    len_point++;
  } else if (fl.space == 1 && num > 0) {
    len_point++;
  }

  if (fl.zero == -1 && fl.minus == -1 && fl.width != -1) {
    if (fl.accuracy != -1) {
      if (fl.indx_point == 0 && fl.accuracy != 0) {
        len_point++;
      }
      len_acc = len_point + fl.accuracy;
      for (j = 0; j < fl.width - len_acc; j++) {
        *str = ' ';
        str++;
      }
    }
  }
  if (fl.space == 1 && num >= 0) {
    *str = ' ';
    str++;
    len_point--;
  }

  if (fl.plus == 1 && num > 0) {
    *str = '+';
    str++;
    len_point--;
  }

  if (num < 0) {
    *str = '-';
    str++;
    num = -num;
    len_point--;
  }

  s21_itoa_double(str_num, num, fl.accuracy);
  s21_strncat(str, str_num, s21_strlen(str_num));

  *(str + s21_strlen(str)) = '\0';
  free(str_num);
}

s21_size_t len_wchar(wchar_t *str) {
  s21_size_t i = 0;
  while (str[i]) {
    i++;
  }
  return i;
}

int int_func(char *str, struct flags fl, va_list arguments, int len) {
  int length = len;
  char *str_int = (char *)calloc(512, sizeof(char));
  int varint;
  short int varhint;
  long long int varlongint;

  varint = 0;
  varlongint = 0;
  if (fl.indx_point == 1) {
    fl.accuracy = 0;
  }
  if (fl.len == 'l') {
    varlongint = va_arg(arguments, long long int);
    proc_long_int(str_int, varlongint, fl);

    s21_strcat(str, str_int);
    length += s21_strlen(str_int);
    str += s21_strlen(str_int);
  } else if (fl.len == 'h') {
    varhint = va_arg(arguments, int);
    proc_int(str_int, (int)varhint, fl);
    s21_strcat(str, str_int);
    length += s21_strlen(str_int);
    str += s21_strlen(str_int);
  } else {
    varint = va_arg(arguments, int);
    proc_int(str_int, varint, fl);
    s21_strcat(str, str_int);
    length += s21_strlen(str_int);
    str += s21_strlen(str_int);
  }
  free(str_int);
  return (length);
}

int int_u_func(char *str, struct flags fl, va_list arguments, int len) {
  int length = len;
  char *str_int_u = (char *)calloc(512, sizeof(char));
  int varint;
  unsigned long int varulongint;
  unsigned int varuint;

  varint = 0;
  varuint = 0;
  varulongint = 0;
  if (fl.indx_point == 1) {
    fl.accuracy = 0;
  }
  if (fl.len == 'l') {
    varulongint = va_arg(arguments, unsigned long int);
    proc_u_long_int(str_int_u, varulongint, fl);
    s21_strcat(str, str_int_u);
    length += s21_strlen(str_int_u);
    str += s21_strlen(str_int_u);
  } else if (fl.len == 'h') {
    varint = va_arg(arguments, int);
    varuint = (unsigned short int)varint;
    proc_u_int(str_int_u, varuint, fl);
    s21_strcat(str, str_int_u);
    length += s21_strlen(str_int_u);
    str += s21_strlen(str_int_u);
  } else {
    varuint = va_arg(arguments, unsigned int);
    proc_u_int(str_int_u, varuint, fl);
    s21_strcat(str, str_int_u);
    length += s21_strlen(str_int_u);
    str += s21_strlen(str_int_u);
  }
  free(str_int_u);
  return (length);
}

int string_func(char *str, struct flags fl, va_list arguments, int len) {
  int length = len;
  char str_str[1024];
  char str_strW[1024];
  //=========  e,hfnm 30 b gjvtyznm yf 1024 ниже
  for (register int i = 0; i < 30; i++) {
    str_str[i] = '\0';
    str_strW[i] = '\0';
  }
  int st = 0;
  int end = 0;
  int len_str = 0;
  s21_size_t lengW = 0;
  wchar_t *strW;

  if (fl.len == 'l') {
    strW = (wchar_t *)va_arg(arguments, wchar_t *);
    lengW = len_wchar(strW);
    if (fl.accuracy > 0) {
      st = 0;
      for (int i = 0; i < fl.accuracy && fl.accuracy > 0;
           i += (int)sizeof(wchar_t)) {
        st++;
      }
      if (fl.minus == -1 && fl.width != -1) {
        for (int i = 0; i < fl.width - (st * 3); i++) {
          *str = ' ';
          str++;
          length++;
        }
      }
      wcstombs(str_strW, strW, st * sizeof(wchar_t));
      *(str_strW + s21_strlen(str_strW)) = '\0';
      len_str = s21_strlen(str_strW);
      length += s21_strlen(str_strW);
    } else if (fl.indx_point == 1 || fl.accuracy == 0) {
      for (int i = 0; i < fl.width; i++) {
        s21_strcat(str, " ");
        length++;
      }
      str += s21_strlen(str);
      return (length);
    } else {
      if (fl.minus == -1 && fl.width != -1) {
        for (long unsigned int i = 0; i < fl.width - (lengW * 3); i++) {
          *str = ' ';
          str++;
          length++;
        }
      }
      wcstombs(str_strW, strW, lengW * sizeof(wchar_t));
      *(str_strW + s21_strlen(str_strW)) = '\0';
      len_str = s21_strlen(str_strW);
      length += s21_strlen(str_strW);
    }

    s21_strcat(str, str_strW);
    len_str = s21_strlen(str);
    if (fl.minus == 1) {
      for (int i = 0; i < fl.width - len_str; i++) {
        s21_strcat(str, " ");
        length++;
      }
    }
    str += s21_strlen(str);
    *str = '\0';
  } else {
    char *varstr = va_arg(arguments, char *);
    if (fl.indx_point == 1 || fl.accuracy == 0) {
      // len_str = 0;
      for (int i = 0; i < fl.width; i++) {
        s21_strcat(str, " ");
        length++;
      }
      // str += s21_strlen(str);
      return (length);
    }
    if (varstr == s21_NULL) {
      if (fl.accuracy != -1 && fl.accuracy < 6) {
        s21_strncat(str_str, "(null)", fl.accuracy);
        length += fl.accuracy;
        end = fl.accuracy;
      } else {
        s21_strncat(str_str, "(null)", 6);
        length += 6;
        end = 6;
      }
    } else {
      st = 0;
      for (; *varstr; varstr++) {
        st++;
        if (fl.accuracy < st && fl.accuracy > 0) {
          continue;
        }
        end = st;
        *(str_str + st - 1) = *varstr;
        length++;
      }
    }

    *(str_str + end) = '\0';
    len_str = s21_strlen(str_str);
    if (fl.minus == -1) {
      for (int i = 0; i < fl.width - len_str; i++) {
        s21_strcat(str, " ");
        length++;
      }
    }

    *(str_str + s21_strlen(str_str)) = '\0';
    s21_strcat(str, str_str);
    if (fl.minus == 1) {
      for (int i = 0; i < fl.width - len_str; i++) {
        s21_strcat(str, " ");
        length++;
      }
    }
    str += s21_strlen(str);
  }
  return (length);
}

int float_func(char *str, struct flags fl, va_list arguments, int len) {
  int length = len;
  char *str_dbl = (char *)calloc(1024, sizeof(char));
  double vard;
  int len_number;

  vard = 0.;
  vard = va_arg(arguments, double);
  if (fl.indx_point == 1) {
    fl.accuracy = 0;
  }
  if (fl.accuracy == -1) {
    fl.accuracy = 6;
  }
  proc_double(str_dbl, vard, fl);

  if (fl.accuracy == 0) {
    if (fl.minus == 1) {
      len_number = (int)s21_strlen(str_dbl);
      for (int i = 0; i < fl.width - len_number; i++) {
        *(str_dbl + s21_strlen(str_dbl)) = ' ';
      }
    }
    length += s21_strlen(str_dbl);
    s21_strcat(str, str_dbl);
    str += s21_strlen(str);
    free(str_dbl);
    return (length);
  }

  if (fl.minus == 1) {
    len_number = (int)s21_strlen(str_dbl);
    for (int i = 0; i < fl.width - len_number; i++) {
      *(str_dbl + s21_strlen(str_dbl)) = ' ';
    }
  }
  length += s21_strlen(str_dbl);
  s21_strcat(str, str_dbl);
  str += s21_strlen(str);
  *str = '\0';
  free(str_dbl);
  return (length);
}

int s21_sprintf(char *str, const char *format, ...) {
  setlocale(LC_ALL, "");
  setlocale(LC_ALL, "en_US.UTF-8");
  va_list arguments;
  va_start(arguments, format);
  int length = 0;
  int copy_len = 0;
  *str = '\0';
  char symbol;
  wchar_t symbolW;

  struct flags fl;

  while (*format) {
    if (*format != '%') {
      s21_strncat(str, format, 1);
      length++;
      str++;
    }

    fl.minus = -1;
    fl.plus = -1;
    fl.space = -1;
    fl.lattice = -1;
    fl.zero = -1;
    fl.width = -1;
    fl.accuracy = -1;
    fl.len = -1;
    fl.indx_point = 0;

    if (*format == '%') {
      format++;
      while (1) {
        if (*format == '-' || *format == '+' || *format == ' ' ||
            *format == '#' || *format == '0') {
          if (*format == '-') {
            fl.minus = 1;
            format++;
          } else if (*format == '+') {
            fl.plus = 1;
            format++;
          } else if (*format == ' ') {
            fl.space = 1;
            format++;
          } else if (*format == '0') {
            fl.zero = 1;
            format++;
          }
        } else {
          break;
        }
      }
      if ((fl.zero == 1) && (47 < *format && *format < 58)) {
        char *str_wid = (char *)calloc(350, sizeof(char));
        for (int i = 0; 47 < *format && *format < 58; i++) {
          *(str_wid + i) = *format;
          format++;
        }
        fl.width = s21_atoi(str_wid);
        free(str_wid);
      }
      if (47 < *format && *format < 58) {
        char *str_wid = (char *)calloc(350, sizeof(char));
        for (int i = 0; 47 < *format && *format < 58; i++) {
          *(str_wid + i) = *format;
          format++;
        }
        fl.width = s21_atoi(str_wid);
        free(str_wid);
      }

      switch (*format) {
        case '.':
          if (*(format + 1) == '*') {
            fl.accuracy = va_arg(arguments, int);
            format += 2;
          } else if ((47 < *(format + 1) && *(format + 1) < 58) ||
                     *(format + 1) == '-') {
            int i = 0;
            format++;
            char *str_acc = (char *)calloc(350, sizeof(char));
            if (*format == '-') {
              format++;
              *(str_acc + i) = '-';
              i++;
            }
            for (; 47 < *format && *format < 58; i++) {
              *(str_acc + i) = *format;
              format++;
            }
            fl.accuracy = s21_atoi(str_acc);
            if (fl.accuracy < 0) {
              fl.accuracy = 0;
            }
            free(str_acc);
          } else {
            fl.indx_point = 1;
            fl.accuracy = 0;
            format++;
          }
      }

      if ((*format == 'h') || (*format == 'l') || (*format == 'L')) {
        if (*format == 'h') {
          fl.len = *format;
          format++;
        } else if (*format == 'l') {
          fl.len = *format;
          format++;
        }
      }

      switch (*format) {
        case '%':
          if (fl.minus == -1 && fl.width != -1) {
            for (register int i = 0; i < fl.width - 1; i++) {
              *str = ' ';
              str++;
              length++;
            }
          }
          *str = '%';
          str++;
          length++;
          if (fl.minus == 1 && fl.width != -1) {
            for (register int i = 0; i < fl.width - 1; i++) {
              *str = ' ';
              str++;
              length++;
            }
          }
          *str = '\0';
          break;
        case 'c':
          if (fl.len == 'l') {
            symbolW = (wchar_t)va_arg(arguments, wchar_t);
            if (fl.minus == -1 && fl.width != -1) {
              for (int i = 0; i < fl.width - 3; i++) {
                *str = ' ';
                str++;
                length++;
              }
            }
            char *pmb = (char *)calloc(MB_CUR_MAX, sizeof(char));
            wctomb(pmb, symbolW);
            s21_strncat(str, pmb, 3);
            str += s21_strlen(pmb);
            length += s21_strlen(pmb);
            if (fl.minus == 1 && fl.width != -1) {
              for (long unsigned int i = 0; i < fl.width - s21_strlen(pmb);
                   i++) {
                *str = ' ';
                str++;
                length++;
              }
            }
            free(pmb);
          } else {
            symbol = va_arg(arguments, int);
            if (fl.minus == -1 && fl.width != -1) {
              for (int i = 0; i < fl.width - 1; i++) {
                *str = ' ';
                str++;
                length++;
              }
            }
            *str = symbol;
            str++;
            length++;
            if (fl.minus == 1 && fl.width != -1) {
              for (int i = 0; i < fl.width - 1; i++) {
                *str = ' ';
                str++;
                length++;
              }
            }
            *str = '\0';
          }
          break;

        case 'd':
          copy_len = length;
          length = int_func(str, fl, arguments, length);
          str += (length - copy_len);
          break;

        case 'i':
          copy_len = length;
          length = int_func(str, fl, arguments, length);
          str += (length - copy_len);
          break;

        case 'u':
          copy_len = length;
          length = int_u_func(str, fl, arguments, length);
          str += (length - copy_len);
          break;

        case 's':
          copy_len = length;
          length = string_func(str, fl, arguments, length);
          str += (length - copy_len);
          break;

        case 'f':
          copy_len = length;
          length = float_func(str, fl, arguments, length);
          str += (length - copy_len);
          break;
      }
    }
    format++;
  }
  *(str + s21_strlen(str)) = '\0';
  va_end(arguments);
  return length;
}
