### README.md

- PanTilt_2Axis_SampleCode
* DRS-0101 두 개를 이용한 Pantilt Module제어용 예제입니다.
* 해당 예제에서는 HDLL(HerkuleX.DLL)을 이용한 각종 함수들의 사용방법에 대한 기능들이 구현되어 있습니다.
. 통신 연결/해제.
. RAM Register와 EEP Register의 읽기/쓰기.
. LED 제어.
. 위치/속도 제어.
. JOG모드의 활용.


-UI화면의 구성

![1](https://user-images.githubusercontent.com/58063370/73431797-8edfd800-4384-11ea-97ea-b42bc6240849.png)

①	HerkuleX와 PC간의 통신연결 및 Motor의 토크/브레이크 제어.

	Connect버튼: COM Port 3번에 115,200bps로 시리얼 통신연결 후 Initialize함수 호출.

	Disconnect버튼: 통신연결 해제.

	Torque On버튼: Motor의 Servo Enable을 호출.

	Torque Off버튼: Motor의 Servo Disable을 호출.

	Brake On버튼: Motor의 Brake기능을 호출.

②	RAM Register & EEP Register의 데이터 읽기 요청 및 데이터 확인 기능.

	RAM Register의 주소를 입력하고, ‘SET’버튼을 클릭하면, 해당 주소의 데이터 요청.

	데이터 요청 후 ‘GET’버튼을 클릭하면, HerkuleX로 부터 전달받은 RAM Data가 출력됨.

	EEP Register의 주소를 입력하고, ‘SET’버튼을 클릭하면, 해당 주소의 데이터 요청.

	데이터 요청 후 ‘GET’버튼을 클릭하면, HerkuleX로 부터 전달받은 EEP Data가 출력됨.

③	RAM Register & EEP Register의 데이터 쓰기기능.

	RAM Register 주소와 변경할 데이터를 입력하고, ‘Write’버튼을 클릭하면, 데이터 쓰기가 호출.

	EEP Register 주소와 변경할 데이터를 입력하고, ‘Write’버튼을 클릭하면, 데이터 쓰기가 호출.

④	HerkuleX의 위치/속도 제어모드 (Position Mode와 Velocity Move함수 사용)

	목표위치 값과 동작시간을 입력한 후에 ‘Position Move’버튼을 클릭하면 위치동작 실행.

	목표속도 값을 입력한 후에 ‘Velocity Move’버튼을 클릭하면 속도동작 실행. (동작시간은 무시됨)

⑤	HerkuleX에 장착된 LED(Green, Blue, Red)의 On/Off설정기능

	Green, Blue, Red 체크박스를 각각 선택하고, ‘Set LED’버튼을 클릭하면, 해당 LED가 켜짐.

⑥	HerkuleX의 각도제어 및 각도 확인기능.

	원하는 각도(degree)를 입력한 후에 ‘Angle Move’버튼을 클릭하여 원하는 각도로 위치동작.

	HerkuleX의 현재 각도를 확인하기 위해서는 ‘Set Angle Call’버튼을 클릭하여 데이터를 요청하고, ‘Get Angle Data’버튼을 클릭하여 각도 값을 확인.

⑦	HerkuleX의 상태 확인기능.

	‘Get Status’버튼을 클릭하여, HerkuleX’의 상태정보를 요청하고, ‘View Status’버튼을 클릭하여 상태정보를 메시지 박스형태로 확인가능.

![11](https://user-images.githubusercontent.com/58063370/73431856-b898ff00-4384-11ea-9cc4-10875f634882.png)

	위의 그림과 같은 경우는 Min Position의 범위를 넘어서 위치제어를 시도한 상태이기 때문에 Position Limit Error가 ‘1’로 되어 있는 것을 볼 수 있음.

⑧	HerkuleX의 Error해제 및 공장초기화, 리부팅 기능.

	발생된 Error의 해제와 RAM & EEP의 Data를 모두 공장 초기화, 전원의 Off->On을 호출.





