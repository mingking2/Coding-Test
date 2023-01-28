2022 KAKAO BLIND RECRUITMENT
=====================

<details>
<summary>문제 1</summary>



문제 1 - 신고 결과 받기
------------------------

### 문제 설명

신입사원 무지는 게시판 불량 이용자를 신고하고 처리 결과를 메일로 발송하는 시스템을 개발하려 합니다. 무지가 개발하려는 시스템은 다음과 같습니다.

* 각 유저는 한 번에 한 명의 유저를 신고할 수 있습니다.
   * 신고 횟수에 제한은 없습니다. 서로 다른 유저를 계속해서 신고할 수 있습니다.
   * 한 유저를 여러 번 신고할 수도 있지만, 동일한 유저에 대한 신고 횟수는 1회로 처리됩니다.

* k번 이상 신고된 유저는 즉시 게시판 이용이 정지되며, 해당 유저를 신고한 모든 유저에게 정지 사실을 메일로 발송합니다.
   * 유저가 신고한 모든 내용을 취합하여 마지막에 한꺼번에 게시판 이용 정지를 시키면서 정지 메일을 발송합니다.   
      
    
다음은 전체 유저 목록이 [“muzi”, “frodo”, “apeach”, “neo”]이고, k = 2(즉, 2번 이상 신고 당하면 이용 정지)인 경우의 예시입니다.   

|유저 ID|유저가 신고한 ID|설명|
|-------|-----------------|----|
|"muzi"|"frodo"|"muzi"가 "frodo"를 신고했습니다.|
|"apeach"|"frodo"|"apeach"가 "frodo"를 신고했습니다.|
|"frodo"|"neo"|"frodo"가 "neo"를 신고했습니다.|
|"muzi"|"neo"|"muzi"가 "neo"를 신고했습니다.|
|"apeach"|"muzi"|"apeach"가 "muzi"를 신고했습니다.|


각 유저별로 신고당한 횟수는 다음과 같습니다.



|유저 ID|신고당한 횟수|
|-------|-----------------|
|"muzi"|1|
|"frodo"|2|
|"apeach"|0|
|"neo"|2|



위 예시에서는 2번 이상 신고당한 "frodo"와 "neo"의 게시판 이용이 정지됩니다. 이때, 각 유저별로 신고한 아이디와정지된 아이디를 정리하면 다음과 같습니다.



|유저 ID|유저가 신고한 ID|정지된 ID|
|-------|-----------------|----|
|"muzi"|["frodo", "neo"]|["frodo", "neo"]|
|"frodo"|["neo"]|["neo"]|
|"apeach"|["muzi", "frodo"]|["frodo"]|
|"neo"|없음|없음|


따라서 "muzi"는 처리 결과 메일을 2회, "frodo"와 "apeach"는 각각 처리 결과 메일을 1회 받게 됩니다.



이용자의 ID가 담긴 문자열 배열 **id_list**, 각 이용자가 신고한 이용자의 ID 정보가 담긴 문자열 배열 **report**, 정지 기준이 되는 신고 횟수 **k**가 매개변수로 주어질 때, 각 유저별로 처리 결과 메일을 받은 횟수를 배열에 담아 return 하도록 solution 함수를 완성해주세요.

.
### 제한사항
* 2 ≤ id_list의 길이 ≤ 1,000
  * 1 ≤ id_list의 원소 길이 ≤ 10
  * id_list의 원소는 이용자의 id를 나타내는 문자열이며 알파벳 소문자로만 이루어져 있습니다.
  * id_list에는 같은 아이디가 중복해서 들어있지 않습니다.
  
  
* 1 ≤ report의 길이 ≤ 200,000
  * 3 ≤ report의 원소 길이 ≤ 21
  * report의 원소는 "이용자id 신고한id"형태의 문자열입니다.
  * 예를 들어 "muzi frodo"의 경우 "muzi"가 "frodo"를 신고했다는 의미입니다.
  * id는 알파벳 소문자로만 이루어져 있습니다.
  * 이용자id와 신고한id는 공백(스페이스)하나로 구분되어 있습니다.
  * 자기 자신을 신고하는 경우는 없습니다.
  
  
* 1 ≤ k ≤ 200, k는 자연수입니다.
* return 하는 배열은 id_list에 담긴 id 순서대로 각 유저가 받은 결과 메일 수를 담으면 됩니다.




