격투겜 함수 자동생성
ㄴ텍스트파일에 함수 써두면 그걸 토대로 소스파일,헤더파일 생성
ㄴ직렬화버퍼에 차례대로 넣고 그걸 들어온 player인자 제외하는 SendBroadcast하는 함수들

hw_33_1
ㄴbroadcast인지 unicast인지 확인 필요..해당 코드 넣기...
ㄴ끝이나 맨앞에 숫자 넣어서 그걸로 구분해야할 듯..
  ㄴ수정했음..
ㄴ#define에는 .이 들어가면 안돼용...글자,숫자만 들어가야해용..

hw_33_2
ㄴ함수 하나 넣으면 broadcast unicast 해당인자제외broadcast 3개가 한꺼번에 만들어지도록

hw_33_3
ㄴReqProc함수들에 unsigned id빼고 인자 들어가도록
