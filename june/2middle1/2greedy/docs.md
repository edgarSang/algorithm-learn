잃어버린 괄호
------------------------
 - 식에서 적절히 쳐서 식의 값을 최소로


수 묶기
-----------------------
 - 두수를 적절히 묶어서 수열의 합을 최대로 구하는 문제.
 - 양수는 큰수끼리, 음수는 작은수끼리, 0은 묶지않는것이최대

대회 or 인턴
------------------
 - 여학생 N 명 남학생 M명
 - 1팀 : 여2 남 1
 - K명은 인턴에 가야함, 총몇팀이나오냐?  

30
---------------
 - 어떤 수 N이주어졌을떄 숫자를 섞어 30의 배수로
 - 2 * 3 * 5 2,3,5

병든나이트
----------------
 - 1억을 넘는경우는 수식으로 해결되는경우가많다.
 - 1. height = 1 움직일수있는방법 전혀없다
 - 2. height = 2 두가지 방법만 할 수 있다
 -  - 따라서 정답은 min (4, (widht+1) /2)
 -  - 이동횟수 제한때문에 4가 필요함
 - 3. height >= 3 인경우
 - 3. 1. width>=7 
 - 3. 2. width<7


NMK
------------
1부터 N까지의 수를 한번씩 이용해서 최대 부분 증가수열의 길이가 M이고, 최대 부분 감소 수열의 길이가 K인 수열을 구하는문제

LIS(최대부분 증가수열) = D[i] max(D[j]) + 1
j < i , A[j] < A[i];

- 문제를 풀때 예제를 뺴고생각해라,
- 1. 불가능한 경우 찾기



행렬
-----------

롤러코스터
---------------


문제
------------------
1541
1744
2875
10610
1783
1201
1080
2973