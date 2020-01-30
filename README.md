### README.md

- PanTilt_2Axis_SampleCode
* DRS-0101 두 개를 이용한 Pantilt Module제어용 예제입니다.
* 해당 예제에서는 HDLL(HerkuleX.DLL)을 이용한 각종 함수들의 사용방법에 대한 기능들이 구현되어 있습니다.

. 통신 연결/해제.

. RAM Register와 EEP Register의 읽기/쓰기.

. LED 제어.

. 위치/속도 제어.

. JOG모드의 활용.



-	해당 Sample Code는 2개의 HerkuleX(DRS-0101)을 이용한 Pan/Tilt Module 제어 프로그램이다.

-	Sample Code에서는 Pan과 Tilt를 개별로 동작하는 Position Move함수와 S_JOG MOVE함수를 이용하여 2개의 HerkuleX를 동기제어(위치제어)를 사용하였다. (S_JOG함수의 사용을 위하여, SJOG구조체 사용)

	WM_HSCROLL 메시지를 이용하여, 2개의 Slider Control로 Pan과 Tilt의 위치동작을 해볼 수 있으며, 해당 기능에서 사용된 함수는 Position Move이다.

	키보드의 방향키 입력을 이용하여, Pan/Tilt를 동시에 움직일 수 있으며, 해당 기능에서 사용된 함수는 S_JOG Move이다.

	WM_TIMER 메시지를 이용하여, Pan과 Tilt의 위치 값을 확인 후 화면에 업데이트한다. 

 ![2](https://user-images.githubusercontent.com/58063370/73432158-7fad5a00-4385-11ea-8627-876ed27db29a.png)


①	통신연결/해제, 원점위치 이동 기능.

	‘Connect’버튼을 클릭하면, COM3번에 115,200bps로 통신연결이 호출되고, Pan(HerkuleX ID 1)과 Tilt(HerkuleX ID 2)의 Initialize함수를 호출한다. Pan/Tilt의 Torque On를 시킨 후 S_JOG Move를 이용하여 Pan/Tilt를 원점(0도)위치로 동작(HOME Pose버튼)시킨다.

②	Pan제어그룹.

	Slider Control를 조작하여, Pan의 위치제어를 할 수가 있으며, Play Time에 입력된 값으로 동작시간을 결정한다.

	Position 입력 창에는 Timer에서 확인된 위치 피드백 데이터가 업데이트 된다.

③	Tilt제어그룹.

	Slider Control를 조작하여, Tilt의 위치제어를 할 수가 있으며, Play Time에 입력된 값으로 동작시간을 결정한다.

	Position 입력 창에는 Timer에서 확인된 위치 피드백 데이터가 업데이트 된다.

④	키보드 입력 기능설명 텍스트.

	어떠한 키보드 입력으로 어떤 동작이 가능한지에 대해서 작성된 텍스트 부분이다.