### 입출력 예
|id_list|report|k|result|
|-------|-----------------|----|----|
|["muzi", "frodo", "apeach", "neo"]|["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]|2|[2,1,1,0]|
|["con", "ryan"]|["ryan con", "ryan con", "ryan con", "ryan con"]|3|[0,0]|


### 입출력 예 설명



**입출력 예 #1**


문제의 예시와 같습니다.


**입출력 예 #2**


"ryan"이 "con"을 4번 신고했으나, 주어진 조건에 따라 한 유저가 같은 유저를 여러 번 신고한 경우는 신고 횟수 1회로 처리합니다. 따라서 "con"은 1회 신고당했습니다. 3번 이상 신고당한 이용자는 없으며, "con"과 "ryan"은 결과 메일을 받지 않습니다. 따라서 [0, 0]을 return 합니다.



### 제한시간 안내
  * 정확성 테스트 : 10초
 
 
 
---




### solution.c


```
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// id_list_len은 배열 id_list의 길이입니다.
// report_len은 배열 report의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(1);
    return answer;
}
```
  
  
### - 1등 코드 (민기, 승제)


<details>


<summary>코드 보기</summary>


```
#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 20

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const char* id_list[] = { "muzi", "frodo", "apeach", "neo" };
const char* report[] = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };

size_t id_list_len = sizeof(id_list) / sizeof(id_list[0]);
size_t report_len = sizeof(report) / sizeof(report[0]);


int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {

	int** ch;
	int i, j;
	ch = (int**)malloc(sizeof(int*) * id_list_len);
	for (int i = 0; i < id_list_len; i++) {
		if (ch != NULL) {
			ch[i] = (int*)malloc(sizeof(int) * id_list_len);
		}
	}

	for (i = 0; i < report_len; i++) {
		char* report_strtok;
		char report_copy[20];
		strcpy(report_copy, report[i]);

		report_strtok = strtok(report_copy, " ");
		int index1 = 0;
		for (j = 0; j < id_list_len; j++) {
			if (strcmp(id_list[j], report_strtok) == 0) {
				index1 = j;
				break;
			}
		}

		report_strtok = strtok(NULL, " ");
		int index2 = 0;
		for (j = 0; j < id_list_len; j++) {
			if (strcmp(id_list[j], report_strtok) == 0) {
				index2 = j;
				break;
			}
		}

		ch[index1][index2] = 1;
	}

	int* result = (int*)calloc(id_list_len, sizeof(int));
	int* answer = (int*)calloc(id_list_len, sizeof(int));
	for (j = 0; j < id_list_len; j++) {
		for (i = 0; i < id_list_len; i++) {
			if (ch[i][j] == 1) result[j] += 1;
		}
		if (result[j] >= k) {
			for (i = 0; i < id_list_len; i++) {
				if (ch[i][j] == 1) answer[i] += 1;
			}
		}
	}

	for (i = 0; i < id_list_len; i++) {
		free(ch[i]);
	}
	free(ch);
	free(result);
	return answer;
}
```
  
</details>  
  
  
---
---  
</details>



<details>
<summary>문제 2</summary>




문제 2 - 신고 결과 받기
------------------------

### 문제 설명

양의 정수 **n**이 주어집니다. 이 숫자를 **k**진수로 바꿨을 때, 변환된 수 안에 아래 조건에 맞는 소수(Prime number)가 몇 개인지 알아보려 합니다.

* **0P0**처럼 소수 양쪽에 0이 있는 경우
* **P0**처럼 소수 오른쪽에만 0이 있고 왼쪽에는 아무것도 없는 경우
* **0P**처럼 소수 왼쪽에만 0이 있고 오른쪽에는 아무것도 없는 경우
* **P**처럼 소수 양쪽에 아무것도 없는 경우
* 단, **P**는 각 자릿수에 0을 포함하지 않는 소수입니다.
   * 예를 들어, 101은 **P**가 될 수 없다.
      
    
예를들어, 437674을 3진수로 바꾸면 **211**0**2**01010**11**입니다. 여기서 찾을 수 있는 조건에 맞는 소수는 왼쪽부터 순서대로 211, 2, 11이 있으며, 총 3개입니다.
(211, 2, 11을 **k**진법으로 보았을 때가 아닌, 10진법으로 보았을 때 소수여야 한다는 점에 주의합니다.)
211은 **P0** 형태에서 찾을 수 있으며, 2는 **0P0**에서, 11은 **0P**에서 찾을 수 있습니다.


정수 **n**과 **k**가 매개변수로 주어집니다. **n**을 **k**진수로 바꿧을 때, 변환된 수 안에서 찾을 수 있는 **위 조건에 맞는 소수**의 개수를 return 하도록 solution 함수를 완성해 주세요.


---



### 제한사항
  * 1 <= **n** <= 1,000,000
  * 3 <= **k** <= 10
  
  
  
---


### 입출력 예
|n|k|result|
|-|-|------|
|437674|3|3|
|110011|10|2|
  
  
  
---



### 입출력 예 설명



**입출력 예 #1**


문제 예시와 같습니다.


**입출력 예 #2**


110011을 10진수로 바꾸면 110011입니다. 여기서 찾을 수 있는 조건에 맞는 소수는 11, 11 2개입니다. 이와 같이, 중복되는 소수를 발견하더라도 모두 따로 세어야 합니다.
 
 
 
---



### solution.c


```
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n,int k){
  int answer = -1;
  return answer;
}
```


### - 1등 코드 (??, ??)


<details>


<summary>코드 보기</summary>



```

```



---
---
</details>



</details>
