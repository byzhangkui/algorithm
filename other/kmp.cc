#include <iostream>

int* scores = nullptr;
size_t scroes_length = 0;
// 实现 KMP 的回溯函数
//length 纯字符串长度，不包含 \0
int* GenerateFailedFunction(const char str[], size_t length) {
  scores = new int[length];
  scroes_length = length;
  memset(scores, -1, sizeof(int) * length);

  for (size_t j = 1; j < length; ++j) {//p0~pj 字串
    for (size_t k = 0; k < j; ++k) {//p0p1..pk 与 pj-k..pk 字串
      bool is_all_match = true;
      for (size_t i = 0; i <= k; ++i) {
        if (str[i] != str[j - k + i]) {
          //std::cout << "i:" << i << ",j-k+i:" << j-k+i << "," << str[i] << "," << str[j - k + i] << std::endl;
          is_all_match = false;
          break;
        }
      }
      //std::cout << "j:" << j << ",k:" << k << " " << "is_all_match:" << is_all_match << std::endl;
      if (is_all_match) {
        scores[j] = k;
      }
    }
  }
  std::cout << "scores:";
  for (int i = 0; i < length; ++i) {
    std::cout << scores[i] << " ";
  }
  std::cout << std::endl;
  return scores;
}
  
int GetNextStep(size_t index) {
  if (scores == nullptr || index > scroes_length || scores[index] == -1) {
    return 1;
  }
    
  int next_step = index - scores[index];
  return next_step > 0 ? next_step : 1;
}

//返回匹配到到起始位置
int KMPCompare(const char* original, size_t original_length, 
  const char* dest, size_t dest_length) {
  bool is_find = false;
  int pos = -1;
  size_t compared_length = 0;
  for (size_t i = 0 ; i < original_length; i += GetNextStep(compared_length)) {
    std::cout << "i:" << i << std::endl;
    for (size_t j = 0; j < dest_length, i + j < original_length; ++j) {
      if (original[i + j] == dest[j]) {
        if (j == dest_length - 1) {
          is_find = true;
          pos = i;
        };
      } else {
        compared_length = j > 0 ? j - 1 : 0;
        break;
      }
    }
    if (is_find) {
      break;
    }
  }
  
  return pos;
}

int NormalCompareByPoint(const char* original, size_t original_length, 
  const char* dest, size_t dest_length) {
  if (original == nullptr || dest == nullptr) {
    return -1;
  }

  const char* ori_cursur = original;
  const char* dest_cursur = dest;
  int dest_pos = 0;
  while (*ori_cursur) {
    if (*ori_cursur == *dest_cursur) {
      ++ori_cursur;
      ++dest_cursur;
      if(!*dest_cursur) {
        return dest_pos;
        //找到了
      }
    } else {
      ++dest_pos;
      ori_cursur = original + dest_pos;
      dest_cursur = dest;
    }
  }

  return -1;
}

int KMPCompareByPoint(const char* original, size_t original_length, 
  const char* dest, size_t dest_length) {
  if (original == nullptr || dest == nullptr) {
    return -1;
  }

  const char* ori_cursur = original;
  const char* dest_cursur = dest;
  int dest_pos = 0;
  while (*ori_cursur) {
    if (*ori_cursur == *dest_cursur) {
      ++ori_cursur;
      ++dest_cursur;
      if(!*dest_cursur) {
        return dest_pos;
        //找到了
      }
    } else {
      dest_pos += GetNextStep(dest_pos > 0 ? dest_pos - 1 : 0);
      ori_cursur = original + dest_pos;
      dest_cursur = dest;
    }
  }

  return -1;
}
int NormalCompare(const char* original, size_t original_length, 
  const char* dest, size_t dest_length) {
  bool is_find = false;
  int pos = -1;
  for (int i = 0 ; i < original_length; ++i) {
    for (int j = 0; j < dest_length, i + j < original_length; ++j) {
      if (original[i + j] == dest[j]) {
        if (j == dest_length - 1) {
          is_find = true;
          pos = i;
        };
      } else {
        break;
      }
    }
    if (is_find) {
      break;
    }
  }
  
  return pos;
}

int main() {
  //char str[] = "abaabcac";
  //char str[] = "abaabcaba";
  char original_string[] = "BBC ABCDAB ABCDABCDABDE";
  char dest[] = "ABCDABD";
  int pos = NormalCompare(original_string, sizeof(original_string)/sizeof(char) -1, dest, sizeof(dest)/sizeof(char) - 1);
  std::cout << "normal compare pos:" << pos << std::endl;

  scores = GenerateFailedFunction(dest, sizeof(dest)/sizeof(char) - 1);
  int pos_kmp = KMPCompare(original_string, sizeof(original_string)/sizeof(char) -1, dest, sizeof(dest)/sizeof(char) - 1);
  std::cout << "KMP compare pos:" << pos_kmp << std::endl;

  int pos_point = NormalCompareByPoint(original_string, sizeof(original_string)/sizeof(char) -1, dest, sizeof(dest)/sizeof(char) - 1);
  std::cout << "normal compare by point pos:" << pos_point << std::endl;

  int pos_kmp_point = KMPCompareByPoint(original_string, sizeof(original_string)/sizeof(char) -1, dest, sizeof(dest)/sizeof(char) - 1);
  std::cout << "KMP compare by point pos:" << pos_kmp_point << std::endl;

  delete[] scores;
}